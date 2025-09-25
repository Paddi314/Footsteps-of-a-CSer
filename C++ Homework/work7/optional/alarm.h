#ifndef ALARM_H
#define ALARM_H

#include "clock.h"

class AlarmClock : public Clock {
private:
    int _alarmHour, _alarmMinute; // 闹铃时间（小时和分钟）

public:
    AlarmClock(int h = 0, int m = 0, int s = 0, 
               int ah = 0, int am = 0); // 构造函数
    void SetAlarmTime(int h, int m); // 设置闹铃时间
    void Alarm() const; // 检查是否触发闹铃
    
};

#endif // ALARM_H