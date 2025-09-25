// work5_main.cpp
// by Paddi

// Compile with FamElec.cpp 

#include "FamElec.h"
#include <vector>

int main() {

    int n;
    cout<<"Enter the number of users: ";
    cin>>n;

    vector<FamElec> families;
    families.reserve(n);
    for (int i=0; i<n; i++) {
        
        string name;
        cout<<"Enter user's name: ";
        cin>>name;

        string room;
        cout<<"Enter room number: ";
        cin>>room;

        int elec[12];
        cout<<"Enter electricity consumption for each of the 12 months:\n";
        for (int j=0; j<12; j++) {
            cin>>elec[j];
        }

        families.emplace_back(name, room, elec);
    }

    cout<<"Their information about electricity consumption are as follows:\n";
    for (auto fam: families) {
        fam.Show();
    }

    return 0;
}