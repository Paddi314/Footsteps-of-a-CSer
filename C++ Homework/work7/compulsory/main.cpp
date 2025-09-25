// work7_main.cpp
// by Paddi

#include "work7.h"
#include <cstdlib>
using namespace std;

void Conversion();
void Subtraction();
void End();

int main(){
    char choice;
    do {
        cout << "Conversion / Subtraction / End : ";
        cin >> choice;
        
        switch (choice) {
            case 'c':
            case 'C':
                Conversion();
                break;

            case 's':
            case 'S':
                Subtraction();
                break;

            case 'e':
            case 'E':
                End();
                break;

            default:
                cout << "Please input 'c', 's', or 'e'!\n";
                continue;
        }
        cout << '\n';
    } while (true);

    return 0;
}

void Conversion() {
    string city1, city2;
    int hour = 0, minute = 0, second = 0;
    
    cout << "Input City: ";
    cin >> city1;
    cout << "Input hour minute second: ";
    cin >> hour >> minute >> second;
    cout << "Input Conversion City: ";
    cin >> city2;

    // Create WorldClock objects using improved constructors
    WorldClock world_clock1(CITY_ABBR_TO_ENUM[city1], hour, minute, second);
    WorldClock world_clock2;
    world_clock2.Set(CITY_ABBR_TO_ENUM[city2], world_clock1);

    cout << "Time is " << world_clock1.Get()
         << '\n' << world_clock2.Get() << '\n';
}

void Subtraction() {
    string city1, city2;
    int hour1 = 0, minute1 = 0, second1 = 0;
    int hour2 = 0, minute2 = 0, second2 = 0;
    
    cout << "Input City: ";
    cin >> city1;
    cout << "Input hour minute second: ";
    cin >> hour1 >> minute1 >> second1;
    cout << "Input City: ";
    cin >> city2;
    cout << "Input hour minute second: ";
    cin >> hour2 >> minute2 >> second2;

    // Create WorldClock objects using improved constructors
    WorldClock world_clock1(CITY_ABBR_TO_ENUM[city1], hour1, minute1, second1);
    WorldClock world_clock2(CITY_ABBR_TO_ENUM[city2], hour2, minute2, second2);

    WorldClock sub_clock = world_clock1.Sub(world_clock2);
    cout << world_clock1.Get() << " - " << world_clock2.Get() 
         << " = " << sub_clock.Get() << '\n';
}

void End() {
    cout << "Byebye~" << endl;
    exit(0);
}