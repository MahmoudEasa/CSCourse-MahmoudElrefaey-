#include <stdio.h>

int main() {

  // for (int i = 1; i <= 10; i++) {
  //   printf("%d\t", i);
  //   for (int j = i + i; j <= i * 10; j += i) {
  //     printf("%d\t", j);
  //   }
  //   printf("\n");
  // }

  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      printf("%4d", i * j);
    }
    printf("\n");
  }

  return 0;
}