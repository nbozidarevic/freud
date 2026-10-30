#include <stdio.h>

// Decimal printing must handle every byte value, including numbers
// with interior zeros (101, 205) and the range boundaries.
int main() {
  printf("%d\n", 0);
  printf("%d\n", 5);
  printf("%d\n", 9);
  printf("%d\n", 10);
  printf("%d\n", 11);
  printf("%d\n", 19);
  printf("%d\n", 20);
  printf("%d\n", 99);
  printf("%d\n", 100);
  printf("%d\n", 101);
  printf("%d\n", 109);
  printf("%d\n", 110);
  printf("%d\n", 111);
  printf("%d\n", 199);
  printf("%d\n", 200);
  printf("%d\n", 201);
  printf("%d\n", 202);
  printf("%d\n", 203);
  printf("%d\n", 209);
  printf("%d\n", 210);
  printf("%d\n", 250);
  printf("%d\n", 255);
  int a = 101;
  int b = a + 9;
  printf("%d\n", b);
  int c = 200;
  c = c + 5;
  printf("%d\n", c);
}
