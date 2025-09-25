//work4_main.cpp
//by Paddi (Github: Paddi314)

#include <iostream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Fish.h"

int main(){

    //initialize random number
    srand(static_cast<unsigned int>(time(0)));
    
    //ask total number of fish
    int N;
    while (true){
        cout<<"How many fish dou you want to raise(N>5): __\b\b";
        cin>>N;
        if (cin.fail() || N <= 5){
            cout<<"Failed!";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }else{
            Fish::update_total(N);
            break;
        }
    }

    //initialize fish
    vector<Fish> fish(N);
    for (int i=0; i<N; i++){
        string name, color;
        cout<<"Set Fish "<<i+1<<"'s name and color:\n";
        cin>>name>>color;
        fish[i].set_name(name);
        fish[i].set_color(color);
    }

    cout<<"Start raising fish!\n";

    //main loop
    char c;
    
    do{

        static int day = 0;

        //1s means 1 day.
        this_thread::sleep_for(chrono::seconds(1));
        day++;
        
        //to pick out and broadcast today's lucky fish
        cout<<"Day "<<day<<": ";
        int lucky_fish_index = rand() % Fish::get_total(); 
        fish[lucky_fish_index].eat();

        //to update weights and last_eat_day
        fish[lucky_fish_index].gain_weight();
        fish[lucky_fish_index].set_last_eat_day(day);

        for (int i=0; i<fish.size() && i!=lucky_fish_index; i++){
            int days_hungry;
            days_hungry = day - fish[i].get_last_eat_day();
            if (days_hungry >= 5){
                fish[i].lose_weight();
            }
        }

        //to check if to die
        vector<int> to_die;
        for (int i=0; i<fish.size(); i++){
            if (fish[i].is_dead()){
                to_die.push_back(i);
            } 
        }
        sort(to_die.begin(), to_die.end(), greater<int>());
        for (int index: to_die){
            cout<<fish[index].get_name()<<" died.\n";
            fish.erase(fish.begin()+index);
        }

        //to check if all fish is died
        if (Fish::get_total() == 0){
            cout<<"All fish died!\n";
            break;
        }

        //to update total nubmer
        Fish::update_total(fish.size());

        //to broadcast current situation every 10 days
        if (day % 10 == 0){

            cout<<"There're "<<Fish::get_total()<<" fish alive now. Here's a glance.\n";
            cout<<"Name\tColor\tWeight\tLast day for eating\n";
            for (auto f: fish){
                cout<<f.get_name()<<'\t'
                    <<f.get_color()<<'\t'
                    <<f.get_weight()<<"g\t"
                    <<"Day "<<f.get_last_eat_day()
                    <<'\n';
            }
        }
        
        //to give a chance for ending
        cout<<"Do you want to end raising?(Y/N): ";
        cin>>c;

    } while (c == 'Y' || c == 'y');

    cout<<"Raising over. Welcome back.";

    return 0;
}