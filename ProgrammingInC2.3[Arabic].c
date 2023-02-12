#include <stdio.h>

/*
https://ideone.com/BqSeBZ
    First Task =>
        1= Read Operator [+, -, *, /, %, >, <, =],
        2= Read Num1
        3= Read Num2
        4= Print Result [Num1 Operator Num2]

https://ideone.com/XLPYcO
    Second Task =>
        1= Read the Day [Number]
        2= Read the Month [Number]
        3= Print Result [Name of Day & Name of Month]
*/

// First Task
// char readOperator(){
//     char theOperator;

//     do{
//         printf("Please Enter One of These Operators [+, -, *, /, %c, >, <, =]
//         to Calcult: ", 37); // ASCII 37 =>  % scanf(" %c", &theOperator);
//     }while(
//         (
//             theOperator != '+'
//             && theOperator != '-'
//             && theOperator != '*'
//             && theOperator != '/'
//             && theOperator != '%'
//             && theOperator != '<'
//             && theOperator != '>'
//             && theOperator != '='
//         )
//     );

//     return theOperator;
// }

// void readNumbers(float *num1, float *num2){
//     int isScaned = 0;
//     printf("Please Enter a Positive Number 1: ");
//     isScaned = scanf("%f", num1);

//     while(*num1 < 0){
//         if (isScaned != 1){
//             while(getchar()!= '\n');
//             printf("Error!Please Enter a Number: ");
//         }
//         else{
//             printf("Error!Please Enter a Positive Number 1: ");
//         }
//         isScaned = scanf("%f", num1);
//     }

//     printf("Please Enter a Positive Number 2: ");
//     isScaned = scanf("%f", num2);

//     while(*num2 < 0){
//         if(isScaned != 1) {
//             while(getchar()!= '\n');
//             printf("Error!Please Enter a Number: ");
//         }
//         else{
//             printf("Error!Please Enter a Positive Number 2: ");
//         }
//         isScaned = scanf("%f", num2);
//     }
// }

// void printResult(char theOperator, float num1, float num2){
//     switch(theOperator) {
//         case '+':
//             printf("%.2f + %.2f = %.2f", num1, num2, (num1 + num2));
//             break;
//         case '-':
//             printf("%.2f - %.2f = %.2f", num1, num2, (num1 - num2));
//             break;
//         case '*':
//             printf("%.2f * %.2f = %.2f", num1, num2, (num1 * num2));
//             break;
//         case '/':
//             printf("%.2f / %.2f = %.2f", num1, num2, (num1 / num2));
//             break;
//         case '%':
//             printf("%.2f %% %.2f = %d", num1, num2, ((int)num1 % (int)num2));
//             break;
//         case '>':
//             if(num1 > num2){
//                 printf("( %.2f > %.2f )", num1, num2);
//             }else {
//                 printf("( %.2f > %.2f )", num2, num1);
//             }
//             break;
//         case '<':
//             if(num1 < num2){
//                 printf("( %.2f < %.2f )", num1, num2);
//             }else {
//                 printf("( %.2f < %.2f )", num2, num1);
//             };
//             break;
//         case '=':
//             if(num1 == num2){
//                 printf("( %.2f = %.2f )", num1, num2);
//             }else {
//                 printf("( %.2f != %.2f )", num1, num2);
//             };
//             // break;
//         // default: I don't want the default because I have validation on
//         scanf
//             // printf("");
//     }
// }

// int main() {
//     float num1 = -1, num2 = -1;
//     char theOperator = readOperator();

//     readNumbers(&num1, &num2);
//     printResult(theOperator, num1, num2);

//     return 0;
// }

//
//
//
//
//
//

// Second Task
// int readNumOfDay() {
//   int numOfDay = 0;
//   int isScaned = 0;

//   printf("Please Enter Number Of Day From 1 To 7: ");
//   isScaned = scanf("%d", &numOfDay);

//   while ((numOfDay <= 0 || numOfDay > 7)) {
//     if (isScaned != 1) {
//       while (getchar() != '\n')
//         ;
//       printf("Error!Please Enter a Number: ");
//     } else {
//       printf("Please Enter Number Of Day From 1 To 7: ");
//     }
//     isScaned = scanf("%d", &numOfDay);
//   }
//   return numOfDay;
// }

// int readNumOfMonth() {
//   int numOfMonth = 0;
//   int isScaned = 0;

//   printf("Please Enter Number Of Month From 1 To 12: ");
//   isScaned = scanf("%d", &numOfMonth);

//   while ((numOfMonth <= 0 || numOfMonth > 12)) {
//     if (isScaned != 1) {
//       while (getchar() != '\n')
//         ;
//       printf("Error!Please Enter a Number: ");
//     } else {
//       printf("Please Enter Number Of Month From 1 To 12: ");
//     }
//     isScaned = scanf("%d", &numOfMonth);
//   }
//   return numOfMonth;
// }

// char *convertNumOfDayToName(int numOfDay) {
//   switch (numOfDay) {
//   case 1:
//     return "Saturday";
//   case 2:
//     return "Sunday";
//   case 3:
//     return "Monday";
//   case 4:
//     return "Tuesday";
//   case 5:
//     return "Wednesday";
//   case 6:
//     return "Thursday";
//   case 7:
//     return "Friday";
//   }
// }

// char *convertNumOfMonthToName(int numOfMonth) {
//   switch (numOfMonth) {
//   case 1:
//     return "January";
//   case 2:
//     return "February";
//   case 3:
//     return "March";
//   case 4:
//     return "April";
//   case 5:
//     return "May";
//   case 6:
//     return "June";
//   case 7:
//     return "July";
//   case 8:
//     return "August";
//   case 9:
//     return "September";
//   case 10:
//     return "October";
//   case 11:
//     return "November";
//   case 12:
//     return "December";
//   }
// }

// void printResult(int numOfDay, int numOfMonth) {
//   printf("%d of Day is %s and %d of Month is %s", numOfDay,
//          convertNumOfDayToName(numOfDay), numOfMonth,
//          convertNumOfMonthToName(numOfMonth));
// }

// int main() {
//   int numOfDay = readNumOfDay();
//   int numOfMonth = readNumOfMonth();

//   printResult(numOfDay, numOfMonth);

//   return 0;
// }
