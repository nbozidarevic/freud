# 0005 — Final stack decision: Rust core, hand-written parser

Date: 2026-10-26. Status: accepted. Closes Phase 4 (evidence: 0003,
0004, `spike/core-lang` CI).

## Parser: hand-written, in the new core language

- Beats Tree-sitter (0004): diagnostics (`line:col` at the failure
  point vs building error rendering over ERROR nodes), zero
  dependency weight, trivial subset evolution (`do...while` is ~20
  lines). Tree-sitter's strengths (incremental parsing, full-language
  coverage, highlighting ecosystems) do not serve batch transpilation
  of a deliberately small subset.
- Beats status-quo ANTLR: Java codegen dependency, frozen grammar (no
  regen toolchain on hand), 5.7k-line generated parser, observed ASan
  failures in generated code. The ANTLR C++ implementation is frozen
  as the behavioral reference during migration, then retired.
- Fallback noted: if the subset ever grows toward full C/C++, revisit
  Tree-sitter (+ `tree-sitter-cpp` grammar).

## Core language: Rust

- Spike evidence: C++/Rust/Zig tokenizers produce byte-identical
  dumps on all 15 fixtures (`spike/core-lang` CI green, reported by
  the owner on 2026-10-26). Sizes are the same order (C++ 249,
  Rust 298, Zig 256 lines), so the choice rests on
  ecosystem, distribution, and ergonomics — not capability.
- Rust wins on Phase 7 distribution: `wasm-pack` → npm/demo site is
  the mature path; a dependency-free `extern "C"` core (pollution
  veto enforced structurally) bridges to C++; UniFFI covers
  Kotlin/Swift, JNI covers Java. No other candidate reaches all four
  targets from one core.
- Rust wins on Phase 2/5 ergonomics: cargo (hermetic builds via
  lockfile, built-in tests/benches for the perf-harness mandate),
  `Result`-based diagnostics, pattern matching for codegen. Memory
  safety retires the ASan class of failures.
- Zig rejected (with respect): explicit allocators match the thesis
  theme and C-ABI is effortless, but pre-1.0 churn guarantees
  migration tax, and the distribution ecosystem (no `wasm-pack`/UniFFI
  equivalents) is DIY. Revisit only if the borrow checker proves a
  genuine blocker — not expected (arena/indices pattern).
- C++ rejected as the future (kept as reference): weakest
  distribution story (Emscripten heavier than `wasm-pack`, all bridges
  hand-written), DIY hermetic builds, keeps the memory-safety tax.
  The existing suite stays green in CI as the migration oracle.

## Migration shape: sliced, oracle-guarded, no big bang

- The 26-test behavioral corpus is the safety net; every slice is a
  stacked green commit on master.
- Slices: (1) scaffold the `freud-core` crate + promote the
  differential tokenizer to master CI (C++ reference vs Rust; Zig
  served its spike purpose and stays on the spike branch);
  (2) Rust parser with structural differential; (3) codegen port with
  BF behavioral differential via the existing g++-oracle harness;
  (4) runner port vs `run/` goldens; (5) retire the C++ implementation
  + ANTLR.
- Crate naming: `freud-core` now, renamed in the Phase 8 sweep with
  everything else.

## Consequences

- Phase 4 closed; Phase 2 proceeds as Cargo-based (hermetic build =
  cargo + lockfile; structured tests = `cargo test` + existing
  harness).
- Future contributors need the Rust toolchain; CI installs it
  (`dtolnay/rust-toolchain@stable`). The Zig toolchain is needed for
  nothing outside the spike branch.
- Spike branches retained as evidence, unmerged.

## Amendment (2026-10-26): the reinvent-the-wheel concern

On review, the owner challenged the hand-written parser: are we
reinventing the wheel, especially as the C subset grows? Verdict
stands; reasoning recorded:

- The subset boundary is the product. A full-C parser accepts programs
  we cannot transpile (`struct`, `typedef`, casts) and fails late in
  codegen; the hand parser rejects non-subset constructs at the source
  location with a targeted message. Tree-sitter would still need a
  lowering pass (full-C tree → subset AST) with the same rejections —
  fused passes, not removed work.
- Growth is codegen-bound: Phase 6 constructs need tens of lines of
  recursive descent each; the hard part is always BF codegen and
  memory layout. Parsing only gets genuinely hard at
  typedef/structs/preprocessor semantics — growth the backend likely
  cannot follow.
- The g++-oracle differential strategy de-risks hand parsing
  specifically: precedence/associativity bugs surface as behavioral
  divergence from real C compilers.
- Conceded limitations: fail-fast single errors (no multi-error
  recovery), less declarative than a grammar file for future
  contributors. Acceptable for a solo transpiler CLI.

Explicit revisit trigger: if the subset approaches full-C surface
(structs/typedef/casts/preprocessor semantics), revisit Tree-sitter
(+ `tree-sitter-cpp`). The swap stays cheap: the parser sits behind
the AST boundary and the differential corpus verifies any front end.
