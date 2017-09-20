#include <stdio.h>

void print(int a[], int n)
{
    int i = 0;
    for(i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    putchar(10);
}

int main()
{
    int a[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *p = &a[0][0];

    print(p, 9);
    return 0;
}
