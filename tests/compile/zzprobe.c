#include <stdio.h>

// TEMPORARY debug probe (Phase 6d): per-iteration prints isolate the
// for+continue codegen divergence. Deleted before the final commit.
int main() {
  int u = 0;
  int k = 0;
  for (k = 0; k < 3; k = k + 1) {
    u = u + 1;
    printf("%d\n", k);
    printf("%d\n", u);
    if (k == 1) {
      continue;
    }
    u = u + 100;
    printf("%d\n", u);
  }
  printf("%d\n", u);
}
