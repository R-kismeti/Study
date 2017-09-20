#include <stdio.h>
#include <time.h>

/*
需要调用time.h
localtime:将时间转化为本地时间
asctime:将时间转换为正常(原本为毫秒)
*/
#define LOG(s) do{	\
	time_t t;		\
	struct tm* ti;	\
	time(&t);		\
	ti = localtime(&t);		\
	printf("%s[%s:%d] %s\n", asctime(ti), __FILE__, __LINE__, s);	\
}while(0)

void f()
{
    LOG("Enter f()...\n");
    LOG("Exit f()...\n");
}

int main()
{
    LOG("Enter main...\n");
    f();
    LOG("Exit main...\n");
    return 0;
}