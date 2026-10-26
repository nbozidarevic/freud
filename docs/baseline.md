# Baseline (2026-10-26, pre-hardening)

First full test run on this machine. Method: manual orchestration mirroring
`tests/test` step-for-step (compile oracle, run oracle, `freud compile`,
`freud run`, byte-exact `cmp`), because the script rebuilds `tmp.o` per test
and every fresh binary needs a Santa hash allow-rule on this host. Scripts
used: `/tmp/baseline-A.sh`, `/tmp/baseline-complex-compile.sh`,
`/tmp/baseline-complex-run.sh` (throwaway, not committed).

Build: `make ANTLR_LIBRARY=/tmp/antlr-arm64/libantlr4-runtime.a` (shipped
`.a` is x86_64-only; runtime rebuilt from ANTLR 4.7.1 sources for arm64).
No rebuilds during the baseline, so allowed hashes stayed valid.
Host: arm64 macOS, Apple Clang 21, Santa Lockdown with per-hash allows,
managed Microsoft Defender (fresh binaries also die on first exec for a few
minutes even when Santa allows them — a second, transient gate).

## Results: 7 pass, 2 fail

| Test | Result | Notes |
|---|---|---|
| COMPILE-addition | PASS | `40+50` → `90`; generated BF 47,335 bytes |
| COMPILE-hello_world | PASS | 14 bytes out; generated BF 1,209 bytes |
| FORMAT-bubble_sort | PASS | byte-identical |
| FORMAT-game_of_life | PASS | byte-identical |
| FORMAT-squares | PASS | byte-identical |
| RUN-addition | PASS | checked-in `.bf` runs correctly |
| RUN-hello_world | PASS | checked-in `.bf` runs correctly |
| COMPILE-complex | FAIL | Even/Odd lines wrong (see below); generated BF 361,951 bytes |
| RUN-complex | FAIL | identical Even/Odd diff on checked-in `.bf` |

## The complex failure (modulo bug, codegen-level)

Only the `one % 2 == 0` Even/Odd lines differ (oracle says Even for
one=2,4,6,8; transpiled says Odd); all arithmetic lines — including
`one * ten / 3 + 2 - 1` for all 9 iterations — match. The checked-in
`tests/run/complex.bf` fails identically, so the interpreter faithfully
reproduces a compiler-emitted bug: `%` (or its composition with `==`/`if`)
is broken while `/` and `*` work in the same program. Phase 1 isolates this
with focused single-construct tests.

```
8c8 < \tEven / > \tOdd   (one=2)
16c16 < \tEven / > \tOdd  (one=4)
22c22 < \tEven / > \tOdd  (one=6)
28c28 < \tEven / > \tOdd  (one=8)
```

Oracle binaries kept (untracked, Santa-allowed) for regression reruns:
`tests/compile/{addition,complex,hello_world}.oracle`.
