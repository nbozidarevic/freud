# Differential parse-dump format (v1)

`parsedump FILE` writes the parse tree to stdout as one single-line
S-expression plus `\n`, and exits 0. This format is the structural
contract between the frozen C++ reference (`parse.cpp`) and the Rust
core: both must produce byte-identical output on every fixture.

## Serialization

- `(kind)` — node with empty text and no children, e.g. `(empty)`.
- `(kind text)` — leaf with text, e.g. `(ident x)`, `(int 42)`.
- `(kind text? kid kid...)` — single spaces, no trailing space, e.g.
  `(binop + (ident x) (int 42))`, `(compound (decl int ...))`.
- `text` uses the tokenizer dump escaping: `\` → `\\`, newline → `\n`,
  tab → `\t`, CR → `\r`, NUL → `\0`.
- No positions, no token stream: structure only. (Positions are covered
  by the tokenizer differential.)

## CLI conventions (same as `tokdump`)

- Tokenize/parse error: stderr `FILE:LINE:COL: error: MSG`, exit 1.
- Usage/open errors: exit 2. Negative fixtures only assert exit ≠ 0;
  stderr message parity is a SHOULD, verified by review and Rust unit
  tests, not by the differential.

## Node shapes (frozen by the C++ reference)

- `tu`: top-level `decl`/`funcdef` nodes in order (stray `;` skipped).
- `funcdef(name)`: `[compound body]`. Parameters and return type are
  consumed, not kept.
- `decl(spec)`: `[initdecl]?` (`int;` has no children).
- `initdecl(name)`: `[init]?`.
- `compound`: block items in order. `exprstmt`: `[expr]`. `empty`: none.
- `if`: `[cond, then]`; `ifelse`: `[cond, then, else]`.
- `switch`: `[expr, body]`; `while`: `[cond, body]`.
- `for`: `[init, cond?, incr?, body]` — 2 to 4 children. `init` is
  `fordecl`, `empty-init`, or an expression; `cond`/`incr` appear only
  when non-empty (`for(;;)` → `[empty-init, body]`).
- `fordecl("spec name"|"spec")`: `[init]?`.
- `return`: `[expr]?`; `break`, `continue`: none (kind is the keyword).
- `case`: `[label, body]` (label is an assignment-expression);
  `default`: `[body]`; `goto-label(name)`: `[body]`.
- `comma`: `[first, rest...]` (2+; only built when a comma is present).
- `assign(op)`: `[lhs, rhs]`, right-associative; `op` is one of
  `= += -= *= /= %=`. Non-lvalue `lhs` (other than parenthesized
  lvalues) is a parse error.
- `binop(op)`: `[l, r]`, left-associative. Levels low→high:
  `||`, `&&`, `== !=`, `< > <= >=`, `+ -`, `* / %`.
- `unary(op)`: `[e]`; `op` is one of `! & ++ --` (no unary minus/plus,
  no `~`, no casts, no `sizeof`, no ternary — accepted subset surface).
- `postfix(op)`: `[e]` (`++`/`--`); `call`: `[callee, args...]`
  (callee is any postfix expression).
- `paren`: `[e]` — parentheses are kept as nodes, not transparent.
- `int`: raw digits; `char`: raw slice including quotes; `string`:
  concatenated cooked contents of adjacent literals (C string
  pasting); `ident`: the name.
- Trailing tokens after the translation unit are an error
  (`unexpected trailing ...`).
