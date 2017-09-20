#include <stdio.h>
#include <string.h>

int main()
{
	char *p = NULL;
	printf("%d\n", sizeof(p));
	printf("%d\n", sizeof(*p));


	int a[100];
	printf("%4d%4d%4d%4d\n", sizeof(a), sizeof(a[100]), sizeof(&a), sizeof(&a[0])); //&a[0]代表只想数组第一个元素的指针

	/*关于signed和unsigned的区别*/
	signed char b[1000];
	int i;
	for(i = 0; i < 1000; i++)
		b[i] = -1-i;
	printf("%d\n", strlen(b));
	fun(b);


	int i = -20;
	unsigned j = 10;
	printf("%d", i + j);
	return 0;
}

void fun(int b[100])
{
	printf("%d\n", sizeof(b));
}
