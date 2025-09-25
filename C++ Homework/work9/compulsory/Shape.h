// Shape.h

#pragma once

class Shape {

    public:

        Shape() {}
        virtual ~Shape() {}

        virtual void show() = 0;
        virtual double get_area() = 0;
        virtual double get_perimeter() = 0;     

        void display_info() const;   

};