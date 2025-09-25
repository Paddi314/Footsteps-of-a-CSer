// Teacher.cpp
// by Paddi

#include "Teacher.h"
#include <map>

Teacher::Teacher(std::string num, std::string name):
_num(num), _name(name)
{
}

void Teacher::set_score(Student& stu, float math) 
{
    stu._math = math;
};

void Teacher::calculate_rankings(std::vector<Student>& students)
{
    std::map<float, int> ave_index;
    for (int i=0; i<students.size(); i++){
        float oppo_ave = (-1) * students[i].get_ave();
        ave_index.emplace(oppo_ave, i);
    }
    
    for (auto pair: ave_index){
        static int rating = 1;
        int i = pair.second;
        students[i].set_rating(rating);
        int level = (rating + 3) / 4;
        students[i].set_level(level);
        rating++;
    }
}