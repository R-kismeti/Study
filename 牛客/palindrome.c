/********
回文数
********/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char a[1001];
	while(scanf("%s", a) != EOF)
	{
		int end = strlen(a)-1;
		int flag = 1;
		for(int i = 0; i < strlen(a); ++i)
		{
			if(a[i] == a[end])
			{
				flag = 1;
				end--;
			}
			else
			{
				flag = 0;
				break;
			}
		}
		if(flag == 1)
			printf("Yes!\n");
		else
			printf("No!\n");
	}
}