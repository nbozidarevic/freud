#include <stdio.h>

// Focused do...while tests: body-first execution, false-at-entry,
// non-compound bodies, nesting, and empty bodies.
int main() {
  int i = 0;
  int s = 0;
  do {
    s = s + i;
    i = i + 1;
  } while (i < 5);
  printf("%d\n", s);
  printf("%d\n", i);
  int j = 0;
  int once = 0;
  do {
    once = once + 1;
  } while (j > 0);
  printf("%d\n", once);
  int k = 0;
  do k = k + 1; while (k < 3);
  printf("%d\n", k);
  int a = 0;
  int b = 0;
  while (a < 2) {
    b = 0;
    do {
      b = b + 1;
    } while (b < 3);
    a = a + 1;
  }
  printf("%d\n", a);
  printf("%d\n", b);
  int m = 0;
  do {
    m = m + 1;
  } while (m < 0);
  printf("%d\n", m);
  do; while (0);
  printf("%d\n", 7);
}
