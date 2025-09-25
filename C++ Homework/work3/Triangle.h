//Triangle.h
//by Paddi

#pragma once

#include "Point.h"

class Triangle{

    private:
        Point _p[3];
    
    public:
        Triangle() = default;
        Triangle(Point p[3]);
        ~Triangle() = default;

        void calculate_edges_square(double edges_square[3]) const;
        void print_points() const;
        void print_type() const;
        float get_area() const;
        float get_perimeter() const;
        
};