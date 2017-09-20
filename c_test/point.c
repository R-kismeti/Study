#include <stdio.h>

int main()
{
    int i = 5;
    int *p = &i;
    printf("%d, %08x\n", i, p);
    *p = 10;  //i = 10;
    printf("%d, %08x\n", i, p);

    return 0;
}
