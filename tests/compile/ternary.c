#include <stdio.h>

// Ternary conditional: basic branches, nesting, compound conditions,
// and side effects confined to the taken branch.
int main() {
  int a = 5;
  int x = a > 3 ? 7 : 9;
  printf("%d\n", x);
  int y = a < 3 ? 7 : 9;
  printf("%d\n", y);
  int z = a == 5 ? 10 : a == 4 ? 20 : 30;
  printf("%d\n", z);
  int w = a == 4 ? 10 : a == 5 ? 20 : 30;
  printf("%d\n", w);
  int t = 0;
  int s = a > 3 ? (t = t + 1) : (t = t + 10);
  printf("%d\n", s);
  printf("%d\n", t);
  int u = 0;
  int v = a < 3 ? (u = u + 1) : (u = u + 10);
  printf("%d\n", v);
  printf("%d\n", u);
  printf("%d\n", a || 0 ? 1 : 2);
  printf("%d\n", 0 && a ? 1 : 2);
}
