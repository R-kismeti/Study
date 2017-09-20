#include <stdio.h>

int my_memcmp(const void *buffer1, const void *buffer2, int count)
{
	/*比较内存区域buffer1和buffer2的前count个字节。
	当buffer1 < buffer2时，返回值 < 0；
	当buffer1 = buffer2时，返回值 0；
	当buffer1 > buffer2时，返回值 > 0。*/

	if(!count)
		return 0;
	while(count && *(char *)buffer1 == *(char *)buffer2)
	{
		//判断前count个字符是否相等
		buffer1 = (char *)buffer1 + 1;
		buffer2 = (char *)buffer2 + 1;
		--count;
	}
	//返回两个字符串的首个字符的差值
	return ( *((unsigned char *)buffer1) - *((unsigned char *)buffer2) );
}

int main()
{
	char *str1 = "hello";
    char *str2 = "world";
    int n = 0;
    scanf("%d", &n);

    int res = my_memcmp(str1, str2, n);
	if(res > 0)
	    printf("%s Upper Than %s\n", str1, str2);
    else if(res < 0)
        printf("%s Lower Than %s\n", str1, str2);
    else
        printf("%s Equal %s\n", str1, str2);

	return 0;
}