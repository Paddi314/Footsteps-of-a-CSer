// Triangle.h

#pragma once

#include "Point.h"

class Triangle: public Shape {

    private:

        Point A;
        Point B;
        Point C;
    
    public:

        Triangle();
        Triangle(Point A, Point B, Point C);
        virtual ~Triangle();

        virtual void show();
        virtual double get_area();
        virtual double get_perimeter();

};