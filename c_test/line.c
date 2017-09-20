#include <stdio.h>

#line 14 "hello.c"

#define NAME1 "NAME1"
#define NAME2 "NAME2"

void f()
{
	return 0;  //错误代码,测试程序
}

int main()
{
	printf("%s\n", NAME1);
	printf("%s\n", NAME2);
	printf("%d\n", __LINE__);
	printf("%s\n", __FILE__);

	f();

	return 0;
}