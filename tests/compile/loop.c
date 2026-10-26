#include <stdio.h>

// Focused loop tests. Note: ++/-- are not implemented by the transpiler,
// so updates use explicit assignment.
int main() {
  int i = 0;
  int s = 0;
  while (i < 5) {
    s = s + i;
    i = i + 1;
  }
  printf("%d\n", s);
  printf("%d\n", i);
  int p = 1;
  for (i = 1; i <= 4; i = i + 1) {
    p = p * i;
  }
  printf("%d\n", p);
}
