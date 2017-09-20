#include <stdio.h>

int Factorial(int n)
{
	if(1 == n)
	{
		return 1;
	}
	else
		return n * Factorial(n-1);
}

int main()
{
	int n = 0;

	while(scanf("%d", &n) != EOF)
	{
		int odd = 0;
		int even = 0;
		while(n)
		{
			if(n & 1 && n >= 1)
			{
				odd = odd + Factorial(n);
			}
			else if(n >= 1)
			{
				even = even + Factorial(n);
			}
			n--;
		}
		printf("%d %d\n", odd, even);
	}

	return 0;
}