#include <stdio.h>

// Focused scanf/printf tests for %d and %c, plus char literals.
int main() {
  int a = 0;
  char c = 0;
  scanf("%d %c", &a, &c);
  printf("%d %c\n", a, c);
  printf("%c", 'X');
  printf("%c\n", '!');
}
