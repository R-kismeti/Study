#include <stdio.h>

int main()
{
	char a[5] = {'A', 'B', 'C', 'D'};
	char (*p3)[10] = &a;
	char (*p4)[10] = a;
	//char (*p3)[3] = &a;
	//char (*p4)[3] = a;
	printf("%x  %x", p3+1, p4+1);
	return 0;
}