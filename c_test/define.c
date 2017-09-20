#include <stdio.h>

#define SWAP(a, b)  \
{                   \
    int temp = a;   \
    a = b;          \
    b = temp;       \
}  //这样可以直接进行覆盖  //如果定义函数不是真正意义上的交换

#define SUM(a, b) (a)+(b)
#define MIN(a, b) ((a < b) ? a : b)

//#define f   (x)   ((x)-1)  //错误

//避免在宏里面写表达式，而应该写sizeof(arrary)的大小，因为函数无法做到

int main()
{
    int a = 2,
        b = 5;
    SWAP(a, b);
    printf("%d %d\n", a, b);
    printf("%d\n", SUM(a, b) * SUM(a, b));
    printf("%d\n", MIN(a++, b));

    printf("%d", f   (3));
    return 0;
}
