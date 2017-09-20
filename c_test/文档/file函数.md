###C语言文件函数

####1.说明:
    t（text）： 文本文件，可省略不写
    b（banary）： 二进制文件
    +: 读和写
    name：要打开的文件的(路径)名字
    mode：要打开的文件的模式
    FILE：文件指针(结构体)
    打开方式mode说明:
    r  :以只读方式打开文件，只允许读取，不允许写入。该文件必须存在
    r+ :以读/写方式打开文件，允许读取和写入。该文件必须存在
    rb+:以读/写方式打开一个二进制文件，允许读/写数据，文件必须存在
    rt+:以读/写方式打开一个文本文件，允许读和写，文件必须存在
    w  :以只写方式打开文件，若文件存在则长度清为0，即该文件内容消失，若不存在则创建该文件
    w+ :以读/写方式打开文件，若文件存在则文件长度清为零，即该文件内容会消失。若文件不存在则建立该文件
    a  :追加的方式打开只写文件。若文件不存在，建立该文件，否则写入的数据会被加到文件尾(EOF保留)
    a+ :以追加方式打开可读/写的文件;
    wb :以只写方式打开或新建一个二进制文件，只允许写数据
    wb+:以读/写方式打开或建立一个二进制文件，允许读和写
    wt+:以读/写方式打开或建立一个文本文件，允许读写
    at+:以读/写方式打开一个文本文件，允许读或在文本末追加数据
    ab+:以读/写方式打开一个二进制文件，允许读或在文件末追加数据

####2.fopen函数
1. 原型：`FILE *fopen(char const *name, char const *mode)`
2. 返回：打开成功返回指向FILE结构的指针，否则返回NULL
3. 注意：应该始终检查fopen的返回值！如果失败返回NULL，不检查则会把NULL指针传给后续的I/O函数
4. 同类型函数：freopen函数
> 1.原型：`FILE *freopen(char const *filename, char const *mode, FILE *stream)`	
> 2.作用：打开或者重新打开一个特定的文件流	 
> 3.函数先试图关闭要打开的文件流(有可能是以前的，也有可能是标准流的stdin、stdout、stderr),然后用指定的文件和模式打开这个流	
> 4.如果成功返回第三个参数值，否则返回NULL
5. 示例：

```c
FILE *input;
input = fopen("data3", "r");
if(input == NULL)  //检查打开是否成功
{
	perror("data3");  //返回错误的方式
	exit(EXIT_FAILURE);  //终止程序的执行
}
```
- **注：**如果错误返回: `data3:No such file or directory`

####3.flcose函数
1. 原型：`int fclose(FILE *f)`
2. 返回：成功返回零值，否则返回EOF并把错误代码存到errno
3. 示例：

```c
int main(int ac, char **av)
{
	int exit_status = EXIT_SUCCESS;
	FILE *input;
	/*当还有更多的文件名时*/
	while(*++av != NULL)
	{
		/*试图打开这个文件*/
		input = fopen(*av, "r");
		if(input == NULL)
		{
			perror(*av);
			exit_status = EXIT_FAILURE;
			continue;
		}
		/*处理文件*/
		/*关闭文件*/
		if(fclose(input) != 0)
		{
			perror("fclose");
			exit(EXIT_FAILURE);
		}
	}
	return exit_status;
}
```
- **注：**fclose会在文件关闭之前刷新缓冲区。程序一定要检查文件是否关闭，因为很可能在fclose调用之前文件就已经关闭。


####4.fgetc与getchar函数
1. 原型：`int fgetc(FILE *stream)`
	     `int getchar(void)`
2. 返回：返回整形值是为了允许函数报告文件的末尾(EOF)
3. 注意：
> 1.fgetc需要操作的流是要参数传递，getchar需要从标准输入读取并把它作为返回值返回	
> 2.getchar函数是fgetc的宏定义


####5.fputc与putchar函数
1. 原型：`int fputc(int character, FILE　*stream)`
		 `int putchar(int character)`
2. 说明：第一个参数是要被打印的字符
3. 注意：
> 1.打印之前，函数把第一个整形参数裁剪为一个无符号字符型值		
> 2.putchar函数是fputc的宏定义 	
> 如果任何原因导致函数失败，都返回EOF

---
```c
void main(int argc, char *argv[])
{
    char ch = '\0';
    FILE *file = NULL;
    if(argc != 2)
    {
        printf("Error format,Usage: display filename1\n");
        return;
    }
    if((file = fopen(argv[1], "r")) == NULL)
    {
        printf("The file <%s> can not be opened.\n", argv[1]);
        return;
    }
    while((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }
    fclose(file);
}
```
---

> `putchar('abc')`

