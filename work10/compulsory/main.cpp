#include <iostream>
#include "RMB.h"

using namespace std;

int main() {
    char choice, repeat = 'Y';
    RMB rmb1, rmb2, result;
    
    while (repeat == 'Y' || repeat == 'y') {

        cout << "Please construct two RMB values:" << endl;
        cin >> rmb1 >> rmb2;
        rmb1.standard();
        rmb2.standard();
        
        bool validOperation = false;
        int times = 0;
        do {
            cout << "Please select operation (A:+/S:-/Q:++i/H:i++/J:--i/K:i--/): ";
            cin >> choice;
            validOperation = true;
            
            switch(choice) {
                case 'A':
                    result = rmb1 + rmb2;
                    cout << rmb1 << " + " << rmb2 << " = " << result << endl;
                    break;
                case 'S':
                    result = rmb1 - rmb2;
                    cout << rmb1 << " - " << rmb2 << " = " << result << endl;
                    break;
                case 'Q':
                    cout << "++" << rmb1 << " = ";
                    result = ++rmb1;
                    cout << result << endl;
                    break;
                case 'H': {
                    cout << " " << rmb1 << " ++ = ";
                    result = rmb1++;
                    cout << result << endl;
                    cout << "RMB1: " << rmb1 << endl;
                    break;
                }
                case 'J':
                    cout << "--" << rmb1 << " = ";
                    result = --rmb1;
                    cout << result << endl;
                    break;
                case 'K': {
                    cout << " " << rmb1 << " -- = ";
                    result = rmb1--;
                    cout << result << endl;
                    cout << "RMB1: " << rmb1 << endl;
                    break;
                }
                default:
                    cout << "Invalid choice! Please try again." << endl;
                    validOperation = false;
            }

            times++;

        } while (!validOperation || times < 6);
        
        cout << "Do you want to continue? (Y/N): ";
        cin >> repeat;
    }
    
    cout << "Press any key to continue..." << endl;
    
    return 0;
}