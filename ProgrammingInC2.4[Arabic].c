#include <stdio.h>

// Mahmoud Easa

/*
https://ideone.com/12nmNY

    1 = Read 6 digits
    2 = if num1 is greater than num2, num3, num4, num5, num6: return num1
    3 = else if num2 is greater than num3, num4, num5, num6: return num2
    4 = else if num3 is greater than num4, num5 and num6: return num3
    5 = else if num4 is greater than num5 and num6: return num4
    6 = else if num5 is greater than num6: return num5
    7 = else return num6
*/

// void read6Nums(int *num1, int *num2, int *num3, int *num4, int *num5,
//                int *num6) {
//   printf("Please Enter 6 Numbers:\n");
//   scanf("%d %d %d %d %d %d", num1, num2, num3, num4, num5, num6);
// }

// int greaterNumOf6Nums(int num1, int num2, int num3, int num4, int num5,
//                       int num6) {
//   if (num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1 >
//   num6) {
//     return num1;
//   } else if (num2 > num3 && num2 > num4 && num2 > num5 && num2 > num6) {
//     return num2;
//   } else if (num3 > num4 && num3 > num5 && num3 > num6) {
//     return num3;
//   } else if (num4 > num5 && num4 > num6) {
//     return num4;
//   } else if (num5 > num6) {
//     return num5;
//   } else {
//     return num6;
//   }
// }

// void printResult(int greater_num, int num1, int num2, int num3, int num4,
//                  int num5, int num6) {
//   printf("The greater number of [ %d, %d, %d, %d, %d, %d ] is %d", num1,
//   num2,
//          num3, num4, num5, num6, greater_num);
// }

// int main() {
//   int num1, num2, num3, num4, num5, num6, greater_num;

//   read6Nums(&num1, &num2, &num3, &num4, &num5, &num6);

//   greater_num = greaterNumOf6Nums(num1, num2, num3, num4, num5, num6);

//   printResult(greater_num, num1, num2, num3, num4, num5, num6);

//   return 0;
// }

//
//
//
//
//
//
//

// int greaterNumOf6Nums(int num1, int num2, int num3, int num4, int num5,
//                       int num6) {
//   int greaterNum =
//       num1 > num2 && num1 > num3 && num1 > num4 && num1 > num5 && num1 > num6
//           ? num1
//       : num2 > num3 && num2 > num4 && num2 > num5 && num2 > num6 ? num2
//       : num3 > num4 && num3 > num5 && num3 > num6                ? num3
//       : num4 > num5 && num4 > num6                               ? num4
//       : num5 > num6                                              ? num5
//                                                                  : num6;

//   return greaterNum;
// }
//
//
//
//
//
//
//
// Other Solution

// https://ideone.com/KviGAH

// void read6Nums(int *num1, int *num2, int *num3, int *num4, int *num5,
//                int *num6) {
//   printf("Please Enter 6 Numbers:\n");
//   scanf("%d %d %d %d %d %d", num1, num2, num3, num4, num5, num6);
// }

// int greaterNumOf2Nums(int num1, int num2) {
//   if (num1 > num2) {
//     return num1;
//   } else {
//     return num2;
//   }
// }

// int greaterNumOf6Nums(int num1, int num2, int num3, int num4, int num5,
//                       int num6) {
//   int number1 = greaterNumOf2Nums(num1, num2);
//   int number2 = greaterNumOf2Nums(num3, num4);
//   int number3 = greaterNumOf2Nums(num5, num6);
//   int number4 = greaterNumOf2Nums(number1, number2);
//   int number5 = greaterNumOf2Nums(number3, number4);

//   return number5;
// }

// void printResult(int greater_num, int num1, int num2, int num3, int num4,
//                  int num5, int num6) {
//   printf("The greater number of [ %d, %d, %d, %d, %d, %d ] is %d", num1,
//   num2,
//          num3, num4, num5, num6, greater_num);
// }

// int main() {
//   int num1, num2, num3, num4, num5, num6, greater_num;

//   read6Nums(&num1, &num2, &num3, &num4, &num5, &num6);

//   greater_num = greaterNumOf6Nums(num1, num2, num3, num4, num5, num6);

//   printResult(greater_num, num1, num2, num3, num4, num5, num6);

//   return 0;
// }
