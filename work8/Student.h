#pragma once
#include "Person.h"

class Student : virtual public Person {
protected:  // Changed from private to protected for access in stuEmployee
    std::string major;
    std::string student_id;

public:
    Student(); // Default constructor
    Student(const std::string& name, int age, const std::string& major, const std::string& student_id);
    
    // Setter functions
    void SetMajor(const std::string& major);
    void SetStudentId(const std::string& student_id);
    
    // Display function
    virtual void Display() const override;
    
    // Destructor
    virtual ~Student();
};