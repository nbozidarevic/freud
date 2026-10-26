# 0004 — Tree-sitter spike verdict (covers corpus; diagnostics weaker)

Date: 2026-10-26. Status: accepted (spike result; final stack
decision pending the core-language spike).

## Result: tree-sitter-c parses the whole corpus cleanly

- Branch `spike/tree-sitter` holds the evidence: a version-adaptive
  `spike/treesitter/check.py` parses all 15 `tests/compile/*.c`
  fixtures with `tree-sitter-c`, asserting zero ERROR/MISSING nodes
  per fixture.
- CI (`Spike tree-sitter check` workflow, Ubuntu, stock
  `pip install tree-sitter tree-sitter-c`) green, reported by the
  owner on 2026-10-26. Inline invalid-snippet probes confirm recovery
  behavior: the parse never fails, errors surface as ERROR nodes.
- Coverage was expected — tree-sitter-c is a complete C grammar. The
  spike's value is confirming zero gaps on our exact corpus and
  measuring integration cost.

## Assessment vs the hand parser (0003)

- Coverage: both cover the corpus. Tree-sitter additionally covers all
  of C (future-proof for subset growth) with a sibling C++ grammar
  (`tree-sitter-cpp`) if richer syntax is ever wanted.
- Diagnostics: weaker. Error recovery means parsing never fails, so
  `line:col` errors must be built by walking ERROR nodes ourselves.
  The hand parser reports at the failure point for free.
- Dependencies: a native grammar (compiled shared object or vendored
  C sources) plus a per-language binding (C API, Rust crate, and
  official WASM build all exist). The hand parser is one
  dependency-free file.
- Portability note: tree-sitter's official WASM build helps the
  Phase 7 gated web adapter — but only if the parser lives behind the
  adapter boundary, never in the dependency-free core.

## Not decided

- The final parser pick awaits the core-language spike (a Rust core
  pairs well with either option; a C++ core favors hand-written).
- No dedicated ANTLR-upgrade spike: the incumbent's pains (Java
  codegen dependency, 5.7k-line generated parser, observed ASan
  failures in generated code) are version-independent. The final
  verdict is hand-written vs Tree-sitter vs status-quo ANTLR on
  already-known evidence.
- The spike branch is retained as evidence and is not merged.
