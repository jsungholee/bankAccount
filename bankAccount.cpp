/*
    Name: Joshua Lee
    Date: March 17, 2015
    Purpose: Creating a bank account program that allows users to login and save information.
    Algorithm:
        1) Show a menu to allow user to either create a bank account, login, and close 2) Validate that the user chose a valid option
        3) If the user wants to create a login, allow them to create and save the info to a file
        4) If the user wants to login, validate that the info matches and log them in and show a new menu
        5) If the user wants to quit, send a goodbye message
        6) Once logged in, show another menu to withdraw, deposit, request balance, and quit
           check that the choice is a valid option, if not show menu again
        7) If withdraw, then ask for a number and validate it is possible
        8) If deposit, ask for number and add the money to the user account
        9) If checking balance, get the user's account balance
        10 If quit, then send bad to the first menu

*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// function prototypes
char mainMenu();
bool validateMainMenu(char);
string navigateMenu(char);
bool login();
void createAccount();
char loginMenu();
string navigateLoginMenu(char);
void displayAmount();
string depositAmount();
string withdrawAmount();

// Global variables used to set account detail
string account = "notSet";
string password;
double balance = 0.0;

int main()
{
//declare an array of float for balance,

//delcare two arrays for username and password

  cout << "Hi! Welcome to Future Computer Programmer ATM Machine!";
  // Output the main menu and store the choice
  char choice = mainMenu();
  string output;

  // Send the choice and make the program do what the user wants
  output = navigateMenu(choice);

  // Continue to show mainMenu until the user quit
  while (output == "MainMenu")
  {
    choice = mainMenu();
    output = navigateMenu(choice);
  }

  // Continue to show the logged in menu until quit
  while (output == "loggedIn")
  {
    choice = loginMenu();
    output = navigateLoginMenu(choice);
  }
  cout << "Thanks for stopping by!\n" << endl;
}

string navigateLoginMenu(char choice)
{
  switch(choice)
  {

    case 'd':
    case 'D':
    {
      depositAmount();
      return "loggedIn";
    }
    case 'w':
    case 'W':
    {
      withdrawAmount();
      return "loggedIn";
    }
    case 'r':
    case 'R':
    {
      displayAmount();
      return "loggedIn";
    }
    default:
    {
      return "Goodbye";
    }
  }
}

string withdrawAmount()
{
  double withdraw;
  cout << "Enter amount of withdrawal: $";
  cin >> withdraw;
  // Check if withdrawal amount is greater than balance
  if (withdraw > balance)
  {
    cout << "Sorry withdrawal amount exceeds the balance amount. Can't withdraw!\n";
  }
  else
  {
    balance -= withdraw;
  }
  // tell the computer to show the logged in menu
  return "loggedIn";
}

string depositAmount()
{
  double deposit;
  cout << "Enter amount of deposit: $";
  cin >> deposit;
  while (deposit <= 0)
  {
    cout << "Enter an amount greater than 0: $";
    cin >> deposit;
  }
  balance += deposit;
  return "loggedIn";
}

void displayAmount()
{
  cout << "Your balance is $" << setprecision(2) << fixed << balance << endl;
}

char loginMenu()
{
  char choice;
  cout << "Please select an option from the menu below\n";
  cout << "D -> Deposit Money\n";
  cout << "W -> Withdraw Money\n";
  cout << "R -> Request Balance\n";
  cout << "Q -> quit\n";
  cin >> choice;
  return choice;
}

void createAccount()
{
  // Set a random password that will never be set
  string verifyPassword = "ewriouti3489715ydhfasdfneiru";

  cout << "Please enter your user name: ";
  cin >> account;
  cout << "Please enter your password: ";
  cin >> password;
  // Keep asking to verify password until it is the same
  while (verifyPassword != password)
  {
    cout << "Please verify the password. ";
    cin >> verifyPassword;
  }
  cout << "Thank you! Your account has been created!\n";
}

string navigateMenu(char choice)
{
  switch (choice)
  {
    case 'q':
    case 'Q':
    {
      return "Goodbye";
      break;
    }
    case 'c':
    case 'C':
    {
      createAccount();
      return "MainMenu";
      break;
    }
    case 'l':
    case 'L':
    {
      bool loggedIn;
//      if (account == "notSet")
//      {
//        cout << "Sorry Login Failed!\n";
//        return "MainMenu";
//      }
//      else
//      {
        loggedIn = login();
        if (loggedIn == true)
        {
          cout << "Access Granted!\n";
          return "loggedIn";
        }
        else
        {
          cout << "Incorrect Username or Password!\n";
          return "MainMenu";
        }
      //}
      break;
    }
    default:
    {
      return "Goodbye";
    }
  }
}

bool login()
{
  string username;
  string verifyPassword;

  cout << "Please enter your user name: ";
  cin >> username;
  cout << "Please enter your password: ";
  cin >> verifyPassword;

  if (username == account)
  {

    if (verifyPassword == password)
    {
      cout << "Access Granted!";
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    cout << "Sorry Login Failed!\n";
    return false;
  }
}

char mainMenu()
{
  char choice = 'a';

  // Continues to show the menu until a valid choice is made
  while (!validateMainMenu(choice))
  {
    cout << "Please select an option from the menu below:\n";
    cout << "C -> Create a bank account.\n";
    cout << "L -> Log into account.\n";
    cout << "Q -> Quit.\n";
    cout << "Enter your choice: ";
    cin >> choice;
  }
  return choice;
}

// function to make sure that they are inputting a valid choice
bool validateMainMenu(char input)
{
  switch (input)
  {
    case 'C':
    case 'c':
    {
      return true;
      break;
    }
    case 'L':
    case 'l':
    {
      return true;
      break;
    }
    case 'Q':
    case 'q':
    {
      return true;
      break;
    }
    default:
      return false;
  }
}
