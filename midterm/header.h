#pragma once
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>
#include <cctype>

// savings account class handles deposits, withdrawals, and balance
class SavingsAcct {
    private:
        static double balance; // static var to track balance across all instances
        double interestRate; // interest rate for calculations, this will be 1%
    public: 
        // constructor to init account
        SavingsAcct(double startBalance, double rate = 0.01) {
            balance = startBalance;
            interestRate = rate;
        }
        
        // display current balance
        void displayBalance() {
            std::cout << "Current balance: $" << balance << std::endl;
        }

        // function to withdraw from account
        void withdraw(double amount) {
            if (amount < 0) {
                throw std::invalid_argument("Negative entries are not allowed.");
            }
            if (amount > balance) {
                throw std::runtime_error("Insufficient Funds.");
            }
            balance -= amount;
        } 

        // function to deposit into account
        void deposit(double amount) {
            if (amount < 0) {
                throw std::invalid_argument("Negative entries are not allowed.");
            }
            balance += amount;
        }

        // function to calculate and apply interest to balance
        void applyInterest() {
            double interest = balance * interestRate;
            balance += interest;
            std::cout << "Interest accrued: $" << interest;
        }

        // static function to get balance
        static double getBalance() {
            return balance;
        }
};

double SavingsAcct::balance = 0;

// login 
bool login() {
    std::string username, password;
    const std::string correctUsername = "user"; // hard-code username
    const std::string correctPassword = "pass"; // hard-code password

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    return (username == correctUsername && password == correctPassword); // for purpose of this assignment, I've hardcoded the username and password
}

// most bank apps have you confirm transactions before submission, let's implement that here too
bool confirmTransaction(std::string action, double amount) {
    // capitalize action so it reads better
    if (!action.empty()) { 
        action[0] = std::toupper(action[0]);
    }

    // storing user response as char
    char response;
    
    while (true) {
        std::cout << "Are you sure you want to " << action << " $" << amount << "? (Y/N): ";
        std::cin >> response;
        if (response == 'Y' || response == 'y') {
            return true;
        } else if (response == 'N' || 'n') {
            std::cout << action << " cancelled.\n";
            return false;
        } else {
            std::cout << "Invalid input. Please enter 'Y' for yes or 'N' for no.\n";
        }
    }
}

// menu
void displayMenu() {
    std::cout << "\n--- Savings Account Menu ---\n";
    std::cout << "1. View Balance\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Apply Interest\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}