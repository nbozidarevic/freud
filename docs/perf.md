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
| addition | 47167 | 0.031 | 5.546 | 5.366 | 100 | 2 |
| addsub | 436224 | 0.630 | 81.145 | 79.384 | 25 | 28 |
| assign | 1751145 | 2.326 | 6.635 | 6.364 | 100 | 32 |
| branch | 11037 | 0.027 | 0.103 | 0.089 | 100 | 10 |
| cmp | 791215 | 0.505 | 2.263 | 1.854 | 100 | 32 |
| complex | 360661 | 0.235 | 23.418 | 21.151 | 86 | 210 |
| div | 506880 | 0.330 | 2.112 | 1.839 | 100 | 18 |
| fordecl | 258562 | 0.177 | 2.320 | 2.229 | 100 | 10 |
| hello_world | 1209 | 0.003 | 0.005 | 0.004 | 100 | 14 |
| io | 119058 | 0.081 | 6.225 | 6.184 | 100 | 8 |
| logic | 680296 | 0.441 | 1.744 | 1.543 | 100 | 28 |
| loop | 207264 | 0.143 | 2.005 | 1.951 | 100 | 8 |
| mod | 539862 | 0.346 | 2.216 | 1.873 | 100 | 18 |
| mul | 387704 | 0.262 | 67.198 | 65.445 | 30 | 24 |
| switch | 97941 | 0.101 | 0.556 | 0.524 | 100 | 21 |

Runner microbenchmarks:

| name | BF bytes | run mean (ms) | run min (ms) | iters | out bytes |
|---|---|---|---|---|---|
| nested-loops | 43 | 0.005 | 0.005 | 100 | 1 |
| tape-walk | 200002 | 0.293 | 0.274 | 100 | 1 |
| cell-bump | 100001 | 0.311 | 0.307 | 100 | 1 |
| skip-scan | 100002 | 0.147 | 0.144 | 100 | 0 |
| io-echo | 5 | 0.050 | 0.049 | 100 | 4096 |
<!-- END RESULTS -->

## Freshness mandate

Refresh this file after any change to the runner, the code emitter,
or the harness itself: regenerate with
`./rs/target/release/freud-bench --write docs/perf.md` and commit the
result. Perf-affecting changes without a refreshed results section
are incomplete.

## Optimization log

- Baseline (no optimizations yet; see the results above).
