# freud
Freud – A toolset for working with the Brainfuck programming language

## Usage

```
freud command file [parametres]
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
