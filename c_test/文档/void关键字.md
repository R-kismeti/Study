###void关键字

####1.类型：

- void 是“空类型”。
- void *则为“空类型指针”，void *可以指向任何类型的数据。

####2.void
1. 作用：
> 对函数返回的限定	
> 对函数参数的限定

2. void a
	1. 说明：因为void为无类型，在内存中偏移量为0，它声明变量a，a在内存中没有空间，所以无法定义且后面无法赋值从而报错。

	2. 变量赋值条件：
		
		> 1."="左边要指向一个有效的地址		
		> 2."="左边指向的有效的地址需要有可用的内存的空间

####3.void作用：

- 如果函数没有返回值，那么应声明为void 类型。

	> 凡是函数不加返回值类型的都当做int处理

```c

	add (int a, int b)
	{
		return a + b;
	}

```

- 如果函数无参数，那么应声明其参数为void

	> 函数不接受参数，如果不声明为void，则会出错

```c
fun()
{
	return 1;
}
int main()
{
	printf("%d\n", fun(2));
	return 0;
}
```

> 注：上面的程序在C中结果为1，在C++中编译出错：`'fun' : function does not take 1 parameters`

####4.void指针：

- 说明:

```c
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
```
> 注意：尽量使用ANSI的标准

- 函数返回值和参数的类型:

	> 这种情况在写一些通用代码的函数的时候特别灵活

```c
	/*下面的是一些系统函数，可以实现多种类型的操作，相对字符串的str函数灵活许多*/
	void * memcpy(void *dest, const void *src, size_t len);
	void * memset ( void * buffer, int c, size_t num );
	void * memmove(void *dest, const void *src, int count);
	void *my_memccpy(void *dest, const void *src, char ch, int count);
```
> 注：void指针体现了C语言对内存的操作(不区分类型)

####5.参考：
- [C语言中文网](http://c.biancheng.net/)