//bubble_sort.h

#pragma once

#include <iostream>

template <typename T>
void bubble_sort(T arr[], int size) {
    for (int i=0; i<size; i++) {
        for (int j=i; j<size-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}

template <typename T>
void print_array(T arr[], int size) {
    for (int i=0; i<size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << endl;
}