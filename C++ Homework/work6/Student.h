// Student.h
// by Paddi

#pragma once
#include <iostream>
class Student{
    
    private:
        std::string _num, _name;
        float _chi, _math, _eng;
        int _rating = 0, _level = 0;

    public:
        Student() {};
        Student(std::string num, std::string name, 
                float chi, float math, float eng);
        ~Student() {};        
        
        std::string get_num() {return _num;};
        float get_ave() {return (_chi+_math+_eng) / 3;};

        void set_rating(int rating) {_rating = rating;};
        void set_level(int level) {_level = level;};

        void show_info();

    friend class Teacher;
};