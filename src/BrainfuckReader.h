#ifndef __BRAINFUCK_READER_H_INCLUDED__
#define __BRAINFUCK_READER_H_INCLUDED__

#include <iostream>

using namespace std;

enum BrainfuckCommand {
  NONE = 0,
  MOVE_LEFT = '<',
  MOVE_RIGHT = '>',
  VALUE_INCREMENT = '+',
  VALUE_DECREMENT = '-',
  VALUE_READ = '.',
  VALUE_WRITE = ',',
  LOOP_BEGIN = '[',
  LOOP_END = ']'
};

class BrainfuckReader {
public:
  BrainfuckReader(istream& input);
  BrainfuckCommand get_next_command();
private:
  istream& input;
  int line;
  int col;
  string lineContents;
  bool is_valid_command(char c);
};

#endif
