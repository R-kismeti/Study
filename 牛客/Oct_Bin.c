#include <stdio.h>

int main()
{
	int N = 0;
	int a[32] = {0};

	while(scanf("%d", &N) != EOF)
	{
		int i = 0;
		while(N)
		{
			a[i++] = N % 8;
			N = N / 8;
		}
		for(int j = i-1; j >= 0; j--)
			printf("%d", a[j]);
		putchar(10);
	}

	return 0;
}