#include <stdio.h>

// Focused break tests: while/for/do...while, nested loops, break
// binding the switch (not the loop), and break-free loops.
int main() {
  int i = 0;
  while (i < 10) {
    if (i == 3) {
      break;
    }
    i = i + 1;
  }
  printf("%d\n", i);
  int j = 0;
  for (j = 0; j < 5; j = j + 1) {
    if (j == 2) {
      break;
    }
  }
  printf("%d\n", j);
  int a = 0;
  int b = 0;
  while (a < 3) {
    b = 0;
    while (b < 10) {
      if (b == 1) {
        break;
      }
      b = b + 1;
    }
    printf("%d\n", b);
    a = a + 1;
  }
  printf("%d\n", a);
  int s = 0;
  int k = 0;
  while (k < 3) {
    switch (k) {
      case 0: s = s + 1; break;
      case 1: s = s + 10; break;
      default: s = s + 100; break;
    }
    k = k + 1;
  }
  printf("%d\n", s);
  printf("%d\n", k);
  int m = 0;
  do {
    if (m == 2) {
      break;
    }
    m = m + 1;
  } while (m < 10);
  printf("%d\n", m);
  int n = 0;
  while (n < 4) {
    n = n + 1;
  }
  printf("%d\n", n);
  int t = 0;
  switch (1) {
    case 1: t = t + 5; break; t = t + 100;
    default: t = t + 1000; break;
  }
  printf("%d\n", t);
}
