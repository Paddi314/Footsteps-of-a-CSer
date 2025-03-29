//Sporter.h
//by Paddi (Github: Paddi314)

#pragma once

#include <iostream>
using namespace std;

class Sporter{

    private:
        string _name;
        string _number;
        char _gender; 
        //'m' means male, and 'f' means female.
        double _second = 0;

    public:
        Sporter(string name="xxx", string num="00000",
            char gen='m', double score=0);
        double GetSecond() const;
        void Show() const;
        friend Sporter FastSporter(Sporter* s, int size);
};

