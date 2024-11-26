#pragma once
#ifndef BASICSHAPE_H
#define BASICSHAPE_H

class BasicShape {
    private:
        double area;

    protected:
        void setArea(double a) { // update private area, protected to restrict access externally
            area = a;
        }

    public:
        BasicShape() : area (0) {}
        virtual double getArea() const {
            return area;
        }
        virtual void calcArea() = 0; // pure virtual func
};

#endif