#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;


void wordCountWithMultiset() {
    multiset<string> words;
    string word;
    
    cout << "Enter words (type QUIT to stop):" << endl;
    while (cin >> word && word != "QUIT") {

        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        words.insert(word);
        int count = words.count(word);
        
        cout << "\"" << word << "\" ";
        if (count > 1) {
            cout << "has appeared " << count << " times." << endl;
        } else {
            cout << "is new." << endl;
        }
    }
}


void wordCountWithMap() {
    map<string, int> wordCount;
    string word;
    
    cout << "Enter words (type QUIT to stop):" << endl;
    while (cin >> word && word != "QUIT") {

        transform(word.begin(), word.end(), word.begin(), ::tolower);
        
        int& count = wordCount[word]; 
        count++;
        
        cout << "\"" << word << "\" ";
        if (count > 1) {
            cout << "has appeared " << count << " times." << endl;
        } else {
            cout << "is new." << endl;
        }
    }
}

int main() {
    cout << "Choose implementation:" << endl;
    cout << "1. multiset" << endl;
    cout << "2. map" << endl;
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        wordCountWithMultiset();
    } else if (choice == 2) {
        wordCountWithMap();
    } else {
        cout << "Invalid choice." << endl;
    }
    
    return 0;
}