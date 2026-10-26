#include <stdio.h>

// Focused addition/subtraction tests. All results stay in [0, 255] so the
// g++ oracle agrees with the transpiler by construction.
int main() {
  printf("%d\n", 40 + 50);
  printf("%d\n", 100 + 155);
  printf("%d\n", 200 - 56);
  printf("%d\n", 0 + 0);
  printf("%d\n", 5 - 5);
  printf("%d\n", 255 - 255);
  int a = 100;
  int b = 55;
  printf("%d\n", a + b);
  printf("%d\n", a - b);
  printf("%d\n", 200 - b);
}
