/*
    Emery Mangona
    CIS 242 Project 6

    Pure Abstract Base Class Project
        Define a pure abstract base class called BasicShape. The BasicShape class should have the following members:
            Private Member Variable:
                area, a double used to hold the shape's area.

            Public Member Functions:
                getArea. This function should return the value in the member variable area.
                calcArea. This function should be a pure virtual function.

        Next, define a class named Circle. It should be derived from the BasicShape class. It should have the following members:
            Private Member Variables:
                centerX, a long integer used to hold the x coordinate of the circle's center.
                centerY, a long integer used to hold the y coordinate of the circle's center.
                radius, a double used to hold the circle's radius.

            Public Member Functions:
                constructor. Accepts values for centerX, centerY, and radius. Should call the overridden calcArea function described below. 
                getCenterX. Returns the value in centerX.
                getCenterY. Returns the value in centerY.
                calcArea. calculates the area of the circle (area = 3.14159 radius * radius) and stores the result in the inherited member area.

        Next, define a class named Rectangle. It should be derived from the BasicShape class. It should have the following members:
            Private Member Variables:
                width, a long integer used to hold the width of the rectangle.
                length, a long integer used to hold the length of the rectangle.
            
            Public Member Functions:
                constructor. Accepts values for width and length. Should call the overridden calcArea function described below. 
                getWidth. Returns the value in width.
                getLength. Returns the value in length.
                calcArea. calculates the area of the circle (area = length * width) and stores the result in the inherited member area.
        
        After you have created these classes, create a driver program that defines a Circle object and a Rectangle object. Demonstrate that each object properly calculates and reports its area.

*/

#include <iostream>
#include "BasicShape.h"
#include "Circle.h"
#include "Rectangle.h"

int main() {
    double radius;
    long width, length;

    // input values for circle
    std::cout << "Enter the radius of your circle: ";
    std::cin >> radius;

    if (radius <= 0) {
        std::cerr << "Error: Radius must be a positive value.\n";
        return 1; 
    }

    // input values for rectangle
    std::cout << "Enter the width of your rectangle: ";
    std::cin >> width;
    std::cout << "Enter the length of your rectangle: ";
    std::cin >> length;

    // create circle obj
    Circle circle(0, 0, radius); // hard-coded center at origin since it doesn't affect anything

    // create rectangle obj
    Rectangle rectangle(width, length); // width = 4, length = 7

    // output results
    std::cout << "\nCircle:\n";
    std::cout << "\tCenter: (" << circle.getCenterX() << ", " << circle.getCenterY() << ")\n";
    std::cout << "\tRadius: " << circle.getRadius() << " units\n";
    std::cout << "\tArea = PI * r^2 = " << circle.getArea() << " square units\n\n";
    
    std::cout << "Rectangle:\n";
    std::cout << "\tWidth: " << rectangle.getWidth() << " units\n";
    std::cout << "\tLength: " << rectangle.getLength() << " units\n";
    std::cout << "\tArea = length * width = " << rectangle.getArea() << " square units\n\n";

    return 0;
}