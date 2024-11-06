/*
    Emery Mangona
    CIS 242 Project 5

    Static Stack Template
        Write your own version of a class template that will create a static stack of any data type. Demonstrate the class with a driver program.
*/

#include <iostream>
#include "template.h"

int main() {
    std::cout << "Creating stack of doubles.\n";
	StaticStack<double> doubleStack(5);
	double values[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	double value;

	// Store values
	std::cout << "Pushing doubles...\n";
	for (int i = 0; i < 5; i++) {
		std::cout << values[i] << "  ";
		doubleStack.push(values[i]);
	}
	std::cout << std::endl;

	std::cout << "Popping doubles...\n";
	while (!doubleStack.isEmpty()) {
		doubleStack.pop(value);
		std::cout << value << "  ";
	}
	std::cout << std::endl;

    if (doubleStack.isEmpty()) {
        std::cout << "The stack of doubles is now empty.";
    }

    return 0;
}