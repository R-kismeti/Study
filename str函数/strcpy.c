#include <stdio.h>
#include <string.h>
#include <assert.h>

char * my_strcpy(char * destin, const char * source)
{
	/***把source指向的字符串拷贝到destin指向的字符串中***/
	assert(destin != NULL && source != NULL);  //检查source和destin的指向是否为空
	while(*destin++ = *source++)  //将source指向的字符复制给destin指向的字符
	{};
	return destin;  //返回指向最终结果的指针
}

int main()
{
	char destination[10] = {0};
   	char *source = "abcdefgh";

   	my_strcpy(destination, source);
   	printf("%s\n", destination);

	return 0;
}