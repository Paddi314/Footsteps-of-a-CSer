#include "alarm.h"
#include <iostream>

AlarmClock::AlarmClock(int h, int m, int s, int ah, int am)
    : Clock(h, m, s) {
    // 初始化闹铃时间
    _alarmHour = (ah % 24 + 24) % 24;
    _alarmMinute = (am % 60 + 60) % 60;
}

void AlarmClock::SetAlarmTime(int h, int m) {
    _alarmHour = (h % 24 + 24) % 24;
    _alarmMinute = (m % 60 + 60) % 60;
}

void AlarmClock::Alarm() const {
    if (Get_h() == _alarmHour && Get_m() == _alarmMinute) {
        std::cout << "\a\a\a";
    }
}