// submit_testform.cjs
// Usage: node submit_testform.cjs testdata1.csv
const fs = require('fs');
const readline = require('readline');
const { parse } = require('csv-parse/sync');
const { chromium } = require('playwright');

// ====== EDIT THIS URL (your form's Respond link) ======
const FORM_URL = "https://forms.office.com/Pages/ResponsePage.aspx?id=yxdjdkjpX06M7Nq8ji_V2igJW0GHZOdMp5lnhmhNqStURDU3V0ZTVFExUFNTSUVUWElRME44Wkc2Ti4u";
// ======================================================

function rlQuestion(q) {
  const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
  return new Promise(res => rl.question(q, ans => { rl.close(); res(ans); }));
}

// --- CSV loading (robust to BOM and different delimiters) ---
function parseSmart(text) {
  const base = { columns: true, skip_empty_lines: true, bom: true, relax_column_count: true, trim: true };
  for (const delimiter of [',',';','\t']) {
    try {
      const rows = parse(text, { ...base, delimiter });
      if (!rows.length) return rows;
      const cols = Object.keys(rows[0]).map(c => c.trim().toLowerCase());
      if (cols.includes('question1') && cols.includes('nps') && cols.includes('rating')) return rows;
    } catch {}
  }
  throw new Error("Could not parse CSV with ',', ';' or TAB. Need headers: Question1,NPS,Rating.");
}

function parseRow(row) {
  const key = k => Object.keys(row).find(h => h.trim().toLowerCase() === k);
  const q1 = ((row[key('question1')] ?? "No") + "").trim();
  let nps = parseInt(row[key('nps')] ?? "0", 10);
  let stars = parseInt(row[key('rating')] ?? "1", 10);
  if (isNaN(nps)) nps = 0;
  if (isNaN(stars)) stars = 1;
  nps   = Math.max(0, Math.min(10, nps));
  stars = Math.max(1, Math.min(5, stars));
  return { q1, nps, stars };
}

async function waitUntilFormVisible(page) {
  await page.waitForURL(/forms\.office\.com\/.*responsepage/i, { timeout: 0 });
  // “Submit” or “Send” — page or any frame
  const hasSubmitAnywhere = async p => {
    if (await p.getByRole('button', { name: /(submit|send)/i }).count()) return true;
    for (const f of p.frames()) {
      if (await f.getByRole('button', { name: /(submit|send)/i }).count()) return true;
    }
    return false;
  };
  const start = Date.now();
  while (!(await hasSubmitAnywhere(page))) {
    if (Date.now() - start > 60000) throw new Error("Form not visible after 60s");
    await page.waitForTimeout(500);
  }
}

// Return Page/Frame that contains the form controls
async function getFormScope(page) {
  const scopes = [page, ...page.frames()];
  for (const s of scopes) {
    if (await s.getByRole('button', { name: /(submit|send)/i }).count()) return s;
  }
  const start = Date.now();
  while (Date.now() - start < 15000) {
    for (const s of [page, ...page.frames()]) {
      if (await s.getByRole('button', { name: /(submit|send)/i }).count()) return s;
    }
    await page.waitForTimeout(500);
  }
  return page;
}

// Click “Yes/No” inside a (radio)group; fallback to first/second radio
async function clickYesNo(container, yes) {
  const target = yes ? /yes/i : /no/i;
  const byName = container.getByRole('radio', { name: target });
  if (await byName.count()) { await byName.first().scrollIntoViewIfNeeded(); await byName.first().check(); return; }
  const radios = container.getByRole('radio');
  const rCount = await radios.count();
  console.log(`    (Yes/No) radios=${rCount}`);
  if (!rCount) throw new Error("No radios found for Yes/No");
  const idx = yes ? 0 : 1;
  await radios.nth(Math.min(idx, rCount - 1)).scrollIntoViewIfNeeded();
  await radios.nth(Math.min(idx, rCount - 1)).check();
}

// Generic numeric choice (NPS 0–10). Works with radios, options, or buttons by index.
async function clickNumberInGroup(container, number) {
  const candidates = container.locator('input[type="radio"], [role="radio"], [role="option"], button');
  await candidates.first().waitFor({ state: 'visible', timeout: 10000 }).catch(() => {});
  const count = await candidates.count();
  console.log(`    (NPS) candidates=${count}`);
  if (count === 0) throw new Error('No clickable choices found for NPS');
  const idx = Math.max(0, Math.min(count - 1, number)); // ordered 0..10 visually
  const el = candidates.nth(idx);
  await el.scrollIntoViewIfNeeded();
  await el.click({ force: true });
}

