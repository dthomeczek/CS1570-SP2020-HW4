// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 2/24/2020
// File: hw4.cpp
// Purpose: To calculate the cube root or the power of a given base number

#include <iostream>
using namespace std;

int main()
{
  const char MENU_ONE = '1'; // First input of the menu
  const char MENU_TWO = '2'; // Second input of the menu
  const char MENU_THREE = '3'; // Third input of the menu
  const char MENU_FOUR = '4'; // Fourth input of the menu
  const int COUNT_START = 1; // Starting value of loop
  const int ROOT_ITERATION = 10; // Number of iterations to find a cube root
  const int MULTIPLICAND = 2; // Multiplicand in root formula
  const int DIVISOR = 3; // Divisor in root formula

  char menu_input; // User's menu input
  int user_input; // User's number input
  int user_power; // User's power input
  int multiple_holder; // Holds the value for the number of power multiples
  double root_form_hold; // Holds the value of the user input for root formula
  int i; // Counting variable
  bool quit = false; // Determines if the quit option was selected or not
  bool check_one = false; // Defaults menu option one to false, therefore 
                          // making options 2 and 3 unavailable until
                          // option 1 has been performed properly

  // Brief introductory message
  cout << "Welcome to the power determiner! Please select an option." <<
  endl << endl;
  do
  {
    // Prompt the user with the menu
    cout << "   === Menu ===   " << endl;
    cout << "   ------------   " << endl;
    cout << "1. Enter a number" << endl;
    cout << "2. Power the number" << endl;
    cout << "3. Cube root of the number" << endl;
    cout << "4. Quit" << endl << endl;
    cin >> menu_input;
    
    // Check each menu option based on the input
    switch (menu_input)
    {
      
      // Prompts the user for the base number
      case MENU_ONE:
        cout << "Enter a number:" << endl;
        cin >> user_input;
        // Makes sure the user's base number input is a positive integer
        while (user_input <= 0)
        {
          cout << "Invalid input! Please enter an integer larger than 0!" <<
          endl;
          cin >> user_input;
        }
        check_one = true;
        break;

      // Prompts the user for the power to raise the base number to
      case MENU_TWO:
        if (check_one == true)
        {
          cout << "Enter a power:" << endl;
          cin >> user_power;
          // Makes sure the user's power input is a positive integer
          while (user_power <= 0)
          {
            cout << "Invalid input! Please enter an integer larger than 0!" <<
            endl;
            cin >> user_power;
          }
         
          // Multiplies the number by itself base on the power
          multiple_holder = user_input;
          for (i = COUNT_START; i < user_power; i++)
          {
            user_input = user_input * multiple_holder;
          }
          cout << multiple_holder << "^" << user_power << " = " <<
          user_input << endl << endl;
        }
        else if (check_one == false)
        {
          cout << "Invalid input! Please select option 1 first!" << endl <<
          endl;
        }
        check_one = false;
        break;

      // Performs the cube root of the user's input base number
      case MENU_THREE:
        if (check_one == true)
        {
          root_form_hold = user_input;
          for (i = COUNT_START; i < ROOT_ITERATION; i++)
          {
            root_form_hold = ((MULTIPLICAND * root_form_hold) + (user_input)
            / (root_form_hold * root_form_hold)) / (DIVISOR);
          }
          cout << "The cube root of " << user_input << " is " <<
          root_form_hold << "." << endl << endl;
          check_one = false;
        }
        else if (check_one == false)
        {
          cout << "Invalid input! Please select option 1 first!" << endl <<
          endl;
        }
        break;
      
      //  Quits the program
      case MENU_FOUR:
        quit = true;
        break;
      
      // Re-prompts the user for a valid option
      default:
        cout << "Invalid input! Please input a valid menu option! (1-4)" << endl <<
        endl;
        break;
    }
  } while (quit != true);

  // Brief conclusory message
  cout << "Thank you for using this power determiner!" << endl;
  return 0;
}