#include <stdio.h>
#include <string.h>

// Mahmoud Easa

/*
  Print the name of the person based on the last 5 national numbers sent from
  the user Step 1 => Start Step 2 => Store 5 of (last 5 national numbers) In
  Array Step 3 => Store 5 Names In Array Step 4 => If number input = national
  number =>  return name[id of national number] Step 5 => If no number => return
  no name Step 6 => End
*/
// int readNationalNum();
// char *returnNameWithNationalNum(int id);
// void printResult(int id);

// int main() {
//   int id = -1, national_input;
//   int national_numbers[5] = {11111, 22222, 33333, 44444, 55555};
//   int arr_size = sizeof(national_numbers) / sizeof(national_numbers[0]);

//   national_input = readNationalNum();

//   for(int i = 0; i < arr_size; i++) {
//     if(national_input == national_numbers[i])
//       id = i;
//   }

//   printResult(id);

//   return 0;
// }

// int readNationalNum() {
//   int national_num;
//   printf("Please Enter National Number [11111, 22222, 33333, 44444, 55555]:
//   "); scanf("%d", &national_num);

//   return national_num;
// }

// char *returnNameWithNationalNum(int id) {
//   char names[5][10] = {"Mahmoud", "Ahmed", "Ali", "Osama", "Alaa"};
//   char name[10];

//   if(id < 0 || id > 4)
//     return "No Name";

//   strcpy(name, names[id]);

//   return name;
// }

// void printResult(int id) {
//   printf("%s", returnNameWithNationalNum(id));
// }
