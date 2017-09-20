#include <stdio.h>
#include <stdlib.h>
/*
int main(void)
{
    int n, *arr;

    while (scanf("%d", &n) != EOF) {
        arr = (int *)malloc(sizeof(int) * n);
    }

    return 0;
}
*/

int main(void)
{
    int i, row, column, **arr;

    while (scanf("%d %d", &row, &column) != EOF) {
        arr = (int **)malloc(sizeof(int *) * row); // 分配所有行的首地址
        for (i = 0; i < row; i ++) { // 按行分配每一列
            arr[i] = (int *)malloc(sizeof(int) * column);
        }

        // 释放开辟的二维数组空间
        for (int i = 0; i < row; ++i)
        {
            free(*(arr + i));
        }
    }

    return 0;
}