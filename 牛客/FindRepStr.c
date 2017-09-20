#include <stdio.h>
#include <string.h>

int main()
{
	char str[100];

	while(scanf("%s", str) != EOF)
	{
		int i = 0;
		while(i < strlen(str))
		{
			int j = i + 1;
			int num = 0;
			while(j < strlen(str))
			{
				if(str[i] == str[j] && str[i] != '*')
				{
					if(num == 0)
					{
						printf("%c:%d", str[i], i);
						printf(",%c:%d", str[j], j);
						num = 1;
					}
					else
					{
						printf(",%c:%d", str[j], j);
						num = 1;
					}
					str[j] = '*';
					num = 1;
				}
				j++;
			}
			if(num == 1)
            	 printf("\n");
			i++;
		}
	}
	return 0;
}