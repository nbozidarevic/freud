#include <stdio.h>

// Focused continue tests: while/for/do...while, nesting, continue
// binding the loop (not the switch), and mixed break/continue. A
// `continue` skips the rest of the body but still runs the `for`
// update and re-tests the condition; continue-free loops are
// unchanged (pinned by the other fixtures' goldens).
int main() {
  int i = 0;
  int s = 0;
  while (i < 10) {
    i = i + 1;
    if (i % 2 == 0) {
      continue;
    }
    s = s + i;
  }
  printf("%d\n", i);
  printf("%d\n", s);
  int j = 0;
  int t = 0;
  for (j = 0; j < 5; j = j + 1) {
    if (j == 2) {
      continue;
    }
    t = t + 10;
  }
  printf("%d\n", j);
  printf("%d\n", t);
  int u = 0;
  int k = 0;
  for (k = 0; k < 3; k = k + 1) {
    u = u + 1;
    if (k == 1) {
      continue;
    }
    u = u + 100;
  }
  printf("%d\n", u);
  int m = 0;
  int v = 0;
  do {
    m = m + 1;
    if (m == 2) {
      continue;
    }
    v = v + 1;
  } while (m < 4);
  printf("%d\n", m);
  printf("%d\n", v);
  int a = 0;
  int b = 0;
  int s2 = 0;
  while (a < 3) {
    a = a + 1;
    b = 0;
    while (b < 3) {
      b = b + 1;
      if (b == 2) {
        continue;
      }
    }
    s2 = s2 + 1;
  }
  printf("%d\n", s2);
  printf("%d\n", a);
  int w = 0;
  int s3 = 0;
  while (w < 3) {
    w = w + 1;
    switch (w) {
      case 1: s3 = s3 + 1; continue;
      case 2: s3 = s3 + 2; continue;
      default: s3 = s3 + 4; break;
    }
    s3 = s3 + 10;
  }
  printf("%d\n", s3);
  int p = 0;
  int s4 = 0;
  while (p < 10) {
    p = p + 1;
    if (p == 3) {
      continue;
    }
    if (p == 6) {
      break;
    }
    s4 = s4 + 1;
  }
  printf("%d\n", p);
  printf("%d\n", s4);
}
