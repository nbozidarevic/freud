#include <stdio.h>

// Focused comparison tests. All results are 0/1.
int main() {
  printf("%d\n", 3 < 5);
  printf("%d\n", 5 < 3);
  printf("%d\n", 5 < 5);
  printf("%d\n", 3 <= 5);
  printf("%d\n", 5 <= 5);
  printf("%d\n", 6 <= 5);
  printf("%d\n", 5 > 3);
  printf("%d\n", 3 > 5);
  printf("%d\n", 5 >= 5);
  printf("%d\n", 4 >= 5);
  printf("%d\n", 5 == 5);
  printf("%d\n", 5 == 4);
  printf("%d\n", 5 != 4);
  printf("%d\n", 5 != 5);
  int a = 7;
  int b = 7;
  printf("%d\n", a == b);
  printf("%d\n", a < b);
}
