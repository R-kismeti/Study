#include <stdio.h>

#define DIM(a) (sizeof(a)/sizeof(*a))

int main()
{
    int a[] = {2, 3, 5, 7, 2, 2, 2, 5, 3, 7, 1, 1, 1, 1, 7};
    int find = 0;

    for(int i = 0; i < DIM(a); ++i)
    {
         find = find ^ a[i];
    }

    printf("%d\n", find);

    //printf("%d", 1 << -1);
    //printf("%d", 1 << 32);
    return 0;
}
