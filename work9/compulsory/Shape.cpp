// Shape.cpp
#include "Shape.h"
#include <iostream>

using namespace std;

void Shape::display_info() const {
    cout << "This is a ";
    const_cast<Shape*>(this)->show();
    cout << endl << "Area is " << const_cast<Shape*>(this)->get_area();
    cout << endl << "Perimeter is " << const_cast<Shape*>(this)->get_perimeter();
    cout << endl;
}
