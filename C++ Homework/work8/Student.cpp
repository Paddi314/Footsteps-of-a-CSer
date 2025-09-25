#include "Student.h"

// Default constructor
Student::Student() : Person(), major(""), student_id("") {
}

// Parameterized constructor
Student::Student(const std::string& name, int age, const std::string& major, const std::string& student_id)
    : Person(name, age), major(major), student_id(student_id) {
}

// Setter functions
void Student::SetMajor(const std::string& major) {
    this->major = major;
}

void Student::SetStudentId(const std::string& student_id) {
    this->student_id = student_id;
}

// Display function
void Student::Display() const {
    Person::Display();
    std::cout << " " << major << " " << student_id;
}

// Destructor
Student::~Student() {
}