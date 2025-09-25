# C++ Shape Assignment

## 1.1 Shape Class Implementation

This assignment involves implementing a shape class hierarchy with the following requirements:

- Create a base `Shape` class
- Implement specific shape objects that inherit from it
- Each shape should be able to calculate its area and perimeter

## 1.2 Base Shape Class Definition

```cpp
class Shape {
public:
    Shape() {}
    virtual ~Shape() {}
    
    void GetInfo() const {
        cout << "This is a ";
        Show();
        cout << endl << "Area is " << Area();
        cout << endl << "Perimeter is " << Perimeter();
    }
    
    virtual void Show() = 0;
    virtual double Area() = 0;
    virtual double Perimeter() = 0;
};
```

## 1.3 Main Program Requirements

The program should:
- Read shape data from the "shape.xlsx" file
- Create shape objects according to the data
- Store pointers to shape objects in an array
- Display information (type, area, perimeter) for each shape

## 1.4 Excel Data File Information

The input file "shape.xlsx" (Excel file) contains data for 20 different shapes. The first row contains headers, and each subsequent row contains data for one shape, including:
- Shape type
- Coordinates or dimensions

An alternative CSV format (shape.csv) is also provided for the same data.

### Converting CSV to TXT Format

Use the following code to convert CSV to TXT:

```cpp
ifstream infile("shape.csv");
ofstream outfile("shape.txt");
char temp[50] = { 0 };
char outtemp[50] = { 0 };

do {
    for (int i = 0; i < 50; i++) {
        temp[i] = 0;
        outtemp[i] = 0;
    }
    
    infile.getline(temp, 49);
    
    for (int i = 0; i < strlen(temp); i++)
        if (temp[i] != ',')
            outtemp[i] = temp[i];
        else
            outtemp[i] = ' ';
            
    outfile << outtemp << endl;
} while (!infile.eof());

infile.close();
outfile.close();
```

Remember to close the file streams after use.

## 1.5 Expected Output

The program should generate output like this:

```
Shape 1:
This is a Circle at (0, 0) with radius 3.5
Area is 38.465
Perimeter is 21.98

Shape 2:
This is a Circle at (2, 1) with radius 2
Area is 12.56
Perimeter is 12.56

...

Shape 20:
This is a Triangle at (0, 0), (3, 0), (0, 4)
Area is 6
Perimeter is 12

Total Area: 777.992
Total Perimeter: 415.034
```

## 1.6 Shape Array Implementation

Use the following approach to create an array of shape pointers:

```cpp
Shape **arrayShape;
arrayShape = new Shape*[x]; // where x is the number of shapes
```

## 1.7 Memory Management

Remember to properly free memory when done:

```cpp
if (arrayShape) {
    delete[] arrayShape;
    arrayShape = NULL;
}
```

## 1.8 Shape Class Hierarchy

Implement the following shape classes:

### Circle Class
- Inherits from Shape
- Properties:
  - Center point (x, y)
  - Radius
- Must implement:
  - Constructor/destructor
  - Show() method
  - Area() method
  - Perimeter() method

### Rectangle Class
- Inherits from Shape
- Properties:
  - Width
  - Height
- Must implement:
  - Constructor/destructor
  - Show() method
  - Area() method
  - Perimeter() method

### Triangle Class
- Inherits from Shape
- Properties:
  - Three vertices (points)
- Must implement:
  - Constructor/destructor
  - Show() method
  - Area() method
  - Perimeter() method

### Additional Requirements
- All shape classes should properly handle memory allocation and deallocation
- The program should calculate and display the total area and perimeter of all shapes
