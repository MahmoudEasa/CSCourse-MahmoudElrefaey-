#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define CLIENTS 2
#define ACCOUNTS 2
#define EG_USD 30.23

// Mahmoud Easa

typedef struct Accounts
{
  int id;
  float balance;
  char currency;
}Accounts;

typedef struct Clients
{
  char name[30];
  char password[20];
  char status;
  Accounts accounts[ACCOUNTS];
}Clients;

void fillDataToStruct(Clients c[]);
void login(char name[], char password[]);
char welcome(char *name);
int filterClientWithName(char name_input[], Clients c[]);
char readCurrency();
int readAmount();
void readStatus(char name_change_status[], char *status);
int readId();
float currencyConvert(char currency, float amount);
int checkIdInStruct(int id,  Accounts a[]);
void withdraw(Accounts a[], int id, float amount, char currency_amount);
void deposit(Accounts a[], int id, float amount, char currency_amount);
void transfer(Clients c[], Accounts a[], int id_from, int id_to, float amount, char currency_amount);
void changeStatus(Clients c[], char name_input[], char status_change);

int main() {
  int id_from, id_to;
  char currency = 'E';
  float amount = 0;
  char status = '0';
  Clients client[CLIENTS];
  Clients *ptr_client = client;
  fillDataToStruct(ptr_client);
  char name_change_status[30];
  char name_login[30];
  char password_login[30];
  login(name_login, password_login);
  int client_index = filterClientWithName(name_login, ptr_client);
  
  if(client_index > -1 &&
        strcmp(password_login, client[client_index].password) == 0 && client[client_index].status == '1'){
    char make = welcome(name_login);
    Clients client_filter = client[client_index];

    switch (make)
    {
    case '1':
    case '2':
    case '3':
      currency = readCurrency();
      amount = readAmount();
      printf("Please Enter Your Account Id: ");
      id_from = readId();
    }

    switch (make)
    {
    case '1':
      withdraw(client_filter.accounts, id_from, amount, currency);
      break;
    case '2':
      deposit(client_filter.accounts, id_from, amount, currency);
      break;
    case '3':
      printf("Please Enter Account Id to transfer to: ");
      id_to = readId();
      transfer(ptr_client, client_filter.accounts, id_from, id_to, amount, currency);
      break;
    case '4':
      readStatus(name_change_status, &status);
      changeStatus(ptr_client, name_change_status, status);
      break;
    default:
      printf("There is no service with this number");
    }
  } else {
    if(client_index != -1 && client[client_index].status == 0)
      printf("Your Account Is Pending\n");
    else
      printf("Something is wrong\n");
  }

  return 0;
}

void fillDataToStruct(Clients c[])
{
  strcpy(c[0].name, "Mahmoud Easa");
  strcpy(c[1].name, "Ahmed Easa");
  strcpy(c[0].password, "123");
  strcpy(c[1].password, "123");

  c[0].status = '1';
  c[1].status = '0';

  c[0].accounts[0].id = 123;
  c[0].accounts[1].id = 234;
  c[1].accounts[0].id = 345;
  c[1].accounts[1].id = 456;

  c[0].accounts[0].balance = 5000;
  c[0].accounts[1].balance = 10000;
  c[1].accounts[0].balance = 3000;
  c[1].accounts[1].balance = 2000;

  c[0].accounts[0].currency = '$';
  c[0].accounts[1].currency = 'E';
  c[1].accounts[0].currency = 'E';
  c[1].accounts[1].currency = '$';
}

void login(char name[], char password[])
{
  printf("Welcome to the Islamic bank Mahmoud Easa without benefits because benefits are haram\n");
  printf("Please Enter Your Name: ");
  gets(name);
  printf("Please Enter Your Password: ");
  gets(password);
}

char welcome(char *name)
{
  char make;
  printf("Welcome %s\n", name);
  printf("What do want you to do? Choose Number [1,2,3,4]: \n");
  printf("1- Withdraw Balance\n");
  printf("2- Deposit Balance\n");
  printf("3- Transfer Balance\n");
  printf("4- Change Status\n");
  
  scanf(" %c", &make);
  return make;
}

