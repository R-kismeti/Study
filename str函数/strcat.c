#include <stdio.h>
#include <string.h>

char * my_strcat(char* destin, const char *source)
{
	/***连接两个字符串，将source连接到destin,返回以NULL结尾***/
	char * temp = destin;  //定义temp指针变量存放destin的地址

	while(*temp)  //判断temp字符串是否读到了'\0'
	{
		temp++;  //将temp指针读到字符串末尾
	}

	while(*temp++ = *source++)	//把source字符串从temp末尾开始复制给temp
		{};

	return temp;  //返回链接好的字符串的指针
}

int main()
{
	/***对函数Strcat的调用***/
	char destination[25];  //定义一个大小为25的数组
    char *space = " ",
    	 *String = "C++!",
    	 *Hello = "Hello";

	strcpy(destination, Hello);  //进行拷贝
    my_strcat(destination, space);
    my_strcat(destination, String);

    printf("%s\n", destination);  //打印最终结果
	return 0;
}
