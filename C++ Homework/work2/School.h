//School.h
//by Paddi (Github: Paddi314)

# pragma once

class School{

    private:
        char* _name;
        char* _addr;
    
    public:
        School(const char* name, const char* addr);
        School(const School& s);
        ~School();
        void Show() const;
};
