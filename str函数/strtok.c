#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/***因strtok函数内部使用了静态指针，因此它不是线程安全的***/
static char *olds;
char *my_strtok(char *sou, char *delim)
{
	/***strtok函数用来将字符串分割成一个个片段，
	在参数sou的字符串中发现到参数delim的分割字符时则会将该字符改为\0 字符***/
	//参数sou指向欲分割的字符串，参数delim为分割字符串
	//在第一次调用时，strtok()必需给予参数sou字符串，往后的调用则将参数sou设置成NULL
	//每次调用成功则返回下一个分割后的字符串指针

	char *token = NULL;
	if(sou == NULL)  //如果sou为空则将上一次的位置给sou
	{
		sou = olds;
	}

	/*将指针移到第一个非delim的位置*/
	sou += strspn(sou, delim);
	if(*sou == '\0')  //如果是结束符，则将结束符保存并退出函数
	{
		olds = sou;
		return NULL;
	}

	/*获取delim的字符在字符串sou中第一次出现的位置*/
	token = sou;
	sou = strpbrk(token, delim);

	if(sou == NULL)
	{
		olds = __rawmemchr (token, '\0');  //参考http://dev.wikl.net/89401.html
	}
	else
	{
		*sou = '\0';  //将分隔符的位置用'\0'替换
		olds = sou + 1;  //将olds指向下一次需要操作的位置
	}
	return token;
}

int main()
{
	//strtok处理的是函数的局部状态信息，所以不能同时解析两个字符串
	char sou[100] = " Micael_SX is so good";
	char *delim = " ";
	char *token;
	token = my_strtok(sou, delim);
	while(token != NULL)
	{
    	printf("%s\n", token);
    	token = my_strtok(NULL, delim);
	}
	return 0;
}