#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[101];
	int a[8];
	while(scanf("%s", str) != EOF)
	{
		int j = 0;
		int len = strlen(str);
		while(j < len)
		{
			int i = 0;
			int flag = 0;
			memset(a, 0, sizeof(a));
			while(str[j] != 0)
			{
				if((str[j] % 2) == 1)
					flag++;
				a[i++] = str[j] % 2;
				str[j] /= 2;
			}
			if(flag % 2 == 1)
			{
				a[7] = 0;
			}
			else
			{
				a[7] = 1;
			}

			for(int k = 7; k >= 0; --k)
				printf("%d", a[k]);

			putchar(10);
			j++;
		}
	}
	return 0;
}
