#!/usr/bin/env bash
set -euo pipefail

# ====== You can either: (A) set these as env vars when you run, or (B) paste here as defaults ======
: "${FORM_URL:=https://forms.office.com/formapi/api/766317cb-e948-4e5f-8cec-dabc8e2fd5da/users/415b0928-6487-4ce7-a799-6786684da92b/forms('yxdjdkjpX06M7Nq8ji_V2igJW0GHZOdMp5lnhmhNqStURDU3V0ZTVFExUFNTSUVUWElRME44Wkc2Ti4u')/responses}"
: "${REFERER:=https://forms.office.com/Pages/ResponsePage.aspx?id=yxdjdkjpX06M7Nq8ji_V2igJW0GHZOdMp5lnhmhNqStURDU3V0ZTVFExUFNTSUVUWElRME44Wkc2Ti4u}"
: "${TOKEN:=}"    # paste fresh __requestverificationtoken here OR export TOKEN='...'
: "${COOKIE:=}"   # paste full cookie header value here OR export COOKIE='...'

# ====== Question IDs from your captured body (unchanged) ======
Q1="r63aec74a51a34658952545952a41d1eb"   # text
Q2="rddab9a5faba043478c7d81277a2a4809"   # number
Q3="r2df6f745250f41558213ab393abef702"   # number

# ====== CSV path (defaults to testdata.csv) — expects header: q1,q2,q3 ======
csv="${1:-testdata.csv}"

# Throttle a little between submissions
DELAY_SEC=0.3

# ----- helpers -----
die(){ echo "Error: $*" >&2; exit 1; }

command -v curl >/dev/null 2>&1 || die "curl not found. Use Git Bash with curl available."
command -v python >/dev/null 2>&1 || die "python not found. Install Python (for safe JSON quoting)."
[[ -s "$csv" ]] || die "CSV '$csv' not found or empty."
[[ "$FORM_URL" == https://*responses ]] || die "FORM_URL looks wrong."
[[ "$REFERER" == https://forms.office.com/Pages/ResponsePage.aspx* ]] || die "REFERER looks wrong."

# Token/cookie must be present (don’t enforce specific contents—just non-empty)
[[ -n "$TOKEN" ]]  || die "TOKEN is empty. Copy '__requestverificationtoken' from the successful POST in DevTools."
[[ -n "$COOKIE" ]] || die "COOKIE is empty. Copy the full 'cookie' header from the successful POST in DevTools."

# JSON-escape stdin as a string literal
json_escape() {
  python - <<'PY'
import json, sys
print(json.dumps(sys.stdin.read().rstrip("\n")))
PY
}

# Convert stdin to a JSON string value (used to wrap the answers array text)
json_stringify() {
  python - <<'PY'
import json, sys
print(json.dumps(sys.stdin.read()))
PY
}

# ----- main loop -----
# Robust CSV read (handles quoted cells). Skip header row.
awk -v FPAT='([^,]+)|(\"([^\"]|\"\")*\")' 'NR>1{print}' "$csv" | \
while IFS=, read -r raw1 raw2 raw3; do
  # unquote & unescape
  a1="${raw1%\"}"; a1="${a1#\"}"; a1="${a1//\"\"/\"}"
  a2="${raw2%\"}"; a2="${a2#\"}"; a2="${a2//\"\"/\"}"
  a3="${raw3%\"}"; a3="${a3#\"}"; a3="${a3//\"\"/\"}"

  # optional validation for numeric fields
  [[ -z "$a2" || "$a2" =~ ^-?[0-9]+(\.[0-9]+)?$ ]] || die "Row has non-numeric q2: '$a2'"
  [[ -z "$a3" || "$a3" =~ ^-?[0-9]+(\.[0-9]+)?$ ]] || die "Row has non-numeric q3: '$a3'"

  start_iso="$(date -u +"%Y-%m-%dT%H:%M:%S.000Z")"
  submit_iso="$(date -u +"%Y-%m-%dT%H:%M:%S.000Z")"

  # Build the inner answers array (JSON), then wrap it as a string (MS Forms quirk)
  a1_json="$(printf '%s' "$a1" | json_escape)"
  answers_inner=$(cat <<ANS
[
  {"questionId":"$Q1","answer1": $a1_json},
  {"questionId":"$Q2","answer1": $a2},
  {"questionId":"$Q3","answer1": $a3}
]
ANS
)
  answers_str="$(printf '%s' "$answers_inner" | json_stringify)"

  body=$(cat <<JSON
{
  "startDate": "$start_iso",
  "submitDate": "$submit_iso",
  "answers": $answers_str
}
JSON
)

  echo "Submitting: q1=$a1, q2=$a2, q3=$a3"
  http_code=$(
    curl -sS -o /tmp/forms_resp.json -w "%{http_code}" "$FORM_URL" \
      -H "__requestverificationtoken: $TOKEN" \
      -H "Accept: application/json" \
      -H "Content-Type: application/json" \
      -H "Origin: https://forms.office.com" \
      -H "Referer: $REFERER" \
      -H "x-ms-form-request-ring: business" \
      -H "x-ms-form-request-source: ms-formweb" \
      -b "$COOKIE" \
      --data-raw "$body"
  )

  if [[ "$http_code" == "201" ]]; then
    echo "  ✓ Created (201)."
  elif [[ "$http_code" == "401" ]]; then
    echo "  ✗ 401 Unauthorized — tokens/cookies expired. Re-copy TOKEN and COOKIE from DevTools."
    cat /tmp/forms_resp.json
    exit 1
  else
    echo "  ✗ Failed ($http_code). Response:"
    cat /tmp/forms_resp.json
    exit 1
  fi

  sleep "$DELAY_SEC"
done
