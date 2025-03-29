//School.cpp
//by Paddi (Github: Paddi314)

#include "school.h"
#include <iostream>
#include <cstring>

School::School(const char* name, const char* addr){
    if (name==nullptr){
        _name = nullptr;
    }
    else{
        _name = new char[strlen(name)+1];
        strcpy(_name, name);
    }

    if (addr==nullptr){
        _addr = nullptr;
    }
    else{
        _addr = new char[strlen(addr)+1];
        strcpy(_addr, addr);
    }

    std::cout<<"\nSchool Constructed!\n";
}

School::School(const School& s){
    this->_name = new char[strlen(s._name)+1];
    strcpy(this->_name, s._name);
    this->_addr = new char[strlen(s._addr)+1];
    strcpy(this->_addr, s._addr);
    std::cout<<"\nSchool copy constructed.\n";
}

School::~School(){
    delete _name;
    delete _addr;
    std::cout<<"\nSchool deconstructed." 
        "delete space of name and address.\n";
}

void School::Show() const{
    std::cout<<"\nSchool name: "<<_name
        <<"\nSchool address: "<<_addr<<'\n';
}