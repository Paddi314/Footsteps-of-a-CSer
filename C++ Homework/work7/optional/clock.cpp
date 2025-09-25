#include "clock.h"
#include <iostream>
#include <iomanip> // 用于setw

Clock::Clock(int hour, int minute, int second) {
    // 标准化时间（确保在合法范围内）
    _h = (hour % 24 + 24) % 24;
    _m = (minute % 60 + 60) % 60;
    _s = (second % 60 + 60) % 60;
}

void Clock::Show() const {
    std::cout << std::setw(2) << std::setfill('0') << _h << ":"
              << std::setw(2) << std::setfill('0') << _m << ":"
              << std::setw(2) << std::setfill('0') << _s;
}

void Clock::Tick() {
    _s++;
    if (_s >= 60) {
        _s = 0;
        _m++;
        if (_m >= 60) {
            _m = 0;
            _h++;
            if (_h >= 24) _h = 0;
        }
    }
}

void Clock::Set(int h, int m, int s) {
    _h = (h % 24 + 24) % 24;
    _m = (m % 60 + 60) % 60;
    _s = (s % 60 + 60) % 60;
}

int Clock::Get_h() const{
    return _h;
}
int Clock::Get_m() const{
    return _m;
}
int Clock::Get_s() const{
    return _s;
}