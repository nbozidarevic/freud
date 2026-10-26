#include "BrainfuckRunner.h"

BrainfuckRunner::BrainfuckRunner(
  istream& code,
  istream& input,
  ostream& output
):bfr(BrainfuckReader(code)), input(input), output(output) {
  tape = vector<unsigned char>(1024, 0);
  origin = 512;
  pointer = 0;
  currentPosition = 0;
  commandBufferStartPosition = 0;
  currentDepth = 0;
  usingBuffer = false;
}

BrainfuckRunner::~BrainfuckRunner() {}

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
        ++cell();
        break;
      case VALUE_DECREMENT:
        --cell();
        break;
      case VALUE_READ: {
        char c;
        if (input.get(c)) {
          cell() = static_cast<unsigned char>(c);
        }
        break;
      }
      case VALUE_WRITE:
        // output << pointer << " " << (int)(memory[pointer]) << endl;
        output.put(static_cast<char>(cell()));
        break;
      case LOOP_BEGIN:
        if (cell() == 0) {
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
        if (loopBeginnings.empty()) {
          throw "Unbalanced Brainfuck code: unexpected ']'";
        }
        --currentDepth;
        if (cell() != 0) {
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
  if (!loopBeginnings.empty()) {
    throw "Unbalanced Brainfuck code: unclosed '['";
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

unsigned char& BrainfuckRunner::cell() {
  int index = pointer + origin;
  if (index < 0) {
    tape.insert(tape.begin(), -index, 0);
    origin += -index;
    index = 0;
  } else if (index >= (int)tape.size()) {
    tape.resize(2 * index + 1, 0);
  }
  return tape[index];
}
