#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
srand((unsigned)time(null));
(a,b) (rand()%(b-a+1))+a-1
[a,b) (rand()%(b-a))+a
(a,b] (rand()%(b-a))+a+1
[a,b] (rand()%(b-a+1))+a
 */

/*
1：m=n此时不该叫随机数，这里返回m
2：m>n:
        标记pos=n，距离差pos=m-n+1
　　　　 返回 rand() % dis + pos
3：n>m:
        标记pos=m，距离差=n-m+1
　　　　 返回rand()%dis + pos
 */

int Random(int m, int n)
{
    int pos, dis;
    if(m == n)
    {
        return m;
    }
    else if(m > n)
    {
        pos = n;
        dis = m - n + 1;
        return rand() % dis + pos;
    }
    else
    {
        pos = m;
        dis = n - m + 1;
        return rand() % dis + pos;
    }
}
int main()
{
    int i, m, n;
    srand((int)time(NULL));
    m = -3;
    n = -7;
    for(i=0; i<10; i++)
    {
        printf("%d\n", Random(m, n));
    }
    return 0;
}