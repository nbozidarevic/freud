#include <stdio.h>

// Focused multiplication tests. All products fit in one 8-bit cell so the
// g++ oracle agrees with the transpiler by construction.
int main() {
  printf("%d\n", 7 * 3);
  printf("%d\n", 8 * 0);
  printf("%d\n", 0 * 5);
  printf("%d\n", 12 * 20);
  printf("%d\n", 1 * 255);
  int a = 9;
  int b = 4;
  printf("%d\n", a * b);
  printf("%d\n", a * 2);
  printf("%d\n", 10 * b);
}