int filterClientWithName(char name_input[], Clients c[])
{
  int index = -1;

  for(int i=0; i < CLIENTS; i++)
  {
    if(strcmp(name_input, c[i].name) == 0){
      index = i;
      break;
    }
  }
  return index;
}

char readCurrency()
{
  char currency;
  printf("please enter the currency [$ or E]: ");
  scanf(" %c", &currency);

  while((currency != '$' && currency != 'E'))
  {
    printf("please enter the currency [$ or E]: ");
    scanf(" %c", &currency);
  }
  return currency;
}

int readAmount()
{
  float amount = 0;
  printf("please enter the amount: ");
  scanf("%f", &amount);

  while(amount <= 0){
    printf("please enter a positive number greater than 0: ");
    scanf("%f", &amount);
  }

  return amount;
}

void readStatus(char name_change_status[], char *status)
{
  while (getchar() != '\n');
  printf("Please enter client name to change status: ");
  gets(name_change_status);
  printf("Please Enter Status: ");
  scanf(" %c", status);
}

int readId(){
  int id;
  scanf("%d", &id);
  return id;
}

float currencyConvert(char currency, float amount)
{
  if (currency == '$')
    return amount * EG_USD;
  else
    return amount / EG_USD;
}

int checkIdInStruct(int id, Accounts a[])
{
  for(int i=0; i<ACCOUNTS; i++)
    if(id == a[i].id)
      return i;
  return -1;
}

void withdraw(Accounts a[], int id, float amount, char currency_amount)
{
  int index = checkIdInStruct(id, a);

  if(index == -1){
    printf("Something is wrong");
    return;
  }

  if(a[index].currency == currency_amount) {
    if(a[index].balance < amount){
      printf("The account balance is less than the required amount.");
      return;
    }

    a[index].balance -= amount;
    printf("Withdraw is successfully your balance is: %.2f%c", a[index].balance, a[index].currency);
  } else {
    float converted_currency = currencyConvert(currency_amount, amount);

    if(a[index].balance < converted_currency){
      printf("The account balance is less than the required amount.");
      return;
    }

    a[index].balance -= converted_currency;
    printf("Withdraw is successfully your balance is: %.2f%c", a[index].balance, a[index].currency);
  }
  
}

void deposit(Accounts a[], int id, float amount, char currency_amount)
{
  int index = checkIdInStruct(id, a);

  if(index == -1){
    printf("Something is wrong");
    return;
  }

  if(a[index].currency == currency_amount) {
    a[index].balance += amount;
    printf("Deposit is successfully your balance is: %.2f%c", a[index].balance, a[index].currency);
  } else {
    float converted_currency = currencyConvert(currency_amount, amount);

    a[index].balance += converted_currency;
    printf("Deposit is successfully your balance is: %.2f%c", a[index].balance, a[index].currency);
  }
}

void transfer(Clients c[], Accounts a[], int id_from, int id_to, float amount, char currency_amount)
{
  int index_from = checkIdInStruct(id_from, a);
  if(index_from == -1){
    printf("Something is wrong");
    return;
  }

  int index_to_client;
  int index_to_account;

  for(int i=0; i<CLIENTS; i++){
    index_to_account = checkIdInStruct(id_to, c[i].accounts);
    index_to_client = i;
    if(index_to_account != -1)
      break;
  }

  if(index_to_account == -1){
    printf("Something is wrong");
    return;
  }

  if(a[index_from].id != c[index_to_client].accounts[index_to_account].id){
    if(a[index_from].currency == currency_amount) {
      a[index_from].balance -= amount;

      if(c[index_to_client].accounts[index_to_account].currency == currency_amount){
        c[index_to_client].accounts[index_to_account].balance += amount;
      }else {
        float converted_currency = currencyConvert(
                                          c[index_to_client].accounts[index_to_account].currency
                                          , amount);
        c[index_to_client].accounts[index_to_account].balance += converted_currency;
      }
      printf("Deposit Is Successfully your balance is: %.2f%c", a[index_from].balance, a[index_from].currency);
    } else {
      float converted_currency = currencyConvert(currency_amount, amount);
      
      a[index_from].balance -= converted_currency;

      if(c[index_to_client].accounts[index_to_account].currency == currency_amount){
        c[index_to_client].accounts[index_to_account].balance += amount;
      }else {
        float converted_currency = currencyConvert(
                                          c[index_to_client].accounts[index_to_account].currency
                                          , amount);
        c[index_to_client].accounts[index_to_account].balance += converted_currency;
      }
      printf("Deposit Is Successfully your balance is: %.2f%c", a[index_from].balance, a[index_from].currency);
    }
  }else
    printf("Something is wrong");
}

