#include <stdio.h>

// Mahmoud Easa

/*
https://ideone.com/fsW27v

  Recursion:
    Read Num
    Read powerInput
    Return Num power powerInput
    Print Result
*/

// void readNumAndPower(int *num, int *powerInput) {
//   printf("Please Enter Number: ");
//   scanf("%d", num);

//   printf("Please Enter Power: ");
//   scanf("%d", powerInput);
// }

// int powerN(int num, int powerInput) {
//   return powerInput > 1 ? num * powerN(num, powerInput - 1) : num;
// }

// void printResult(int num, int powerInput) {
//   printf("%d Power %d = ( %d )", num, powerInput, powerN(num, powerInput));
// }

// int main() {
//   int num, powerInput;
//   readNumAndPower(&num, &powerInput);
//   printResult(num, powerInput);

//   return 0;
// }