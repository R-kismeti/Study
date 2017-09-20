#include <stdio.h>
#include <string.h>

char * my_strchr(char * str, const char c)
{
	/***查找str中c首次出现的位置，并返回位置或者NULL***/
	while(*str != '\0' && *str != c)  //判断str是否为'\0'且等于c
	{
		str++;
	}
	//判断如果str等于c则返回与c匹配的str否则返回NULL
	return (*str == c ? str : NULL);
}

char * my_strrchr(char * str, const char c)
{
	/***查找str中c最后一次出现的位置，并返回位置或者NULL***/
	char * end = str + strlen(str);  //定义指针end存放str的末尾地址

	while(*str != *end && *end != c)  //判断end没有到头部且没找到和c匹配的字符
	{
		end--;  //向前进行移动
	}

	if(*end == *str && *end != c)  //如果没找到则返回NULL
		return NULL;

	return end;
}

int main()
{
	char * string = "abcdefgh";
	char c = 'd',
		 *ptr = NULL,  //存放my_strchr的返回值
		 *ptr1 = NULL;  //存放my_strrchr的返回值

	ptr = my_strchr(string, c);
	if(ptr)
		printf("%c\n", c);
	else
		printf("Not Found!\n");

	ptr1 = my_strrchr(string, c);
	if(ptr1)
		printf("%c\n", c);
	else
		printf("Not Found!\n");

	return 0;
}