// Circle.h

#pragma once

#include "Point.h"

class Circle: public Shape {

    private:

        Point center;
        double radius;
    
    public:

        Circle();
        Circle(Point center, double r);
        virtual ~Circle();

        virtual void show();
        virtual double get_area();
        virtual double get_perimeter();

};
