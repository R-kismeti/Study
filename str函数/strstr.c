#include <stdio.h>
#include <string.h>
#include <assert.h>

char * my_strstr(const char * str1, char * str2)
{
	/***查找str2在str1中出现的位置，找到返回位置，否则返回NULL***/
	assert(str1 != NULL & str2 != NULL);  //检查str1和str2
	int len1 = strlen(str1);  //定len1来获取str1的长度
	int len2 = strlen(str2);  //定len2来获取str2的长度

	while(len1 >= len2)  //必须str1的长度大于str2的长度
	{
		len1--;  //str1的长度每一次减去一个
		if(!strncmp(str1, str2, len2))  //进行比较str2和str1的前len2个字符
		{
			return str2;  //如果匹配返回str2
		}
		str1++;  //str1每一次都要向后走一步
	}
	return NULL;
}

int main()
{
	char *str1 = "China is a nation!",
		 *str2 = "nation",
		 *ptr = NULL;

   	ptr = my_strstr(str1, str2);
   	printf("The string is: %s\n", ptr);
	return 0;
}