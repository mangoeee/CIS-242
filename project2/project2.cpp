/*
    Instructions

    Write a function that dynamically allocates an array of integers. The function should accept an integer argument indicating the number of elements to allocate. The function should return a pointer to the array. 

*/

#include <iostream>
using namespace std;

// Declaring function first, then defining under int main
int* allocateArray(int numElements); 

int main() {
    int size;
    
    // Ask the user for the number of elements
    std::cout << "Enter the number of elements: ";
    std::cin >> size;
    
    // Call the function to allocate the array
    int* myArray = allocateArray(size);

    // Output the values of the array
    std::cout << "Allocated array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;
    
    // Free the allocated memory, I think I have to do this every time I dynamically allocate memory?
    delete[] myArray;

    return 0;
}

int* allocateArray(int numElements) {
    // Dynamically allocate memory for an array of integers
    int* array = new int[numElements];

    // Return the pointer to the array
    return array;
}