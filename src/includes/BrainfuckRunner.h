#ifndef __BRAINFUCK_RUNNER_H_INCLUDED__
#define __BRAINFUCK_RUNNER_H_INCLUDED__

#include <iostream>
#include <stack>
#include <vector>

#include "BrainfuckReader.h"

using namespace std;

class BrainfuckRunner {
public:
  BrainfuckRunner(istream& code, istream& input, ostream& output);
  ~BrainfuckRunner();
  void run();
private:
  BrainfuckReader bfr;
  istream& input;
  ostream& output;
  char* memory;
  int pointer;
  vector<BrainfuckCommand> commandBuffer;
  int commandBufferStartPosition;
  int currentDepth;
  int currentPosition;
  BrainfuckCommand get_command(int position);
  stack<int> loopBeginnings;
  bool usingBuffer;
};

#endif
