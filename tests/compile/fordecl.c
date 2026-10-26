#include <stdio.h>

// For-loop variations: declaration init, comma-separated init/update.
// Note: no block scoping exists (flat memory), so loop variables leak;
// values are still correct, which is what the oracle checks.
int main() {
  int s = 0;
  int i = 0;
  for (int k = 0; k < 5; k++) {
    s = s + k;
  }
  printf("%d\n", s);
  int p = 0;
  int q = 0;
  for (p = 1, q = 2; p < 4; p = p + 1, q = q + 1) {
    s = s + p + q;
  }
  printf("%d %d %d\n", s, p, q);
}
