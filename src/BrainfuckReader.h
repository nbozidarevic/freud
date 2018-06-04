#ifndef __BRAINFUCK_READER_H_INCLUDED__
#define __BRAINFUCK_READER_H_INCLUDED__

#include <iostream>

using namespace std;

class BrainfuckReader {
public:
  BrainfuckReader(istream& input);
private:
  istream& input;
};

#endif
