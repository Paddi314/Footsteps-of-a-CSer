// Point.h

#pragma once

#include "Shape.h"

class Point: public Shape {
    
    private:

        double x;
        double y;
    
    public:

        Point();
        Point(double x, double y);
        virtual ~Point();
        
        virtual void show();
        virtual double get_area();
        virtual double get_perimeter();
        
        // Accessor methods
        double get_x() const;
        double get_y() const;

};