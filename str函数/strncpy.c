#include <stdio.h>
#include <string.h>
#include <assert.h>

/***如果str1的长度比str2的count个要少，那么返回的不会以NULL结尾***/
char * my_strncpy(char * str1, char * str2, int count)
{
	assert(str1 != NULL);  //检验str1是否为空
	while(count && (*str1++ = *str2++))  //把str2的前n个字符复制给str1
	{
		count--;  //长度随着复制的进行而减少
	}
	while(count--)
	{
		*str1++ = '\0';  //如果str2的长度小于count那就用NULL填充str1的剩余
	}
	return str1;
}

int main()
{
	char destination[10] = {0};
   	char *source = "abcdefgh";
   	int count = 5;

   	my_strncpy(destination, source, count);
   	printf("%s\n", destination);
	return 0;
}