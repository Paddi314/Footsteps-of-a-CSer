#include "Employee.h"

// Default constructor
Employee::Employee() : Person(), department(""), employee_id("") {
}

// Parameterized constructor
Employee::Employee(const std::string& name, int age, const std::string& department, const std::string& employee_id)
    : Person(name, age), department(department), employee_id(employee_id) {
}

// Setter functions
void Employee::SetDepartment(const std::string& department) {
    this->department = department;
}

void Employee::SetEmployeeId(const std::string& employee_id) {
    this->employee_id = employee_id;
}

// Display function
void Employee::Display() const {
    Person::Display();
    std::cout << " " << department << " " << employee_id;
}

// Destructor
Employee::~Employee() {
}