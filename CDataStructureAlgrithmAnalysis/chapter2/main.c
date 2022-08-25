#include <stdio.h>


#define Max(a, b) ((a) > (b)) ? a : b

static int
Max3(int a, int b, int c) {
    return Max(Max(a, b), c);
}

static int
MaxSubSum(const int A[], int Left, int Right) {
    int MaxLeftSum, MaxRightSum;

    int Center;

    if (Left == Right) {
        if (A[Left] > 0)
            return A[Left];
        else
            return 0;
    }

    Center = (Left + Right) / 2;

    MaxLeftSum = MaxSubSum(A, Left, Center);
    MaxRightSum = MaxSubSum(A, Center + 1, Right);

    int MaxLeftSumBound = 0, LeftSumBound = 0;
    for (int i = Center; i >= Left; i--) {
        LeftSumBound += A[i];
        if (LeftSumBound > MaxLeftSumBound)
            MaxLeftSumBound = LeftSumBound;
    }
    int MaxRightSumBound = 0, RightSumBound = 0;
    for (int i = Center + 1; i < Right; i++) {
        RightSumBound += A[i];
        if (RightSumBound > MaxRightSumBound)
            MaxRightSumBound = RightSumBound;
    }

    return Max3(MaxLeftSum, MaxRightSum, MaxLeftSumBound + MaxRightSumBound);
}


int main(void) {
    const int size = 10;
    int A[10] = {1, -3, 5, 3, 4, 5, -3, 6, 1, 5};

    int r = MaxSubSum(A, 0, 10);
    printf("the max sub sum is %d", r);
    return 0;
}