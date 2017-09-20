#include <stdio.h>
#include <string.h>

int my_strcmp(const char * str1, const char * str2)
{
	/***比较str1和str2，str1 > str2返回大于0的数，str1 == str2返回0，
	    str1 < str2返回小于0的数，使用时可以和0比较***/
	while( ! ((*str1 != *str2) && str1 != '\0'))
	{
		//如果str1和str2的字符相等且字符str1没有到末尾则进入循环
		str1++;  //指针str1向后加一位
		str2++;  //指针str2向后加一位
	}
	return (*str1 - *str2);  //返回跳出循环的str1和str2当前的字符的差值比较的结果(0或1或-1)
}

int main()
{
	char *buf1 = "aaaa",
		 *buf2 = "aaaab",
		 *buf3 = "aaaac";
    int ptr = 0;  //定义变量用来存放my_strcmp返回的值

    ptr = my_strcmp(buf2, buf1);
    if (ptr > 0)
       	printf("string 2 is bigger than string 1\n");
    else
       	printf("string 2 is smaller than string 1\n");

    ptr = my_strcmp(buf2, buf3);
    if (ptr > 0)
       	printf("string 2 is bigger than string 3\n");
    else
       	printf("string 2 is smaller than string 3\n");

	return 0;
}