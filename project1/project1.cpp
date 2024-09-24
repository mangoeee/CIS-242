/* Instructions 

    Write a function that accepts an int array and the array's size as arguments. The function should create a copy of the array, except that the element values should be reversed in the copy. The function should return a point to the new array. Demonstrate the function in a complete program.

    Additional Requirement: Ask the user for the 20 values for the array.

*/

#include <iostream>
using namespace std;
    
// function to reverse the array
int* reverseArray(const int* arr, int size) {
    int* reversedArray = new int[size];
    
    for (int i = 0; i < size; i++) {
        reversedArray[i] = arr[size - 1 - i];
    }
    
    return reversedArray;
}

int main() {
    const int size = 20;  // fixing the size of the array to 20
    int arr[size];

    // obtain 20 elements from the user
    cout << "Please enter 20 integers you'd like to be reversed in an array: ";
    
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // calling function to reverse the array
    int* reversedArray = reverseArray(arr, size);

    // display reversed array
    cout << "Reversed array: ";
    
    for (int i = 0; i < size; i++) {
        cout << reversedArray[i] << " ";
    }
    
    cout << endl;

    return 0;
}