// Stars 1–5. Works with radios/options/buttons by index.
async function clickStars(container, stars) {
  const candidates = container.locator('input[type="radio"], [role="radio"], [role="option"], button');
  await candidates.first().waitFor({ state: 'visible', timeout: 10000 }).catch(() => {});
  const count = await candidates.count();
  console.log(`    (Stars) candidates=${count}`);
  if (count === 0) throw new Error('No clickable choices found for Stars');
  const idx = Math.max(0, Math.min(count - 1, stars - 1)); // ordered 1..5 visually
  const el = candidates.nth(idx);
  await el.scrollIntoViewIfNeeded();
  await el.click({ force: true });
}

async function fillAndSubmit(scope, { q1, nps, stars }) {
  scope.setDefaultTimeout?.(60000);

  // Prefer role=radiogroup, else role=group, else fallback to root
  const radioGroups = scope.getByRole('radiogroup');
  const groups     = scope.getByRole('group');
  const rgCount = await radioGroups.count();
  const gCount  = await groups.count();
  console.log(`  Found groups: group=${gCount}, radiogroup=${rgCount}`);

  let yesNoGrp, npsGrp, starsGrp;
  if (rgCount >= 3) {
    yesNoGrp = radioGroups.nth(0);
    npsGrp   = radioGroups.nth(1);
    starsGrp = radioGroups.nth(2);
  } else if (gCount >= 3) {
    yesNoGrp = groups.nth(0);
    npsGrp   = groups.nth(1);
    starsGrp = groups.nth(2);
  } else {
    yesNoGrp = scope;
    npsGrp   = scope;
    starsGrp = scope;
  }

  await clickYesNo(yesNoGrp, /yes/i.test(q1));
  await clickNumberInGroup(npsGrp, nps);
  await clickStars(starsGrp, stars);

  // Submit (accept Submit/Send)
  const submitBtn = scope.getByRole('button', { name: /(submit|send)/i });
  await submitBtn.scrollIntoViewIfNeeded();
  await submitBtn.click();

  // If "Submit another response" appears (button or link), click it
  await scope.waitForTimeout(800);
  const anotherBtn  = scope.getByRole('button', { name: /submit another response/i });
  const anotherLink = scope.getByRole('link',   { name: /submit another response/i });
  if (await anotherBtn.count())      await anotherBtn.click();
  else if (await anotherLink.count()) await anotherLink.click();
}

// Pick the tab that actually has the form (handles login opening a new tab)
async function pickFormPage(ctx) {
  const isForm = async p => {
    try {
      const url = p.url();
      if (!/forms\.office\.com/i.test(url)) return false;
      await p.waitForLoadState('domcontentloaded', { timeout: 5000 }).catch(() => {});
      if (await p.getByRole('button', { name: /(submit|send)/i }).count()) return true;
      for (const f of p.frames()) {
        if (await f.getByRole('button', { name: /(submit|send)/i }).count()) return true;
      }
      return false;
    } catch { return false; }
  };

  for (const p of ctx.pages()) if (await isForm(p)) return p;
  const start = Date.now();
  while (Date.now() - start < 60000) {
    for (const p of ctx.pages()) if (await isForm(p)) return p;
    await new Promise(r => setTimeout(r, 500));
  }
  throw new Error("Could not find a tab with the form (no Submit/Send detected).");
}

(async () => {
  const csvPath = process.argv[2] || "testdata1.csv";
  if (!fs.existsSync(csvPath)) {
    console.error(`CSV not found: ${csvPath}`);
    process.exit(1);
  }
  const raw = fs.readFileSync(csvPath, "utf8");
  const rows = parseSmart(raw);
  if (!rows.length) {
    console.error("CSV contains no data rows.");
    process.exit(1);
  }
  console.log("First parsed row:", rows[0]);

  const ctx = await chromium.launchPersistentContext('ms-profile', { headless: false });
  let page = await ctx.newPage();

  await page.goto(FORM_URL, { waitUntil: 'domcontentloaded' });
  console.log("A browser window opened. If you see Microsoft login, sign in fully.");
  await rlQuestion("Press Enter in THIS terminal AFTER you’ve finished login and can see the form.\n");

  page = await pickFormPage(ctx);
  await page.bringToFront();
  console.log("Using page:", page.url());
  await waitUntilFormVisible(page);

  for (let i = 0; i < rows.length; i++) {
    const data = parseRow(rows[i]);
    console.log(`Row ${i + 1}/${rows.length}: Q1=${data.q1}, NPS=${data.nps}, Rating=${data.stars}`);

    await page.goto(FORM_URL, { waitUntil: 'domcontentloaded' });
    await waitUntilFormVisible(page);

    try {
      const scope = await getFormScope(page);
      await fillAndSubmit(scope, data);
    } catch (err) {
      console.warn(`  Row ${i + 1} failed first try: ${err?.message || err}`);
      await page.reload({ waitUntil: 'domcontentloaded' });
      await waitUntilFormVisible(page);
      const scope2 = await getFormScope(page);
      await fillAndSubmit(scope2, data);
    }

    await page.waitForTimeout(1000); // gentle pacing
  }

  await ctx.close();
})().catch(err => { console.error(err); process.exit(1); });
