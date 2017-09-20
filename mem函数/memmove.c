#include <stdio.h>
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