// compulsory.cpp
// by Paddi

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
using namespace std;

template <typename Container>
int josephus(int n, int m) {

    Container knights(n);
    for (auto ite=knights.begin(); ite!=knights.end(); ite++) {
        static int i = 1;
        *ite = i;
        i++;
    }   

    auto cur = knights.begin();
    while (knights.size() > 1) {

        for (int i=0; i<m; i++) {
            cur++;
            if (cur == knights.end()) {
                cur = knights.begin();
            }
        }

        cur = knights.erase(cur);
        if (cur == knights.end()) {
            cur = knights.begin();
        }

    }

    return *knights.begin();
}

template <typename Container>
void measure_josephus(int n, int m, const std::string& container_name) {
    auto start = std::chrono::high_resolution_clock::now();
    int result = josephus<Container>(n, m);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << container_name << " time: " << elapsed.count() << "s\n";
}

int main() {

    int n = 100000, m = 5;
    cout << "n: " << n << "  m: " << m << "\n";
    measure_josephus<vector<int>>(n, m, "vector<int>");
    measure_josephus<list<int>>(n, m, "list<int>");

    return 0;
}