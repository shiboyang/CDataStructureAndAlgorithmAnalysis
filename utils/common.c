#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void random_int_arr(int arr[], int length, int max_num)
{
    srand((unsigned int)time(0));
    for (int i=0; i<length; i++)
    {
        arr[i] = rand() % max_num;
    }
}


void show_int_arr(int arr[], int length)
{
    for (int i=0; i<length; i++)
    {
        printf("%d\n", arr[i]);
    }
}