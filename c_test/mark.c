#include <stdio.h>

int main()
{
    /*
    char *p1 = 1;
    char *p2 = '1';
    char *p3 = "1";
    printf("%s  %s  %s\n", p1, p2, p3);*/

    /*
    char c =" ";
    while(c == '\t' || c == ' ' || c == '\n')
        scanf("%c", &c);
    */

    int a = 1, b = 2;
    //(a > b ? a : b) = 3;  //等号左边是一个值，所以无法赋值
    *(a > b ? &a : &b) = 3;  //可执行

    printf("%d", !0);
    printf("%d", !1);
    printf("%d", !100);
    printf("%d", !-10000);
    return 0;
}
