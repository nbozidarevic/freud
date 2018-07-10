#ifndef __BRAINFUCK_MEMORY_H_INCLUDED__
#define __BRAINFUCK_MEMORY_H_INCLUDED__

#include <map>
#include <string>

using namespace std;

class BrainfuckMemory {
public:
  BrainfuckMemory();
  int getTemporaryCell();
  int getVariableCell(string name);
private:
  int nextAvailableCell = 0;
  map<string, int> memory;
};

#endif
