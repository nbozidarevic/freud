# Semantics

Ground-truth behavior for the transpiler, taken from the Master's thesis
(`Varijacije`, `Okruženje`, `Sintaksa`, `Testiranje interpretera` chapters).
Where the implementation deviates from the thesis, the deviation is listed as
fix-or-pin work for Phase 1.

## Tape and cells

- Cells are 1 byte, with wrapping arithmetic ("obmotavanje"): `255 + 1 → 0`,
  `0 − 1 → 255`.
- Only `char` variables are supported; anything wider needs multi-cell
  representation (deferred to language expansion).
- The thesis specifies addressable memory for any integer index (its reference
  interpreter uses `map<int, char>`), i.e. negative indices are legal.
- The original Brainfuck spec defines a minimum of 30,000 cells; transpiled
  programs need many temporaries, so in practice far more are required.

## Execution

- All cells start at `0`; the pointer starts at cell `0`.
- `[` skips forward to the matching `]` when the current cell is `0`;
  `]` jumps back to the matching `[` (unconditionally — the cell is re-tested
  at `[`, so loop-exit means "current cell is `0`", not "`> 0`").
- `,` reads one character as its ASCII value; `.` writes the current cell as
  the character with that ASCII value. All other characters in BF source are
  ignored (comments must avoid `.` and `,`).

## Known implementation deviations (Phase 1 work)

1. `BrainfuckRunner` uses a fixed `char memory[65536]` with `pointer = 0`:
   negative indices are out-of-bounds (spec: legal), indices past 65535 are
   out-of-bounds (spec: legal).
2. `char` signedness is platform-defined; wrap behavior at 127/128 therefore
   differs from the specified 0–255 wrapping on platforms with signed `char`.
3. `LOOP_END` resumes the loop while `memory[pointer] > 0`; the spec means
   `!= 0`, which differs once cells can hold negative values.
4. End-of-input (`, ` at EOF) and division-by-zero behavior are unspecified;
   Phase 1 pins and tests them against oracle-defined expectations.

## Port notes (retired C++ behaviors)

Deliberate deviations from the original C++ implementation (retired in
slice 5f; documented, not mirrored):

1. A zero-cell `[` with no matching `]` spins forever in C++ (it keeps
   reading `NONE` past EOF). The Rust runner reports
   `Unbalanced Brainfuck code: unclosed '['` instead — a hang has no
   observable output to match.
2. A missing/unopenable code file spins forever in C++ (`BrainfuckReader`
   only breaks on `eof()`, which a failed-open stream never reports).
   The Rust CLIs treat it as an empty program instead.

## Source language

See `decisions/0001-source-language-identity.md` for what the accepted source
language is. Only constructs in that definition are in scope for hardening.
