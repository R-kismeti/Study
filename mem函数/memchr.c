#include <stdio.h>
#include <string.h>

void * my_memchr(const void *buffer, int ch, int count)
{
	/*从buffer所指内存区域的前count个字节查找字符ch，
	当第一次遇到字符ch时停止查找。
	如果成功，返回指向字符ch的指针,否则返回NULL*/
	//对于数字字符，遇见空格则停止，并返回指向空格的指针

	while(count-- && (unsigned char)ch != *(unsigned char *)buffer)
	{
		buffer = (unsigned char *)buffer + 1;
	}
	return(count ? (void *)buffer : NULL);
}

int main()
{
	char *str = "hello world!";
	char *p;
	char ch;

	ch = '1';
	p = (char *)my_memchr(str, ch, strlen(str)+1);
	if(p == NULL)
		printf("Can't find the character %c !\n", ch);
	else
		printf("Find the character %c !\n", *p);

	ch = 'd';
	p = (char *)my_memchr(str ,ch, strlen(str)+1);
	if(p == NULL)
		printf("Can't find the character %c !\n", ch);
	else
		printf("Find the character %c !\n", *p);

	return 0;
}