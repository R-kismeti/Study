#include <stdio.h>
#include <string.h>

void *my_memccpy(void *dest, const void *src, char ch, int count)
{
	/*如果src前n个字节中存在’ch’，返回指向字符’ch’后的第一个字符的指针；
	返回NULL，并且复制src。
	一个条件达到就结束*/
	//对于数字字符，遇见空格则停止，并返回指向空格的指针

	while(count--)
	{
		*(char *)dest = *(char *)src;
		dest = (char *)dest + 1;
		if(*(char *)src == (char)ch)
			break;
		src = (char *)src + 1;
	}
	return (count ? (char *)dest : NULL);
}

int main()
{
	char a[20];
	char *p;
	char *str ="hello world!";
	char ch;

	ch = '9';
	p = (char *)my_memccpy(a, str, ch, strlen(str)+1);
	if(p == NULL)
		printf("Can't not find character.\n");
	else
	{
		printf("Find the character! \n");
		*p= '\0';  //为下面的puts函数准备
	}
	printf("The String which has been copied is:  ");
	puts(a);  //puts()从string的开头往stdout中输出字符，直到遇见结束标志 '\0'，'\0'不会被输出到stdout。

	printf("************************************");

	ch = 'b';
	p = (char *)my_memccpy(a, str, ch, strlen(str)+1);
	if(p == NULL)
		printf("Can't not find character.\n");
	else
	{
		printf("\nFind the character! \n");
		*p = '\0';
	}
	printf("The String which has been copied is:  ");
	puts(a);
	return 0;
}