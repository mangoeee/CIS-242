#ifndef CIRCLE_H
#define CIRCLE_H

#pragma once
#include "BasicShape.h"
#include <cmath>
#include <stdexcept>

class Circle : public BasicShape {
    private:
        long centerX;
        long centerY;
        double radius;
    
    public:
        Circle(long x, long y, double r) : centerX(x), centerY(y), radius(r) {
            if (radius <= 0) {
                throw std::invalid_argument("The area of a geometric shape is always positive, so radius must be a positive value.");
            }
            calcArea();
        }  
        long getCenterX() const {
            return centerX;
        }
        long getCenterY() const {
            return centerY;
        }
        double getRadius() const {
            return radius;
        }
        void calcArea() override {
            setArea(3.14159 * (pow(radius, 2)));
        }
};

#endif