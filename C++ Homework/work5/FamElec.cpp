// FamElec.cpp
// by Paddi

#include "FamElec.h"
#include <iomanip>
#include <cstring>

int FamElec::_step_amount = 2880;
double FamElec::_basic_price = 0.4884;
double FamElec::_step_price = 0.5383;

FamElec::FamElec(std::string name, std::string room, int* elec)
    : _name(std::move(name)), _room(std::move(room)) {
    std::memcpy(_elec, elec, sizeof(int) * 12);
}

void FamElec::Show() const {

    cout<<"Name: "<<_name<<'\n';
    cout<<"Room: "<<_room<<'\n';

    cout<<"12 months of Electricity consumption:\n";
    for (int i=0; i<6; i++) {
        cout<<_elec[i]<<' ';
    }
    cout<<'\n';
    for (int i=6; i<12; i++) {
        cout<<_elec[i]<<' ';
    }

    cout<<'\n';

    cout<<std::fixed<<std::setprecision(2);
    cout<<"Average monthly electricy consumption: "<<AveElec(*this)<<'\n';
    cout<<"Anuual electricy consumption: "<<TotalElec(*this)<<'\n';
    cout<<"Annual eletricty fee: "<<Cost(*this)<<'\n';
}

double TotalElec(const FamElec& fam) {
    
    double sum = 0;
    for (int i=0; i<12; i++) {
        sum += fam._elec[i];
    }
    return sum;
}

double AveElec(const FamElec& fam) {
    return TotalElec(fam) / 12.0;
}

double Cost(const FamElec& fam) {
    
    double total_elec = TotalElec(fam);
    auto a = FamElec::_step_amount;
    auto b = FamElec::_basic_price;
    auto c = FamElec::_step_price; 
    if (total_elec <= a) {
        return (total_elec * b);
    }
    else{
        return (c*total_elec - a*(c-b));
    }
}

