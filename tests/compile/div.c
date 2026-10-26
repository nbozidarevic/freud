#include <stdio.h>

// Focused division tests. All results fit in one 8-bit cell so the g++
// oracle agrees with the transpiler by construction (see docs/semantics.md).
int main() {
  printf("%d\n", 7 / 3);
  printf("%d\n", 8 / 2);
  printf("%d\n", 6 / 4);
  printf("%d\n", 5 / 5);
  printf("%d\n", 3 / 7);
  printf("%d\n", 0 / 5);
  int a = 9;
  int b = 4;
  printf("%d\n", a / b);
  printf("%d\n", a / 2);
  printf("%d\n", 10 / b);
}
