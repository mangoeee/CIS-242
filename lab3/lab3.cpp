/*
    Instructions

    Write a program that uses a loop to display Pattern A below, followed by another loop that displays Patter B.

    Pattern A               Pattern B
    +                       **********
    ++                      *********
    +++                     ********
    ++++                    *******
    +++++                   ******
    ++++++                  *****
    +++++++                 ****    
    ++++++++                ***
    +++++++++               **  
    ++++++++++              *

    Extra credit: Place Pattern A in its own function and Pattern B in its own function. Use pointers. 
*/

#include <iostream>
using namespace std;

void patternA(int row);
void patternB(int row, int maxSymbols);

int main() {
    const int maxSymbols = 10;  // Max number of symbols in each pattern
    const int spaceBetween = maxSymbols + 6;  // Fix the number of spaces between patterns

    cout << "Pattern A\tPattern B" << endl;

    // Print Pattern A and Pattern B side by side
    for (int i = 1; i <= maxSymbols; i++) {
        patternA(i);

        // Print spaces between Pattern A and Pattern B to keep it aligned
        int spaces = spaceBetween - i;  // Calculate remaining spaces after Pattern A
        for (int k = 0; k < spaces; k++) {
            cout << " ";
        }

        patternB(i, maxSymbols);

        cout << endl;
    }

    return 0;
}

// Print Pattern A
void patternA(int row) {
    for (int j = 1; j <= row; j++) {
        cout << "+";
    }
}

// Print Pattern B
void patternB(int row, int maxSymbols) {
    for (int j = maxSymbols; j >= row; j--) {
        cout << "*";
    }
}