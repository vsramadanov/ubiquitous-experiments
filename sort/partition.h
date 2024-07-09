#pragma once

#include <utility>

template <typename T>
int partition(T* arr, int len) {
    int lo    = 0;
    int hi    = 1;
    T   pivot = arr[0];
    for (; hi < len; hi++) {
        if (arr[hi] <= pivot) {
            std::swap(arr[++lo], arr[hi]);
        }
    };
    std::swap(arr[lo], arr[0]);
    return lo;
};
