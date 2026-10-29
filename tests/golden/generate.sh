#!/usr/bin/env bash
# Regenerate the golden files under tests/golden/ from the Rust binaries.
# Run (binaries must be built first):
#   cargo build --release --manifest-path rs/Cargo.toml
#   ./tests/golden/generate.sh
# Goldens pin the byte outputs proven equal to the retired C++ oracle
# (differentials green at retirement); regenerate only with review.
set -euo pipefail
cd "$(dirname "$0")/.."
FREUD=../rs/target/release/freud
TOK=../rs/target/release/tokdump
PARSE=../rs/target/release/parsedump
BFC=../rs/target/release/bfcompile
rm -rf golden
mkdir -p golden/tokdump golden/parsedump golden/bf golden/format-min golden/cli
for f in compile/*.c; do
  n=${f%.c}; n=${n#compile/}
  "$TOK" "$f" > "golden/tokdump/$n.tok"
  "$PARSE" "$f" > "golden/parsedump/$n.parse"
  "$BFC" "$f" > "golden/bf/$n.bf"
done
for f in differential/micro/*.c; do
  n=${f%.c}; n=${n#differential/micro/}
  "$BFC" "$f" > "golden/bf/micro_$n.bf"
done
for f in format/*.in; do
  n=${f%.in}; n=${n#format/}
  "$FREUD" format -c "$f" -m > "golden/format-min/$n.out"
done
# Error-path run goldens live with the fixtures (combined stdout+stderr).
"$FREUD" run -c run/unbalanced_close.bf -i run/unbalanced_close.in > run/unbalanced_close.out 2>&1 || true
"$FREUD" run -c run/unbalanced_open.bf -i run/unbalanced_open.in > run/unbalanced_open.out 2>&1 || true
# Errors go to stderr; goldens capture stdout+stderr combined.
"$FREUD" > golden/cli/no-args.out 2>&1
"$FREUD" help > golden/cli/help.out 2>&1
"$FREUD" --version > golden/cli/version.out 2>&1
"$FREUD" -c > golden/cli/compile-c-missing.out 2>&1 || true
"$FREUD" run > golden/cli/run-no-file.out 2>&1 || true
"$FREUD" run -c > golden/cli/run-c-missing.out 2>&1 || true
"$FREUD" run -c run/nested.bf -i > golden/cli/run-i-missing.out 2>&1 || true
"$FREUD" run -c run/nested.bf -o > golden/cli/run-o-missing.out 2>&1 || true
"$FREUD" format -c > golden/cli/format-c-missing.out 2>&1 || true
"$FREUD" format -c format/squares.in -o > golden/cli/format-o-missing.out 2>&1 || true
"$FREUD" run -c run/nested.bf -i run/nested.in -z > golden/cli/run-unknown-flag.out 2>&1
"$FREUD" format -c format/squares.in -i whatever > golden/cli/format-i-ignored.out 2>&1
"$FREUD" run -c run/eof.bf -i /nonexistent-xyz > golden/cli/run-missing-input.out 2>&1 || true
"$FREUD" run -c run/nested.bf -i run/nested.in -o /nonexistent-dir-xyz/f > golden/cli/run-bad-output.out 2>&1 || true
"$FREUD" format -c format/squares.in -o /nonexistent-dir-xyz/f > golden/cli/format-bad-output.out 2>&1 || true
"$FREUD" run -c /nonexistent-xyz > golden/cli/run-missing-code.out 2>&1 || true
"$FREUD" format -c /nonexistent-xyz > golden/cli/format-missing-code.out 2>&1 || true
"$FREUD" compile -c /nonexistent-xyz > golden/cli/compile-missing-code.out 2>&1 || true
"$FREUD" /nonexistent-xyz > golden/cli/compile-bare-missing.out 2>&1 || true
echo "goldens written: $(find golden -type f | wc -l) files, $(du -sh golden | cut -f1)"
