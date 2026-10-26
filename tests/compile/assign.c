#include <stdio.h>

// Compound assignment and increment/decrement tests. Sequential by design:
// each line depends on the accumulated state above it.
int main() {
  int a = 10;
  int b = 3;
  a += b;
  printf("%d\n", a);
  a -= 4;
  printf("%d\n", a);
  a *= 2;
  printf("%d\n", a);
  a /= 3;
  printf("%d\n", a);
  a %= 4;
  printf("%d\n", a);
  a++;
  printf("%d\n", a);
  a--;
  printf("%d\n", a);
  int c = a++;
  printf("%d %d\n", c, a);
  int d = ++a;
  printf("%d %d\n", d, a);
  int e = a--;
  printf("%d %d\n", e, a);
  int f = --a;
  printf("%d %d\n", f, a);
}
