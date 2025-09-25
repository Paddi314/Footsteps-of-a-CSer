// RMB.h

#pragma once

#include <iostream>

class RMB {

    private:

        char _sign;
        int _yuan = 0, _jiao = 0, _fen = 0;

    public:

        RMB() {}
        RMB(int yuan, int jiao, int fen):
            _yuan(yuan), _jiao(jiao), _fen(fen) {}
        ~RMB() {}
        
        RMB operator+(const RMB& money);
        RMB operator-(const RMB& money);
        RMB& operator++(); // prefix increment
        RMB operator++(int); // postfix increment
        friend RMB& operator--(RMB& money);
        friend RMB operator--(RMB& money, int);

        friend std::istream& operator>>(std::istream& in, RMB& money);
        friend std::ostream& operator<<(std::ostream& out, RMB& money);

        void standard();

};