#include <stdio.h>

int main()
{
    int a = -2;
    unsigned int b = 1;

    if((a + b) > 0)
        printf("Yes!\n");

    printf("%d\n", a + b);
    printf("%u\n", a + b);
    printf("%0x\n", a + b);
    return 0;
}
