#include <stdio.h>

int main()
{
	int a, b;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		int sum = a+b;
		printf("%d", sum);
		putchar(10);
	}
	return 0;
}