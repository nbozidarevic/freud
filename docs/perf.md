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
| addition | 56339 | 0.080 | 5.932 | 5.899 | 100 | 2 |
| addsub | 521520 | 1.367 | 95.262 | 94.915 | 21 | 28 |
| assign | 1787399 | 2.509 | 16.553 | 16.173 | 100 | 32 |
| branch | 11037 | 0.044 | 0.126 | 0.123 | 100 | 10 |
| break | 632935 | 0.947 | 18.096 | 17.770 | 100 | 24 |
| cmp | 938027 | 1.336 | 4.521 | 4.431 | 100 | 32 |
| complex | 376767 | 0.571 | 43.712 | 43.489 | 46 | 210 |
| continue | 855743 | 1.274 | 39.665 | 39.257 | 51 | 30 |
| div | 585138 | 0.834 | 3.996 | 3.838 | 100 | 18 |
| dowhile | 515169 | 0.763 | 4.763 | 4.630 | 100 | 17 |
| fordecl | 280864 | 0.433 | 5.016 | 4.947 | 100 | 10 |
| hello_world | 1209 | 0.005 | 0.008 | 0.008 | 100 | 14 |
| io | 123200 | 0.221 | 10.317 | 9.594 | 100 | 8 |
| logic | 812538 | 1.162 | 3.371 | 3.261 | 100 | 28 |
| loop | 236198 | 0.340 | 4.559 | 4.520 | 100 | 8 |
| mod | 617886 | 0.883 | 3.868 | 3.804 | 100 | 18 |
| mul | 462766 | 0.663 | 72.950 | 72.529 | 28 | 24 |
| printnum | 1360845 | 1.913 | 302.606 | 302.224 | 7 | 85 |
| switch | 106465 | 0.197 | 0.965 | 0.943 | 100 | 21 |
| ternary | 726950 | 1.059 | 9.039 | 8.866 | 100 | 24 |

Runner microbenchmarks:

| name | BF bytes | run mean (ms) | run min (ms) | iters | out bytes |
|---|---|---|---|---|---|
| nested-loops | 43 | 0.007 | 0.007 | 100 | 1 |
| tape-walk | 200002 | 0.855 | 0.828 | 100 | 1 |
| cell-bump | 100001 | 0.610 | 0.595 | 100 | 1 |
| skip-scan | 100002 | 0.208 | 0.197 | 100 | 0 |
| io-echo | 5 | 0.067 | 0.065 | 100 | 4096 |
<!-- END RESULTS -->

## Freshness mandate

Refresh this file after any change to the runner, the code emitter,
or the harness itself: regenerate with
`./rs/target/release/freud-bench --write docs/perf.md` and commit the
result (or run the `perf-snapshot` workflow from the Actions tab and
commit its artifact). Perf-affecting changes without a refreshed
results section are incomplete.

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
- Peephole post-pass measured and rejected: across all golden
  outputs, zero occurrences of `<>`, `><`, `+-`, `-+`, `[]`, and
  doubled clears — the emitter already tracks the pointer exactly,
  so a cancellation pass would change nothing. The remaining
  structural lever is loop-based constant construction (`[-]` plus
  up to 255 `+`s occurs 12,816 times); it needs a scratch cell and
  would churn every golden, so it is deferred to future codegen work.
