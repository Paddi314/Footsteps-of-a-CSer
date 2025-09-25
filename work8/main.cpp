#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "stuEmployee.h"

using namespace std;

int main() {
    char choice;
    string name, major, student_id, department, employee_id;
    int age;
    
    do {
        cout << "Test p--Person s--Student e--Employee v--StudentEmployee o--Test Over: ";
        cin >> choice;
        
        switch (choice) {
            case 'p': {
                // Test Person class
                cout << "Input person name: ";
                cin >> name;
                cout << "Input person age: ";
                cin >> age;
                
                Person person(name, age);
                cout << "输出: ";
                person.Display();
                cout << endl;
                break;
            }
            
            case 's': {
                // Test Student class
                cout << "Input student name: ";
                cin >> name;
                cout << "Input student age: ";
                cin >> age;
                cout << "Input student major: ";
                cin >> major;
                cout << "Input student id: ";
                cin >> student_id;
                
                Student student(name, age, major, student_id);
                cout << "输出: ";
                student.Display();
                cout << endl;
                break;
            }
            
            case 'e': {
                // Test Employee class
                cout << "Input employee name: ";
                cin >> name;
                cout << "Input employee age: ";
                cin >> age;
                cout << "Input employee department: ";
                cin >> department;
                cout << "Input employee id: ";
                cin >> employee_id;
                
                Employee employee(name, age, department, employee_id);
                cout << "输出: ";
                employee.Display();
                cout << endl;
                break;
            }
            
            case 'v': {
                // Test stuEmployee class
                cout << "Input student employee name: ";
                cin >> name;
                cout << "Input student employee age: ";
                cin >> age;
                cout << "Input student major: ";
                cin >> major;
                cout << "Input student id: ";
                cin >> student_id;
                cout << "Input employee department: ";
                cin >> department;
                cout << "Input employee id: ";
                cin >> employee_id;
                
                stuEmployee stuEmp(name, age, major, student_id, department, employee_id);
                cout << "输出: ";
                stuEmp.Display();
                cout << endl;
                break;
            }
            
            case 'o':
                cout << "Byebye~" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
    } while (choice != 'o');
    
    return 0;
}