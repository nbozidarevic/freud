# Roadmap

Evolve the C-to-Brainfuck transpiler into a tested, documented, portable
toolchain. Current position: Phase 1 complete (26/26 tests green, CI green).

Phase order is deliberate: harden, then decide the stack, then modernize
the build (no point polishing a build the stack decision might replace),
then optimize, extend, and distribute.

- [x] Phase 0 — Ground truth: semantics doc, language identity (C subset),
      baseline record.
- [x] Phase 1 — Harden to the thesis test spec: differential tests per
      construct, runner memory model, switch/break, errors with exit codes.
- [ ] Phase 4 — Stack decision (pulled forward): time-boxed spikes with
      decision records. Parser: hand-written vs Tree-sitter vs ANTLR
      upgrade. Core language: Rust vs Zig vs incumbent C++.
- [ ] Phase 2 — Hermetic build + structured tests + CI follow-ups,
      following the stack decision.
- [ ] Phase 3 — Reframe CLI/docs to transpile-first (no rename yet).
- [ ] Phase 5 — Performance: harness, published results, optimizations.
- [ ] Phase 6 — Language expansion (thesis order).
- [ ] Phase 7 — Native-first distribution adapters; web adapter gated.
- [ ] Phase 8 — Rename, final docs, changelog, tag.

## Operating loop (CI-primary)

Local binary execution is blocked by Santa, so CI is the verification
authority: implement locally, compile-check locally (compiling needs no
allows), commit, push; CI builds and runs the suite on Ubuntu + macOS.
Spike work happens on `spike/*` branches with branch-scoped workflows;
spikes run sequentially (stop when the decision is clear) and conclude
with a record under `docs/decisions/`.
