// Point.cpp
#include "Point.h"
#include <iostream>
#include <cmath>

using namespace std;

Point::Point() : x(0), y(0) {
}

Point::Point(double x, double y) : x(x), y(y) {
}

Point::~Point() {
}

void Point::show() {
    cout << "Point at (" << x << ", " << y << ")";
}

double Point::get_area() {
    return 0; // A point has no area
}

double Point::get_perimeter() {
    return 0; // A point has no perimeter
}

// Accessor methods to get x and y coordinates
double Point::get_x() const {
    return x;
}

double Point::get_y() const {
    return y;
}
