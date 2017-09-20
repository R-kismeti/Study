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

unsigned int my_strlen(const char * str)
{
	/***计算str的长度并返回***/
	unsigned length = 0;  //定义无符号变量length统计str的长度
	while(*str != '\0')  //判断str指向的字符是否为'\0'
	{
		length++;  //长度加1
		str++;  //指向的地址向后加1位
	}
	return length;
}

int main()
{
	char destination[200];  //定义一个大小为200的数组
    char str1[100],
    	 str2[100];
    while(scanf("%s%s", str1, str2) != EOF)
    {
    	strcpy(destination, str1);
    	my_strcat(destination, str2);
    	printf("%s\n", destination);  //打印最终结果
    }
	return 0;
}