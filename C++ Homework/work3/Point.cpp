//Point.cpp
//by Paddi

#include "Point.h"
#include <cmath>

void Point::set_x(float x) {_x = x;}

void Point::set_y(float y) {_y = y;}

float Point::get_x() const {return _x;}

float Point::get_y() const {return _y;}

bool is_triangle(const Point p[3]){
    
    float area = (p[1]._x - p[0]._x) * (p[2]._y - p[0]._y) 
               - (p[2]._x - p[0]._x) * (p[1]._y - p[0]._y);
    
    return (fabs(area) > 1e-6); 

}
float get_dist_square(const Point& p1, const Point& p2){
    
    double dx, dy;
    dx = p1._x - p2._x;
    dy = p1._y - p2._y;
    return (dx * dx + dy * dy);

}