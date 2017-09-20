#include <stdio.h>

int main()
{
	int N;

	while(scanf("%d", &N) != EOF)
	{
		if(N < 2 || N >= 100)
			continue;
		int tmp = N * N;
		int k = 1,
			tmp1 = tmp;
		do
		{
			k *= 10;
			tmp1 /= k;
		}
		while(tmp1 / k != 0);
		if(tmp % k  == N)
			printf("Yes!\n");
		else
			printf("No!\n");
	}
	return 0;
}