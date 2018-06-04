#ifndef __BRAINFUCK_FORMATTER_H_INCLUDED__
#define __BRAINFUCK_FORMATTER_H_INCLUDED__

#include <iostream>

#include "BrainfuckReader.h"

using namespace std;

class BrainfuckFormatter {
public:
  BrainfuckFormatter(istream& input, ostream& output, bool minify);
  void run();
private:
  BrainfuckReader bfr;
  ostream& output;
  bool minify;
};

#endif
