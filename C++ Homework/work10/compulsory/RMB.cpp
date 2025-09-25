// RMB.cpp

#include "RMB.h"
#include <cmath>

RMB RMB::operator+(const RMB& money) {
    RMB res;
    
    // Convert to total fen
    int this_total = (_sign == '+' ? 1 : -1) * (_yuan * 100 + _jiao * 10 + _fen);
    int money_total = (money._sign == '+' ? 1 : -1) * (money._yuan * 100 + money._jiao * 10 + money._fen);
    int result_total = this_total + money_total;
    
    // Set sign based on result
    res._sign = (result_total >= 0) ? '+' : '-';
    
    // Convert back from total fen
    result_total = std::abs(result_total);
    res._yuan = result_total / 100;
    result_total %= 100;
    res._jiao = result_total / 10;
    res._fen = result_total % 10;
    
    return res;
};

RMB RMB::operator-(const RMB& money) {
    RMB res;
    
    // Convert to total fen
    int this_total = (_sign == '+' ? 1 : -1) * (_yuan * 100 + _jiao * 10 + _fen);
    int money_total = (money._sign == '+' ? 1 : -1) * (money._yuan * 100 + money._jiao * 10 + money._fen);
    int result_total = this_total - money_total;
    
    // Set sign based on result
    res._sign = (result_total >= 0) ? '+' : '-';
    
    // Convert back from total fen
    result_total = std::abs(result_total);
    res._yuan = result_total / 100;
    result_total %= 100;
    res._jiao = result_total / 10;
    res._fen = result_total % 10;
    
    return res;
};

RMB& RMB::operator++() {
    int total = (_sign == '+' ? 1 : -1) * (_yuan * 100 + _jiao * 10 + _fen);
    total++;
    
    _sign = (total >= 0) ? '+' : '-';
    total = std::abs(total);
    _yuan = total / 100;
    total %= 100;
    _jiao = total / 10;
    _fen = total % 10;
    
    return *this;
};

RMB RMB::operator++(int) {
    RMB temp = *this;
    
    int total = (_sign == '+' ? 1 : -1) * (_yuan * 100 + _jiao * 10 + _fen);
    total++;
    
    _sign = (total >= 0) ? '+' : '-';
    total = std::abs(total);
    _yuan = total / 100;
    total %= 100;
    _jiao = total / 10;
    _fen = total % 10;
    
    return temp;
};

RMB& operator--(RMB& money) {
    int total = (money._sign == '+' ? 1 : -1) * (money._yuan * 100 + money._jiao * 10 + money._fen);
    total--;
    
    money._sign = (total >= 0) ? '+' : '-';
    total = std::abs(total);
    money._yuan = total / 100;
    total %= 100;
    money._jiao = total / 10;
    money._fen = total % 10;
    
    return money;
};

RMB operator--(RMB& money, int) {
    RMB temp = money;
    
    int total = (money._sign == '+' ? 1 : -1) * (money._yuan * 100 + money._jiao * 10 + money._fen);
    total--;
    
    money._sign = (total >= 0) ? '+' : '-';
    total = std::abs(total);
    money._yuan = total / 100;
    total %= 100;
    money._jiao = total / 10;
    money._fen = total % 10;
    
    return temp;
};

std::istream& operator>>(std::istream& in, RMB& money) {
    in >> money._sign >> money._yuan >> money._jiao >> money._fen;
    return in;
};

std::ostream& operator<<(std::ostream& out, RMB& money) {
    out << "(" << money._sign << " "
        << money._yuan << " yuan " 
        << money._jiao << " jiao " 
        << money._fen << " fen)";
    return out;
};

void RMB::standard() {
    // Convert values to total fen for easier calculation
    int total_fen = _yuan * 100 + _jiao * 10 + _fen;
    
    // If total is zero, make sign positive
    if (total_fen == 0) {
        _sign = '+';
        _yuan = 0;
        _jiao = 0;
        _fen = 0;
        return;
    }
    
    // Determine sign
    bool is_negative = (_sign == '-' && total_fen > 0) || 
                       (_sign != '-' && total_fen < 0);
    _sign = is_negative ? '-' : '+';
    
    // Use absolute value for calculations
    total_fen = std::abs(total_fen);
    
    // Calculate yuan, jiao, fen
    _yuan = total_fen / 100;
    total_fen %= 100;
    _jiao = total_fen / 10;
    _fen = total_fen % 10;
};
