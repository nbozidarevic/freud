# freud
Freud – A toolset for working with the Brainfuck programming language

## Requirements
- Unix (due to the Makefile)
- G++
- ANTLR 4.7.1

## Usage

```
> make
> ./bin/freud command file [parametres]
```

## Supported commands

```
format file [-o output-file] [-m]

  Formats the specified Brainfuck program by removing all
  invalid characters and adding indentation.

  If no output file is specified, the standard
  output is used.

  If the -m flag is specified, all whitespace is removed.
```
```
run file

  Executes the specified Brainfuck program.
```
```
compile file [-o output-file]

  Compiles the specified C program to Brainfuck.

  If no output file is specified, the standard
  output is used.
```
