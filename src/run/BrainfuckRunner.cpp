#include "BrainfuckRunner.h"

BrainfuckRunner::BrainfuckRunner(
  istream& code,
  istream& input,
  ostream& output
):bfr(BrainfuckReader(code)), input(input), output(output) {
  memory = new char[65536];
  pointer = 0;
  currentPosition = 0;
  commandBufferStartPosition = 0;
  currentDepth = 0;
  usingBuffer = false;
}

BrainfuckRunner::~BrainfuckRunner() {
  delete []memory;
}

void BrainfuckRunner::run() {
  BrainfuckCommand command = NONE;
  while ((command = this->get_command(currentPosition++)) != NONE) {
    switch (command) {
      case MOVE_LEFT:
        --pointer;
        break;
      case MOVE_RIGHT:
        ++pointer;
        break;
      case VALUE_INCREMENT:
        ++memory[pointer];
        break;
      case VALUE_DECREMENT:
        --memory[pointer];
        break;
      case VALUE_READ:
        input.get(memory[pointer]);
        break;
      case VALUE_WRITE:
        // output << pointer << " " << (int)(memory[pointer]) << endl;
        output.put(memory[pointer]);
        break;
      case LOOP_BEGIN:
        if (memory[pointer] == 0) {
          int depth = 1;
          while (depth > 0) {
            command = this->get_command(currentPosition++);
            if (command == LOOP_BEGIN) {
              ++depth;
            } else if (command == LOOP_END) {
              --depth;
            }
          }
        } else {
          ++currentDepth;
          loopBeginnings.push(currentPosition - 1);
          if (!usingBuffer) {
            commandBuffer.clear();
            commandBuffer.push_back(LOOP_BEGIN);
            commandBufferStartPosition = currentPosition - 1;
            usingBuffer = true;
          }
        }
        break;
      case LOOP_END:
        --currentDepth;
        if (memory[pointer] > 0) {
          currentPosition = loopBeginnings.top();
        } else if (currentDepth == 0) {
          usingBuffer = false;
        }
        loopBeginnings.pop();
        break;
      default:
        break;
    }
  }
}

BrainfuckCommand BrainfuckRunner::get_command(int position) {
  if (!usingBuffer) {
    return bfr.get_next_command();
  }

  int positionInBuffer = position - commandBufferStartPosition;
  if (
    positionInBuffer < 0 ||
    positionInBuffer > commandBuffer.size()
  ) {
    throw "Invalid command position requested";
  }

  if (positionInBuffer < commandBuffer.size()) {
    return commandBuffer[positionInBuffer];
  }

  BrainfuckCommand command = bfr.get_next_command();
  commandBuffer.push_back(command);
  return command;
}
