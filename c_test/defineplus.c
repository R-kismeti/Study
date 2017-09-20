#include <stdio.h>

#define MIN(a, b) ((a < b) ? a : b)

/*
 系统的宏
 1.__FILE__ 被编译的文件名
 2.__LINE__ 当前行号
 3.__DATE__ 编译时的日期
 4.__TIME__ 编译时的时间
 5.__STDC__ 编译是否遵循标准c规范
*/

/*
 可以通过宏来使用上面的系统的宏定义日志追踪
 如果使用函数会出现行号不匹配
*/

/*
 可以使用循环语句(do{}while(0))把许多行语句接到一行里面，再使用接续符定义宏
*/

#define LOG(s) printf("%s:%d %s\n", __FILE__, __LINE__, s);

int f1(int a, int b)
{
    #define _MIN_(a, b) ((a) < (b) ? a : b)
    return _MIN_(a, b);
    //#undef
}

int f2(int a, int b, int c)
{
    //#define 没有作用域的限制，需要#undef来结束，限制作用域
    return _MIN_(_MIN_(a, b), c);
}

int main()
{
    LOG("Enter main...");
    printf("%d\n", f1(1, 2));
    printf("%d\n", f2(5, 3, 2));
    return 0;
}
