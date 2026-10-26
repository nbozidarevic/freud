#include <stdio.h>

// Focused switch tests: match, fallthrough, break, default placement,
// no-match, and single evaluation of the switched expression.
int main() {
  int a = 2;
  switch (a) {
    case 1: printf("one"); break;
    case 2: printf("two"); break;
    case 3: printf("three"); break;
  }
  printf("\n");
  switch (a) {
    case 1: printf("1");
    case 2: printf("2");
    case 3: printf("3");
  }
  printf("\n");
  switch (10) {
    case 1: printf("x"); break;
    default: printf("D");
  }
  switch (1) {
    case 1: printf("y");
    default: printf("Z");
  }
  printf("\n");
  switch (2) {
    case 1: printf("X");
    default: printf("M");
    case 2: printf("Y");
  }
  printf("\n");
  switch (9) {
    case 1: printf("X");
    default: printf("M");
    case 2: printf("Y");
  }
  printf("\n");
  switch (7) {
    case 1: printf("q"); break;
  }
  printf("E\n");
  int b = 1;
  switch (b = b + 1) {
    case 2: printf("S"); break;
  }
  printf("%d\n", b);
}
