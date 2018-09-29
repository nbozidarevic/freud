#include <stdio.h>

int one = 1;
char ten = 10;

int main() {
  int inputA = 0;
  char inputB = 0;
  scanf("%d %c", &inputA, &inputB);
  while (one < ten) {
    printf("%d %c\n", one, one + '0');
    if (one < 5) {
      printf("Still smaller than five\n");
    }
    printf("%d\n", one * ten / 3 + 2 - 1);
    if (one % 2 == 0) {
      printf("\tEven\n");
    } else {
      printf("\tOdd\n");
    }
    one = one + 1;
  }
  printf("%d %c\n", inputA, inputB);
}
