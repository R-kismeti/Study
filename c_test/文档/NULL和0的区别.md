###C语言NULL和0的区别详解
####**1.分析**
	0 would digit zero, that is, a numerical value.
	'0' could be the character capital oh or the character zero. For example: char word[10] = "Oxford"; char number[10] = "01234";
	Depending on typeface used 'O' may look exactly like '0' making it difficult to tell them apart out of context.
	'\0' is the null character used to terminate strings in C/C++.
	"\0" is an empty string.

- 在C语言及其派生语言中，\0不是一个单独的转义序列，而是一个以**八进制**表示常数，而常数的数值为0，\0后面不能接0至7的数字，不然会视为是一个八进制的数字。


- NULL和0的值都是**一样的**，但是为了**目的和用途及容易识别**的原因，NULL用于**指针和对象**，0用于**数值**。对于**字符串**的结尾，使用'\0'，它的值也是0，但是让人一看就知道这是字符串的结尾，不是指针，也不是普通的数值。


- 在不同的系统中，NULL并非总是和0等同，NULL仅仅代表**空值**，也就是指向一个**不被使用的地址**，在大多数系统中，都将0作为不被使用的地址，所以就有了类似这样的定义。但并非总是如此，也有些系统不将0地址作为NULL，而是用其他的地址，所以说，**千万别将NULL和0等价起来**，特别是在一些跨平台的代码中，这更是将给你带来灾难 \#define NULL 0

####**2.空指针常量**
	 An integer constant expression with the value 0, or such an expression cast to type void *, is called a null pointer constant

- NULL在stdio.h中的定义：

```c
#if !defined(NULL) && defined(__NEEDS_NULL)
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif
```


- 在c++定义为0，在c中定义为(void *)0;的原因：

> **注意：** 0、0L、'\0'、3 - 3、0 \* 17 （它们都是“integer constant expression”）以及 (void\*)0 等都是空指针常量（注意 (char*) 0 不叫空指针常量，只是一个空指针值）

- 一般的 C 系统选择 (void\*)0 或者 0 的居多（也有个别的选择 0L）；至于 C++ 系统，由于存在严格的类型转化的要求，void* 不能象 C 中那样自由转换为其它指针类型，所以通常选 0 作为空指针常量

####**3.空指针**
	If a null pointer constant is converted to a pointer type, the resulting pointer, called a null pointer, is guaranteed to compare unequal to a pointer to any object or function.

- **char \*p=0；**此时p就是一个**空指针**，不指向任何实际对象。
因此，如果 p 是一个指针变量，则 **p = 0;、p = 0L;、p = '\0';、p = 3 - 3;、p = 0 \* 17**; 中的任何一种赋值操作之后(对于 C 来说还可以是 p = (void\*)0;)，p 都成为一个空指针，由系统保证空指针不指向任何实际的对象或者函数。反过来说，任何对象或者函数的地址都不可能是空指针。**（tyc: 比如这里的(void*)0就是一个空指针**

####**4.NULL**
	The macro NULL is defined in <stddef.h> (and other headers) as a null pointer constant

- 即 NULL 是一个标准规定的宏定义，用来表示**空指针常量**。因此，除了上面的各种赋值方式之外，还可以用 **p = NULL**; 来使 p 成为一个空指针。（tyc：很多系统中的实现：**#define NULL (void\*)0**，与这里的“a null pointer constant”并不是完全一致的）

####**5.空指针的内部实现**
- 标准并没有对空指针指向内存中的什么地方这一个问题作出规定，我们**常见的**空指针一般指向 0 地址，即空指针的内部用**全 0** 来表示（zero null pointer，零空指针）；也有一些系统用一些特殊的地址值或者特殊的方式表示空指针（nonzero null pointer，非零空指针）

- **注意：**不要把空指针的内部表示等同于整数 0 的对象表示

####6.判断一个指针是否是一个空指针
- 假设 p 是一个指针变量，q 是一个同类型的空指针，要检查 p 是否是一个空指针，可以采用下列任意形式之一

		if ( p == 0 )
		if ( p == '\0' )
		if ( p == 3 - 3 )
		if ( p == NULL )
		if ( NULL == p )
		if ( !p )
		if ( p == q )

- **注意：**不可以用 memset 函数来得到一个空指针。
因为有的系统存在着“非零空指针” （nonzero null pointer），所以这时 **memset( &p, 0, sizeof(p) ); 和 p = 0;** 这两者**不等价**

####**7.自定义NULL**
	If the program declares or defines an identifier in a context in which it is reserved (other than as allowed by 7.1.4), or defines a reserved identifier as a macro name, the behavior is undefined.

- 所以，如果包含了相应的标准头文件而引入了 NULL 的话，则再在程序中重新定义NULL为不同的内容是非法的，其行为是未定义的。即NULL只能是 0

####**8.malloc分配内存失败的的返回**
	If the space cannot be allocated, a null pointer is returned.

- malloc 函数是标准C规定的库函数。在标准中明确规定了在其内存分配失败时返回的是一个 “null pointer”（空指针）

####**9.字符的结束符'\0'**
- '\0'是C++中字符串的结尾标志，存储在字符串的结尾。

- eg: char cha[5]表示可以放5个字符的字符串，由于c/c++中规定字符串的结尾标志为'\0',它虽然不计入串长，但要占内存空间.

- 一个汉字一般用两个字节表示，且c/c++中如一个数组cha[5]，有5个变量，分别是 cha[0] , cha[1] , cha[2] , cha[3] , cha[4] , 所以cha[5]可以放5个字母或者放2个汉字（1个汉字占2个字节，1个字母占一个字节），cha[5]占5个字节内存空间.

####**10.参考文章**
链接：

1. <http://www.cnblogs.com/youxin/archive/2012/03/27/2420023.html>
2. <https://zh.wikipedia.org/wiki/%E7%A9%BA%E5%AD%97%E7%AC%A6>