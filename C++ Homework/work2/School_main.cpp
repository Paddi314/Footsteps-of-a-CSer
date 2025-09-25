//School_main.cpp
//by Paddi (Github: Paddi314)

//Compile with School.cpp

#include "School.h"
#include "iostream"
using namespace std;

void test01(){

    char *name, *address;
    name = new char[50];
    address = new char[50];
    cout<<"Input school name: ";
    cin.getline(name, 50);
    cout<<"Input school address: ";
    cin.getline(address, 50);

    School myschool(name, address);
    School yourschool(myschool);

    cout<<"\nmyschool\n";
    myschool.Show();
    cout<<"\nyourschool\n";
    yourschool.Show();

    delete[] name;
    delete[] address;
}

int main(){

    test01();
    system("pause");

    return 0;
}