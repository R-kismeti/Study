#include <stdio.h>
#include <string.h>

unsigned int my_strlen(const char * str)
{
	/***计算str的长度并返回***/
	unsigned length = 0;  //定义无符号变量length统计str的长度
	while(*str != '\0')  //判断str指向的字符是否为'\0'
	{
		length++;  //长度加1
		str++;  //指向的地址向后加1位
	}
	return length;
}

int main()
{
	char * str = "abcdefgh";
	int len = 0;

	len = my_strlen(str);

	printf("%d\n", len);
	return 0;
}