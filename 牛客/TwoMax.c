#include <stdio.h>

int main()
{
	int A[4][5];
	int B[2][5];
	int n;
	scanf("%d", &n);

	while(n--)
	{
		for(int i = 0; i < 4; ++i)
		{
			for(int j = 0; j < 5; ++j)
			{
				scanf("%d", &A[i][j]);
			}
		}
		int t = 0;
		for(int i = 0; i < 5; i++)
		{
			int MAX = A[0][i],
				MID = A[0][i];
			int k = 0,
				num1 = 0,
				num2 = 0;
			for(int j = 0; j < 4; j++)
			{
				if(A[j][i] > MAX)
				{
					MID = MAX;
					MAX = A[j][i];
					num1 = j;
					num2 = j;
				}
				else if(A[j][i] > MID)
				{
					MID = A[j][i];
					num2 = j;
				}
				else if(A[j][i] < MID && A[0][i] == MAX && j == 1)
				{
					MID = A[j][i];
					num2 = j;
				}
			}
			if(num1 < num2)
			{
				B[k][t] = MAX;
				B[k+1][t] = MID;
			}
			else
			{
				B[k][t] = MID;
				B[k+1][t] = MAX;
			}
			t++;
		}

		for(int i = 0; i < 2; ++i)
		{
			for(int j = 0; j < 5; ++j)
			{
				printf("%d ", B[i][j]);
			}
			putchar(10);
		}
	}
	return 0;
}