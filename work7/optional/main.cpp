#include <iostream>
#include <iomanip>
#include <windows.h> 
#include "alarm.h"

using namespace std;

int main() {
    char choice = 'Y';
    while (choice == 'Y' || choice == 'y') {
        int h, m, s, ah, am, minutes, seconds;

        cout << "Initial time (hour minute second): ";
        cin >> h >> m >> s;

        cout << "Alarm time (hour minute): ";
        cin >> ah >> am;

        cout << "Counting time (minute second): ";
        cin >> minutes >> seconds;
        int totalSeconds = minutes * 60 + seconds;

        AlarmClock clock(h, m, s, ah, am);

        for (int i = 0; i <= totalSeconds; ++i) {

            // 显示时间（覆盖同一行）
            cout << "\r" << setw(8) << setfill(' ');
            clock.Show();
            cout.flush(); // 立即输出

            clock.Tick();
            clock.Alarm(); 
            Sleep(1000); // 暂停1秒
        }

        cout << "\nCounting over. Continue?(Y/N) ";
        cin >> choice;
    }

    cout << "Byebye~\n";
    return 0;
}