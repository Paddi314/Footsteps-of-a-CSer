// Teacher.h
// by Paddi

#pragma once
#include <iostream>
#include <vector>
#include "Student.h"
class Teacher{
    
    private:
        std::string _num, _name;
    
    public:
        Teacher() {};
        Teacher(std::string num, std::string name);
        ~Teacher() {};
        
        void set_score(Student& stu, float math);  
        void calculate_rankings(std::vector<Student>& students);
};