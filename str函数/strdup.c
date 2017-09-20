#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char * my_strdup(const char * str)
{
	/***拷贝字符串到新申请的内存中返回内存指针，否则返回NULL***/
	char * temp = (char*)malloc(strlen(str) + 1);  //给temp申请内存
	assert(str != NULL && temp != NULL);  //进行检查是否为NULL
	strcpy(temp, str);  //进行拷贝
	return temp;  //返回的内存在堆中需要手动释放内存
}

int main()
{
	char *str = NULL,
		 *string = "abcde";

    str = my_strdup(string);
    printf("%s\n", str);
    free(str);  //释放内存

	return 0;
}