#pragma once
#include <iostream>
#include <string>

// login algo
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

// savings account class handles deposits, withdrawals, and balance
class SavingsAcct {
    private:
        static double balance; // static var to track balance across all instances
        double interestRate; // interest rate for calculations, this will be 1%
    public: 
        SavingsAcct(double startBalance, double rate = 0.01) {
            balance = startBalance;
            interestRate = rate;
        }

        void displayBalance() {
            std::cout << "Current balance: $" << balance << std::endl;
        }
};