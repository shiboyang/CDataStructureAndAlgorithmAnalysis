#include <stdio.h>
#include <time.h>

int main(void)
{
    const int size = 100;
    clock_t t1, t2;
    int m;
    double record[size];

    for (int i=0; i<size; i++)
    {
        t1 = clock();
        m = i/2;
        t2 = clock();
        record[i] = (double)(t2 - t1);
    }

    for (int i=0; i<size; i++)
    {
        printf("%lf\t", record[i]);
        if ((i+1) % 10 == 0)
            printf("\n");
    }

    return 0;
}