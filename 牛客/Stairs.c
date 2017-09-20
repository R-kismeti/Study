#include <stdio.h>

int main()
{
	long long N;
	while(scanf("%lld", &N) != EOF)
	{
		if(N == 1 || N == 2)
			printf("%d", N);
		else
		{
			long long count = 0;
			long long pre = 1,
				next = 1;
			for(int j = 2; j <= N; ++j)
			{
				count = pre + next;
				pre = next;
				next = count;
			}
			printf("%lld", count);
		}
		putchar(10);
	}
	return 0;
}