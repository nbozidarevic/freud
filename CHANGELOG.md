# Changelog

All notable changes to this project. The project has no releases or
tags yet; the version is `0.0.0` throughout, and entries below are
grouped by the roadmap phases that produced them. The rename to the
`c2bf` family (see "Rename pending" below) will be the first
release-shaped change.

## Rename pending (owner's step, Phase 8)

The project is still named `freud` everywhere: crate names, binaries,
the C ABI (`freud_*`), the WASM package, docs, and CI. Renaming is
the owner's final step; `docs/rename-checklist.md` is the complete,
evidence-based inventory of what changes, and this file will gain a
release entry when the rename lands. The exact new name is the
owner's call (`c2bf` family per `docs/decisions/0001`).

## Phase 7 — Distribution adapters

- C ABI adapter (`rs/ffi/`): separate `freud-ffi` crate exposing
  `freud_compile`/`freud_run`/`freud_format` with a hand-written
  `freud.h`, a C example, Rust ABI tests, and a `c-abi` CI job on
  Ubuntu and macOS. The core crate stays dependency-free.
- Web adapter (`rs/wasm/`, `demo/`): `wasm-bindgen` crate exporting
  `compile`/`run`/`format_code`, a static demo page, a Node smoke
  test, and a dispatch-only GitHub Pages workflow. All three
  `wasm-pack` targets (`web`, `nodejs`, `bundler`) are CI-verified;
  npm publishing and Pages deployment are manual, owner-gated steps.
- UniFFI (Kotlin/Swift) and JNI (Java) bridges are named and
  deferred; both build on the C ABI. See
  `docs/decisions/0006-distribution-adapters.md`.

## Phase 6 — Language expansion

- `do...while` completes the thesis iteration set (`while`/`for`/
  `do...while`).
- `break` inside loops and `switch`, via a flag protocol;
  break-free loops emit byte-identical code.
- Ternary conditional (`?:`) as a value-producing expression.
- `continue` inside loops, via a parallel flag protocol;
  `continue` binds the loop, not an enclosing `switch`, and the
  `for` update still runs.
- Decimal printing fixed (`print_as_number` rewritten around
  place values): numbers with interior zeros printed wrong
  (101 as 110, 209 as 2900) and cost tens of millions of extra
  interpreter steps; all byte values now print correctly. Covered
  by the `tests/compile/printnum.c` oracle fixture and a refreshed
  `docs/perf.md`.

## Phase 5 — Performance

- Execution perf harness (`freud-bench`): in-process timing of
  transpilation and execution for the corpus plus synthetic runner
  microbenchmarks; results published in `docs/perf.md` and
  refreshed with codegen changes.
- Runner optimization: jump table for brackets, buffered I/O.
- Peephole post-pass evaluated by measurement and rejected (zero
  occurrences in the golden corpus).

## Phase 3 — Transpile-first reframe

- `compile` is the default command; `run`/`format` are auxiliary.
  Positional files, errors on stderr, exit code 1. Docs and CLI
  describe a C subset, not a Brainfuck toolset (decision 0001).

## Phase 2 — Rust migration

- Tokenizer, hand-written parser, codegen, runner, and formatter
  ported to Rust (`freud-core`), guarded by byte-compare goldens
  and the g++-oracle differential suite.
- C++ implementation and ANTLR toolchain retired after the Rust
  port matched it byte-for-byte.

## Phase 4 — Stack decision (pulled forward)

- Spikes: hand-written parser (feasible, better diagnostics),
  tree-sitter-c (weaker diagnostics), C++/Rust/Zig tokenizer
  differential (byte-identical). Verdict (decision 0005, amended):
  Rust core, hand-written parser, C ABI distribution floor,
  `wasm-pack` for web. Revisit trigger: subset approaching full C.

## Phases 0–1 — Hardening to the thesis spec

- Baseline record, semantics doc, and language-identity decision
  (honest C subset, decision 0001).
- Division/modulo differential tests; `switch` implemented;
  end-of-input pinned (cell unchanged); error paths given exit
  codes. The thesis test spec is the hardening scope (decision
  0002).

## Pre-history (university project, 2018–2019)

- C++ / ANTLR transpiler for a C subset to Brainfuck, with a
  Brainfuck runner and formatter, per the Master's thesis
  (Serbian) and the accompanying blog post. Retired in Phase 2;
  behavior preserved by the differential corpus.
