//Fish.h
//by Paddi

#pragma once
using namespace std;

class Fish {

    private:
        
        string _name;
        string _color;
        int _weight = 100;
        int _last_eat_day = 0;
        static int _total;
    
    public:

        void eat() {cout<<_name<<" eats food today.\n";}

        string get_name() const {return _name;}
        string get_color() const {return _color;}
        int get_weight() const {return _weight;}
        int get_last_eat_day() const {return _last_eat_day;}
        static int get_total() {return _total;}

        void set_name(string name) {_name = name;}
        void set_color(string color) {_color = color;}
        void set_last_eat_day(int day = 0) {_last_eat_day = day;}
        void gain_weight() {_weight += 10;}
        void lose_weight() {_weight -= 10;}
        static void update_total(int num) {_total = num;}

        bool is_dead() {return _weight >= 300 || _weight <= 0;}
        
};

int Fish::_total = 0;