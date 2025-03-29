//Sporter.cpp
//by Paddi (Github: Paddi314)

#include "Sporter.h"

Sporter::Sporter(string name, string num,
    char gen, double score):
    _name(name), _number(num), 
    _gender(gen), _second(score)
{
};

double Sporter::GetSecond() const{
    return _second;
}

void Sporter::Show() const{
    cout<<"name: "<<_name;
    cout<<"\nnumber: "<<_number;
    if (_gender == 'm'){
        cout<<"\ngender: Male";
    }
    else{
        cout<<"\ngender: Female";
    }
    cout<<"\nsecond: "<<_second<<'\n';
}

Sporter FastSporter(Sporter* s, int size){
    Sporter* fast = s;
    for (Sporter* p=s+1; p<s+size; p++){
        if (p->_second<fast->_second){
            fast = p;
        }
    }
    return *fast;
}
