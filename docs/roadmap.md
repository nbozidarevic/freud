# Roadmap

Evolve the C-to-Brainfuck transpiler into a tested, documented, portable
toolchain. Current position: Phase 2 complete — Rust core migrated,
C++ retired (see 0005); goldens pin the verified outputs.

Phase order is deliberate: harden, then decide the stack, then modernize
the build (no point polishing a build the stack decision might replace),
then optimize, extend, and distribute.

- [x] Phase 0 — Ground truth: semantics doc, language identity (C subset),
      baseline record.
- [x] Phase 1 — Harden to the thesis test spec: differential tests per
      construct, runner memory model, switch/break, errors with exit codes.
- [x] Phase 4 — Stack decision (pulled forward): spikes + records 0003
      (hand parser: feasible), 0004 (tree-sitter: weaker diagnostics),
      core-lang differential (Rust/Zig/C++ byte-identical) → 0005 verdict:
      Rust core, hand-written parser.
- [x] Phase 2 — Rust migration (tokenizer, parser, codegen, runner,
      formatter, unified CLI) + golden CI; C++ retired.
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
