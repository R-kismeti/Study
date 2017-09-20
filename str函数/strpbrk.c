#include <stdio.h>
#include <assert.h>

char *my_strpbrk(const char *str1, const char *str2)
{
	/***strpbrk()从str1的第一个字符向后检索，直到'\0'，如果当前字符存在于str2中，
	    那么返回当前字符的地址，并停止检索***/
	assert(str1 != NULL && str2 != NULL);
	const char *str3 = str2;

	while(*str1)  //判断石头人字符串str1是否结束
	{
		for(str3 = str2; *str3; ++str3)  //str2进行循环与str1的自费比较
		{
			if(*str1 == *str3)  //如果相等则进行str1的下一个判断
				break;
		}
		if(*str3)  //如果str3结束则结束比较
			break;
		str1++;
	}

	if(*str3 == '\0')  //如果str1到末尾则返回NULL
		str1 = NULL;
	return (char*)str1;
}

int main()
{
	char s1[] = "http://see.xidian.edu.cn/cpp/u/xitong/";
    char s2[] = "see";
    char *p = my_strpbrk(s1, s2);
    if(p)
    {
        printf("The result is: %s\n",p);
    }
    else
    {
        printf("Sorry!\n");
    }
	return 0;
}