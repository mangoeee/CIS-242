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

int main() {

    return 0;
}