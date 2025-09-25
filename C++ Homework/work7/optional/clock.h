#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>

class Clock {
private:
    int _h, _m, _s; // 24小时制时间

public:
    Clock(int hour = 0, int minute = 0, int second = 0); // 默认构造函数
    void Show() const; // 显示时间
    void Tick(); // 时间前进1秒
    void Set(int h, int m, int s); // 设置时间
    int Get_h() const;
    int Get_m() const;
    int Get_s() const;
};

#endif // CLOCK_H