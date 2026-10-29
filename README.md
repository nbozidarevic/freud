# freud
`freud` transpiles a C subset to Brainfuck — and, as helpers around
that, runs Brainfuck programs and pretty-prints Brainfuck code.

## Quick start

```
> cargo build --release --manifest-path rs/Cargo.toml
> ./rs/target/release/freud program.c -o program.bf
```

`freud program.c` (no command) compiles. Without `-o`, Brainfuck goes
to stdout; without a code file, source is read from stdin.

## Commands

```
compile [file] [-o file]        Transpile C source to Brainfuck (default)
run [file] [-i file] [-o file]  Run a Brainfuck program
format [file] [-o file] [-m]    Pretty-print Brainfuck (-m minifies)
help                            Show help
```

The code file may also be given as `-c file`. `run` requires a code
file; `compile` and `format` fall back to stdin. Errors go to stderr
with usage; exit code is 1.

Run a transpiled program, feeding it input:

```
> ./rs/target/release/freud run -c program.bf -i input.txt
```

## Tests

```
> cd tests && python3 test          # oracle + golden suite (needs the build above)
```

Byte outputs are pinned under `tests/golden/`; regenerate them (with
review) after intentional changes:

```
> ./tests/golden/generate.sh
```

## What it accepts

Only a C subset: `int`/`char` variables, arithmetic, comparisons,
logic, `if`/`else`, `while`/`for`/`do...while`, `switch`, `break`/`continue`,
`printf`/`scanf` with `%d`/`%c`, and more — see `docs/semantics.md`
for the ground-truth
behavior and `tests/compile/` for examples. The original C++/ANTLR
implementation was retired after the Rust port matched it byte-for-byte
(see `docs/decisions/`).
