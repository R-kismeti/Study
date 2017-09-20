#include<stdio.h>

int main()
{
    int a, b, c, d, n = 0;
    while(scanf("%d", &n) != EOF)
    {
        int i = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d.%d.%d.%d", &a, &b, &c, &d);
            if(a>>8 || b>>8 || c>>8 || d>>8)
            {
                printf("No!\n");
            }
            else
            {
                printf("Yes!\n");
            }
        }
    }
    return 0;
}