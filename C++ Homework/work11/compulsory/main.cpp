// main.cpp

#include "bubble_sort.h"

void test01() {
    int nums[4] {1, 3, 2, 4};
    bubble_sort<int>(nums, 4);
    print_array(nums, 4);
}

void test02() {
    char chs[4] {'a', 'd', 'c', 'b'};
    bubble_sort<char>(chs, 4);
    print_array(chs, 4);
}

void test03() {
    std::string strs[4] {"Weslie", "Paddi", "Sparky", "Wolfy"};
    bubble_sort<std::string>(strs, 4);
    print_array(strs, 4);
}

int main() {

    test01();
    test02();
    test03();

    return 0;
}