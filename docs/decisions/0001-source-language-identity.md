# 0001 — Source language identity: honest C subset

Date: 2026-10-26. Status: accepted (revisit if C++-surface constructs are named).

## Context

The project was branded "cpp" for the richer C++ syntax, but everything it
actually accepts is C: the ANTLR grammar (`src/grammar/SimpleC.g4`) is a
simplified C grammar, the thesis specifies a C subset (global/local `char`
declarations, assignment, arithmetic, boolean logic, `printf`/`scanf`,
`if`/`else`, `for`/`while`/`do...while`), and no C++-only construct
(`cout`, references, `bool`, overloading, …) is parsed or compiled.

## Decision

Reframe around the C subset (plan option A):

- Docs, CLI help, and tests describe a C subset — no C++ claims.
- The hardening scope (Phase 1) is exactly the thesis subset list.
- The parser spike (Phase 4) targets C-subset parsing; a Clang-based frontend
  only enters if a genuine C++ surface is adopted later.
- C++-flavored conveniences may be added in language expansion (Phase 6), each
  as a named, individually justified construct — never by vague "C++" labeling.
- The end-of-project rename follows this decision (`c2bf` family), executed in
  the final phase per the owner's instruction.

## Consequences

- Test files stay `.c` with C semantics; the `g++` oracle continues to define
  expected behavior.
- No grammar work is needed to "support C++" in hardening; scope stays small.
