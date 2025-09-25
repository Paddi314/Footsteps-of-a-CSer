// Triangle.cpp
#include "Triangle.h"
#include "utils.h"
#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle() : A(), B(), C() {
}

Triangle::Triangle(Point A, Point B, Point C) : A(A), B(B), C(C) {
}

Triangle::~Triangle() {
}

void Triangle::show() {
    cout << "Triangle at (";
    A.show();
    cout << "), (";
    B.show();
    cout << "), (";
    C.show();
    cout << ")";
}

double Triangle::get_area() {
    // Using the formula: Area = 1/2 * |x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)|
    double x1 = A.get_x();
    double y1 = A.get_y();
    double x2 = B.get_x();
    double y2 = B.get_y();
    double x3 = C.get_x();
    double y3 = C.get_y();
    
    double area = 0.5 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return area;
}

double Triangle::get_perimeter() {
    // Calculate the length of each side and sum them
    double side1 = distance(A, B);
    double side2 = distance(B, C);
    double side3 = distance(C, A);
    
    return side1 + side2 + side3;
}
