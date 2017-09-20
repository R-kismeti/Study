#include <stdio.h>
#include <stdlib.h>

/*测试static的作用效果*/

static int j; //定义全局变量j

void fun1(void)
{
	static int i = 0;
	i++;  //i的值每次加1
	printf("%d\n", i);
}

void fun2(void)
{
	j = 0;
	j++;  //每一次调用函数都不会导致j的值发生改变
	printf("%d\n", j);
}

int main()
{
	for(int k = 0; k < 10; ++k)
	{
		fun1();
		fun2();
	}
	return 0;
}

