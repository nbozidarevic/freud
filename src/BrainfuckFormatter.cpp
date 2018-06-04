#include "BrainfuckFormatter.h"

BrainfuckFormatter::BrainfuckFormatter(
  istream& input,
  ostream& output,
  bool minify
):bfr(BrainfuckReader(input)), output(output), minify(minify) {}

void BrainfuckFormatter::run() {
  BrainfuckCommand command = NONE, prevCommand = NONE;
  int depth = 0;

  while ((command = bfr.get_next_command()) != NONE) {
    if (!minify) {
      bool shouldIndent = false;
      switch (command) {
        case MOVE_LEFT:
        case MOVE_RIGHT:
          if (prevCommand != MOVE_LEFT && prevCommand != MOVE_RIGHT) {
            shouldIndent = true;
          }
          break;
        case VALUE_READ:
        case VALUE_WRITE:
          if (prevCommand != VALUE_READ && prevCommand != VALUE_WRITE) {
            shouldIndent = true;
          }
          break;
        case VALUE_DECREMENT:
        case VALUE_INCREMENT:
          if (
            prevCommand != VALUE_INCREMENT &&
            prevCommand != VALUE_DECREMENT
          ) {
            shouldIndent = true;
          }
          break;
        case LOOP_BEGIN:
          shouldIndent = true;
          break;
        case LOOP_END:
          shouldIndent = true;
          --depth;
          break;
        default:
          break;
      }

      if (shouldIndent) {
        if (prevCommand != NONE) {
          output << endl;
        }
        for (int i = 0; i < depth; ++i) {
          output << "  ";
        }
      }

      if (command == LOOP_BEGIN) {
        ++depth;
      }
    }

    output << (char)command;
    prevCommand = command;
  }
}
