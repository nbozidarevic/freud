#include <iostream>
#include "BrainfuckReader.h"

using namespace std;

BrainfuckReader::BrainfuckReader(istream& input):input(input) {}

BrainfuckCommand BrainfuckReader::get_next_command() {
  while (true) {
    for (int i = col; i < lineContents.length(); ++i) {
      if (this->is_valid_command(lineContents[i])) {
        col = i + 1;
        return (BrainfuckCommand)lineContents[i];
      }
    }

    if (input.eof()) {
      break;
    }

    getline(input, lineContents);
    col = 0;
    ++line;
  }

  return NONE;
}

bool BrainfuckReader::is_valid_command(char c) {
  switch (c) {
    case MOVE_LEFT:
    case MOVE_RIGHT:
    case VALUE_INCREMENT:
    case VALUE_DECREMENT:
    case VALUE_READ:
    case VALUE_WRITE:
    case LOOP_BEGIN:
    case LOOP_END:
      return true;
  }
  return false;
}
