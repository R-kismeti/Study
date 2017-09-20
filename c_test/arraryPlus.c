#include <stdio.h>
#include <stdlib.h>

int** Malloc(int row, int col)
{
    int** ret = (int **)malloc(sizeof(int*) * row);
    int* p = (int *)malloc(sizeof(int) * row * col);

    int i = 0;
    if(ret && p)
    {
         for(i = 0; i < row; ++i)
         {
             ret[i] = (p + col * i);
         }
    }
    else
    {
         free(ret);
         free(p);
         return NULL;
    }
    return ret;
}

void Free(int** a)
{
     free(a[0]);
     free(a);
}

int main()
{
    #if 0
    int a[5][5];
    //int (*p)[4];
    int (*p)[5];

    p = a;

    printf("%d\n", &p[4][2] - &a[4][2]);
    #endif

    #if 0
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int i = 0;
    int j = 0;

    for(i = 0; i < 3; ++i)
    {
         for(j = 0; j < 3; ++j)
         {
             printf("%d ", *(*(a + i) + j));
         }
    }
    putchar(10);
    #endif

    return 0;
}
