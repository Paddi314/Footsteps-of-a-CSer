// Student.cpp
// by Paddi

#include "Student.h"
#include <iomanip>

Student::Student(std::string num, std::string name, 
    float chi, float math, float eng):
_num(num), _name(name), _chi(chi), _math(math), _eng(eng)
{
}

void Student::show_info(){
    std::cout<<_num<<"\t\t"<<_name<<"\t\t";
    std::cout<<std::fixed<<std::setprecision(1)
        <<_chi<<"\t"<<_math<<"\t"<<_eng<<"\t"<<(*this).get_ave();
    std::cout<<"\t"<<_rating<<"\t"<<_level<<"\n";
}