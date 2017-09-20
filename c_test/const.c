#include <stdio.h>

int main()
{
	const int cc = 1;
	int *p = (int *) &cc;

	printf("%d\n", cc);

	*p = 3;  //标准c的处理方法 //定义指针变量取地址然后对地址中的值进行修改

	//cc = 2;  //const修饰的只可读,不可修改

	printf("%d\n", cc);

	const int A[5] = {0};  //const修饰的数组的空间不可改变
	int *p1 = (int *)A;  //可以用指针改变，但是会在编译时死掉

	const int *p;  //p可变，p指向的内容不可变
	int const *p;  //p可变，p指向的内容不可变
	int *const p;  //p不可变，p指向的内容可变
	const int *const p;  //p不可变，p指向的内容不可变
	return 0;
}