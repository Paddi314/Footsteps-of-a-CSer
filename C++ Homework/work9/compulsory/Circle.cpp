// Circle.cpp
#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

Circle::Circle() : center(), radius(0) {
}

Circle::Circle(Point center, double r) : center(center), radius(r) {
}

Circle::~Circle() {
}

void Circle::show() {
    cout << "Circle at (";
    center.show();
    cout << ") with radius " << radius;
}

double Circle::get_area() {
    return M_PI * radius * radius;
}

double Circle::get_perimeter() {
    return 2 * M_PI * radius;
}
