#include <stdio.h>
#include <stdlib.h>
#include "../utils/common.h"

#define size 10

void maopao_sort(int arr[], int length)
{
    int t;
    for (int i=0; i<length; i++)
    {
        for (int m=i; m<length; m++)
        {
            if (arr[m]>arr[i])
            {
                t = arr[i]; 
                arr[i] = arr[m];
                arr[m] = t;
            }
        }
    }
}


int custom_sort(const void * x, const void * y)
{
    int * a = (int *)x;
    int * b = (int *)y;
    return (*b) - (*a);
}

int find_nth_maximum(int arr[], int length, int k)
{
    int karr[k];
    for (int i=0; i<k; i++)
    {
        karr[i] = arr[i];
    }
    qsort(karr, k, sizeof(int), custom_sort);
    for (int i=k; i<length; i++)
    {
        if (karr[k-1] < arr[i])
        {
            karr[k-1] = arr[i];
            qsort(karr, k, sizeof(int), custom_sort);
        }
    }
    return karr[k-1];
}


int main(void)
{
    int arr[size];
    random_int_arr(arr, size, 100);
    show_int_arr(arr, size);
    // puts("-------------------");
    // maopao_sort(arr, size);
    // show_int_arr(arr, size);
    // puts("-------------------");
    // qsort(arr, size, sizeof(int), custom_sort);
    // show_int_arr(arr, size);

    int k_maximum = find_nth_maximum(arr, size, 5);
    puts("===================");
    show_int_arr(arr, size);
    printf("the fiveth maximum is %d\n", k_maximum);
    puts("-------------------");
    qsort(arr, size, sizeof(int), custom_sort);
    show_int_arr(arr, size);
    return 0;
}