// work7.h

#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

enum City {
    HAWAII,
    ALASKA,
    LOS_ANGELES,
    CHICAGO,
    NEW_YORK,
    ATLANTIC,
    BRAZIL,
    ATLANTIC_M,
    LONDON,
    BERLIN,
    CAIRO,
    MOSCOW,
    NEW_DELHI,
    BANGKOK,
    BEIJING,
    TOKYO,
    SYDNEY,
    CITY_COUNT
};

// {city's full name, time zone offset}
const std::string CITY_DATA[CITY_COUNT][2] = {
    {"Hawaii", "-10"},      
    {"Alaska", "-9"},       
    {"LosAngeles", "-8"},   
    {"Chicago", "-6"},      
    {"NewYork", "-5"},      
    {"Atlantic", "-4"},     
    {"Brazil", "-3"},       
    {"AtlanticM", "-2"},    
    {"London", "0"},        
    {"Berlin", "+1"},       
    {"Cario", "+2"},        
    {"Moscow", "+3"},       
    {"NewDelhi", "+5"},     
    {"Bangkok", "+7"},      
    {"Beijing", "+8"},      
    {"Tokyo", "+9"},        
    {"Sydney", "+10"}       
};

extern std::unordered_map<std::string, City> CITY_ABBR_TO_ENUM;

class Clock {

private:
    int _h, _m, _s;  

public:
    
    Clock(int h = 0, int m = 0, int s = 0);  
    Clock(const Clock& c);
    virtual ~Clock();  
    
    void Standard();

    void Set(int h, int m, int s);
    
    int GetHour() const;
    int GetMinute() const;
    int GetSecond() const;
    
    virtual std::string Get() const;

    Clock Sub(const Clock& c) const;
    
protected:

    void SetTime(int h, int m, int s);
    void GetTime(int& h, int& m, int& s) const;
};

class WorldClock: public Clock {

private:
    City _city;

public:

    WorldClock(City city = BEIJING, int h = 0, int m = 0, int s = 0);
    WorldClock(const WorldClock& c);
    virtual ~WorldClock();

    void Set(City city, int h, int m, int s);
    void Set(City city, const WorldClock& c);
    
    City GetCity() const;
    
    virtual std::string Get() const override;

    WorldClock Sub(const WorldClock& c) const;
};