- 上述函数只打印一个字符，打印哪个，根据编译器选择

---

- fgetc和fputc都是真正的函数，但getchar和putchar都是通过\#define指令定义的宏，宏在执行效率上稍高

####6.fprintf函数:
1. 函数原型：`int fprintf(FILE *stream, char *format[, argument,...])`
2. 功能：传送格式化输出到一个文件中
3. 参数说明：FILE\*一个FILE型的指针；char\*格式化输入函数，和printf里的格式一样
4. 返回值：成功时返回转换的字节数，失败时返回一个负数

	eg：`fprintf(fp,"%s\n",str)`

####7.fscanf函数:
1. 函数原型：`int fscanf(FILE *stream, char *format[,argument...])`
2. 功能：从一个流中执行格式化输入
3. 参数说明：FILE\*一个FILE型的指针；char\*格式化输出函数，和scanf里的格式一样
4. 返回值：成功时返回转换的字节数，失败时返回一个负数

    eg：`fscanf(fp,"%s",str)`

####8.feof函数:
1. 函数原型：int feof(FILE * stream)
2. 作用：检查文件流是否读到了文件尾(在打印的同时会打印最后一个EOF)
3. 返回值：非零值代表已到达文件尾，其他情况返回0

####9.fgets函数与fputs函数:
1. 函数原型：`char * fgets(char * s,int size,FILE * stream)` `int fputs(const char * s,FILE * stream)`
2. 函数说明：
> 1.fgets:文件内读入字符并存到参数s所指的内存空间，直到出现换行字符、读到文件尾或是已读了size-1个字符为止，最后会加上NULL作为字符串结束	
> 2.fputs:将参数s所指的字符串写入到参数stream所指的文件内
3. 返回参数说明：
> 1.fgets:成功则返回s指针，返回NULL则表示有错误发生	
> 2.fputs:成功则返回写出的字符个数，返回EOF则表示有错误发生


####10.fread函数:
1. 函数原型：`size_t fread(void * ptr, size_t size, size_t count, FILE * stream)`
2. 参数说明：stream为已打开的文件指针；ptr 指向欲存放读取进来的数据空间(一个或多个值的数组)；size是缓冲区每个元素的字节数；读取的字符数以参数size*count来决定
3. 返回参数说明：返回实际读取到的count数目(不是字节数)，如果此值比参数count 来得小，则代表可能读到了文件尾或有错误发生，这时必须用feof()或ferror()来决定发生什么事情

####11.fwrite函数:
1. 函数原型：`size_t fwrite(const void * ptr, size_t size, size_t count, FILE * stream)`
2. 参数说明：stream为已打开的文件指针，参数ptr 指向欲写入的数据地址，总共写入的字符数以参数size*count来决定
3. 返回值说明：返回实际写入的count数目

---
```c
/*从输入文件读取二进制数据并且把结果写入到一个输出文件*/
struct VALUE
{
	long a;
	float b;
	char c[SIZE];
}value[ARRAY_SIZE];
...
n_value = fread(value, sizeof(struct VALUE), ARRAY_SIZE, input_stream);
fwrite(values, sizeof(struct VALUE), n_value, output_stream);
```
---

####12.fseek函数:
1. 函数原型： `int fseek(FILE * stream,long offset,int whence)`
2. 相似函数:
> 原型：`fsetpos(FILE　*stream, fpos_t const *position)`	
> 作用：把文件位置设置为存储在这个位置(fpos_t指针)的值
3. 函数说明：用来移动文件流的读写位置
4. 参数说明：
> 1.stream为已打开的文件指针，参数offset为根据参数whence来移动读写位置的位移数	
> 2.whence类型:
>>SEEK_SET：从距文件开头offset位移量为新的读写位置(offset必须为非负值)；   
>>SEEK_CUR：以目前的读写位置往后增加offset个位移量(offset可正可负)；   
>>SEEK_END：将读写位置指向文件尾后再增加offset个位移量(offset可正可负，如果为正值将定位到文件尾的后面)(二进制流中可能不被支持，应该避免)
	
5. 备注：当whence值为SEEK_CUR 或SEEK_END时，参数offset允许负值的出现
6. 常用方式:
> 1.欲将读写位置移动到文件开头时:fseek(FILE *stream,0,SEEK_SET);	
> 2.欲将读写位置移动到文件尾时:fseek(FILE *stream,0,SEEK_END);

7. 返回参数说明：成功时则返回0，若有错误则返回-1
8. 附加说明：fseek()不像lseek()会返回读写位置，因此必须使用ftell()来取得目前读写的位置


