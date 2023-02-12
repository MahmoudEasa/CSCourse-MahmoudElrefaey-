#include <stdio.h>

/*
    printf("Please Enter USD, EUR, and SAR Currencies in order: ")
    read USD, EUR, and SAR

    printf("What is your salary: ")
    read salary

    printf("What Currency do you want to convert to: ")
    u => USD => 30.23
    E => EUR => 32.63
    R => SAR => 8.06
    read currency

    convert salary

    if salary >= 5000 EGP It is good
    else It is bad

*/

// void readCurrencies(float *USD, float *EUR, float *SAR) {
//   printf("Please Enter USD, EUR, and SAR Currencies in order: ");
//   scanf("%f %f %f", USD, EUR, SAR);
// }

// void readSalaryAndCurrencySymbol(float *salary, char *currencySymbol) {
//   printf("What is your salary: ");
//   scanf("%f", salary);
//   printf("What Currency do you want to convert to:\n");
//   printf("u => USD\ne => EUR\nr => SAR\n");
//   scanf(" %c", currencySymbol);
// }

// float convertSymbolToCurrency(char currencySymbol, float USD, float EUR,
//                               float SAR) {
//   if (currencySymbol == 'u' || currencySymbol == 'U') {
//     return USD;
//   } else if (currencySymbol == 'e' || currencySymbol == 'E') {
//     return EUR;
//   } else if (currencySymbol == 'r' || currencySymbol == 'R') {
//     return SAR;
//   } else {
//     return 1;
//   }
// }

// float convertSalary(float currency, float salary) { return salary / currency;
// }

// void printResult(float salaryConverted, float salary) {
//   if (salary >= 5000) {
//     printf("Your Salary Converted is: %.2f It is good", salaryConverted);
//   } else {
//     printf("Your Salary Converted is: %.2f It is bad", salaryConverted);
//   }
// }

// int main() {
//   float USD, EUR, SAR, salary;
//   char currencySymbol;

//   readCurrencies(&USD, &EUR, &SAR);
//   readSalaryAndCurrencySymbol(&salary, &currencySymbol);
//   printResult(
//       convertSalary(convertSymbolToCurrency(currencySymbol, USD, EUR, SAR),
//                     salary),
//       salary);

//   return 0;
// }
