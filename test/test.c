//
// Created by shiby on 22-9-29.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {

//    int *pi = (int[]) {1, 2, 3, 4, 5};
    int *p = (int *) malloc(sizeof(int));
    free(p);
    p = NULL;
    free(p);

    return 0;
}
