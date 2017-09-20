#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n = 0;
	while(scanf("%d", &n) != EOF)
	{
		if(n < 1 || n > 50)
			continue;
		else
		{
			for(int i = 0; i < n; ++i)
			{
				char ip[16] = {'0'};
				scanf("%s", ip);
				int j = 0;
				int count = 0;
				while(ip[j] != '\0')
				{
					if(ip[j] != '.')
					{
						if(count == 1)
						{
						    if(ip[j] < '0' || ip[j] > '2')
						    {
						        printf("No!\n");
						        break;
						    }
						    else
	                        {
                                j++;
                                count++;
	                        }
	                    }
	                    else
	                    {
	                    	if(ip[j] < '0' || ip[j] > '5')
						    {
						        printf("No!\n");
						        break;
						    }
						    else
	                        {
                                j++;
                                count++;
	                        }
	                    }
					}
					else
					{
						count = 1;
                        j++;
					}
				}
				if(count > 1)
				{
					printf("Yes!\n");
				}
			}
		}
	}
	return 0;
}
