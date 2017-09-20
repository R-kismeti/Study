#include <stdio.h>
int main()
{
	int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int ave = 0,
		ave1 = 0,
		max = a[0][0];
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			ave += a[i][j];
			ave1 += a[i][j];
			if(max < a[i][j])
				max = a[i][j];
		}
		printf("every line£º%d  %d\n", ave/4, max);
	}
	printf("finally result£º%d  %d\n", ave1/3, max);
	return 0;
}