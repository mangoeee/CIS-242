#pragma once
#include <iostream>

class Shapes {
    public:
        Shapes();

        void drawTriangle(int height);
        void drawInvertedTriangle(int height);
        void drawRectangle(int width, int height);
};

int getUserChoice(); // fxn declared to get user's choice