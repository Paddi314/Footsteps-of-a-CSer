#pragma once
#include <string>
#include <iostream>

class Person {
private:
    std::string name;
    int age;

public:
    Person(); // Default constructor
    Person(const std::string& name, int age); // Parameterized constructor
    
    // Setter functions
    void SetName(const std::string& name);
    void SetAge(int age);
    
    // Display function
    virtual void Display() const;
    
    // Destructor
    virtual ~Person();
};