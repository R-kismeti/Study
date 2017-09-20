#include <stdio.h>
#include <assert.h>

/***strspn()函数检索区分大小写***/
int my_strspn(const char *str1, const char *str2)
{
	/***从参数str1字符串的开头计算连续的字符,而这些字符都完全是str2所指字符串中的字符。
	简单的说,若strspn()返回的数值为n,则代表字符串str1开头连续有n个字符都是属于字符串str2内的字符***/
	assert(str1 != NULL && str2 != NULL);
	const char *tmp = str1;
	const char *str3;

	while(*tmp)
	{
		for(str3 = str2; *str3; ++str3)
		{
			if(*str3 == *tmp)  //判断str1是否存在str2的字符
				break;
		}
		if(*str3 == '\0')  //如果str2结束则跳出循环str1++
			break;
		tmp++;
	}

	return tmp - str1;  //返回差值，即str1共有几个连续的字符是str2中存在的
}

int main()
{
	char s1[] = "hello world!";
    char s2[] = "i am lihua";

    int p = my_strspn(s1, s2);

    printf("The result is:%d\n", p);
	return 0;
}