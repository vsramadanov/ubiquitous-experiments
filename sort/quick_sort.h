#pragma once

#include <partition.h>

template <typename T>
void quick_sort(T* arr, int len) {
    if (len < 2) {
        return;
    }
    int mid = partition(arr, len);
    quick_sort(arr, mid);
    quick_sort(arr + mid + 1, len - mid - 1);
}
