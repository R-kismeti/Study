#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main()
{
	int N = 0;
	while(scanf("%d", &N) != EOF)
	{
		int *a = (int *)malloc(sizeof(int) * N);
		memset(a, 0, sizeof(a));
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &a[i]);
		}

		qsort(a, N, sizeof(a[0]), cmp);

		printf("%d\n", a[N-1]);
		if(N <= 1)
		{
			printf("-1");
		}
		else
		{
			for(int j = 0; j < N-1; ++j)
			{
				if(j == 0)
					printf("%d", a[j]);
				else
					printf(" %d", a[j]);
			}
		}
		putchar(10);
		free(a);
	}
	return 0;
}