// FamElec.h
// by Paddi

#pragma once
#include <iostream>
using namespace std;

class FamElec {

    private:
        string _name;           
        string _room;           
        int _elec[12];          
        
        static int _step_amount;  // 阶梯电量阈值（2880度）
        static double _basic_price;    // 基础电价（0.4884元/度）
        static double _step_price;// 阶梯电价（0.5383元/度）
    
    public:
        FamElec() {}
        FamElec(string name, string room, int* elec); 
        ~FamElec() {}
        
        void Show() const;      
        string getName() const { return _name; }
        string getRoom() const { return _room; }
        
        friend double TotalElec(const FamElec& fam);    
        friend double AveElec(const FamElec& fam);     
        friend double Cost(const FamElec& fam);         

};
    
