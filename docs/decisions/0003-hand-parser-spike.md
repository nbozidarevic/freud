# 0003 — Hand-parser spike verdict (feasible, decision input recorded)

Date: 2026-10-26. Status: accepted (spike result; final stack decision
still pending Tree-sitter and core-language spikes).

## Result: a hand-written parser covers the whole corpus

- Branch `spike/hand-parser` holds the evidence: an executable Python
  prototype (`spike/handparse/proto.py`, tokenizer + recursive descent)
  ported to a single dependency-free C++11 file
  (`spike/handparse/parser.cpp`, ~700 lines, `-Wall` clean).
- CI (`Spike hand-parser check` workflow, Ubuntu): all 15
  `tests/compile/*.c` fixtures parse OK; all 6 negative fixtures are
  rejected with `line:col: error:` diagnostics. Reported green by the
  owner on 2026-10-26.
- Coverage includes every construct the transpiler accepts today
  (`switch` with fallthrough, compound assignment, `++`/`--`,
  `for`-init declarations, empty statements, labels) plus
  `do...while`-shaped iteration groundwork the ANTLR grammar lacks.

## What this decides (and what it does not)

- Decided: hand-written parsing is feasible for the supported C subset
  and removes the ANTLR runtime + Java codegen dependency entirely.
  Error quality (`line:col` messages) already beats the current
  generated-parser failures (e.g. the old `logic.c` segfault class).
- Not decided: whether hand-written wins over Tree-sitter or an ANTLR
  upgrade. That verdict needs the remaining Phase 4 spikes.
- The spike branch is retained as evidence and is not merged; only
  this record lands on master.

## Consequences

- `do...while` (descoped in 0002 for lack of grammar regen) is
  unblocked under a hand-parser outcome: it becomes a ~20-line addition.
- Santa moved to centrally-managed rules during this spike, so local
  binary execution is fully blocked; all spike verification runs in
  GitHub Actions (CI-primary loop), with the owner as CI monitor.
