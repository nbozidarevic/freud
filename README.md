# freud
Freud – A toolset for working with the Brainfuck programming language

## Requirements
- Rust (stable toolchain)
- A C compiler (`g++`/`clang`) — only for the end-to-end oracle checks,
  which compare transpiled-program output against natively compiled output

## Usage

```
> cargo build --release --manifest-path rs/Cargo.toml
> ./rs/target/release/freud command [parametres]
```

## Supported commands

```
format [-c code-file] [-o output-file] [-m]

  Formats the specified Brainfuck program by removing all
  invalid characters and adding indentation.

  If no code file is specified, the standard
  input is used.

  If no output file is specified, the standard
  output is used.

  If the -m flag is specified, all whitespace is removed.
```
```
run -c code-file [-i input-file] [-o output-file]

  Executes the specified Brainfuck program.

  If no input file is specified, the standard
  input is used.

  If no output file is specified, the standard
  output is used.
```
```
compile [-c code-file] [-o output-file]

  Compiles the specified C program to Brainfuck.

  If no code file is specified, the standard
  input is used.

  If no output file is specified, the standard
  output is used.
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
