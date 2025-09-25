// work6_main.cpp
// by Paddi

// Compile with Teacher.cpp and Student.cpp

#include <fstream>

#include <set>

#include <algorithm>
#include "Student.h"
#include "Teacher.h"
using namespace std;
const int SIZE = 20;

Teacher teacher("2006005", "Dequan Li");
vector<Student> students;

void step1(){

    // create teacher and students
    ifstream info("stu_info.txt");
    if (!info.is_open()){
        cout<<"Lack of students' information!";
        exit(1);
    }

    for (int i=0; i<SIZE; i++){
        string num, name;
        float chi, math, eng;
        info>>num>>name>>chi>>math>>eng;
        students.emplace_back(num, name, chi, math, eng);
    }
    
    info.close();
}

void step2(){
    // modify students' scores
    ifstream to_modify("scores_to_modify.txt");
    if (!to_modify.is_open()){
        cout<<"Lack of modification information!";
        exit(1);
    }

    string num;
    string name;
    float math;  
    while (to_modify>>num>>name>>math){
        for (auto& student: students){
            if (student.get_num() == num){
                teacher.set_score(student, math);
            }
        }
    }

    to_modify.close();
}

void step3(){
    // calculate rankings and evaluate scholarship level
    teacher.calculate_rankings(students); 
}

void step4(){
    // show whole infomation
    cout<<"Student number""\t""Name""\t\t"
        <<"Chinese""\t""Math""\t""English""\t""Average"
        <<"\t""Rating""\t""Scholarship level\n";
    for (int i=0; i<SIZE; i++){
        students[i].show_info();
    }
}

int main(){
    
    students.reserve(SIZE);

    step1();
    step2();
    step3();
    step4();

    return 0;
}