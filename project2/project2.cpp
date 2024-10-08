/*
    Instructions

    Write a function that dynamically allocates an array of integers. The function should accept an integer argument indicating the number of elements to allocate. The function should return a pointer to the array. 

*/

#include <iostream>
using namespace std;

// declaring function first, then defining under int main
int *allocateArray(int numElements);

int main() {
    int *ptrArr = nullptr;
    int size;
    
    // ask the user for the number of elements
    std::cout << "Enter the number of elements to allocate: ";
    std::cin >> size;
    
    // call the function to allocate the array
    ptrArr = allocateArray(size);

    // enter values for each index
    for (int i = 0; i < size; i++)
	{
		cout << "Enter value for number " << (i + 1) << ": ";
		cin >> ptrArr[i];
	}

    // output the values of the array
    std::cout << "Allocated array elements: ";
    for (int i = 0; i < size; i++) {
        std::cout << *(ptrArr+i) << " ";
    }
    std::cout << std::endl;
    
    // free the allocated memory, I think I have to do this every time I dynamically allocate memory?
    delete[] ptrArr;
    ptrArr = nullptr;

    return 0;
}

int *allocateArray(int numElements) {
    int *array = nullptr;
    // dynamically allocate memory for an array of integers

    array = new int[numElements];

    // return the pointer to the array
    return array;
}