/* 
    Instructions 
    
    Have a user input of 2 numbers. Take those 2 numbers to add, multiply, divide, subtract and mod. Each operation(+,-,*,/,%) must be a function and include a couple void functions, call by reference functions. Extra credit a pointer function. 
*/

#include <iostream>
using namespace std;

int add(int a, int b);
void subtract(int a, int b, int &result);  // Call by reference
int multiply(int a, int b);
void divide(int a, int b, double &result); // Call by reference with void
int mod(int a, int b);

int main() {
    int num1, num2;
    int resultInt;
    double resultDouble;

    // User input
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Addition
    resultInt = add(num1, num2);
    cout << "Addition: " << resultInt << endl;

    // Subtraction
    subtract(num1, num2, resultInt); // Call by reference
    cout << "Subtraction: " << resultInt << endl;

    // Multiplication
    resultInt = multiply(num1, num2);
    cout << "Multiplication: " << resultInt << endl;

    // Division
    if (num2 != 0) {
        divide(num1, num2, resultDouble); // Call by reference
        cout << "Division: " << resultDouble << endl;
    } else {
        cout << "Division: Error! Division by zero." << endl;
    }

    // Modulus
    if (num2 != 0) {
        resultInt = mod(num1, num2);
        cout << "Modulus: " << resultInt << endl;
    } else {
        cout << "Modulus: Error! Division by zero." << endl;
    }

    return 0;
}

// Addition function
int add(int a, int b) {
    return a + b;
}

// Subtraction function (void and call by reference)
void subtract(int a, int b, int &result) {
    result = a - b;
}

// Multiplication function
int multiply(int a, int b) {
    return a * b;
}

// Division function (void and call by reference)
void divide(int a, int b, double &result) {
    result = static_cast<double>(a) / b;
}

// Modulus function
int mod(int a, int b) {
    return a % b;
}