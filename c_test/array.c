#include <stdio.h>

typedef int(INT)[5];
typedef float(FLOAT)[10];
typedef char(CHAR)[9];

int main()
{
    INT a1;
    float fArrary[10];
    FLOAT *pf = &fArrary;
    CHAR cArrary;
    char(*pc)[9] = &cArrary;
    char(*pcv)[4] = cArrary;

    int i = 0;

    printf("%d, %d\n", sizeof(INT), sizeof(a1));

    for(i = 0; i < 10; ++i)
    {
         (*pf)[i] = i;
    }

    for(i = 0; i < 10; ++i)
    {
         printf("%f\n", fArrary[i]);
    }

    printf("%0x, %0x, %0x\n", &cArrary, pc+1, pcv+1);
    return 0;
}
