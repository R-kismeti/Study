#include <stdio.h>

void access(int (*a)[3], int row)
{
    int col = sizeof(*a)/sizeof(int);
    int i = 0;
    int j = 0;

    for(i = 0; i < row; ++i)
    {
        for(j = 0; j < col; ++j)
        {
            printf("%d ", a[i][j]);
        }
        putchar(10);
    }
}

int main()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6, }, {7, 8, 9}};
    access(a, 3);
    return 0;
}
