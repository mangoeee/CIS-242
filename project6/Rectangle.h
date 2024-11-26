#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "BasicShape.h"
#include <stdexcept>

class Rectangle : public BasicShape {
    private:
        long width;
        long length;
    
    public:
        Rectangle(long w, long l) : width(w), length(l) {
            if (length <= 0 || width <= 0) {
                throw std::invalid_argument("The area of a geometric shape is always positive, so length and width must be a positive value.");
            }
            calcArea();
        }
        long getWidth() {
            return width;
        }
        long getLength() {
            return length;
        }
        void calcArea() override {
            setArea(static_cast<double>(width) * static_cast<double>(length)); // need consistent types, setArea is of double type
        }
};

#endif