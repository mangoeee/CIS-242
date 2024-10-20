/*
    Emery Mangona
    CIS 242 Project 4

    Create a program that has a Starting Balance, deposits, withdrawal from a savings account, and returns the following on the screen:
        - Balance use any amount hard-coded in your code
        - Amount withdrawn (input by user)
        - Amount deposit (input from user)
        - Interest accrued (it is whatever equation you come up with from teh starting balance)
        - Exit (exit out of the program)

    If the withdrawal amount is greater than the starting balance, a message appears stating: "Insufficient Funds" and then ask the user to either Exit or go back to Main Menu

    If the withdrawal amount is a negative number, a message appears stating: "Negative entries are not allowed" and then ask the user to either Exit or go back to Main Menu

    Next, you will then ask the user to either Exit or go back to the main menu

    Before being able to see the menu options, a username and password should be inputted by the user

    Calculate interest at 1% of the Starting Balance (this should take place after the user enters their information), it should show them their interest thus far

    ****** Please makes sure when there is a withdrawal or deposit I should be able to go back to the Balance and see that it is change. For instance if I start it with 1,000 do a deposit of $500. I should be able to go back to the menu and see that reflection in the Balance option. The starting Balance in your code should not be a constant variable it needs to be a static variable. **************
*/

#include <iostream>
#include "header.h"

bool login();
void displayMenu();
class SavingsAcct::SavingsAcct;

int main() {
    double initialBalance = 1000.0; // hard-coded balance as per instructions
    SavingsAcct account(initialBalance);

    std::cout << "Welcome to your hypothetical Savings Account!\n";

    if (!login()) {
        std::cout << "Invalid username or password. Exiting program...\n";
        return 1;
    }



    return 0;
}