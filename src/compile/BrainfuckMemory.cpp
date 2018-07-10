#include "BrainfuckMemory.h"

BrainfuckMemory::BrainfuckMemory() {}

int BrainfuckMemory::getTemporaryCell() {
  return nextAvailableCell;
}

int BrainfuckMemory::getVariableCell(string name) {
  map<string, int>::iterator it = memory.find(name);
  if (it == memory.end()) {
    return memory.insert(
      pair<string, int>(name, nextAvailableCell++)
    ).first->second;
  }
  return it->second;
}