####13.ftell函数:
1. 函数原型：`long ftell(FILE * stream)`
2. 作用：取得文件流的读取位置(下一个读取或写入将要开始的位置距离文件起始位置的偏移量)
3. 返回参数说明：当调用成功时则返回目前的读写位置，若有错误则返回-1


####14.fflush函数:
1. 函数原型： `int fflush(FILE* stream)`
2. 函数说明：强制将缓冲区内的数据写回参数stream指定的文件中
3. 返回值说明：成功返回0，失败返回EOF

---
```c
#define putchar(ch) fputc(ch, stdout)

int main(int argc, char *argv[])
{

    //char *buffer = (char *)malloc(20);
    //char *buffer = "hello world!";

    int datas[4] = {5, 6, 7, 8};
    FILE *file = NULL;
    int i = 0;

    if((file = fopen(argv[1], "r")) == NULL)
    {
        printf("Open file error!\n");
        return 0;
    }
    //fwrite(datas, sizeof(int), sizeof(datas) / sizeof(int), file);
    fseek(file, sizeof(datas) + 1, SEEK_SET);
    fread(datas, sizeof(int), sizeof(datas) / sizeof(int), file);
    for(i = 0 ; i < sizeof(datas) / sizeof(int); ++i)
    {
        printf("%4d", datas[i]);
    }
    putchar(10);
    fseek(file, 0, SEEK_SET);
    fread(datas, sizeof(int), sizeof(datas) / sizeof(int), file);
    for(i = 0 ; i < sizeof(datas) / sizeof(int); ++i)
    {
        printf("%4d", datas[i]);
    }
    putchar(10);

    /*while((ch = getchar()) != '$') 
    {
        fputc(ch, file);
    }*/

    /*if(EOF == fputs(buffer, file))
    {
        printf("Write file error!\n");
        return 0;
    }*/

    //printf("%s\n", buffer);

    /*while((ch = fgetc(file)) != EOF) 
    {
        putchar(ch);
    }*/
    /*while(!feof(file))
    {
        putchar(fgetc(file));
    }*/
    fclose(file);
    //free(buffer);

    return 0;
}
```
---

####15.clearerr函数:
1. 函数原型：`void clearerr(FILE * stream)`
2. 作用：清除文件流的错误旗标


####16.rewind函数(重设文件流的读写位置为文件开头):
1. 函数原型：`void rewind(FILE * stream)`
2. 函数说明：把文件流的读写位置移至文件开头
3. 备注：此函数相当于调用`fseek(stream, 0, SEEK_SET)`
4. 相似函数：
> 原型：`fgetpos(FILE　*stream, fpos_t, *position)`		
> 作用：在这个位置(fpos_t指针)存储文件的当前位置


####17.setbuf函数(设置文件流的缓冲区):
1. 函数原型：`void setbuf(FILE * stream,char * buf)`
2. 函数说明：在打开文件流后，读取内容之前，调用setbuf()可以用来设置文件流的缓冲区(防止I/O函数动态为它分配一个缓冲区)
3. 参数说明：参数stream为指定的文件流，参数buf指向自定的缓冲区起始地址；如果参数buf为NULL指针，则为无缓冲I/O
4. 注意：setbuf设置了另一个数组用于对流进行缓冲，数组的字符长度必须为**BUFSIZ**(在stdio.h中定义)


####18.setvbuf函数(设置文件流的缓冲区):
1. 函数原型：`int setbuffer(FILE * stream, char * buf, int mode, size_t size)`
2. 函数说明：在打开文件流后，读取内容之前，调用setvbuf()可用来设置文件流的缓冲区
3. 参数说明：stream为指定的文件流，参数buf指向自定的缓冲区起始地址，参数size为缓冲区大小，mode用于指定缓冲的类型(`_IOFBF指定一个完全缓冲的流` `_IONBF指定一个不缓冲的流` `_IOLBF指定一个行缓冲流`)
4. 注意：最好用一个长度为**BUFSIZ**(尽量为系统内部使用的缓冲区的整数倍)的字符数组作为缓冲区


####19.tmpfile函数:
1. 原型：`FILE *tmpfile(void)`
2. 作用：创建一个临时文件保存数据(当文件关闭或程序终止自动删除)
3. 说明：如果文件必须以其他模式打开或者由一个程序打开另一个程序读取则不能使用此函数，而是使用fopen函数：
4. 注：临时文件的名字创建：
> 原型：`char *tmpnam(char *name)`		
> 说明：如果参数为NULL则返回一个指向静态数组的指针，该数组包含了被创建的文件名(调用次数不超过TMP\_MAX次,便没有重名)，否则参数便假定是一个指向长度至少为L_tmpnam的字符数组的指针，且返回值为这个参数

####20.参考文章:
- 《C数组与指针》