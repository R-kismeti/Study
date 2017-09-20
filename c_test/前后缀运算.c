#include <stdio.h>

int main()
{
	int a = 5;
	int i = 7;
	printf("%d %d %d\n", a++, a++, ++a);
	printf("%d %d %d %d\n", ++i, i++, ++i, i++);
	/*从右往左入栈，从左往右出栈*/
	return 0;
}