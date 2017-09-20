#include <stdio.h>
#include <assert.h>
#include <string.h>
#if 0
char * my_strrev(char * str)
{
	/***翻转字符串并返回字符串指针***/
	assert(str != NULL);
	char *end = str;
	char *head = str;
	char temp = '0';

	while(*end++)
	{};

	end--;  /* 与end++抵消 */
	end--;  /* 回跳过结束符'\0' */

	/* 当head和end未重合时，交换它们所指向的字符 */
	while(head < end)
	{
		temp = *head;
		*head++ = *end;  /* head向尾部移动 */
		*end-- = temp;  /* end向头部移动 */
	}
	return str;
}
#endif

char * my_strrev(char * str)
{
	/***翻转字符串并返回字符串指针***/
	if(str == NULL)
	{
		return NULL;
	}
	char *end = strlen(str) + str -1;
	char temp = '0';

	while(str < end)
	{
		temp = *str;
		*str = *end;
		*end = temp;
		str++;
		end--;
	}
	return str;
}


int main()
{
	/***只能逆置字符数组，而不能逆置字符串指针指向的字符串，
	    因为字符串指针指向的是字符串常量，常量不能被修改***/
	char str[] = "HelloWorld";  //定义str数组

   	printf("Before reversal: %s\n", str);
  	my_strrev(str);
   	printf("After reversal:  %s\n", str);
	return 0;
}