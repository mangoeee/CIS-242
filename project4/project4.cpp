/*
    Instructions:

    Create a menu with the following options:
        1. Filled triangle
        2. Filled inverted triangle
        3. Any shape (i.e. square, circle, different angle triangle, etc.)
        4. EXTRA CREDIT: Bow tie shape
        5. Exit (this option would be 4 without the extra credit)

    Requirements:
        a. Create a class to house all of the functions and a constructor
        b. Either ask the user to enter the height (amount of rows) of the shape or ask the user to enter the width and height of the shape
        c. While loop or do/while loop
        d. For loop for each shape
        e. Functions for each shape

    Key point to help: case statements for each menu option that can go inside of int main()
*/

#include <iostream>
#include "project4.h"

const int MAX_HEIGHT = 50; // defining a maximum height for shapes
const int MAX_WIDTH = 50; // defining a maximum width for shapes

int main() {
    Shapes shapes;
    int choice, height, width;

    do {
        choice = getUserChoice(); // call fxn for getUserChoice

        switch(choice) {
            case 1: // draw triangle
                std::cout << "Enter the height of your triangle: ";
                std::cin >> height;
                // check that height is a positive integer and not stupid high
                if (height > 0 && height <= MAX_HEIGHT) {
                    shapes.drawTriangle(height);
                } else {
                    std::cout << "ERROR: Height must be between 1 and " << MAX_HEIGHT << ".\n";
                }
                break;
            case 2: // draw inverted triangle
                std::cout << "Enter the height of your inverted triangle: ";
                std::cin >> height;
                // check that height is a positive integer and not stupid high
                if (height > 0 && height <= MAX_HEIGHT) {
                    shapes.drawInvertedTriangle(height);
                } else {
                    std::cout << "ERROR: Height must be between 1 and " << MAX_HEIGHT << ".\n";
                }
                break;
            case 3: // draw rectangle
                std::cout << "Enter the width and height (separated by a space) of your rectangle: ";
                std::cin >> width >> height;
                // check that height is a positive integer and not stupid high
                if (width > 0 && width <= MAX_WIDTH && height > 0 && height <= MAX_HEIGHT) {
                    shapes.drawRectangle(width, height);
                } else {
                    std::cout << "ERROR: Width and height must be between 1 and " << MAX_WIDTH << " for width, and 1 and " << MAX_HEIGHT << " for height.\n";
                }
                break;
            case 4: // draw bow tie with square in center
                std::cout << "Enter the height of your bow tie (must be an odd number): ";
                std::cin >> height;
                if (height > 0 && height <= MAX_HEIGHT && height % 2 != 0) {
                    shapes.drawBowTie(height);
                } else {
                    std::cout << "ERROR: Height must be an odd number between 1 and " << MAX_HEIGHT << ".\n";
                }
                break;
            case 5: // exit
                std::cout << "Exiting...\n";
                break;
            default: // catching strays
                std::cout << "Invalid choice! Please choose again.\n";
        }
    } while (choice != 5);

    return 0;
}

// fxn definition for getting user's choice from menu
int getUserChoice(){
    int choice;

    std::cout << "Menu:\n";
    std::cout << "1. Triangle\n";
    std::cout << "2. Inverted triangle\n";
    std::cout << "3. Rectangle\n";
    std::cout << "4. Bow Tie\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    return choice;
}

Shapes::Shapes() {
    std::cout << "Program initialized, let's draw some shapes!\n";
}

// fxn definition for drawing a triangle
void Shapes::drawTriangle(int height) {
    for (int i = 1; i <= height; i++){
        for (int j = 1; j <= i; j++){
            std::cout << "*";
        }        
        std::cout << std::endl;
    }
}

// fxn definition for drawing an inverted triangle
void Shapes::drawInvertedTriangle(int height){
    for (int i = height; i >= 1; i--){
        for (int j = 1; j <= i; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

// fxn definition for drawing a rectangle
void Shapes::drawRectangle(int width, int height){
    for (int i = 1; i <= height; i++){
        for (int j = 1; j <= width; j++){
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

// fxn definition for drawing a bow tie
void Shapes::drawBowTie(int height){
    int mid = height / 2 + 1;
    int squareSize = 3; // defining small square's height in middle of bow tie

    // top half
    for (int i = 1; i < mid - squareSize / 2; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        for (int j = -1; j <= (height - 2 * i); j++) {
            std::cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    // center square
    for (int i = 0; i < squareSize; i++) {
        for (int j = 1; j <= mid - squareSize / 2; j++) {
            std::cout << "+";
        }
        for (int j = 1; j <= squareSize; j++) {
            std::cout << "+";
        }
        for (int j = 1; j <= mid - squareSize / 2; j++) {
            std::cout << "+";
        }
        std::cout << std::endl;
    }

    // bottom half
    for (int i = mid - squareSize / 2 - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        for (int j = -1; j <= (height - 2 * i); j++) {
            std::cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }   
}