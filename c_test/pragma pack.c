#include <stdio.h>

#pragma pack(8)

struct s1
{
	short a;	//起始位置：0	大小：2		空白：0
	long b;		//起始位置：4	大小：4		空白：0
};

struct s2
{
	char c;			//起始位置：0	大小：1		空白：0
	struct s1 d;	//起始位置：4	大小：8		空白：0
	double e;		//起始位置：16	大小：8		空白：0
};

//结构体里面有结构体的对齐方式是取里面的结构体对齐数的最大的

int main()
{
	struct s2 s;

	printf("%d\n", sizeof(struct s1));	//8
	printf("%d\n", sizeof(struct s2));	//24
	printf("%d\n", (int)&(s.d) - (int)&(s.c));  //4

	return 0;
}