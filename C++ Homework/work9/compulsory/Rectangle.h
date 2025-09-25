// Rectangle.h

#pragma once

#include "Point.h"

class Rectangle: public Shape {

    private:

        double width;
        double height;

    public:

        Rectangle();
        Rectangle(Point A, Point C);
        virtual ~Rectangle();

        virtual void show();
        virtual double get_area();
        virtual double get_perimeter();

};