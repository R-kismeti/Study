###

####1.\#error和\#warning
1. 用法：`#error message(不需要双引号包围)`
2. 作用：#error自定义生成一个编译错误消息，并立即停止编译，#warning生成编译警告，不会停止编译。
3. 示例：

```c
#define NAME1 "NAME1"
#define NAME2 "NAME2"
//#define COMMAND "Hello"

int main()
{
	#ifdef COMMAND  //根据自己的需要条件定义的COMMAND
	#warning Complation will be stopped
	#error No Defined Constant symbol COMAND
	#endif

	printf("%s\n", COMMAND);
	printf("%s\n", NAME1);
	printf("%s\n", NAME2);
	return 0;
}
```

- linux下测试：
> gcc -DCOMMAND="hello" filename.c -o filename

####2.\#line
1. 用法：`#line number filename(可省略filename)`
2. 作用：强制指定新的行号和编译文件名，并对源程序的代码重新编号(实际中只是想做到无关，因为在一个程序中，也许前面的代码是别人写的，后面是你写的，这时候就可以进行查错)(**这种方式目前已经被淘汰**)
3. 说明：本质上是重定义`__LINE__`和`__FILE__`
4. 示例：

```c
#include <stdio.h>

#line 14 "hello.c"

#define NAME1 "NAME1"
#define NAME2 "NAME2"

void f()
{
	return 0;  //错误代码,测试程序
}

int main()
{
	printf("%s\n", NAME1);
	printf("%s\n", NAME2);
	printf("%d\n", __LINE__);
	printf("%s\n", __FILE__);

	f();

	return 0;
}
```

- 结果：(原文件名"test.c")		
`linux下编译:gcc test.c -o test`
> hello.c: In function 'f':		
> hello.c:20:9: warning: 'return' with a value, in function returning void

- 分析：
> 1.程序的`#line 14 "hello.c"`告诉编译器，此程序改为hello.c    
> 2.并且从下一行开始为指定的第14行    
> 3.可以将f函数的return注释掉，查看终端的显示有27，然而原来的行为17