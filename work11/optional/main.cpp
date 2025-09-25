#include <iostream>
#include <string>
using namespace std;

// Step 1: Define different data types and Student class
int intVar = 10;
double doubleVar = 3.14;
char charVar = 'A';
string stringVar = "Hello";

class Student {
private:
    int studentID;
    string name;
    double grade;

public:
    // Constructor
    Student(int id = 0, string n = "", double g = 0.0) {
        studentID = id;
        name = n;
        grade = g;
    }
    
    // Getter methods
    int getID() const { return studentID; }
    string getName() const { return name; }
    double getGrade() const { return grade; }
    
    // Setter methods
    void setID(int id) { studentID = id; }
    void setName(string n) { name = n; }
    void setGrade(double g) { grade = g; }
    
    // Display student information
    void displayInfo() const {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
        cout << "------------------------" << endl;
    }
};

// Function to demonstrate variable operations and calculations
void demonstrateOperations() {
    cout << "=== Variable Demonstrations ===" << endl;
    cout << "Integer variable: " << intVar << endl;
    cout << "Double variable: " << doubleVar << endl;
    cout << "Character variable: " << charVar << endl;
    cout << "String variable: " << stringVar << endl;
    cout << endl;
    
    cout << "=== Mathematical Operations ===" << endl;
    
    // Example calculations similar to the ones in the document
    // 1 + 2 * 3   4 / 2 = 5
    int result1 = 1 + 2 * 3;
    double result2 = 4.0 / 2;
    cout << "1 + 2 * 3 = " << result1 << endl;
    cout << "4 / 2 = " << result2 << endl;
    
    // 2.5 * 5 + 7/2   1 = 15
    double result3 = 2.5 * 5 + 7.0/2 - 1;
    cout << "2.5 * 5 + 7/2 - 1 = " << result3 << endl;
    cout << endl;
}

// Function to demonstrate array operations and pointer usage
void demonstrateArraysAndPointers() {
    cout << "=== Array and Pointer Demonstrations ===" << endl;
    
    // Create an array of integers
    int numbers[] = {10203, 30201, 20, 30};
    int arraySize = sizeof(numbers) / sizeof(numbers[0]);
    
    cout << "Original array: ";
    for(int i = 0; i < arraySize; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    // Demonstrate pointer operations
    int* ptr = numbers;
    cout << "Using pointer to access array elements:" << endl;
    for(int i = 0; i < arraySize; i++) {
        cout << "Element " << i << ": " << *(ptr + i) << endl;
    }
    
    // Find maximum and minimum values
    int maxVal = numbers[0];
    int minVal = numbers[0];
    for(int i = 1; i < arraySize; i++) {
        if(numbers[i] > maxVal) maxVal = numbers[i];
        if(numbers[i] < minVal) minVal = numbers[i];
    }
    
    cout << "Maximum value in array: " << maxVal << endl;
    cout << "Minimum value in array: " << minVal << endl;
    cout << endl;
}

// Function to demonstrate Student class usage
void demonstrateStudentClass() {
    cout << "=== Student Class Demonstrations ===" << endl;
    
    // Create student objects
    Student student1(10203, "Alice Johnson", 85.5);
    Student student2(30201, "Bob Smith", 92.3);
    Student student3(20, "Charlie Brown", 78.9);
    Student student4(30, "Diana Wilson", 96.7);
    
    // Display student information
    cout << "Student Information:" << endl;
    student1.displayInfo();
    student2.displayInfo();
    student3.displayInfo();
    student4.displayInfo();
    
    // Demonstrate setter methods
    Student student5;
    student5.setID(12345);
    student5.setName("Eve Davis");
    student5.setGrade(88.4);
    
    cout << "New student created using setter methods:" << endl;
    student5.displayInfo();
}

// Function to demonstrate control structures
void demonstrateControlStructures() {
    cout << "=== Control Structure Demonstrations ===" << endl;
    
    // For loop demonstration
    cout << "Counting from 1 to 5:" << endl;
    for(int i = 1; i <= 5; i++) {
        cout << "Count: " << i << endl;
    }
    cout << endl;
    
    // While loop demonstration
    cout << "Countdown from 5:" << endl;
    int countdown = 5;
    while(countdown > 0) {
        cout << "T-minus " << countdown << endl;
        countdown--;
    }
    cout << "Blast off!" << endl << endl;
    
    // If-else demonstration
    int testScore = 85;
    cout << "Grade evaluation for score " << testScore << ": ";
    if(testScore >= 90) {
        cout << "Grade A - Excellent!" << endl;
    } else if(testScore >= 80) {
        cout << "Grade B - Good work!" << endl;
    } else if(testScore >= 70) {
        cout << "Grade C - Satisfactory" << endl;
    } else if(testScore >= 60) {
        cout << "Grade D - Needs improvement" << endl;
    } else {
        cout << "Grade F - Please see instructor" << endl;
    }
    cout << endl;
}

// Main function
int main() {
    cout << "========================================" << endl;
    cout << "    C++ Programming Assignment Demo    " << endl;
    cout << "========================================" << endl << endl;
    
    // Step 1: Demonstrate basic data types and operations
    demonstrateOperations();
    
    // Step 2: Demonstrate arrays and pointers
    demonstrateArraysAndPointers();
    
    // Demonstrate Student class
    demonstrateStudentClass();
    
    // Additional demonstrations
    demonstrateControlStructures();
    
    cout << "========================================" << endl;
    cout << "         Program completed!            " << endl;
    cout << "========================================" << endl;
    
    return 0;
}