//work01.cpp
//2025.3.12
//by Paddi（Github name: Paddi314）


#include <iostream>
#include <string>

inline bool IsLeapYear(unsigned year);
unsigned DaysInMonth(unsigned year, unsigned month);
unsigned DaysInYear(unsigned year);

class Date{

    private:

        unsigned _year, _month, _day;

    public:

        void SetYear(unsigned year);
        void SetMonth(unsigned month);
        void SetDay(unsigned day);

        bool Valid();

        unsigned GetYear();
        unsigned GetMonth();
        unsigned GetDay();
        unsigned GetWeekday();

        void Display();
        void DisplayMonthCalendar();
        void DisplayYearCalendar();

};

void Date::SetYear(unsigned year){
    this->_year = year;
}

void Date::SetMonth(unsigned month){
    this->_month = month;
}

void Date::SetDay(unsigned day){
    this->_day = day;
}

bool Date::Valid(){

    if (GetYear() < 1900){
        return false;
    }

    if (this->_month == 0 || this->_month > 12){
        return false;
    }

    unsigned totalDays;
    totalDays = DaysInMonth(this->_year, this->_month);
    if (this->_day > totalDays|| this->_day == 0){
        return false;
    }

    return true;
}


unsigned Date::GetYear(){
    return this->_year;
}

unsigned Date::GetMonth(){
    return this->_month;
}

unsigned Date::GetDay(){
    return this->_day;
}

unsigned Date::GetWeekday(){

    //1900.1.1 is Monday.
    unsigned weekday = 0;  //1900.1.1
    for (int i=1900; i<this->_year; i++){
        weekday += DaysInYear(i);
    }
    for (int i=1; i<this->_month; i++){
        weekday += DaysInMonth(this->_year, i);
    }
    weekday += this->_day;
    weekday %= 7;

    return weekday;
}

void Date::Display(){
    std::cout<<this->_year
        <<this->_month
        <<this->_day
        <<std::endl;
}

void Date::DisplayMonthCalendar(){

    int weekday;
    weekday = (GetWeekday() - ((this->_day-1) % 7));
    weekday = (weekday+7) % 7;
    // to get the weekday of the 1st day of the month

    std::string days="";
    //to store days in calendar

    for (int i=0; i<weekday; i++){
        days += "     "; //five blanks
    }
    for (int i=1; i<10; i++){
        days = days + "    " + std::to_string(i);
    }
    for (int i=10; i<=DaysInMonth(this->_year, this->_month); i++){
        days = days + "   " + std::to_string(i);
    }

    std::cout<<"Calendar: \n";
    std::cout<<"             "<<this->_year
        <<"  "<<this->_month<<'\n';
    std::cout<<"  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n";
    //Each day occupies 5 spaces.

    int count = 0; //to control line breaks in output
    for (char c: days){
        std::cout<<c;
        count++;
        if (count == 35){
            std::cout<<'\n';
            count = 0;
        }
    }
}

inline bool IsLeapYear(unsigned year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

unsigned DaysInMonth(unsigned year, unsigned month){
    switch (month){
        case 2:
            return (IsLeapYear(year)? 29: 28);

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

    }
}

unsigned DaysInYear(unsigned year){
    return (IsLeapYear(year)? 366: 365);
}

int main(){

    char choice;
    do{
        Date date;
        unsigned temp;
        std::cout<<"Input year(year>=1900): ";
        std::cin>>temp;
        date.SetYear(temp);
        std::cout<<"Input month(1<=month<=12): ";
        std::cin>>temp;
        date.SetMonth(temp);
        std::cout<<"Input day(1<=day<=31): ";
        std::cin>>temp;
        date.SetDay(temp);

        if (date.Valid()){

            std::cout<<"Date is: "
                <<date.GetYear()<<'-'
                <<date.GetMonth()<<'-'
                <<date.GetDay()<<' ';

            std::string week[7] {
                "Sunday","Monday", "Tuesday", "Wednesday",
                "Thursday", "Friday", "Saturday"};
            std::cout<<week[date.GetWeekday()]<<'\n';

        }
        else{
            std::cout<<"Day error!\n";
            choice = 'Y';
            continue;
        }

        date.DisplayMonthCalendar();

        std::cout<<"\nContinue?(Y/N): ";
        std::cin>>choice;
    }while(choice == 'Y' || choice == 'y');

    std::cout<<"\nByebye!\n";

    return 0;
}
