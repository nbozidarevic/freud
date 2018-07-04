#ifndef __BRAINFUCK_COMPILER_H_INCLUDED__
#define __BRAINFUCK_COMPILER_H_INCLUDED__

#include <iostream>
#include "antlr4-runtime.h"
#include "SimpleCLexer.h"
#include "SimpleCParser.h"

using namespace std;

class BrainfuckCompiler {
public:
  BrainfuckCompiler(istream& input, ostream& output);
  void run();
private:
  istream& input;
  ostream& output;
};

#endif
