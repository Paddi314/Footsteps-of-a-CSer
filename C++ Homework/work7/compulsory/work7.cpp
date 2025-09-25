// work7.cpp

#include "work7.h"
#include <string>
#include <iomanip>
#include <sstream>

std::unordered_map<std::string, City> CITY_ABBR_TO_ENUM = {
    {"ha", HAWAII},
    {"ak", ALASKA},
    {"la", LOS_ANGELES},
    {"ch", CHICAGO},
    {"ny", NEW_YORK},
    {"at", ATLANTIC},
    {"bz", BRAZIL},
    {"atm", ATLANTIC_M},
    {"ld", LONDON},
    {"bl", BERLIN},
    {"ca", CAIRO},
    {"mo", MOSCOW},
    {"nd", NEW_DELHI},
    {"bk", BANGKOK},
    {"bj", BEIJING},
    {"tk", TOKYO},
    {"sy", SYDNEY}
};

// ================ Clock Class Implementation ================

Clock::Clock(int h, int m, int s) : _h(h), _m(m), _s(s) {
    Standard();  
}

Clock::Clock(const Clock& c) : _h(c._h), _m(c._m), _s(c._s) {
}

Clock::~Clock() {
}

void Clock::Standard() {
    _m += _s / 60;  
    _s %= 60;       
    
    _h += _m / 60;  
    _m %= 60;      
    
    _h %= 24;     
    
    if (_s < 0) {
        _s += 60;
        _m--;
    }
    if (_m < 0) {
        _m += 60;
        _h--;
    }
    if (_h < 0) {
        _h += 24;
    }
}

void Clock::Set(int h, int m, int s) {
    _h = h;
    _m = m;
    _s = s;
    Standard();
}

int Clock::GetHour() const {
    return _h;
}

int Clock::GetMinute() const {
    return _m;
}

int Clock::GetSecond() const {
    return _s;
}

std::string Clock::Get() const {
    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << _h << ":"
        << std::setw(2) << std::setfill('0') << _m << ":"
        << std::setw(2) << std::setfill('0') << _s;
    return oss.str();
}

Clock Clock::Sub(const Clock& c) const {
    Clock sub(_h - c._h, _m - c._m, _s - c._s);
    return sub;
}

void Clock::SetTime(int h, int m, int s) {
    _h = h;
    _m = m;
    _s = s;
}

void Clock::GetTime(int& h, int& m, int& s) const {
    h = _h;
    m = _m;
    s = _s;
}

// ================ WorldClock Class Implementation ================

WorldClock::WorldClock(City city, int h, int m, int s) 
    : Clock(h, m, s), _city(city) {
}

WorldClock::WorldClock(const WorldClock& c) 
    : Clock(c), _city(c._city) {
}

WorldClock::~WorldClock() {
}

void WorldClock::Set(City city, int h, int m, int s) {
    _city = city;
    Clock::Set(h, m, s);  
}

void WorldClock::Set(City city, const WorldClock& c) {
    _city = city;
    
    // Get time from source clock
    int h, m, s;
    c.GetTime(h, m, s);
    
    // Calculate timezone difference
    int sourceOffset = std::stoi(CITY_DATA[c._city][1]);
    int targetOffset = std::stoi(CITY_DATA[_city][1]);
    
    // Apply timezone conversion
    h += (targetOffset - sourceOffset);
    
    // Use base class Set method
    Clock::Set(h, m, s);
}

City WorldClock::GetCity() const {
    return _city;
}

std::string WorldClock::Get() const {
    std::ostringstream oss;
    oss << CITY_DATA[_city][0] << " " << Clock::Get();  // Call base class Get method
    return oss.str();
}

WorldClock WorldClock::Sub(const WorldClock& c) const {
    // Convert both times to GMT for proper calculation
    int h1, m1, s1, h2, m2, s2;
    this->GetTime(h1, m1, s1);
    c.GetTime(h2, m2, s2);
    
    // Adjust for timezone differences
    int thisOffset = std::stoi(CITY_DATA[_city][1]);
    int otherOffset = std::stoi(CITY_DATA[c._city][1]);
    
    h1 -= thisOffset;   // Convert to GMT
    h2 -= otherOffset;  // Convert to GMT
    
    // Use base class Sub method by creating temporary Clock objects
    Clock thisClock(h1, m1, s1);
    Clock otherClock(h2, m2, s2);
    Clock result = thisClock.Sub(otherClock);
    
    // Create WorldClock result with this city's timezone
    WorldClock worldResult(_city, result.GetHour(), result.GetMinute(), result.GetSecond());
    
    return worldResult;
}