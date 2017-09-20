#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    while(gets(str))
    {
        int len = strlen(str);
	    int count = 0;
	    for(int i = 0; i < len; i++)
	    {
	        if(str[i] != '.')
	        {
	            if(str[i] != ' ')
	            {
	                ++count;
	            }
	            else
	            {
	                printf("%d ",count);
	                count = 0;
	            }
	        }
	        else
	            break;
	    }
	    printf("%d\n",count);
    }
    return 0;
}
