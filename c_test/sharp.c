#include <stdio.h>

#define fun(x) #x

#define CALL(f, p) (printf("Call function %s\n", #f), f(p))

#define NAME(n) name##n

#if 0
/*typedef*/ struct TEST
{
    int i;
    int j;
}/*test;*/
#endif

#define STRUCT(type) typedef struct TEST##type type;\
struct TEST##type

STRUCT(student)
{
    char *name;
    int id;
};

int square(int n)
{
    return n * n;
}

int f(int x)
{
    return x;
}

int main()
{
    printf("%s\n", fun(hello world!));
    printf("%s\n", fun(100));
    printf("%s\n", fun(while));
    printf("%s\n", fun(return));

    putchar(10);
    printf("%d\n", CALL(square, 4));
    printf("%d\n", CALL(f, 10));

    putchar(10);
    int NAME(1);
    int NAME(2);

    NAME(1) = 1;
    NAME(2) = 2;

    printf("%d\n", NAME(1));
    printf("%d\n", NAME(2));

    putchar(10);
    student s1, s2;

    s1.name = "s1";
    s1.id = 0;

    s2.name = "s2";
    s2.id = 1;

    printf("%s\n", s1.name);
    printf("%d\n", s1.id);
    printf("%s\n", s2.name);
    printf("%d\n", s2.id);
    return 0;
}
