###mem函数源码

####1.memcpy函数
1. **原型**：`void *memcpy(void *dest, const void *src, int count)`
2. **作用**：由src指定内存区域拷贝count个字符到dest所指定的内存区域。
3. **代码**：

```c
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
```

####2.memccpy函数
1. **原型**：`void *memccpy(void *dest, const void *src, char ch, int count)`
2. **作用**：如果src前n个字节中存在’ch’，返回指向字符’ch’后的第一个字符的指针；
	返回NULL，并且复制src。
3. **代码**：

```c
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
```

####3.memmove函数
1. **原型**：`void *memmove(void *dest, const void *src, int count)`
2. **作用**：由src所指定的内存区域赋值count个字符到dest所指定的内存区域。
	src和dest所指内存区域可以重叠
3. **代码**：

```c
#include <string.h>

void * my_memmove(void *dest, const void *src, int count)
{
	/*由src所指定的内存区域赋值count个字符到dest所指定的内存区域。
	src和dest所指内存区域可以重叠，
	但复制后src的内容会被更改,最终函数返回指向dest的指针。*/
	//可以自己考虑count的大小，大于0，小于src的大小

	if((unsigned char *)dest >= ((unsigned char *)src + count))
	{
		/*若果没有重叠*/
    	dest = memcpy (dest, src, count);
	}
	else
	{
		/*如果有重叠,则从尾部进行拷贝*/
		unsigned char *p = (unsigned char *)dest + count;
        unsigned char *q = (unsigned char *)src + count;
        while (count--)
        {
            *--p = *--q;
        }
	}
	return dest;
}

int main()
{
	/*正常的复制*/
	char a[20];
    puts((char *)my_memmove(a, "hello world!", 16));

    /*内存重叠*/
    char str[] = "memmove can be very useful......";
    my_memmove (str+20, str+15, 11);
    puts (str);
	return 0;
}
```

####4.memcmp函数
1. **原型**：`int memcmp(const void *buffer1, const void *buffer2, int count)`
2. **作用**：比较内存区域buffer1和buffer2的前count个字节。
3. **代码**：

```c
int my_memcmp(const void *buffer1, const void *buffer2, int count)
{
	/*比较内存区域buffer1和buffer2的前count个字节。
	当buffer1 < buffer2时，返回值 < 0；
	当buffer1 = buffer2时，返回值 0；
	当buffer1 > buffer2时，返回值 > 0。*/

	if(!count)
		return 0;
	while(--count && *(char *)buffer1 == *(char *)buffer2)
	{
		//判断前count个字符是否相等
		buffer1 = (char *)buffer1 + 1;
		buffer2 = (char *)buffer2 + 1;
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
```

####5.memchr函数
1. **原型**：`void *memchr(const void *buffer, int ch, int count)`
2. **作用**：从buffer所指内存区域的前count个字节查找字符ch，
	当第一次遇到字符ch时停止查找。
3. **代码**：

```c
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
```

####参考文章

链接：
<http://www.cnblogs.com/jiangyinglin/p/3247087.html>