#include "Person.h"

// Default constructor
Person::Person() : name(""), age(0) {
}

// Parameterized constructor
Person::Person(const std::string& name, int age) : name(name), age(age) {
}

// Setter functions
void Person::SetName(const std::string& name) {
    this->name = name;
}

void Person::SetAge(int age) {
    this->age = age;
}

// Display function
void Person::Display() const {
    std::cout << name << " " << age;
}

// Destructor
Person::~Person() {
}