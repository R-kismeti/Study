#include <stdio.h>
#include <string.h>

int my_strncmp(const char * str1, const char * str2, int count)
{
	/***比较str1和str2的前n个字符***/
	if(!count)
		return 0;
	while(--count && *str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int main()
{
	char *str1 = "China is a nation!";
	char *str2 = "French is a nation!";
	int count = 5,
		ptr = 0;

	ptr = my_strncmp(str1, str2, count);
	if(ptr != 0)
    	printf("str1 is not equal to str2!\n");
	return 0;
}