// main.cpp

#include <iostream>
#include <fstream>
#include <cstring>
//#include <vector>
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "utils.h"

using namespace std;

Shape **shapes;
int NUM;

// Fixed convert_file function
void convert_file() {
    ifstream infile("shape.csv");
    if (!infile.is_open()) {
        cerr << "Error: Could not open input file 'shape.csv'" << endl;
        return;
    }
    
    ofstream outfile("shape.txt");
    if (!outfile.is_open()) {
        cerr << "Error: Could not open output file 'shape.txt'" << endl;
        infile.close();
        return;
    }

    string line;
    int lineCount = 0;
    int shapeCount = 0;
    
    // Skip header line and count remaining data lines
    if (getline(infile, line)) {
        // Count lines to determine number of shapes
        while (getline(infile, line)) {
            shapeCount++;
        }
        
        // Reset file to beginning
        infile.clear();
        infile.seekg(0, ios::beg);
        
        // Write number of shapes as first line in output file
        outfile << shapeCount << endl;
        
        // Skip header line again
        getline(infile, line);
        
        // Process data lines
        while (getline(infile, line)) {
            // Replace commas with spaces
            for (size_t i = 0; i < line.length(); i++) {
                if (line[i] == ',') line[i] = ' ';
            }
            outfile << (lineCount + 1) << " " << line << endl;
            lineCount++;
        }
    }

    infile.close();
    outfile.close();
}

// Fixed create_objects function
void create_objects() {
    ifstream infile("shape.txt");
    if (!infile.is_open()) {
        cerr << "Error: Could not open shape.txt" << endl;
        return;
    }
    
    infile >> NUM;
    shapes = new Shape*[NUM];
    
    cout << "Number of shapes: " << NUM << endl;

    for (int i = 0; i < NUM; i++) {
        int index;
        string type;
        infile >> index >> index >> type;
        
        cout << "Processing shape " << index << " of type " << type << endl;

        if (type == "circle") {
            double x, y, r;
            infile >> x >> y >> r;
            Point center(x, y);
            shapes[i] = new Circle(center, r);
        }
        else if (type == "rectangle") {
            double x1, y1, x2, y2;
            infile >> x1 >> y1 >> x2 >> y2;
            Point A(x1, y1), C(x2, y2);
            shapes[i] = new Rectangle(A, C);
        }
        else if (type == "triangle") {
            double x1, y1, x2, y2, x3, y3;
            infile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            Point A(x1, y1), B(x2, y2), C(x3, y3);
            shapes[i] = new Triangle(A, B, C);
        }
        else {
            cerr << "Unknown shape type: " << type << endl;
            shapes[i] = nullptr;
        }
    }

    infile.close();

}

void display_all() {

    double total_area = 0;
    double total_perimeter = 0;

    for (int i=0; i<NUM; i++) {
        cout << "Shape "<< i+1 << ":\n";
        shapes[i]->display_info();
        total_area += shapes[i]->get_area();
        total_perimeter += shapes[i]->get_perimeter();
        cout << "\n";
    }
    cout << "Total Area: " << total_area << endl;
    cout << "Total Perimeter: " << total_perimeter << endl;

}

void clean_memory() {

    if (shapes) {
        delete[] shapes;
        shapes = NULL;
    }
    
}

// Modified test01 function with CSV debugging
void test01() {
    
    // Try to convert the file
    convert_file();
    cout << "File converted.\n";
    
    // Check if conversion was successful
    ifstream check("shape.txt");
    int num_shapes = 0;
    check >> num_shapes;
    check.close();
    
    if (num_shapes > 0) {
        create_objects();
        cout << "Objects created.\n";
        display_all();
    } else {
        cout << "No shapes to display! Check the CSV file." << endl;
    }
    
    clean_memory();
}

int main() {

    test01();

    return 0;

}