#include <stdio.h>

// Focused boolean-logic tests. All results are 0/1.
// Note: bare !0 does not parse (no DigitSequence under '!' in the grammar),
// so !(0) is used; grammar-level gap tracked for the Phase 4 parser work.
int main() {
  printf("%d\n", 1 && 1);
  printf("%d\n", 1 && 0);
  printf("%d\n", 0 && 1);
  printf("%d\n", 0 && 0);
  printf("%d\n", 1 || 0);
  printf("%d\n", 0 || 1);
  printf("%d\n", 0 || 0);
  printf("%d\n", !(0));
  printf("%d\n", !1);
  printf("%d\n", !5);
  int a = 3;
  int b = 0;
  printf("%d\n", a && b);
  printf("%d\n", a || b);
  printf("%d\n", !a);
  printf("%d\n", !b);
}
