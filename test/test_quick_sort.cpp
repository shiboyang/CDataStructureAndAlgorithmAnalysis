//
// Created by shiby on 22-10-27.
//

void swap(int list[], int i, int j);

int partition(int list[], int low, int high);

void quick_sort(int list[], int low, int high) {

    int pivot_index;
    if (low < high) {
        pivot_index = partition(list, low, high);
        quick_sort(list, low, pivot_index - 1);
        quick_sort(list, pivot_index + 1, high);
    }
}

int partition(int list[], int low, int high) {

    int pivot = list[low];
    while (low < high) {
        while (low < high && list[high] > pivot)
            --high;
        swap(list, low, high);

        while (low < high && list[low] < pivot)
            ++low;
        swap(list, low, high);
    }
    return low;

}

void swap(int list[], int i, int j) {
    if (i != j) {
        int tmp = list[i];
        list[i] = list[j];
        list[j] = tmp;
    }
}


#include <iostream>


int main() {

    int list[] = {20, 50, 30, 10, 100, 70, 60, 80, 40};
    size_t size = sizeof(list) / sizeof(list[0]);

    quick_sort(list, 0, size - 1);
    for (int i = 0; i < size; ++i) {
        std::cout << list[i] << std::endl;
    }

}