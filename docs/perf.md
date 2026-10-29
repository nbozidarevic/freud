# Performance

Execution speed is the metric that matters here: transpiled Brainfuck
programs do "manual" memory management, so running them is where time
goes. Transpile time is measured too, for context.

## Method

- Harness: `rs/src/bin/freud-bench.rs`, run from the repo root after
  `cargo build --release --manifest-path rs/Cargo.toml`:
  `./rs/target/release/freud-bench`.
- In-process timing (excludes process startup). Each case runs at
  least 3 iterations and until ~2s total elapsed (cap 100 iterations);
  the mean and min over those iterations are reported.
- Corpus: every `tests/compile/*.c` with its `.in`, plus synthetic
  runner microbenchmarks (loop nesting, tape growth, cell bumps,
  skip-scans, I/O echo).
- CI runners are shared and noisy: compare numbers within one run,
  not across runs, and re-run before drawing conclusions.

## Results

<!-- BEGIN RESULTS -->
In-process timing on linux-x86_64 (`freud-bench`, adaptive iterations: at least 3, until ~2s total, cap 100). Times exclude process startup.

| program | BF bytes | compile mean (ms) | run mean (ms) | run min (ms) | iters | out bytes |
|---|---|---|---|---|---|---|
| addition | 47167 | 0.067 | 5.170 | 4.238 | 100 | 2 |
| addsub | 436224 | 1.124 | 59.318 | 46.566 | 34 | 28 |
| assign | 1751145 | 3.946 | 13.978 | 13.769 | 100 | 32 |
| branch | 11037 | 0.042 | 0.134 | 0.129 | 100 | 10 |
| cmp | 791215 | 1.165 | 3.019 | 2.685 | 100 | 32 |
| complex | 360661 | 0.542 | 36.212 | 36.121 | 56 | 210 |
| div | 506880 | 0.769 | 2.234 | 2.052 | 100 | 18 |
| fordecl | 258562 | 0.396 | 3.577 | 3.269 | 100 | 10 |
| hello_world | 1209 | 0.005 | 0.008 | 0.008 | 100 | 14 |
| io | 119058 | 0.211 | 8.783 | 8.689 | 100 | 8 |
| logic | 680296 | 0.965 | 2.217 | 2.098 | 100 | 28 |
| loop | 207264 | 0.309 | 3.054 | 3.003 | 100 | 8 |
| mod | 539862 | 0.773 | 2.318 | 2.180 | 100 | 18 |
| mul | 387704 | 0.550 | 48.953 | 38.437 | 41 | 24 |
| switch | 97941 | 0.184 | 0.740 | 0.719 | 100 | 21 |

Runner microbenchmarks:

| name | BF bytes | run mean (ms) | run min (ms) | iters | out bytes |
|---|---|---|---|---|---|
| nested-loops | 43 | 0.008 | 0.007 | 100 | 1 |
| tape-walk | 200002 | 0.800 | 0.694 | 100 | 1 |
| cell-bump | 100001 | 0.667 | 0.653 | 100 | 1 |
| skip-scan | 100002 | 0.231 | 0.220 | 100 | 0 |
| io-echo | 5 | 0.062 | 0.060 | 100 | 4096 |
<!-- END RESULTS -->

## Freshness mandate

Refresh this file after any change to the runner, the code emitter,
or the harness itself: regenerate with
`./rs/target/release/freud-bench --write docs/perf.md` and commit the
result. Perf-affecting changes without a refreshed results section
are incomplete.

## Optimization log

- Baseline (no optimizations yet; see the results above).
- Runner jump table + buffered I/O (`rs/src/runner.rs`): `[` skips
  and `]` jumps are O(1) via a precomputed table; `,`/`.` go through
  8 KiB buffers. Shared-runner noise dominates corpus means (compile
  times, which this change cannot affect, also moved ~2x between
  runs); heavy-loop programs improved on minima (addsub run-min
  79.4 -> 46.6 ms, mul 65.4 -> 38.4 ms), consistent with cheaper hot
  loops. Buffered I/O shows no change in-process (the harness uses
  in-memory input); its win is at real pipes/files.
