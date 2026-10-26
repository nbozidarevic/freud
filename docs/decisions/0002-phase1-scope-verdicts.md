# 0002 — Phase 1 scope verdicts (switch, do...while, EOF, errors)

Date: 2026-10-26. Status: accepted.

## switch: implement (test-first, this phase)

- The grammar already parses `switch` (`selectionStatement`), but
  `visitSelectionStatement` throws for it; the thesis test spec requires
  `switch` coverage, so it is owed, not optional.
- Needs `break` to be meaningful (jump statements are currently silently
  ignored); implement `switch` with C fallthrough semantics plus `break`
  together, with oracle differential tests.

## do...while: descope (blocked, revisit in Phase 4)

- The construct is absent from the grammar (`iterationStatement` has only
  `while`/`for`), and regenerating the ANTLR parser is currently impossible
  (no Java/ANTLR tool on this machine; grammar regen is a Phase 4 decision
  input). Hand-editing the 5.7k-line generated parser is rejected as fragile.
- Revisit when the parser approach is decided; a hand-written parser makes
  this trivial.

## EOF on `,`: pin "cell unchanged" + test, no code change

- Current behavior: failed read leaves the cell unchanged. The thesis is
  silent; this matches common BF implementations and is the minimal pin.
- A `run/` test pins it (`+++,-.` must emit byte 3).
- Known limitation (documented, not fixed here): generated `scanf` loops
  have no EOF escape and spin forever on exhausted input; fixing that needs
  a generated-code EOF protocol (Phase 6 I/O work, if ever).

## Error types: keep string literals, defer refactor to Phase 3

- Exit codes (the behavior that matters: detect failures) are fixed now.
- Migrating ~25 `throw "..."` sites to typed exceptions is hygiene with no
  behavioral payoff; deferred to the CLI modernization in Phase 3.
