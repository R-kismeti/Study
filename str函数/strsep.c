#include <stdio.h>
#include <string.h>

/***********************************************************
a：如果*stringp为NULL，则该函数不进行任何操作，直接返回NULL；
b：strsep每次都是从*stringp指向的位置开始搜索，搜索到任一分割字符之后，将其置为’\0’，
   并使*stringp指向它的下一个字符。如果找不到任何分割字符，则将*stringp置为NULL。
c：strsep内部没有使用静态指针，因而strsep是线程安全的。
d：strsep返回的子串有可能是空字符串，实际上，就是因为strtok无法返回空子串，才引入的strsep函数。
   不过strtok符合C89/C99标准，因而移植性更好。但strsep却不是。
e: "二八定律",即80%情况下分隔符只有一个字节，使用strchr完成,20%情况有多个字节，调用strpbrk完成
*************************************************************/

char *my_strsep(char **stringp, const char *delim)
{
	/***strsep函数用来将字符串分割成一个个片段***/
	char *begin,
		 *end;
	begin = *stringp;
	if(begin == NULL)
	{
		return NULL;
	}

	/*delim分隔符是单个字符的情况是非常频繁的，因此不需要使用代价昂贵的strpbrk函数
     而只需要调用strchr就能解决*/
	if(delim[0] == '\0' || delim[1] == '\0')
	{
		char ch = delim[0];
		if(ch == '\0')
		{
			end = NULL;
		}
		else
		{
			if(*begin == ch)
			{
				end = begin;
			}
			else if(*begin == '\0')
			{
				end = NULL;
			}
			else
			{
				end = strchr(begin + 1, ch);
			}
		}
	}
	else
	{
		/*delim有两个字符以上,才调用strpbrk*/
		end = strpbrk(begin, delim);
	}

	if(end)
	{
		/*用0封闭这个token；返回stringp，指向一个null指针*/
		*end++ = '\0';
		*stringp = end;
	}
	else
	{
		/*没有出现delim，这是最后一个token*/
		*stringp = NULL;
	}
	return begin;
}

int main()
{
	char source[] = "hello, world! welcome to China!";
    char delim[] = " ,!";

    char *s = strdup(source);
    char *token;
    for(token = my_strsep(&s, delim); token != NULL; token = my_strsep(&s, delim))
    {
        printf(token);
        printf("+");
    }
    printf("\n");
	return 0;
}