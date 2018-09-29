# freud
Freud – A toolset for working with the Brainfuck programming language

## Requirements
- Unix (due to the Makefile)
- G++
- ANTLR 4.7.1

## Usage

```
> make
> ./bin/freud command [parametres]
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
