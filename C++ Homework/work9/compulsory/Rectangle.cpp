// Rectangle.cpp
#include "Rectangle.h"
#include <iostream>
#include <cmath>

using namespace std;

Rectangle::Rectangle() : width(0), height(0) {
}

Rectangle::Rectangle(Point A, Point C) {
    // Calculate width and height based on the two points
    // A is the top-left point and C is the bottom-right point
    width = abs(C.get_x() - A.get_x());
    height = abs(C.get_y() - A.get_y());
}

Rectangle::~Rectangle() {
}

void Rectangle::show() {
    cout << "Rectangle with width " << width << " and height " << height;
}

double Rectangle::get_area() {
    return width * height;
}

double Rectangle::get_perimeter() {
    return 2 * (width + height);
}