void changeStatus(Clients c[], char name_input[], char status_change)
{
  int client_fillter = filterClientWithName(name_input, c);

  if(client_fillter == -1){
    printf("Something is wrong");
    return;
  }

  c[client_fillter].status = status_change;
  printf("Change Status Is Successfully");
}

// المفروض في رسائل الإيرور دائماً أكتب شيء لا يوضح للمستخدم إيه اللي بيحصل للأمان علشان كده بكتب
// Something is wrong

/*
  Task
    * Store 2 clients, each client has 2 accounts
    * Account has [id, balance, currency]
    * Client has [name, password, status, accounts]
    * We need to make the followint
      * Withdraw
      * Deposit
      * Transfer
      * Status
    * Take notes
      * Testcases
      * Reusable code
      * Clean code
      * Performance
*/

/*
  Step 1: Create define for number of clients
  Step 2: Create define EG_USD 30.23
  Step 3: Create define for number of accounts
  Step 4: Create struct for account
          [id, balance, currency]
  Step 5: Create struct for client
          [name, password, status, accounts]
  Step 6: Inside struct client create object of account with array with number of define accounts
  Step 7: Create function void login(char name[], char password[])
            PRINT "Welcome to the Islamic bank Mahmoud Easa without benefits because benefits are haram"
            PRINT "Please Enter Your Name: "
            scan name
            PRINT "Please Enter Your Password: "
            scan password
  Step 8: Create function char *welcome(char *name)
            Declare a variable char make[20]
            PRINT "Welcome %s" name
            PRINT "What do want you to do? "
            PRINT "1- Withdraw Balance"
            PRINT "2- Deposit Balance"
            PRINT "3- Transfer Balance"
            PRINT "4- Change Status"
            scan make
            return make
  Step 9: In tne main
              Declare variable char name[]
              Declare variable char password[]
              create object of client with array with number of define clients
              run Login(name, password) function
              Declare variable int index = filterClientWithName(name, struct clients)
                IF index > -1 && password == client.password && client.status == 1
                  Declare struct clientFilter = client[index]
                  run char make = welcome(clientFilter.name) function
                  IF make == "Withdraw Balance"
                    run readCurrency()
                    run readAmount()
                    run withdraw()
                  ELSE IF make == "Deposit Balance"
                    run readCurrency()
                    run readAmount()
                    run deposit()
                  ELSE IF make == "Transfer Balance"
                    run readCurrency()
                    run readAmount()
                    run transfer()
                  ELSE IF make == "Change Status"
                    run changeStatus()
                Else
                  IF client.status == 0
                    PRINT "Your Account Is Pending"
                  ELSE
                    PRINT "Something is wrong"
  Step 10: Create function char readCurrency()
            Declare a variable char currency
            PRINT "please enter the currency [$ or E]"
            Scan currency
            WHILE (currency != "$" || currency != "EGP")
              PRINT "please enter the currency [$ or E]"
              Scan currency
            RETURN currency
  Step 11: Create function int readAmount()
            Declare a variable int amount = 0
            PRINT "please enter the amount"
            Scan amount
            WHILE amount <= 0
              PRINT "please enter a positive number greater than 0"
              Scan amount
            RETURN amount
  Ster 12: Create function FLOAT currencyConvert(char currency, float amount)
          IF currency == "$"
            return amount / EG_USD
          Else
            return amount * EG_USD
  Ster 13: Create function INT filterClientWithName(char *name, struct clients[num_of_clients])
          FOR i in clients
            IF name == clients[i].name
              RETURN i;
            Else return -1;
  Ster 14: Create function INT checkIdInStruct(int id, struct arr[num_of_clients])
          FOR i in arr
            IF id == arr[i]
              RETURN i;
          RETURN -1;
  Step 15: Create function void withdraw(struct account[num_of_accounts], id, amount, currency_amount)
            Test Cases:
              id not found
              balance < amount
            INT index = checkIdInStruct(int id, struct account[num_of_accounts]);
              IF index == -1
                  PRINT "Something is wrong"
                  RETURN;
              
              IF account[index].currency == currency_amount {
                IF account[index].balance < amount
                  PRINT "The account balance is less than the required amount."
                  RETURN;

                account[index].balance -= amount
                PRINT "Withdraw is successfully your balance is: %d%c" account[index].balance, account[index].currency
              } else {
                Call FUNCTION int converted_currency = currencyConvert(currency_amount, amount)
                
                IF account[index].balance < converted_currency
                  PRINT "The account balance is less than the required amount."
                  RETURN;

                account[index].balance -= converted_currency
                PRINT "Withdraw Is Successfully your balance is: %d%c" account[index].balance, account[index].currency
              }
  Step 16: Create function void deposit(struct account[num_of_accounts],
                                                int id, float amount,
                                                char currency_amount)
            INT index = checkIdInStruct(int id, struct account[num_of_accounts]);
            IF index == -1
                  PRINT "Something is wrong"
                  RETURN;
            IF account[index].currency == currency_amount {
              account[index].balance += amount
              PRINT "Deposit Is Successfully your balance is: %d%c" account[index].balance, account[index].currency
            } else {
              Call FUNCTION int converted_currency = currencyConvert(currency_amount, amount)
              
              account[index].balance += converted_currency
              PRINT "Deposit Is Successfully your balance is: %d%c" account[index].balance, account[index].currency
            }
  Step 17: Create function void transfer(struct clients[num_of_clients],
                                                  struct account[num_of_accounts],
                                                  int id_from, int id_to,
                                                  float amount, char currency_amount)
            INT index_from = checkIdInStruct(int id_from, struct account[num_of_accounts]);
            IF index_from == -1
                  PRINT "Something is wrong"
                  RETURN;

            INT index_to_client;
            INT index_to_account;

            For i in clients
              index_to_account = checkIdInStruct(int id_to, struct clients[i].account[num_of_accounts])
              index_to_client = i;
              If index_to_account != -1
                break;

            IF index_to_account == -1
                  PRINT "Something is wrong"
                  RETURN;

            IF account[index_from].id != clients[index_to_client].account[index_to_account].id
                IF account[index_from].currency == currency_amount {
                  account[index_from].balance -= amount
                  IF clients[index_to_client].account[index_to_account].currency == currency_amount{
                    clients[index_to_client].account[index_to_account].balance += amount
                  }else {
                    Call FUNCTION int converted_currency = currencyConvert(
                                                      clients[index_to_client].account[index_to_account].currency
                                                      , amount)
                    clients[index_to_client].account[index_to_account].balance += converted_currency
                  }
                  PRINT "Deposit Is Successfully your balance is: %d%c" account[index_from].balance, account[index_from].currency
                } else {
                  Call FUNCTION int converted_currency = currencyConvert(currency_amount, amount)
                  
                  account[index_from].balance -= converted_currency

                  IF clients[index_to_client].account[index_to_account].currency == currency_amount{
                    clients[index_to_client].account[index_to_account].balance += amount
                  }else {
                    Call FUNCTION int converted_currency = currencyConvert(
                                                      clients[index_to_client].account[index_to_account].currency
                                                      , amount)
                    clients[index_to_client].account[index_to_account].balance += converted_currency
                  }
                  PRINT "Deposit Is Successfully your balance is: %d%c" account[index_from].balance, account[index].currency
                }
            else
              PRINT "Something is wrong"
  Step 18: Create function void changeStatus(struct Client, bool status)
                    Clients.active = status
                    PRINT "Change Status Is Successfully"
*/
