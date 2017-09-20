#include <stdio.h>

int LeapYear(int y)
{
	if(y % 4 == 0 && y % 100 !=0 || y % 400 == 0)
		return 1;
	else
		return 0;
}

void Calculate(int y, int n, int flag)
{
	int month = 0;
	if(flag == 1)
	{
		int day[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		while(n > day[month])
		{
			n -= day[month];
			month++;
		}
		printf("%04d-%02d-%02d\n", y, month, n);  //表示输出的结果如果不够4个或者两个的用0补充
	}
	else
	{
		int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		while(n > day[month])
		{
			n -= day[month];
			month++;
		}
		printf("%04d-%02d-%02d\n", y, month, n);
	}
}

int main()
{
	int y = 0,
		n = 0;
	while(scanf("%d%d", &y, &n) != EOF)
	{
		if(y >= 1 && y <= 3000 && n >= 1 && n <= 366)
		{
			if(LeapYear(y))
			{
				int flag = 1;
				Calculate(y, n, flag);
			}
			else
			{
				int flag = 0;
				Calculate(y, n, flag);
			}
		}
	}
	return 0;
}