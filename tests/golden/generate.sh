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
"$FREUD" > golden/cli/no-args.out
"$FREUD" bogus > golden/cli/unknown.out || true
"$FREUD" bogus -c > golden/cli/unknown-badflag.out || true
"$FREUD" run > golden/cli/run-no-args.out || true
"$FREUD" run -c > golden/cli/run-c-missing.out || true
"$FREUD" run -c run/nested.bf -i > golden/cli/run-i-missing.out || true
"$FREUD" run -c run/nested.bf -o > golden/cli/run-o-missing.out || true
"$FREUD" format -c > golden/cli/format-c-missing.out || true
"$FREUD" format -c format/squares.in -o > golden/cli/format-o-missing.out || true
"$FREUD" run -c run/nested.bf -i run/nested.in -z > golden/cli/run-unknown-flag.out
"$FREUD" format -c format/squares.in -i whatever > golden/cli/format-i-ignored.out
"$FREUD" run -c run/eof.bf -i /nonexistent-xyz > golden/cli/run-missing-input.out
"$FREUD" run -c run/nested.bf -i run/nested.in -o /nonexistent-dir-xyz/f > golden/cli/run-bad-output.out
"$FREUD" format -c format/squares.in -o /nonexistent-dir-xyz/f > golden/cli/format-bad-output.out
"$FREUD" run -c /nonexistent-xyz > golden/cli/run-missing-code.out
"$FREUD" format -c /nonexistent-xyz > golden/cli/format-missing-code.out
echo "goldens written: $(find golden -type f | wc -l) files, $(du -sh golden | cut -f1)"
