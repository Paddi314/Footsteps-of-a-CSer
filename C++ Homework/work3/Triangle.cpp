//Triangle.cpp
//by Paddi

#include "Triangle.h"
#include <cmath>
#include <algorithm>

Triangle::Triangle(Point p[3]){

    for (int i=0; i<3; i++){
        this->_p[i] = p[i];
    }

}

void Triangle::calculate_edges_square(double edges_square[3]) const{
    
    edges_square[0] = get_dist_square(_p[0], _p[1]);
    edges_square[1] = get_dist_square(_p[1], _p[2]);
    edges_square[2] = get_dist_square(_p[2], _p[0]);

}

void Triangle::print_points() const{

    std::cout<<"Triangle( "
    <<_p[0]._x<<" "<<_p[0]._y<<" , "
    <<_p[1]._x<<" "<<_p[1]._y<<" , "
    <<_p[2]._x<<" "<<_p[2]._y<<" )\n";

}


void Triangle::print_type() const{

    double edges_square[3];
    calculate_edges_square(edges_square);
    std::sort(edges_square, edges_square+3);

    double a2, b2, c2;
    a2 = edges_square[0], b2 = edges_square[1], c2 = edges_square[2];
    const double eps = 1e-6;

    if (fabs(a2+b2-c2) < eps){
        std::cout<<"right triangle\n";
    }
    if (fabs(a2 - b2) < eps && fabs(b2 - c2) < eps) {
        std::cout << "equilateral triangle\n";
    } 
    
    else if (fabs(a2 - b2) < eps || fabs(b2 - c2) < eps || fabs(a2 - c2) < eps) {
        std::cout << "isosceles triangle\n";
    }

}

float Triangle::get_area() const{
    
    double edges_square[3];
    calculate_edges_square(edges_square);

    double a, b, c, p;
    a = sqrt(edges_square[0]);
    b = sqrt(edges_square[1]);
    c = sqrt(edges_square[2]);
    p = (a+b+c) / 2;
    return sqrt(p*(p-a)*(p-b)*(p-c)); 
}

float Triangle::get_perimeter() const{

    double edges_square[3];
    calculate_edges_square(edges_square);
    
    double a, b, c;
    a = sqrt(edges_square[0]);
    b = sqrt(edges_square[1]);
    c = sqrt(edges_square[2]);

    return a+b+c;
}

