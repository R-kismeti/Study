#include <stdio.h>
#include <string.h>

int my_stricmp(const char *str1, const char *str2)
{
	/***不区分大小写的比较str1和str2***/
	char ch1 = '0',
		 ch2 = '0';

	do
	{
		if((ch1 = (unsigned char)(*(str1++))) >= 'A' && ch1 <= 'Z')
			ch1 += 0x20;
		if((ch2 = (unsigned char)(*(str2++))) >= 'A' && ch2 <= 'Z')
			ch2 += 0x20;
	}while(ch1 && (ch1 == ch2));  // 判断是否相等且str1不为'\0'，是则进入循环
	return (ch1 - ch2);  //返回两个数的大小
}

int main()
{
	char *str1= "ammana";
    char *str2 = "bibi";
    char *str3 = "AMMANA";
    int ptr = 0,
    	ptr1 = 0;

    ptr = my_stricmp(str1, str2);
    if(ptr > 0)
    	printf("str1 bigger than str2!\n");
    else
    	printf("str1 smaller than str2!\n");

    ptr1 = my_stricmp(str1, str3);
    if(ptr1 > 0)
    	printf("str1 bigger than str3!\n");
    else if(ptr1 < 0)
    	printf("str1 smaller than str3!\n");
    else
    	printf("str1 equal to str3!\n");

	return 0;
}