#pragma once
#include "Student.h"
#include "Employee.h"

class stuEmployee : public Student, public Employee {
public:
    stuEmployee(); // Default constructor
    stuEmployee(const std::string& name, int age, 
               const std::string& major, const std::string& student_id,
               const std::string& department, const std::string& employee_id);
    
    // Display function
    virtual void Display() const override;
    
    // Destructor
    virtual ~stuEmployee();
};