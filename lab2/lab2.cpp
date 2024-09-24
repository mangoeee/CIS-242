/*
    Instructions

    The following function uses reference variables as parameters. Rewrite the function so it uses pointers instead of reference variables, and then demonstrate the function in a complete program. 

    int doSomething(int &x, int &y){
        int temp = x;
        x = y * 10;
        y = temp * 10;
        return x + y;
    }

    Ask the user for the values, do not hard code them.
*/

#include <iostream>
using namespace std;

int doSomething(int *x, int *y){
        int temp = *x;
        *x = (*y) * 10;
        *y = temp * 10;
        return *x + *y;
    }

int main(){
    int a;
    int b;

    cout << "Please enter the first integer: ";
    cin >> a;
    cout << "Please enter the second integer: ";
    cin >> b;

    int result = doSomething(&a, &b);

    cout << "Result: " << b << " + " << a << " = " << result; 
}