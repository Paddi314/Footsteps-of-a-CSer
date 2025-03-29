//work3_main.cpp
//by Paddi (Github: Paddi314)
//Compile with Point.cpp, Triangle.cpp

#include <fstream>
#include "Point.h"
#include "Triangle.h"
using namespace std;

void test01();
void process(Point p[3]);


void test01(){

    ifstream in("triangle.txt");
    if (in.is_open()){
        float x1, y1, x2, y2, x3, y3;
        while (in>>x1>>y1>>x2>>y2>>x3>>y3){
            Point arrTriangle[3];
            arrTriangle[0].set_x(x1);
            arrTriangle[0].set_y(y1);
            arrTriangle[1].set_x(x2);
            arrTriangle[1].set_y(y2);
            arrTriangle[2].set_x(x3);
            arrTriangle[2].set_y(y3);
            process(arrTriangle);
            cout<<"\n";
        }
    }
    else{
        cout<<"File not open!\n";
    }
}

void process(Point p[3]){

    if (is_triangle(p)){
        cout<<p[0].get_x()<<" "<<p[0].get_y()<<" "
            <<p[1].get_x()<<" "<<p[1].get_y()<<" "
            <<p[2].get_x()<<" "<<p[2].get_y()<<" "
            <<" can be a triangle.\n";
        
        Triangle tri(p);
        tri.print_points();
        tri.print_type();
        cout<<"area = "<<tri.get_area();
        cout<<"\nperimeter = "<<tri.get_perimeter();
        cout<<"\n";
    }
    else{
        cout<<p[0].get_x()<<" "<<p[0].get_y()<<" "
            <<p[1].get_x()<<" "<<p[1].get_y()<<" "
            <<p[2].get_x()<<" "<<p[2].get_y()<<" "
            <<" cannot be a triangle!\n";
    }

}

int main(){
    test01();
    cout<<"\nBye.";
    return 0;
}
