#include <stdio.h>

// Focused if/else tests, including nesting.
int main() {
  if (1) {
    printf("T1");
  } else {
    printf("F1");
  }
  if (0) {
    printf("T2");
  } else {
    printf("F2");
  }
  int a = 5;
  if (a == 5) {
    printf("T3");
  }
  if (a != 5) {
    printf("T4");
  } else {
    printf("F4");
  }
  if (a > 10) {
    printf("X");
  } else {
    if (a > 3) {
      printf("N");
    } else {
      printf("Y");
    }
  }
  printf("\n");
}
