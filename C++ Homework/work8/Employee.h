#pragma once
#include "Person.h"

class Employee : virtual public Person {
protected:  // Changed from private to protected for access in stuEmployee
    std::string department;
    std::string employee_id;

public:
    Employee(); // Default constructor
    Employee(const std::string& name, int age, const std::string& department, const std::string& employee_id);
    
    // Setter functions
    void SetDepartment(const std::string& department);
    void SetEmployeeId(const std::string& employee_id);
    
    // Display function
    virtual void Display() const override;
    
    // Destructor
    virtual ~Employee();
};