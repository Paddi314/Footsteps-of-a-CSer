#include "stuEmployee.h"

// Default constructor
stuEmployee::stuEmployee() : Person(), Student(), Employee() {
}

// Parameterized constructor
stuEmployee::stuEmployee(const std::string& name, int age, 
                       const std::string& major, const std::string& student_id,
                       const std::string& department, const std::string& employee_id)
    : Person(name, age),  // Explicitly call the virtual base class constructor
      Student(name, age, major, student_id),
      Employee(name, age, department, employee_id) {
}

// Display function
void stuEmployee::Display() const {
    // Since both Student and Employee already call Person::Display(),
    // we need a custom implementation to avoid duplicate output

    // Display Person info first
    Person::Display();
    
    // Then display Student-specific info (without the Person part)
    std::cout << " " << Student::major << " " << Student::student_id;
    
    // Finally display Employee-specific info (without the Person part)
    std::cout << " " << Employee::department << " " << Employee::employee_id;
}

// Destructor
stuEmployee::~stuEmployee() {
}