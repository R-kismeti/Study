#include <iostream>
using namespace std;

int main()
{
	void *pvoid;
	pvoid++;   //ANSI错误    GNU正确
	pvoid += 1;   //ANSI错误   GNU正确

	//进行算法操作的指针必须确定知道它指向的数据类型的大小，也就是说确定的知道内存目的地址的确切值


	int *pint;
	pint++;   //ANSI正确

	//避免 GNU 和 ANSI 的出现的不一致

	void *pvoid;
	(char *)pvoid++;   //ANSI正确； GNU正确
	(char *)pvoid += 1;   //ANSI错误；  GNU正确
	return 0;
}