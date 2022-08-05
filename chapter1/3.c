#include <stdio.h>


static int len_str(char * ps)
{
    int l = 0;
    
    while (*ps != '\0')
    {
        l++;
        ps++;
    }
    return l;
}


int main(void)
{

    char s[] = "123456";

    int l1 = len_str(s);
    int l2 = len_str(s);

    printf("l1 = %d, l2 = %d", l1, l2);

    return 0;
}