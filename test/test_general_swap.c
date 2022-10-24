//
// Created by shiby on 22-10-24.
//

#include <stdio.h>
#include <stddef.h>
#include <string.h>

#define swap(X, Y) _swap(&(X), &(Y), sizeof(X));


void _swap(void *ptr1, void *ptr2, size_t size) {
    char *tmp_ptr[size];
    memcpy(tmp_ptr, ptr1, size);
    memcpy(ptr1, ptr2, size);
    memcpy(ptr2, tmp_ptr, size);
}

typedef struct {
    int i;
    char c;
} Data;


int main() {
    int a = 10;
    int b = 100;
    swap(a, b);
    printf("a = %d, b = %d\n", a, b);

    double x = 1.01;
    double y = 2.02;
    swap(x, y);
    printf("x = %g, y=%g\n", x, y);

    Data d1 = {10, 'A'};
    Data d2 = {20, 'B'};
    swap(d1, d2);
    printf("d1.i = %d, d1.c = %c\n", d1.i, d1.c);
    printf("d2.i = %d, d2.c = %c\n", d2.i, d2.c);
}

