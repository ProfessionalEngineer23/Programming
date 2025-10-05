#!/usr/bin/env bash
set -euo pipefail

FORM_URL="${1:?Usage: $0 <FORM_URL>}"
UA="Mozilla/5.0"
WORK="$(mktemp -d)"
COOK="$WORK/cookies.txt"
HTML="$WORK/page.html"
BASE_SCHEME_HOST="$(perl -e '
  ($u)=@ARGV; $u=~m{^(https?)://([^/]+)} or die;
  print "$1://$2";
' "$FORM_URL")"

have_jq=0; command -v jq >/dev/null 2>&1 && have_jq=1

say(){ printf "[*] %s\n" "$*"; }

# 1) Fetch the page
say "GET $FORM_URL"
curl -sSL -A "$UA" -c "$COOK" -o "$HTML" "$FORM_URL"

# 2) Try to extract formId and token from the HTML (several patterns)
form_id="$(
  grep -oE '"formId"\s*:\s*"[^"]+"' "$HTML" | sed -E 's/.*"formId"\s*:\s*"([^"]+)".*/\1/' | head -n1
)"
[[ -z "$form_id" ]] && form_id="$(
  grep -oE 'data-form-id="[^"]+"' "$HTML" | sed -E 's/.*data-form-id="([^"]+)".*/\1/' | head -n1
)"

token="$(
  grep -oE '"token"\s*:\s*"[^"]+"' "$HTML" | sed -E 's/.*"token"\s*:\s*"([^"]+)".*/\1/' | head -n1
)"
[[ -z "$token" ]] && token="$(
  grep -oE 'name="csrf-token"\s+content="[^"]+"' "$HTML" | sed -E 's/.*content="([^"]+)".*/\1/' | head -n1
)"
[[ -z "$token" ]] && token="$(
  grep -oE 'name="__RequestVerificationToken"\s+value="[^"]+"' "$HTML" | sed -E 's/.*value="([^"]+)".*/\1/' | head -n1
)"

# 3) Collect same-origin <script src> URLs and download them
say "Collecting same-origin scripts..."
grep -oE '<script[^>]+src="[^"]+"' "$HTML" | sed -E 's/.*src="([^"]+)".*/\1/' |
awk -v base="$BASE_SCHEME_HOST" '
  /^[a-z]+:\/\// { print; next }
  /^\//          { print base $0; next }
  { print base "/" $0 }
' | sort -u > "$WORK/scripts.txt"

mkdir -p "$WORK/js"
while read -r js; do
  curl -sSL -A "$UA" -b "$COOK" -o "$WORK/js/$(printf "%s" "$js" | sed "s#[/:?&=]#_#g")" "$js" || true
done < "$WORK/scripts.txt"

# 4) Search HTML + JS for endpoints and header names
say "Scanning for endpoints..."
cat "$HTML" "$WORK"/js/* 2>/dev/null | grep -Eo '(/[A-Za-z0-9._-]+){2,}' | \
grep -E 'api|form|submit|submitform|schema|questions|definition' | sort -u > "$WORK/paths.txt"

# Turn relative paths into absolute candidates
awk -v base="$BASE_SCHEME_HOST" '
  {
    if ($0 ~ /^https?:\/\//) print $0; else print base $0;
  }' "$WORK/paths.txt" | sort -u > "$WORK/urls.txt"

# Likely submit/schema URLs by keyword
submit_candidates="$(grep -iE 'submit|submitform' "$WORK/urls.txt" || true)"
schema_candidates="$(grep -iE 'schema|definition|forms/|questions' "$WORK/urls.txt" || true)"

# Header name candidates (X-* and *token* seen in code)
header_candidates="$(
  cat "$HTML" "$WORK"/js/* 2>/dev/null |
  grep -oE '["'\''](X-[A-Za-z0-9-]+|[A-Za-z0-9-]*[Tt]oken[A-Za-z0-9-]*)["'\'']' |
  sed -E 's/^["'\'']|["'\'']$//g' | sort -u
)"

# 5) Print findings
echo
say "=== DISCOVERY RESULTS (candidates) ==="
echo "FORM_URL:       $FORM_URL"
echo "BASE:           $BASE_SCHEME_HOST"
echo "formId:         ${form_id:-<not found in HTML>}"
echo "token (value):  ${token:-<not found in HTML>}"
echo

echo "Possible SUBMIT_URL values:"
if [[ -n "$submit_candidates" ]]; then echo "$submit_candidates"; else echo "  <none found>"; fi
echo

echo "Possible SCHEMA_URL values:"
if [[ -n "$schema_candidates" ]]; then echo "$schema_candidates"; else echo "  <none found>"; fi
echo

echo "Possible TOKEN_HEADER names:"
if [[ -n "$header_candidates" ]]; then echo "$header_candidates"; else echo "  <none found>"; fi
echo

say "Cookies captured (may be auth/CSRF relevant):"
grep -E '^[^#]' "$COOK" || true

say "Done. Inspect and pick the best matches."
echo "Workdir kept at: $WORK"
