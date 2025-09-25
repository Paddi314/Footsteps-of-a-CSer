//Point.h
//by Paddi 

# pragma once

#include <iostream>

class Point{

    private:
        float _x, _y;
    
    public:
        void set_x(float x); 
        void set_y(float y);
        float get_x() const;
        float get_y() const;
        friend bool is_triangle(const Point p[3]);
        friend float get_dist_square(const Point& p1, const Point& p2);
        Point& operator=(const Point& other) = default;

    friend class Triangle;
};

