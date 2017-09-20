#include <stdio.h>

void *my_memcpy(void *dest, const void *src, int count)
{
	/*由src指定内存区域拷贝count个字符到dest所指定的内存区域。
	src和dest内存区域不能重叠，函数返回指向dest的指针。*/
	//拷贝完成不会自动加上'\0'
	unsigned char *p = (unsigned char *)dest;
	unsigned char *q = (unsigned char *)src;
	while(count--)
	{
		*p++ = *q++;
	}
	return dest;
}

int main()
{
	char a[20];
	char *p;
	p = (char *)my_memcpy(a, "hello world!", 12);
	*(p+12) = '\0';  //为puts做准备
	puts(a);
	return 0;
}