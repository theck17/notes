---
title: C
date: 2019-03-17 10:00:00
tags: [Programming Language]
published: true
hideInList: false
feature: /post-images/c.png
---

[TOC]

# 编译 & 执行 C 程序

>```c
>//方法一：
>#include <stdio.h>
>int main()
>{
>/* 我的第一个 C 程序 */
>printf("Hello, World! \n");
>system("pause");      //暂停函数，请按任意键继续...
>return 0;
>}
>//方法二：
>1、在 *.exe 文件目录下建一个 *.bat 文件(建一个文本文档，强制改后缀为 bat)。
>2、用记事本(或其他编辑器)打开，写命令: cmd.exe cd [编译器生成的 *.exe 所在目录]。
>3、运行这个 *.bat 就会自动定位到当前 exe 的目录了，接下来只要敲自己生成的程序的名称，就可以看到结果而不闪退。
>4、补充: 也可以直接开 cmd 直接 cd 到当前目录，只要用 cmd 运行 *.exe 都可以看见结果，除非自己编译的程序本身就无法运行。
>```

## C语言编译过程

**1、预处理**  

​     **1）、宏定义展开**

​     **2）、头文件展开**

​     **3）、删除注释**

​     **4）、条件编译**

​     **格式：gcc -E a.c -o a.i**

**2、编译**

​     **1）、检查语法**

​     **2）、转化成汇编语言**

​     **格式：gcc -S a.i -o a.s**

**3、汇编**

​     **1）、将汇编语言转化成机器语言**

​     **格式：gcc -c a.s -o a.o**

**4、链接**

​     **1）、将库文件链接变成可执行文件**

​     **格式：gcc a.o -o a.exe**

## 处理由C语言函数的警告操作

**1、#define _CRT_SECURE_NO_WARNINGS放在程序第一行**

**2、#pragma warning(disable:4996**

**3、在项目中右击选择属性，在打开对话框中选择C/C++处理器**

**在预处理器定义中编辑 _CRT_SECURE_NO_WARNINGS**

##  exit和return的区别

```c
#include <stdio.h>
#include <stdlib.h>

void fun()
{
	printf("in fun\n");
	//return;
	exit(250); //结束整个程序，结束进程
}

int main(int argc, char *argv[])
{
	fun();
	printf("after fun\n");
	while(1)
	{	
	}
	return 0; //return作用：中断函数，中断main，程序就结束
	printf("main\n");

	return 0;
}
```

## 声明和定义的区别

```c
#include <stdio.h>
//1、编译器很笨，在main函数调用其它函数，只会往前找函数的定义
//2、如果找不到函数的定义，找函数的声明，如果没有声明，C编译器会有警告，C++会出错
//3、如果没有定义，直接调用一个不存在的函数，会报错
//4、如果定义没有放在main函数的前面，那么在调用函数前需要声明，声明加不加extern是一样
//5、一个函数只能定义一次，可以声明多次（注意）
//6、声明的形参变量名和定义的形参变量名可以不一样
//7、可以只声明，不定义函数（无意义），此函数不能调用
//函数的声明，告诉编译器，这个函数是有定义的，只是放在别的地方
extern int my_strlen(char buf[]);
int my_strlen(char a[]);
int my_strlen(char b[]);
int my_strlen(char c[]);
//8、声明时，形参变量名可以不写，可以只写类型，定义时，形参变量名一定要写
void fun(int, int, int);
int main(int argc, char *argv[])
{
	printf("len = %d\n", my_strlen("0123456789"));

	return 0;
}
int my_strlen(char str[])
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}	
	return i;
}
```



# 基本语法

## 标识符

* 字母数字下划线，数字写在不能开头

## 关键字

|                | 关键字   | 描述                                                         |
| -------------- | -------- | ------------------------------------------------------------ |
| 基本数据类型   | void     | 声明函数无返回值或无参数，声明无类型指针，显式丢弃运算结果   |
|                | char     | 字符型类型数据，属于整型数据的一种                           |
|                | int      | 整型数据，通常为编译器指定的机器字长                         |
|                | float    | 单精度浮点型数据，属于浮点数据的一种，小数点后保存6位        |
|                | double   | 双精度浮点型数据，属于浮点数据的一种，比float保存的精度高，小数点后保存15/16位 |
| 类型修饰关键字 | short    | 修饰int，短整型数据，可省略被修饰的int                       |
|                | long     | 修饰int，长整形数据，可省略被修饰的int                       |
|                | signed   | 修饰整型数据，有符号数据类型                                 |
|                | unsigned | 修饰整型数据，无符号数据类型                                 |
| 复杂类型关键字 | struct   | 结构体声明                                                   |
|                | union    | 共用体声明                                                   |
|                | enum     | 枚举声明                                                     |
|                | typedef  | 声明类型别名                                                 |
|                | sizeof   | 得到特定类型或特定类型变量的大小                             |
| 存储级别关键字 | auto     | 指定为自动变量，由编译器自动分配及释放。通常在栈上分配       |
|                | static   | 指定为静态变量，分配在静态变量区，修饰函数时，指定函数作用域为文件内部 |
|                | register | 指定为寄存器变量，建议编译器将变量存储到寄存器中使用，也可以修饰函数形参，建议编译器通 过寄存器而不是堆栈传递参数 |
|                | extern   | 指定对应变量为外部变量，即在另外的目标文件中定义，可以认为是约定由另外文件声明的 |
|                | const    | 与volatile合称“cv特性”，指定变量不可被当前线程/进程改变（但有可能被系统或其他线程/进程改 |
|                | volatile | 与const合称“cv特性”，指定变量的值有可能会被系统或其他进程/线程改变，强制编译器每次从内存 中取得该变量的值。 |
| 跳转结构       | return   | 用在函数体中，返回特定值（或者是void值，即不返回值）         |
|                | continue | 结束当前循环，开始下一轮循环                                 |
|                | break    | 跳出当前循环或switch结构                                     |
|                | goto     | 无条件跳转语句                                               |
| 分支结构       | if       | 条件语句                                                     |
|                | else     | 条件语句否定分支（与if连用）                                 |
|                | switch   | 开关语句（多重分支语句）                                     |
|                | case     | 开关语句中的分支标记                                         |
|                | default  | 开关语句中的“其他”分治，可选                                 |
| 循环结构       | for      | for循环结构，for(1;2;3)4;的执行顺序为1->2->4->3->2...循环，其中2为循环条件 |
|                | do       | do循环结构，do 1 while(2);的执行顺序是1->2->1...循环，2为循环条件 |
|                | while    | while循环结构，while(1) 2;的执行顺序是1->2->1...循环，1为循环条件， 以上循环语句，当循环条件 表达式为真则继续循环，为假则跳出循环 |



## system函数

```c
#include <stdlib.h>
int main(void)
{
    //打开计算器
    system("calc\n");
    //查看当前目录下文件	
    char command[50];
    strcpy( command, "dir" );
    system(command);
    printf("i love three thousand\n");
    return 0;
}
```



## 数据类型

* 整型(int)

| 类型           | 存储大小     | 值范围                                               |
| -------------- | ------------ | ---------------------------------------------------- |
| char           | 1 byte       | -128 到 127 或 0 到 255                              |
| unsigned char  | 1 byte       | 0 到 255                                             |
| signed char    | 1 byte       | -128 到 127                                          |
| int            | 2 或 4 bytes | -32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647 |
| unsigned int   | 2 或 4 bytes | 0 到 65,535 或 0 到 4,294,967,295                    |
| short          | 2 bytes      | -32,768 到 32,767                                    |
| unsigned short | 2 bytes      | 0 到 65,535                                          |
| long           | 4 bytes      | -2,147,483,648 到 2,147,483,647                      |
| unsigned long  | 4 bytes      | 0 到 4,294,967,295                                   |

* 浮点类型

| 类型        | 存储大小 | 值范围                 | 精度      |
| ----------- | -------- | ---------------------- | --------- |
| float       | 4 字节   | 1.2E-38 到 3.4E+38     | 6 位小数  |
| double      | 8 字节   | 2.3E-308 到 1.7E+308   | 15 位小数 |
| long double | 16 字节  | 3.4E-4932 到 1.1E+4932 | 19 位小数 |

* 无值型void 类型
  * 无值型字节长度为0, 主要有两个用途: 一是明确地表示一个函数不返回任何 值; 一是产生一个同一类型指针(可根据需要动态分配给其内存)。 例如: void *buffer; /*buffer被定义为无值型指针*/

| 序号 | 类型与描述                                                   |
| ---- | ------------------------------------------------------------ |
| 1    | **函数返回为空** C 中有各种函数都不返回值，或者您可以说它们返回空。不返回值的函数的返回类型为空。例如 **void exit (int status);** |
| 2    | **函数参数为空** C 中有各种函数不接受任何参数。不带参数的函数可以接受一个 void。例如 **int rand(void);** |
| 3    | **指针指向 void** 类型为 void * 的指针代表对象的地址，而不是类型。例如，内存分配函数 **void \*malloc( size_t size );** 返回指向 void 的指针，可以转换为任何数据类型。 |



* 指针型(\*)
  * 指针是一种特殊的数据类型, 在其它语言中一般没有。指针是指向变量的地址, 实质上指针就是存贮单元的地址。 根据所指的变量类型不同, 可以是整型指针 (int *)、浮点型指针(float *)、字符型指针(char *)、结构指针(struct *)和联 合指针(union *)

# 变量

## 声明和定义

**变量定义：**用于为变量分配存储空间，还可为变量指定初始值。程序中，变量有且仅有一个定义。

变量声明：用于向程序表明变量的类型和名字。

定义也是声明，extern 声明不是定义。

**定义也是声明：**当定义变量时我们声明了它的类型和名字。

**extern 声明不是定义：**通过使用 extern 关键字声明变量名而不定义它。

**[注意]**

变量在使用前就要被定义或者声明。

在一个程序中，变量只能定义一次，却可以声明多次。

定义分配存储空间，而声明不会。

```c
extern int a;     // 声明一个全局变量 a
int a;            // 定义一个全局变量 a
extern int a =0;  // 定义一个全局变量 a 并给初值。一旦给予赋值，一定是定义，定义才会分配存储空间
int a =0;         //定义一个全局变量 a，并给初值
```

## 全局变量和局部变量在内存中的区别

全局变量保存在内存的全局存储区中，占用静态的存储单元；局部变量保存在栈中，只有在所在函数被调用时才动态地为变量分配存储单元。

C语言经过编译之后将内存分为以下几个区域：

-  （1）栈（stack）：由编译器进行管理，自动分配和释放，存放函数调用过程中的各种参数、局部变量、返回值以及函数返回地址。操作方式类似数据结构中的栈。
-  （2）堆（heap）：用于程序动态申请分配和释放空间。C语言中的malloc和free，C++中的new和delete均是在堆中进行的。正常情况下，程序员申请的空间在使用结束后应该释放，若程序员没有释放空间，则程序结束时系统自动回收。注意：这里的“堆”并不是数据结构中的“堆”。
- （3）全局（静态）存储区：分为DATA段和BSS段。DATA段（全局初始化区）存放初始化的全局变量和静态变量；BSS段（全局未初始化区）存放未初始化的全局变量和静态变量。程序运行结束时自动释放。其中BBS段在程序执行之前会被系统自动清0，所以未初始化的全局变量和静态变量在程序执行之前已经为0。
-  （4）文字常量区：存放常量字符串。程序结束后由系统释放。
-  （5）程序代码区：存放程序的二进制代码。

显然，C语言中的全局变量和局部变量在内存中是有区别的。C语言中的全局变量包括外部变量和静态变量，均是保存在全局存储区中，占用永久性的存储单元；局部变量，即自动变量，保存在栈中，只有在所在函数被调用时才由系统动态在栈中分配临时性的存储单元。

```c
#include <stdio.h>
#include <stdlib.h>
int k1 = 1;
int k2;
static int k3 = 2;
static int k4;
int main( )
{  static int m1=2, m2;
    int i=1;
    char *p;
    char str[10] = "hello";
    char *q = "hello";
    p= (char *)malloc( 100 );
    free(p);
    printf("栈区-变量地址  i：%p\n", &i);
    printf("                p：%p\n", &p);
    printf("              str：%p\n", str);
    printf("                q：%p\n", &q);
    printf("堆区地址-动态申请：%p\n", p);
    printf("全局外部有初值 k1：%p\n", &k1);
    printf("    外部无初值 k2：%p\n", &k2);
    printf("静态外部有初值 k3：%p\n", &k3);
    printf("    外静无初值 k4：%p\n", &k4);
    printf("  内静态有初值 m1：%p\n", &m1);
    printf("  内静态无初值 m2：%p\n", &m2);
    printf("文字常量地址    ：%p, %s\n",q, q);
    printf("程序区地址      ：%p\n",&main);
    return0;
}
```

## 数据存储范围

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100

int e;
int f = 10;
static int g;
static int h = 10;
int main()
{
	int a = 10;
	static int b;
	static int c = 10;

	int i[10];
	int j[10] = { 0 };

	int *k;
	int *l = &a;

	char *p = "hello world";
	char ch[] = "hello world";

	const int m = 10;

	printf("局部变量a的地址:%p\n", &a);
	printf("未初始化局部静态变量b的地址:%p\n", &b);
	printf("初始化局部静态变量c的地址:%p\n", &c);
	printf("未初始化全局变量e的地址:%p\n", &e);
	printf("初始化全局变量f的地址:%p\n", &f);
	printf("未初始化静态全局变量g的地址:%p\n", &g);
	printf("初始化静态全局变量h的地址:%p\n", &h);

	printf("未初始化数组i的地址：%p\n", i);
	printf("初始化数组j的地址：%p\n", j);

	printf("未初始化指针k的地址：%p\n", &k);
	printf("初始化指针l的地址：%p\n", &l);

	printf("字符串常量p的地址：%p\n", p);
	printf("常量m的地址：%p\n", &m);

	printf("字符数组ch的地址：%p\n", ch);
	//printf("defien定义的常量", &100);
	//printf("defien定义的常量", &MAX);

	system("pause");
	return EXIT_SUCCESS;
}
```

## 堆空间

### 堆空间的开辟和释放

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{

	int a = 10;
	//定义一个变量 在堆中  单位是BYTE
	//char *p = (char *)malloc(sizeof(char));

	//*p = 100;
	//printf("%c\n", *p);

	//int arr[10];
	int * p = (int *)malloc(sizeof(int) * 10);

	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < 10; i++)
		//printf("%d\n", *(p + i));
		printf("%d\n", p[i]);

	//释放   根据首地址自动释放  如果创建完的堆空间在使用结束之后不释放 会占用系统资源
	free(p);

	system("pause");
	return EXIT_SUCCESS;
}
```

### 堆空间的误区

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	//操作野指针
	int * p = (int *)malloc(0);
	printf("%p\n", p);
	//未野指针赋值
	*p = 100;

	printf("%d\n", *p);

	//system("pause");
	//堆空间开辟没有释放  释放会报错
	//free(p);
	return EXIT_SUCCESS;
}

int * test01()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	//free(p);
	//p = NULL;
	return p;
}
int main1202()
{
	free(NULL);
	int *p = test01();
	if (!p)
		return;
	for (int i = 0; i < 10; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", p[i]);

	//先判断 在释放
	if (p != NULL)
		free(p);
	//释放完成 变成空指针
	p = NULL;
	free(p);
	return 0;
}
```



### 堆空间开辟数组冒泡排序

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
	srand((unsigned int)time(NULL));
	int * p = (int *)malloc(sizeof(int) * MAX);
	//int len = sizeof(p) 
	for (int i = 0; i < MAX; i++)
	{
		//*(p + i) = rand() % 50;
		p[i] = rand() % 50;
		//*p++ = rand() % 50;
	}
	for (int i = 0; i < MAX; i++)
	{
		printf("ÅÅÐòÇ°£º\n");
		printf("%d\n", p[i]);
	}
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = 0; j < MAX - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	printf("ÅÅÐòÇ°£º\n");

	for (int i = 0; i < MAX; i++)
	{
		printf("%d\n", p[i]);
	}
	free(p);


	system("pause");
	return EXIT_SUCCESS;
}
```



### 堆空间操作字符串

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main1401()
{

	//开辟多大堆空间 就要操作多大堆空间
	char * p = malloc(sizeof(char) * 10);//\0

	strcpy(p, "hello world");

	printf("%s", p);


	free(p);


	system("pause");
	return EXIT_SUCCESS;
}

int main()
{
	char arr[100] = "hello world";
	arr[1] = 'A';
	char * p = malloc(sizeof(char) * 100);

	char * p1 = "hello world";
	char * p2 = "hello world";
	printf("%p\n", p1);
	printf("%p\n", p2);
	strcpy(p, "hello world");
	*p = 'A';
	printf("%p\n", p);
	printf("%s\n", p);

	free(p);
	return 0;
}
```



### 内存函数操作

 ```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main1501()
{
	//int * p = (int *)malloc(sizeof(int) * 10);
	////参数：目标 值 字节大小
	//memset(p, 0, 40);
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d\n", p[i]);
	//}
	//char * p = malloc(sizeof(char) * 10);
	//memset(p, 0, 10);
	//printf("%s\n", p);


	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	memset(arr, 0, 40);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	//free(p);
	//system("pause");
	return EXIT_SUCCESS;
}
int main1502()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int *p = malloc(sizeof(int) * 10);
	//memcpy(p, arr, 40);
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d\n", p[i]);
	//}

	//free(p);

	memcpy(&arr[2], arr, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	char arr1[] = { 'h','e','l','l','o' };
	char * p = malloc(100);
	memset(p, 0, 100);
	//1、函数参数不同
	//2、strcpy拷贝字符串 memcpy 可以拷贝一块内存
	//3、拷贝结束标志不同 strcpy \0 memcpy  以个数为结尾
	strcpy(p, arr1);
	memcpy(p, arr1, 5);
	printf("%s\n", p);
	free(p);
	return 0;
}

int main1503()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//memmove拷贝重叠内存地址不会出现问题  但是效率比较低   如果拷贝源和拷贝目标没有重叠  两个函数效率一样
	memmove(&arr[2], arr, 20);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
}
int main()
{
	//int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int arr2[5] = { 1,2,3,4 };

	//int val = memcmp(arr1, arr2, 20);
	//if (!memcmp(arr1, arr2, 8))
	//{
	//	printf("前两个数组元素内容相同");
	//}
	//printf("%d\n", val);

	//int * p1 = malloc(sizeof(int) * 10);
	//char * p2 = malloc(sizeof(char) * 40);

	//memcpy(p1, "hello", 6);
	//memcpy(p2, "hello", 6);
	//if (!memcmp(p1, p2, 6))
	//{
	//	printf("内容相同\n");
	//}
	//else
	//{
	//	printf("内容不相同\n");

	//}

	int a = 0xffff;
	char b = 0xffff;
	//printf("%d\n", b);
	if (!memcmp(&a, &b, 2))
	{
		printf("内容相同\n");
	}
	else
	{
		printf("内容不相同\n");

	}

	//free(p1);
	//free(p2);
	//练习   求出三名学生 三门功课成绩 并排序   通过堆空间来实现  arr[3][3];
	int ** p = (int **)malloc(sizeof(int *) * 3);
	p[0] = (int *)malloc(sizeof(int) * 3);
	p[1] = (int *)malloc(sizeof(int) * 3);
	p[2] = (int *)malloc(sizeof(int) * 3);

	p[0][0] = 90;
	p[0][1] = 80;
	p[0][2] = 70;

	//排序
	free(p[0]);
	free(p[1]);
	free(p[2]);
	free(p);

	return 0;
}
 ```



## C 中的左值（Lvalues）和右值（Rvalues）

1. **左值（lvalue）：**指向内存位置的表达式被称为左值（lvalue）表达式。左值可以出现在赋值号的左边或右边。
2. **右值（rvalue）：**术语右值（rvalue）指的是存储在内存中某些地址的数值。右值是不能对其进行赋值的表达式，也就是说，右值可以出现在赋值号的右边，但不能出现在赋值号的左边。

变量是左值，因此可以出现在赋值号的左边。数值型的字面值是右值，因此不能被赋值，不能出现在赋值号的左边

总结：

-  当需要保存数据的时候，需要lvalues。
-  当需要读取数据的时候，需要rvalues。

* lvalues 和 rvalues 角色的相互转换
  *  根据表达式的上下文情况，lvalues 在需要 rvalues 的地方会自动转换为 rvalues。例如:
  * rvalues 永远不能转换为 lvalues

```c
int n;
int m;
m = n+2; // 这个表达式里 n 是 rvalues
```

# 常量

## 字符常量

| 转义序列 | 含义                       |
| -------- | -------------------------- |
| \\       | \ 字符                     |
| \'       | ' 字符                     |
| \"       | " 字符                     |
| \?       | ? 字符                     |
| \a       | 警报铃声                   |
| \b       | 退格键                     |
| \f       | 换页符                     |
| \n       | 换行符                     |
| \r       | 回车                       |
| \t       | 水平制表符                 |
| \v       | 垂直制表符                 |
| \ooo     | 一到三位的八进制数         |
| \xhh     | 一个或多个数字的十六进制数 |

## 定义常量

### #define 预处理器

```c
#define identifier value
#define 常量名 值
```

* **#define** 是宏定义，它不能定义常量，但宏定义可以实现在字面意义上和其它定义常量相同的功能，本质的区别就在于 **#define** 不为宏名分配内存，而 **const** 也不为常量分配内存，怎么回事呢，其实 **const** 并不是去定义一个常量，而是去改变一个变量的存储类，把该变量所占的内存变为只读！



```c
#include <stdio.h>
 
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'
 
int main()
{
 
   int area;  
  
   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);
 
   return 0;
}
```

### const 关键字

```c
const type variable = value;
const 数据类型 常量名 = 值
```

```c
#include <stdio.h>
 
int main()
{
   const int  LENGTH = 10;
   const int  WIDTH  = 5;
   const char NEWLINE = '\n';
   int area;  
   
   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);
 
   return 0;
}
```

### 区别

**const** 定义的是变量不是常量，只是这个变量的值不允许改变是常变量！带有类型。编译运行的时候起作用存在类型检查。

**define** 定义的是不带类型的常数，只进行简单的字符替换。在预编译的时候起作用，不存在类型检查。

**(1) 编译器处理方式不同**

- \#define 宏是在预处理阶段展开。
-  const 常量是编译运行阶段使用。

**(2) 类型和安全检查不同**

-  \#define 宏没有类型，不做任何类型检查，仅仅是展开。
-  const 常量有具体的类型，在编译阶段会执行类型检查。

**(3) 存储方式不同**

- \#define宏仅仅是展开，有多少地方使用，就展开多少次，不会分配内存。（宏定义不分配内存，变量定义分配内存。）
- const常量会在内存中分配(可以是堆中也可以是栈中)。

**(4) const 可以节省空间，避免不必要的内存分配。 例如：**

```c
#define NUM 3.14159 //常量宏
const doulbe Num = 3.14159; //此时并未将Pi放入ROM中 ......
double i = Num; //此时为Pi分配内存，以后不再分配！
double I= NUM; //编译期间进行宏替换，分配内存
double j = Num; //没有内存分配
double J = NUM; //再进行宏替换，又一次分配内存！
```

const 定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是象 #define 一样给出的是立即数，所以，const 定义的常量在程序运行过程中只有一份拷贝（因为是全局的只读变量，存在静态区），而 #define 定义的常量在内存中有若干个拷贝。

**(5) 提高了效率。 编译器通常不为普通const常量分配存储空间，而是将它们保存在符号表中，这使得它成为一个编译期间的常量，没有了存储与读内存的操作，使得它的效率也很高。**

**(6) 宏替换只作替换，不做计算，不做表达式求解;**

宏预编译时就替换了，程序运行时，并不分配内存。

# 内存管理

## **auto** 

是局部变量的默认存储类, 限定变量只能在函数内部使用

是自动存储，这种对象会自动创建和销毁 ，建议这个变量要放在堆栈上面，调用函数时分配内存，函数结束时释放内存。一般隐藏auto默认为自动存储类别。我们程序都变量大多是自动变量

```c
#include <stdio.h>

int main(void)
{
    auto int i = 9; /* 声明局部变量的关键字是 auto; 因可以省略, 几乎没人使用 */   
    printf("%d\n", i);  
    getchar();
    return 0;
}
```



## **register** 

代表了寄存器变量，不在内存中使用

动态和静态变量都是存放在内存中，程序中遇到该值时用控制器发指令将变量的值送到运算器中，需要存数再保存到内存中。如果频繁使用一个变量，比如一个函数体内的多次循环每次都引用该局部变量，我们则可以把局部变量的值放到CPU的寄存器中，叫寄存器变量。不需要多次到内存中存取提高效率。但是只能局部自动变量和形参可以做寄存器变量。在函数调用时占用一些寄存器，函数结束时释放。不同系统对register要求也不一样，比如对定义register变量个数，数据类型等限制，有的默认为自动变量处理。所以在程序一般也不用

```c 
#include <stdio.h>
#include <time.h>

#define TIME 1000000000
int m, n = TIME; /* 全局变量 */

int main(void)
{   
    time_t start, stop;
    register int a, b = TIME; /* 寄存器变量 */
    int x, y = TIME;          /* 一般变量   */

    time(&start);
    for (a = 0; a < b; a++);
    time(&stop);
    printf("寄存器变量用时: %ld 秒\n", stop - start);
    
    time(&start);
    for (x = 0; x < y; x++);
    time(&stop);
    printf("一般变量用时: %ld 秒\n", stop - start);
    
    time(&start);
    for (m = 0; m < n; m++);
    time(&stop);
    printf("全局变量用时: %ld 秒\n", stop - start);

    return 0;
}
```

## **extern** 

表示全局变量，即对程序内所有文件可见，类似于Java中的public关键字；

## **static**

是全局变量的默认存储类,表示变量在程序生命周期内可见

```c
#include <stdio.h>
 
/* 函数声明 */
void func1(void);
 
static int count=10;        /* 全局变量 - static 是默认的 */
 
int main()
{
  while (count--) {
      func1();
  }
  return 0;
}
 
void func1(void)
{
/* 'thingy' 是 'func1' 的局部变量 - 只初始化一次
 * 每次调用函数 'func1' 'thingy' 值不会被重置。
 */                
  static int thingy=5;
  thingy++;
  printf(" thingy 为 %d ， count 为 %d\n", thingy, count);
}
```

## 总结

| 类型           | 作用域   | 生命周期       | **存储位置**                    |
| -------------- | -------- | -------------- | ------------------------------- |
| auto变量       | 一对{}内 | 当前函数       | 栈区                            |
| static局部变量 | 一对{}内 | 整个程序运行期 | 初始化在data段，未初始化在BSS段 |
| extern变量     | 整个程序 | 整个程序运行期 | 初始化在data段，未初始化在BSS段 |
| static全局变量 | 当前文件 | 整个程序运行期 | 初始化在data段，未初始化在BSS段 |
| extern函数     | 整个程序 | 整个程序运行期 | 代码区                          |
| static函数     | 当前文件 | 整个程序运行期 | 代码区                          |
| register变量   | 一对{}内 | 当前函数       | 运行时存储在CPU寄存器           |
| 字符串常量     | 当前文件 | 整个程序运行期 | data段                          |



## 全局变量、局部变量、静态全局变量、静态局部变量的区别

**从作用域看：**

1、全局变量具有全局作用域。全局变量只需在一个源文件中定义，就可以作用于所有的源文件。当然，其他不包含全局变量定义的源文件需要用extern 关键字再次声明这个全局变量。

2、静态局部变量具有局部作用域，它只被初始化一次，自从第一次被初始化直到程序运行结束都一直存在，它和全局变量的区别在于全局变量对所有的函数都是可见的，而静态局部变量只对定义自己的函数体始终可见。

3、局部变量也只有局部作用域，它是自动对象（auto），它在程序运行期间不是一直存在，而是只在函数执行期间存在，函数的一次调用执行结束后，变量被撤销，其所占用的内存也被收回。

4、静态全局变量也具有全局作用域，它与全局变量的区别在于如果程序包含多个文件的话，它作用于定义它的文件里，不能作用到其它文件里，即被static关键字修饰过的变量具有文件作用域。这样即使两个不同的源文件都定义了相同名字的静态全局变量，它们也是不同的变量。

**从分配内存空间看：**

1、全局变量，静态局部变量，静态全局变量都在静态存储区分配空间，而局部变量在栈里分配空间

2、全局变量本身就是静态存储方式， 静态全局变量当然也是静态存储方式。这两者在存储方式上并无不同。这两者的区别虽在于非静态全局变量的作用域是整个源程序，当一个源程序由多个源文件组成时，非静态的全局变量在各个源文件中都是有效的。而静态全局变量则限制了其作用域，即只在定义该变量的源文件内有效，在同一源程序的其它源文件中不能使用它。由于静态全局变量的作用域局限于一个源文件内，只能为该源文件内的函数公用，因此可以避免在其它源文件中引起错误。

-  1)静态变量会被放在程序的静态数据存储区(全局可见)中，这样可以在下一次调用的时候还可以保持原来的赋值。这一点是它与堆栈变量和堆变量的区别。
-  2)变量用static告知编译器，自己仅仅在变量的作用范围内可见。这一点是它与全局变量的区别。

从以上分析可以看出， 把局部变量改变为静态变量后是改变了它的存储方式即改变了它的生存期。把全局变量改变为静态变量后是改变了它的作用域，限制了它的使用范围。因此static 这个说明符在不同的地方所起的作用是不同的。应予以注意。

**Tips:**

-  A.若全局变量仅在单个C文件中访问，则可以将这个变量修改为静态全局变量，以降低模块间的耦合度；
-  B.若全局变量仅由单个函数访问，则可以将这个变量改为该函数的静态局部变量，以降低模块间的耦合度；
-  C.设计和使用访问动态全局变量、静态全局变量、静态局部变量的函数时，需要考虑重入问题，因为他们都放在静态数据存储区，全局可见；
-  D.如果我们需要一个可重入的函数，那么，我们一定要避免函数中使用static变量(这样的函数被称为：带"内部存储器"功能的的函数)
-  E.函数中必须要使用static变量情况:比如当某函数的返回值为指针类型时，则必须是static的局部变量的地址作为返回值，若为auto类型，则返回为错指针。

## 内存操作函数

### memset()

\#include <string.h>

void *memset(void *s,int c, size_t n);

* 功能：将s的内存区域的前n个字节以参数c填入

* 参数：
  * s：需要操作内存s的首地址
  * c：填充的字符，c虽然参数为int，但必须是unsigned char , 范围为0~255
  * n：指定需要设置的大小

* 返回值：s的首地址

```c
int a[10];

	memset(a, 0, sizeof(a));
	memset(a, 97, sizeof(a));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%c\n", a[i]);
	}

```

###  memcpy()

\#include <string.h>

void *memcpy(void * dest, const void *src,size_t n);

* 功能：拷贝src所指的内存内容的前n个字节到dest所值的内存地址上。

* 参数：
  * dest：目的内存首地址
  * src：源内存首地址，注意：dest和src所指的内存空间不可重叠
  * n：需要拷贝的字节数

* 返回值：dest的首地址

```c
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10];
	
	memcpy(b, a, sizeof(a));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", b[i]);
	}
	printf("\n");

	//memcpy(&a[3], a, 5 * sizeof(int)); //err, 内存重叠

```

### memmove()

* memmove()功能用法和memcpy()一样，区别在于：dest和src所指的内存空间重叠时，memmove()仍然能处理，不过执行效率比memcpy()低些。

### memcmp()

\#include <string.h>

int memcmp(const void *s1,const void * s2, size_t n);

* 功能：比较s1和s2所指向内存区域的前n个字节

* 参数：

  * s1：内存首地址1

  * s2：内存首地址2

  * n：需比较的前n个字节

* 返回值：

  * 相等：=0

  * 大于：>0

  * 小于：<0

```c
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int flag = memcmp(a, b, sizeof(a));
	printf("flag = %d\n", flag);
```

### malloc()

\#include <stdlib.h>

void *malloc(size_t size);

* 功能：在内存的动态存储区(堆区)中分配一块长度为size字节的连续区域，用来存放类型说明符指定的类型。分配的内存空间内容不确定，一般使用memset初始化。

* 参数：size：需要分配内存大小(单位：字节)

* 返回值：

  * 成功：分配空间的起始地址

  * 失败：NULL

```c
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

int main()
{
	int count, *array, n;
	printf("请输入要申请数组的个数:\n");
	scanf("%d", &n);

	array = (int *)malloc(n * sizeof (int));
	if (array == NULL)
	{
		printf("申请空间失败!\n");
		return -1;
	}
	//将申请到空间清0
	memset(array, 0, sizeof(int)*n);

	for (count = 0; count < n; count++) /*给数组赋值*/
		array[count] = count;

	for (count = 0; count < n; count++) /*打印数组元素*/
		printf("%2d", array[count]);

	free(array);

	return 0;
}

```

### free()

\#include <stdlib.h>

void free(void *ptr);

* 功能：释放ptr所指向的一块内存空间，ptr是一个任意类型的指针变量，指向被释放区域的首地址。对同一内存空间多次释放会出错。

* 参数：
  * ptr：需要释放空间的首地址，被释放区应是由malloc函数所分配的区域。

* 返回值：无



# 运算符

## 算术运算符

| 运算符 | 描述                             | 实例             |
| ------ | -------------------------------- | ---------------- |
| +      | 把两个操作数相加                 | A + B 将得到 30  |
| -      | 从第一个操作数中减去第二个操作数 | A - B 将得到 -10 |
| *      | 把两个操作数相乘                 | A * B 将得到 200 |
| /      | 分子除以分母                     | B / A 将得到 2   |
| %      | 取模运算符，整除后的余数         | B % A 将得到 0   |
| ++     | 自增运算符，整数值增加 1         | A++ 将得到 11    |
| --     | 自减运算符，整数值减少 1         | A-- 将得到 9     |

## 关系运算符

| 运算符 | 描述                                                         | 实例              |
| ------ | ------------------------------------------------------------ | ----------------- |
| ==     | 检查两个操作数的值是否相等，如果相等则条件为真。             | (A == B) 不为真。 |
| !=     | 检查两个操作数的值是否相等，如果不相等则条件为真。           | (A != B) 为真。   |
| >      | 检查左操作数的值是否大于右操作数的值，如果是则条件为真。     | (A > B) 不为真。  |
| <      | 检查左操作数的值是否小于右操作数的值，如果是则条件为真。     | (A < B) 为真。    |
| >=     | 检查左操作数的值是否大于或等于右操作数的值，如果是则条件为真。 | (A >= B) 不为真。 |
| <=     | 检查左操作数的值是否小于或等于右操作数的值，如果是则条件为真。 | (A <= B) 为真。   |

## 逻辑运算符

| 运算符 | 描述                                                         | 实例              |
| ------ | ------------------------------------------------------------ | ----------------- |
| &&     | 称为逻辑与运算符。如果两个操作数都非零，则条件为真。         | (A && B) 为假。   |
| \|\|   | 称为逻辑或运算符。如果两个操作数中有任意一个非零，则条件为真。 | (A \|\| B) 为真。 |
| !      | 称为逻辑非运算符。用来逆转操作数的逻辑状态。如果条件为真则逻辑非运算符将使其为假。 |                   |

## 位运算符

| p    | q    | p & q | p \| q | p ^ q |
| ---- | ---- | ----- | ------ | ----- |
| 0    | 0    | 0     | 0      | 0     |
| 0    | 1    | 0     | 1      | 1     |
| 1    | 1    | 1     | 1      | 0     |
| 1    | 0    | 0     | 1      | 1     |

| 运算符 | 描述                                                         | 实例                                                         |
| ------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| &      | 按位与操作，按二进制位进行"与"运算。运算规则：`0&0=0;    0&1=0;     1&0=0;      1&1=1;` | (A & B) 将得到 12，即为 0000 1100                            |
| \|     | 按位或运算符，按二进制位进行"或"运算。运算规则：`0|0=0;    0|1=1;    1|0=1;     1|1=1;` | (A \| B) 将得到 61，即为 0011 1101                           |
| ^      | 异或运算符，按二进制位进行"异或"运算。运算规则：`0^0=0;    0^1=1;    1^0=1;   1^1=0;` | (A ^ B) 将得到 49，即为 0011 0001                            |
| ~      | 取反运算符，按二进制位进行"取反"运算。运算规则：`~1=0;    ~0=1;` | (~A ) 将得到 -61，即为 1100 0011，一个有符号二进制数的补码形式。 |
| <<     | 二进制左移运算符。将一个运算对象的各二进制位全部左移若干位（左边的二进制位丢弃，右边补0）。 | A << 2 将得到 240，即为 1111 0000                            |
| >>     | 二进制右移运算符。将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃。 | A >> 2 将得到                                                |

## 赋值运算符

| 运算符 | 描述                                                         | 实例                            |
| ------ | ------------------------------------------------------------ | ------------------------------- |
| =      | 简单的赋值运算符，把右边操作数的值赋给左边操作数             | C = A + B 将把 A + B 的值赋给 C |
| +=     | 加且赋值运算符，把右边操作数加上左边操作数的结果赋值给左边操作数 | C += A 相当于 C = C + A         |
| -=     | 减且赋值运算符，把左边操作数减去右边操作数的结果赋值给左边操作数 | C -= A 相当于 C = C - A         |
| *=     | 乘且赋值运算符，把右边操作数乘以左边操作数的结果赋值给左边操作数 | C *= A 相当于 C = C * A         |
| /=     | 除且赋值运算符，把左边操作数除以右边操作数的结果赋值给左边操作数 | C /= A 相当于 C = C / A         |
| %=     | 求模且赋值运算符，求两个操作数的模赋值给左边操作数           | C %= A 相当于 C = C % A         |
| <<=    | 左移且赋值运算符                                             | C <<= 2 等同于 C = C << 2       |
| >>=    | 右移且赋值运算符                                             | C >>= 2 等同于 C = C >> 2       |
| &=     | 按位与且赋值运算符                                           | C &= 2 等同于 C = C & 2         |
| ^=     | 按位异或且赋值运算符                                         | C ^= 2 等同于 C = C ^ 2         |
| \|=    | 按位或且赋值运算符                                           | C \|= 2 等同于 C = C \| 2       |

## 杂项运算符 ↦ sizeof & 三元

| 运算符   | 描述             | 实例                                 |
| -------- | ---------------- | ------------------------------------ |
| sizeof() | 返回变量的大小。 | sizeof(a) 将返回 4，其中 a 是整数。  |
| &        | 返回变量的地址。 | &a; 将给出变量的实际地址。           |
| *        | 指向一个变量。   | *a; 将指向一个变量。                 |
| ? :      | 条件表达式       | 如果条件为真 ? 则值为 X : 否则值为 Y |

## 运算符优先级

| 类别       | 运算符                            | 结合性   |
| ---------- | --------------------------------- | -------- |
| 后缀       | () [] -> . ++ - -                 | 从左到右 |
| 一元       | + - ! ~ ++ - - (type)* & sizeof   | 从右到左 |
| 乘除       | * / %                             | 从左到右 |
| 加减       | + -                               | 从左到右 |
| 移位       | << >>                             | 从左到右 |
| 关系       | < <= > >=                         | 从左到右 |
| 相等       | == !=                             | 从左到右 |
| 位与 AND   | &                                 | 从左到右 |
| 位异或 XOR | ^                                 | 从左到右 |
| 位或 OR    | \|                                | 从左到右 |
| 逻辑与 AND | &&                                | 从左到右 |
| 逻辑或 OR  | \|\|                              | 从左到右 |
| 条件       | ?:                                | 从右到左 |
| 赋值       | = += -= *= /= %=>>= <<= &= ^= \|= | 从右到左 |
| 逗号       | ,                                 | 从左到右 |

## 占位符

-  **%d, %i** 代表整数
-  **%f** 浮点
-  **%s** 以字符串形式输出
-  **%c** char
-  **%p** 指针
-  **%fL** 长log
-  **%e** 科学计数
-  **%g** 小数或科学计数。
-  **%a,%A** 读入一个浮点值(仅C99有效)。
-  **%c** 读入一个字符。
-  **%d** 读入十进制整数。
-  **%i** 读入十进制，八进制，十六进制整数。
-  **%o** 读入八进制整数。
-  **%x,%X** 读入十六进制整数（大小写）。
-  **%s** 读入一个字符串，遇空格、制表符或换行符结束。
-  **%f,%F,%e,%E,%g,%G** 用来输入实数，可以用小数形式或指数形式输入。
-  **%p** 读入一个指针。
-  **%u** 读入一个无符号十进制整数。
-  **%n** 至此已读入值的等价字符数。
-  **%[]** 扫描字符集合。
-  **%%** 读 % 符号

## 

# 判断

## if语句

```c
if(逻辑表达式boolean_expression)
{
   /* 如果布尔表达式为真将执行的语句 */
}
```

## if...else 语句

```c
if(boolean_expression)
{
   /* 如果布尔表达式为真将执行的语句 */
}
else
{
   /* 如果布尔表达式为假将执行的语句 */
}
```

## switch 语句

```c
switch(常量表达式expression){
    case constant-expression  :
       statement(s);
       break; /* 可选的 */
    case constant-expression  :
       statement(s);
       break; /* 可选的 */
  
    /* 您可以有任意数量的 case 语句 */
    default : /* 可选的 */
       statement(s);
}
```

**switch** 语句必须遵循下面的规则：

- **switch** 语句中的 **expression** 是一个常量表达式，必须是一个整型或枚举类型。
- 在一个 switch 中可以有任意数量的 case 语句。每个 case 后跟一个要比较的值和一个冒号。
- case 的 **constant-expression** 必须与 switch 中的变量具有相同的数据类型，且必须是一个常量或字面量。
- 当被测试的变量等于 case 中的常量时，case 后跟的语句将被执行，直到遇到 **break** 语句为止。
- 当遇到 **break** 语句时，switch 终止，控制流将跳转到 switch 语句后的下一行。
- 不是每一个 case 都需要包含 **break**。如果 case 语句不包含 **break**，控制流将会 *继续* 后续的 case，直到遇到 break 为止。
- 一个 **switch** 语句可以有一个可选的 **default** case，出现在 switch 的结尾。default case 可用于在上面所有 case 都不为真时执行一个任务。default case 中的 **break** 语句不是必需的。



# 循环

## while 循环

```c
while(条件condition)
{
   statement(s);
}
```



## for 循环

```c
for ( init; 条件condition; 增量increment )
{
   statement(s);
}
```



## do...while 循环

```c
do
{
   statement(s);

}while( condition );
```

# 函数

## 定义函数

```c
return_type function_name( parameter list )
{
   body of the function
}
```

- **返回类型：**一个函数可以返回一个值。**return_type** 是函数返回的值的数据类型。有些函数执行所需的操作而不返回值，在这种情况下，return_type 是关键字 **void**。
- **函数名称：**这是函数的实际名称。函数名和参数列表一起构成了函数签名。
- **参数：**参数就像是占位符。当函数被调用时，您向参数传递一个值，这个值被称为实际参数。参数列表包括函数参数的类型、顺序、数量。参数是可选的，也就是说，函数可能不包含参数。
- **函数主体：**函数主体包含一组定义函数执行任务的语句。

## 函数声明

* 函数**声明**会告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义

```
return_type function_name( parameter list );
```

## 内部函数和外部函数

> 根据函数能否被其他源文件调用，将函数区分为内部函数和外部函数

### 内部函数

如果一个函数只能被本文件中其他函数所调用，它称为内部函数。在定义内部函数时，在函数名和函数类型的前面加 static，即

```
static 类型名 函数名 （形参表）
```

例如，函数的首行：

```
static int max(int a,int b)
```

内部函数又称静态函数。使用内部函数，可以使函数的作用域只局限于所在文件。即使在不同的文件中有同名的内部函数，也互不干扰。提高了程序的可靠性。

### 外部函数

如果在定义函数时，在函数的首部的最左端加关键字 extern，则此函数是外部函数，可供其它文件调用。

如函数首部可以为

```
extern int max (int a,int b)
```

C 语言规定，如果在定义函数时省略 extern，则默认为外部函数。

在需要调用此函数的其他文件中，需要对此函数作声明（不要忘记，即使在本文件中调用一个函数，也要用函数原型来声明）。在对此函数作声明时，要加关键字 extern，表示该函数是在其他文件中定义的外部函数。

### 实例

以下实例通过多个文件的函数实现输入一串字符串，然后删除指定的字符：

file1.c(文件1)

```c
#include <stdio.h>

static void delete_string(char str[],char ch);
int main()
{
    extern void enter(char str[]); // 对函数的声明
    extern void print(char str[]); // 对函数的声明
    char c,str[100];
    enter(str);
    scanf("%c",&c);
    delete_string(str,c);
    print(str);
    return 0;
}

static void delete_string(char str[],char ch)//内部函数
{
    int i,j;
    for(i=j=0;str[i]!='\0';i++)
    if(str[i]!=ch)
    str[j++]=str[i];
    str[j]='\0';
}
```

file2.c(文件2)

```c
#include <stdio.h>

void enter(char str[100]) // 定义外部函数 enter
{
    fgets(str, 100, stdin); // 向字符数组输入字符串
}
```

file3.c(文件3)

```c
#include <stdio.h>

void print(char str[]) // 定义外部函数 print
{
    printf("%s\n",str);
}
```

输入字符串"abcdef"，给字符数组 str，在输入要删去的字符'd'。 运行结果:

```c
$ gcc file1.c file2.c file3.c 
$ ./a.out
abcdef                   # 输入的字符串
d                        # 要删除的字符
abcef                    # 删除后的字符串
```

## 内联函数

内联函数是指用inline关键字修饰的函数。在类内定义的函数被默认成内联函数。内联函数从源代码层看，有函数的结构，而在编译后，却不具备函数的性质。

内联扩展是用来**消除函数调用****时的时间开销**。它通常用于频繁执行的函数，对于小内存空间的函数非常受益。

使用内联函数的时候要注意：

- 递归函数不能定义为内联函数

- 内联函数一般适合于不存在while和switch等复杂的结构且只有1~5条语句的小函数上，否则编译系统将该函数视为普通函数。

- 内联函数只能先定义后使用，否则编译系统也会把它认为是普通函数。

- 对内联函数不能进行异常的接口声明。

**示例：**一个简单的交换函数

```c
inline void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
```

## 关于 main 函数的参数

在有些很专业的书会看到如下代码

```
int main( int argc, char *argv[] )
```

上面的代码中 main 函数带了参数。

但是有时又会看见main函数没有参数，如下：

```
int main()
```

**那么 main 函数到底有没有参数，有没有参数会不会有什么影响？**

main 函数其实与我们写的函数没有什么区别，它也会有自己的参数。

argc 和 argv 是 main 函数的形式参数。

这两个形式参数的类型是系统规定的。如果 main 函数要带参数，就是这两个类型的参数；否则main函数就没有参数。

变量名称argc和argv是常规的名称，当然也可以换成其他名称。在传入参数后main函数收到参数后就会做自己的事。那么，实际参数是如何传递给main函数的argc和argv的呢？我们知道，C程序在编译和链接后，都生成一个exe文件，执行该exe文件时，可以直接执行；也可以在命令行下带参数执行，命令行执行的形式为：可执行文件名称 参数1 参数2 ... ... 参数n。可执行文件名称和参数、参数之间均使用空格隔开。

如果按照这种方法执行，命令行字符串将作为实际参数传递给main函数。具体为：

-  (1) 可执行文件名称和所有参数的个数之和传递给 argc；
-  (2) 可执行文件名称（包括路径名称）作为一个字符串，首地址被赋给 argv[0]，参数1也作为一个字符串，首地址被赋给 argv[1]，... ...依次类推。



# 数组

## 声明数组

```c
type arrayName [ arraySize ];
double a[10];
//求出数组元素个数：
int （size_t） unsigned int 个数  = sizeof(数组名)/sizeof(数组元素 | 数组数据类型) 
//求出数组地址：
printf("%p\n",数组名)
printf("%p\n",数组元素)
```

## 初始化数组

```c
double a[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
double a[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
```

对于数组的初始化需要注意以下几点：

1) 可以只给部分元素赋值，当 **{ }** 中值的个数少于元素个数时，只给前面部分元素赋值。例如：

```
int a[10]={12, 19, 22 , 993, 344};
```

表示只给 **a[0]~a[4] 5** 个元素赋值，而后面 **5** 个元素自动初始化为 **0**。

当赋值的元素少于数组总体元素的时候，不同类型剩余的元素自动初始化值说明如下：

-  对于 short、int、long，就是整数 **0**；
-  对于 char，就是字符 **'\0'**；
-  对于 float、double，就是小数 **0.0**。

我们可以通过下面的形式将数组的所有元素初始化为 0：

```c
int nums[10] = {0};
char str[10] = {0};
float scores[10] = {0.0};
```

由于剩余的元素会自动初始化为 0，所以只需要给第 0 个元素赋值为 0 即可。

2) 只能给元素逐个赋值，不能给数组整体赋值。例如给 10 个元素全部赋值为 1，只能写作：

```c
int a[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
```

而不能写作：

```c
int a[10] = 1;
```

## 强化训练

### 一维数组的最值

```c
#include <stdio.h>

int main()
{
	int a[] = {  1, -2, 3,- 4, 5, -6, 7, -8, -9, 10 };//定义一个数组，同时初始化所有成员变量

	int i = 0;
	int max = a[0];
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	printf("数组中最大值为：%d\n", max);
	return 0;
}

```

### 一维数组的逆置

```c
#include <stdio.h>

int main()
{
	int a[] = {  1, -2, 3,- 4, 5, -6, 7, -8, -9, 10 };//定义一个数组，同时初始化所有成员变量

	int i = 0;
	int j = sizeof(a) / sizeof(a[0]) -1;
	int tmp;

	while (i < j)
	{
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		i++;
		j--;
	}

	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

```

### 冒泡排序

```c
#include <stdio.h>

int main()
{
	int a[] = {  1, -2, 3,- 4, 5, -6, 7, -8, -9, 10 };//定义一个数组，同时初始化所有成员变量

	int i = 0;
	int j = 0;
	int n = sizeof(a) / sizeof(a[0]);
	int tmp;

	//1、流程
	//2、试数
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n - i -1 ; j++)//内循环的目的是比较相邻的元素，把大的放到后面
		{
			if (a[j]  > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

```



## 二维数组

数据类型 数组名【行个数】【列个数】

初始化方式：

​       int arr[2][3] = { {1,2,3},{2,3,4} };

​       int arr[][3] = { {1,2,3},{2,3,4},{3,4,5} };

​       int arr[4][3] = { 1,2,3,4,5,6,7,8,9,10 };//arr[3][1] arr[3][2]

​       int arr[4][3] = { {1},{1} ,{1} };

​       int arr[4][3] = { 1,2,3,4 };

求行数：sizeof(数组名)/sizeof(数组名[0]);

求列数：sizeof(数组名[0])/sizeoef(数组名[0])



二维数组首地址表示方式：

printf("%p\n",数组名);

## 数组和指针的关系

1. 函数的参数中 数组类型参数 `int a[]`本质是指针 可以直接换成 `int *a`;
2. 可以用数组的运算符`[]`进行运算，而且可以通过`a[0]`就直接修改了外面的数组元素;
3. `size of(a) == sizeof(int *)` 所以函数内部没法用`sizeof`得到数组的长度 只能传一个`len`;

```c
// 一个整型数组的指针，长度为 len， 得到数组中的最小值和最大值 ———— 从外部传入两个指针，从而将所求的两个结果保存带出来，得到多个返回值。
void minMax(int a[], int len, int *min, int *max) {
    int i;
    
    *min = *max = a[0]; //假定最大值 最小值相等 为a[0]  
    
    for(i= 1; i < len, i++) {
        if( a[i] < *min) {
          *min = a[i];
        }
        
        if(a[i] > *max) {
          *max = a[i];
        }
    }

}

int a[] = {1, 2, 3, 4, 5, 7, 8, 9, 15, 18, 25, 33};
int min, max;
minMax(a, sizeof(a)/ sizeof(a[0]), &min , &max );
printf( "min = %d, max = %d \n",  min,  max);
```

- 数组变量是特殊的指针，数组变量本身表达地址，int a[10];   int *p =a;
- 数组变量无需用取址符& ;
- 数组的元素表达的是变量，需要用&取地址,如 m = &a[0];
- `[]`运算符可以对数组做，也可以对指针做 `p[0] == a[0]`;
- `*`运算符可以对指针做，也可以对数组做 `*a = 25`, *a可以得到或者修改数组首个元素的值;
- 实际上数组是 const 的指针，所以不能被赋值。 如果 `int a[] = {1,2,5,7}`; `int b[]`，由于 `int b[]`实质上等价于 <===> int const *b;    b 是一个常数，不能被改变，初始化出来代表这个数组就不能再改变。 b = a; (错误) 数组变量之间是不可以这样互相赋值的。 而 int *q = a; 这样是可以的。

## 随机数

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

/*
1、添加头文件 time.h  stdlib.h
2、添加随机数种子 srand((unsigend int )time(NULL));
3、生成随机数 rand()  %  
*/
int main15()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		printf("%d\n", rand() % 11 + 50);//50-60
	}


	//system("pause");
	return EXIT_SUCCESS;
}
```

## enum(枚举)

> 枚举是 C 语言中的一种基本数据类型，它可以让数据更简洁，更易读

### 枚举变量的定义

**1、先定义枚举类型，再定义枚举变量**

```
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
enum DAY day;
```

**2、定义枚举类型的同时定义枚举变量**

```
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
```

**3、省略枚举名称，直接定义枚举变量**

```
enum
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
```

### 将整数转换为枚举

```c
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 
    enum day
    {
        saturday,
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday
    } workday;
 
    int a = 1;
    enum day weekend;
    weekend = ( enum day ) a;  //类型转换
    //weekend = a; //错误
    printf("weekend:%d",weekend);
    return 0;
}
```



# 指针

> **指针**是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，对其进行声明。指针变量声明的一般形式为：
>
> ```c
> type *var-name;
> //1、32位编译器用32位大小(4字节)保存地址
> //2、64位编译器用64位大小(8字节)保存地址
> ```

## 一个实例

```c
#include <stdio.h>
 
int main ()
{
   int  var = 20;   /* 实际变量的声明 */
   int  *ip;        /* 指针变量的声明 */
   ip = &var;  /* 在指针变量中存储 var 的地址 */
   printf("%p\n", &var  );
   /* 在指针变量中存储的地址 */
   printf("%p\n", ip );
   /* 使用指针访问值 */
   printf("%d\n", *ip );
   return 0;
}
```

## 空指针(NULL)、万能指针

* 野指针：野指针是指向一个未知的内存空间，可能在读写的时候出现错误。

 0-255都是系统保留的 不可以读，不可以写

* 空指针 没有指向任何的地址（其指向0的地址）

空制指针就是指向内存编号为零的空间，操作该内存空间会报错，一般情况空指针用于程序条件判断

* 万能指针：void *  指针可以指向任意变量的内存空间

```c
#include <stdio.h>
 
int main ()
{
    //1、空指针，给指针变量赋值为NULL
	//2、NULL就是数字0
   int  *ptr = NULL;
 
   printf("ptr的地址是 %p\n", ptr  );
 
   return 0;
}
```

## 

```c
#include <stdio.h>

int main(int argc, char *argv[])
{
	//1、指针也是一种数据类型
	//p是一个变量，p的类型是int *
	int * p;
	p = 123;
	printf("%d\n", p);
	//2、指针指向谁，就把谁的地址赋值给指针
	int a = 10;
	p = &a; //p保存了a的地址
	//%p打印地址，是以16进制方式打印
	printf("%p, %p\n", p, &a);
	//3、直接操作指针变量本身没有意义
	//4、需要操作*p，操作指针所指向的内存
	*p = 100; //*p相当于a
	printf("%d, %d\n", *p, a);
	return 0;
}
```

### const修饰的指针变量

```c
//1.通过指针修改const修饰的常量
const int a = 10;
int *p += &a;
*p = 100;
a =100;
//可以通过1级指针修改一个常量的值

//2.const修饰指针类型 int * 不能改变指针变量指向的内存地址的值 但是可以改变指针指向的地址 
const int *p = &a
p=&b
*p = 100
//可以改变指针指向的地址

//3.const修饰指针变量    能改变指针指向地址的值，但不能改变指针指向的地址
int * const p = &a;
*p = 100;
 p=&b
//可以修改指针指向地址的值

//4.const修饰指针类型修饰指针变量  不能改变指针指向的的值 也不能改变指针指向的地址 
const int * const *p = &a;
*p =100;
p = &b;


#include <stdio.h>
int main(int argc, char *argv[])
{
	//1、指针变量
	//2、指针所指向的空间
    
	int a = 10;
	int *p1 = &a;
	*p1 = 100; //等价于操作a， *p1操作指针所指向的空间
	p1 = NULL; //操作指针变量
    
	//const修饰*，代表指针所指向的内存是只读
	const int *p2 = &a;
	//*p2 = 100; //err
	p2 = NULL; //ok
    
	//const修饰*，代表指针所指向的内存是只读
	int const *p3 = &a;
	//*p3 = 100;
	p3 = NULL;
    
	//const修饰指针变量，代表指针变量的值为只读
	int *  const p4 = &a;
	*p4 = 100; //ok
	//p4 = NULL; //err
    
	const int *  const p5 = &a;
    
	return 0;
}
```



## 指针的算术运算

### 递增一个指针

```c
#include <stdio.h>

const int MAX = 3;

int main ()
{
   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* 指针中的数组地址 */
   ptr = var;
   for ( i = 0; i < MAX; i++)
   {

      printf("存储地址：var[%d] = %x\n", i, ptr );
      printf("存储值：var[%d] = %d\n", i, *ptr );

      /* 移动到下一个位置 */
      ptr++;
   }
   return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```c
存储地址：var[0] = bf882b30
存储值：var[0] = 10
存储地址：of var[1] = bf882b34
存储值： var[1] = 100
存储地址：of var[2] = bf882b38
存储值：var[2] = 200
```

### 递减一个指针

```c
#include <stdio.h>

const int MAX = 3;

int main ()
{
   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* 指针中最后一个元素的地址 */
   ptr = &var[MAX-1];
   for ( i = MAX; i > 0; i--)
   {

      printf("存储地址：var[%d] = %x\n", i-1, ptr );
      printf("存储值：var[%d] = %d\n", i-1, *ptr );

      /* 移动到下一个位置 */
      ptr--;
   }
   return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```
存储地址：var[2] = 518a0ae4
存储值：var[2] = 200
存储地址：var[1] = 518a0ae0
存储值：var[1] = 100
存储地址：var[0] = 518a0adc
存储值：var[0] = 10
```



### 指针的比较

> 指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。就像其他变量或常量一样，您必须在使用指针存储其他变量地址之前，对其进行声明。
>
> 要理解指针就要先理解计算机的内存。计算机内存会被划分为按顺序编号的内存单元。每个变量都是存储在内存单元中的，称之为地址

```c
#include <stdio.h>

int main ()
{
    int var = 20;   /* 实际变量的声明 此时的 VAR 这个变量是存在某个地址的，地址对应某个内存单元，该单元中存储了数据20 */
    int *ip;         /* 指针变量的声明 定义了一个指针 即一个内存单元的地址变量 */

    ip = &var;      /* 在指针变量中存储 var 的地址 就是将地址值赋值给指针这个变量*/

    /* 在指针变量中存储的地址 利用&符号直接输出了var所存储的数据的内存单元的地址*/
    printf("Address of var variable: %p\n", &var );
    
    /* 在指针变量中存储的地址 ip代表的是这个赋值到的地址的值 所以输出的是地址值 */
    printf("Address stored in ip variable: %p\n", ip );
    
    /* 使用指针访问值 *ip代表的是定义到这个内存单元之后，内存单元中所存储的数据的值也就是将20赋值给var中20这个值 */
    printf("Value of *ip variable: %d\n", *ip );

    return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```
Address of var[0] = bfdbcb20
Value of var[0] = 10
Address of var[1] = bfdbcb24
Value of var[1] = 100
Address of var[2] = bfdbcb28
Value of var[2] = 200
```

## 指针数组和数组指针的区别

>原贴链接：<https://blog.csdn.net/u013719339/article/details/80563247>
>
>**指针数组**
>
>1、存储char *类型的地址数组
>
> char * arr[] ={"hello","world","niao","baobei"};
>
>2、指针数组，它是数组，数组的每个元素都是指针类型。
>
>指针数组：指针数组可以说成是”指针的数组”，首先这个变量是一个数组。
>
>**数组指针**
>
>数组指针：数组指针可以说成是”数组的指针”，首先这个变量是一个指针。
>
>其次，”数组”修饰这个指针，意思是说这个指针存放着一个数组的首地址，或者说这个指针指向一个数组的首地址。

* 首先，理解一下数组指针和指针数组这两个名词：“数组指针”和“指针数组”，只要在名词中间加上“的”字，就知道中心了——
  * 数组的指针：是一个指针，什么样的指针呢？指向数组的指针。
  * 指针的数组：是一个数组，什么样的数组呢？装着指针的数组。

* 然后，需要明确一个优先级顺序：()>[]>**，所以：*
  * (*p)[n]：根据优先级，先看括号内，则p是一个指针，这个指针指向一个一维数组，数组长度为n，这是“数组的指针”，即数组指针；
  * *p[n]：根据优先级，先看[]，则p是一个数组，再结合星号，这个数组的元素是指针类型，共n个元素，这是“指针的数组”，即指针数组。

根据上面两个分析，可以看出，p是什么，则词组的中心词就是什么，即数组“指针”和指针“数组”。

 

**数组指针 (*p)[n]**
数组指针：是指针——指向数组的指针。

```c
#include "stdafx.h"

int main()
{
	//一维数组
	int a[5] = { 1, 2, 3, 4, 5 };
	//步长为5的数组指针，即数组里有5个元素
	int (*p)[5];
	//把数组a的地址赋给p，则p为数组a的地址，则*p表示数组a本身
	p = &a;
    //%p输出地址, %d输出十进制
    //\n回车
    //在C中，在几乎所有使用数组的表达式中，数组名的值是个指针常量，也就是数组第一个元素的地址，它的类型取决于数组元素的类型。
    printf("%p\n", a); //输出数组名，一般用数组的首元素地址来标识一个数组，则输出数组首元素地址
    printf("%p\n", p); //根据上面，p为数组a的地址，输出数组a的地址
    printf("%p\n", *p); //*p表示数组a本身，一般用数组的首元素地址来标识一个数组
    printf("%p\n", &a[0]); //a[0]的地址
    printf("%p\n", &a[1]); //a[1]的地址
    printf("%p\n", p[0]); //数组首元素的地址
    printf("%d\n", **p); //*p为数组a本身，即为数组a首元素地址，则*(*p)为值，当*p为数组首元素地址时，**p表示首元素的值1
    printf("%d\n", *p[0]); //根据优先级，p[0] 表示首元素地址，则*p[0]表示首元素本身，即首元素的值1
    printf("%d\n", *p[1]); //为一个绝对值很大的负数，不表示a[1]...表示什么我还不知道
        //将二维数组赋给指针
    int b[3][4];
    int(*pp)[4]; //定义一个数组指针，指向含4个元素的一维数组
    pp = b; //将该二维数组的首地址赋给pp，也就是b[0]或&b[0]，二维数组中pp=b和pp=&b[0]是等价的
    pp++; //pp=pp+1，该语句执行过后pp的指向从行b[0][]变为了行b[1][]，pp=&b[1]

    int k;
    scanf_s("%d", &k);

    return 0;
}
```


根据上面二维数组可以得出，数组指针也称指向一维数组的指针，所以数组指针也称行指针。

**指针数组 *p[n]**
指针数组：是数组——装着指针的数组。

```c
#include "stdafx.h"

int main()
{
	int a = 1;
	int b = 2;
	int *p[2];
	p[0] = &a;
	p[1] = &b;
    printf("%p\n", p[0]); //a的地址
    printf("%p\n", &a); //a的地址
    printf("%p\n", p[1]); //b的地址
    printf("%p\n", &b); //b的地址
    printf("%d\n", *p[0]); //p[0]表示a的地址，则*p[0]表示a的值
    printf("%d\n", *p[1]); //p[1]表示b的地址，则*p[1]表示b的值
    //将二维数组赋给指针数组
    int *pp[3]; //一个一维数组内存放着三个指针变量，分别是p[0]、p[1]、p[2]，所以要分别赋值
    int c[3][4];
    for (int i = 0; i<3; i++)
        pp[i] = c[i];

    int k;
    scanf_s("%d", &k);

    return 0;
}
```

 

最后，从上文来看：

数组指针是一个指针变量，占有内存中一个指针的存储空间；

指针数组是多个指针变量，以数组的形式存储在内存中，占有多个指针的存储空间。

指向二维数组，取值：

```c
#include "stdafx.h"

int main()
{
	/*同时指向二维数组时，引用、用数组名引用表达是相同的
	定义一个2行3列的二维整型数组
	0 1 2
	3 4 5
	输出第1行第2列的值：5*/
    int a[2][3] = { {0, 1, 2}, {3, 4, 5} }; //2行3列的二维整型数组
    int(*p)[3]; //数组指针，指向含有3个元素的一维数组
    int *q[2]; //指针数组，一个数组内存放2个指针变量

    p = a;
    q[0] = a[0];
    q[1] = a[1];

    //输出第1行第2列的值
    printf("%d\n", a[1][2]); //5

    printf("%d\n", *(p[1] + 2)); //5
    printf("%d\n", *(*(p + 1) + 2)); //5
    printf("%d\n", (*(p + 1))[2]); //5
    printf("%d\n", p[1][2]); //5

    printf("%d\n", *(q[1] + 2)); //5
    printf("%d\n", *(*(q + 1) + 2)); //5
    printf("%d\n", (*(q + 1))[2]); //5
    printf("%d\n", q[1][2]); //5
    int k;
    scanf_s("%d", &k);

    return 0;
}
```

## 多级指针

```c
#include <stdio.h>
 
int main ()
{
   int  var;
   int  *ptr;
   int  **pptr;
   var = 3000;
   /* 获取 var 的地址 */
   ptr = &var;
   /* 使用运算符 & 获取 ptr 的地址 */
   pptr = &ptr;
   /* 使用 pptr 获取值 */
   printf("Value of var = %d\n", var );
   printf("Value available at *ptr = %d\n", *ptr );
   printf("Value available at **pptr = %d\n", **pptr);
   return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```
Value of var = 3000
Value available at *ptr = 3000
Value available at **pptr = 3000
```

## 指针和函数

* 指针作为函数的参数

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1、数组作为函数参数可以退化为指针
//2、在传递数组时需要加上数组的个数

void print01(int * arr,int len)
{
	//函数参数中如有有数组  都会转化为指针  sizeof(int *)  4  所以求出来的值不能作为数组的循环条件存在
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", arr[i]);
	}
}
int main301()
{

	int arr[] = { 1,2,3,4,6,0,7,8,9,10 };

	print01(arr,sizeof(arr)/sizeof(arr[0]));
	system("pause");
	return EXIT_SUCCESS;
}
void print(char * arr)
{
	//两种方式可以求出字符串长度 \0
	int len = strlen(arr);
	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}
}
int main302(void)
{
	//char arr[] = "hello world";
	char arr[] = { 'h','e','l','l','o' };
	print(arr);
	return 0;
}
```

* 函数的返回值是指针

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int aa = 10;

char * test()
{
	//字符数组  创建位置在栈区  
	//char arr[] = "hello world";
	//字符串常量  会在程序运行时   常量区  不能被修改的 在程序结束时 销毁
	char * arr = "hello world";
	//static 
	aa = 100;
	//保证指针地址对应的值是有内容的
	return arr;
}
int main04()
{
	char * p = test();
	printf("%p\n", p);
	printf("%s\n", p);

	system("pause");
	return EXIT_SUCCESS;
}
```



## 指针的一些复杂说明

-  **int p;** -- 这是一个普通的整型变量
-  **int \*p;** -- 首先从 p 处开始,先与*结合,所以说明 p 是一个指针, 然后再与 int 结合, 说明指针所指向的内容的类型为 int 型。所以 p 是一个返回整型数据的指针。
-  **int p[3]** -- 首先从 p 处开始,先与[] 结合,说明 p 是一个数组, 然后与 int 结合, 说明数组里的元素是整型的, 所以 p 是一个由整型数据组成的数组。
-  **int \*p[3];** -- 首先从 p 处开始, 先与 [] 结合, 因为其优先级比 * 高,所以 p 是一个数组, 然后再与 * 结合, 说明数组里的元素是指针类型, 然后再与 int 结合, 说明指针所指向的内容的类型是整型的, 所以 p 是一个由返回整型数据的指针所组成的数组。
-  **int (\*p)[3];** -- 首先从 p 处开始, 先与 * 结合,说明 p 是一个指针然后再与 [] 结合(与"()"这步可以忽略,只是为了改变优先级), 说明指针所指向的内容是一个数组, 然后再与int 结合, 说明数组里的元素是整型的。所以 p 是一个指向由整型数据组成的数组的指针。
-  **int \**p;** -- 首先从 p 开始, 先与 * 结合, 说是 p 是一个指针, 然后再与 * 结合, 说明指针所指向的元素是指针, 然后再与 int 结合, 说明该指针所指向的元素是整型数据。由于二级指针以及更高级的指针极少用在复杂的类型中, 所以后面更复杂的类型我们就不考虑多级指针了, 最多只考虑一级指针。
-  **int p(int);** -- 从 p 处起,先与 () 结合, 说明 p 是一个函数, 然后进入 () 里分析, 说明该函数有一个整型变量的参数, 然后再与外面的 int 结合, 说明函数的返回值是一个整型数据。
-  **int (\*p)(int);** -- 从 p 处开始, 先与指针结合, 说明 p 是一个指针, 然后与()结合, 说明指针指向的是一个函数, 然后再与()里的 int 结合, 说明函数有一个int 型的参数, 再与最外层的 int 结合, 说明函数的返回类型是整型, 所以 p 是一个指向有一个整型参数且返回类型为整型的函数的指针。
-  **int \*(\*p(int))[3];** -- 可以先跳过, 不看这个类型, 过于复杂从 p 开始,先与 () 结合, 说明 p 是一个函数, 然后进入 () 里面, 与 int 结合, 说明函数有一个整型变量参数, 然后再与外面的 * 结合, 说明函数返回的是一个指针, 然后到最外面一层, 先与[]结合, 说明返回的指针指向的是一个数组, 然后再与 * 结合, 说明数组里的元素是指针, 然后再与 int 结合, 说明指针指向的内容是整型数据。所以 p 是一个参数为一个整数据且返回一个指向由整型指针变量组成的数组的指针变量的函数。



# 字符串

## 字符串排序

```c
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//
////字符串排序根据首字母排序
////student tree new bee  bee new student tree
//
//void bubble(char ** arr,int len)
//{
//	for (int i = 0; i < len - 1; i++)
//	{
//		for (int j = 0; j < len - i - 1; j++)
//		{
//			//对比两个字符串的首字母
//			//1.指针判断
//			//if (**(arr + j) < **(arr + j + 1))
//			//{
//			//	char * temp = *(arr+j);
//			//	*(arr + j) = *(arr + j + 1);
//			//	*(arr + j + 1) = temp;
//			//}
//			//2.数组判断
//			//if (arr[j][0] > arr[j+1][0])
//			//{
//			//	char * temp = arr[j];
//			//	arr[j] = arr[j+1];
//			//	arr[j + 1] = temp;
//			//}
//			//3.混合判断
//			if (*arr[j] > *arr[j + 1])
//			{
//				char * temp = arr[j];
//				arr[j] = arr[j+1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	char *arr[] = { "cshdf", "ehsdhf", "bjhdjfhd","abee" };
//
//	/*arr[0][0]
//	student //arr[0]
//	tree//arr[1]
//	new
//	bee
//	*/
//	bubble(arr, 4);
//
//	for (int i = 0; i < 4; i++)
//	{
//		printf("%s\n", arr[i]);
//	}
//	//printf("%c\n", arr[0][0]);
//	//printf("%c\n", arr[1][0]);
//	//printf("%c\n", arr[2][0]);
//	//printf("%c\n", arr[3][0]);
//
//
//	system("pause");
//	return EXIT_SUCCESS;
//}
```



## 字符串的初始化

```c
#include <stdio.h>

// C语言没有字符串类型，通过字符数组模拟
// C语言字符串，以字符‘\0’, 数字0
int main()
{
	//不指定长度, 没有0结束符，有多少个元素就有多长
	char buf[] = { 'a', 'b', 'c' };
	printf("buf = %s\n", buf);	//乱码

	//指定长度，后面没有赋值的元素，自动补0
	char buf2[100] = { 'a', 'b', 'c' };
	printf("buf2 = %s\n", buf2);

	//所有元素赋值为0
	char buf3[100] = { 0 };

	//char buf4[2] = { '1', '2', '3' };//数组越界

	char buf5[50] = { '1', 'a', 'b', '0', '7' };
	printf("buf5 = %s\n", buf5);

	char buf6[50] = { '1', 'a', 'b', 0, '7' };
	printf("buf6 = %s\n", buf6);

	char buf7[50] = { '1', 'a', 'b', '\0', '7' };
	printf("buf7 = %s\n", buf7);

	//使用字符串初始化，编译器自动在后面补0，常用
	char buf8[] = "agjdslgjlsdjg";

	//'\0'后面最好不要连着数字，有可能几个数字连起来刚好是一个转义字符
	//'\ddd'八进制字义字符，'\xdd'十六进制转移字符
	// \012相当于\n
	char str[] = "\012abc";
	printf("str == %s\n", str);

	return 0;
}

```

## 字符串的输入输出

```c
#include <stdio.h>

int main()
{
	char str[100];
   
	printf("input string1 : \n");
	scanf("%s", str);//scanf(“%s”,str)默认以空格分隔
	printf("output:%s\n", str);

	return 0;
}

```



## 字符串追加

```c
#include <stdio.h>

int main()
{
	char str1[] = "abcdef";
	char str2[] = "123456";
	char dst[100];

	int i = 0;
	while (str1[i] != 0)
	{
		dst[i] = str1[i];
		i++;
	}

	int j = 0;
	while (str2[j] != 0)
	{
		dst[i + j] = str2[j];
		j++;
	}
	dst[i + j] = 0; //字符串结束符

	printf("dst = %s\n", dst);

	return 0;
}

```

## 去空字符串

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *  removeSpace(char * arr)
{
	//char temp[100];
	char * start = arr;
	//字符串有效长度需要-1为数组元素下标
	char * end = arr + strlen(arr)-1;
	while (*end ==' ' && end > start)
	{
		end--;
	}
	*(end+1) = '\0';
	while (*start == ' ' && start < end)
	{
		start++;
	}
	return start;
}

int main01()
{

	//char arr[] = "       你好         ";

	//char * p= removeSpace(arr);
	//printf("%s\n", p);
    
	//printf("%d\n", sizeof(int **));
	//printf("%d\n", sizeof(int ***));
	//printf("%d\n", sizeof(void *));

	float arr[10] = {1,2,3};
	//printf("%p\n", &arr[0]);
	//printf("%p\n", &arr[0]+1);
	//&arr[0] + 1;
	char *p = arr;
	*(float *)p = 1000;
	printf("%f\n", arr[0]);
	//*((int *)p + 1) = 2000;
	//printf("%d\n", arr[2]);
	//int *p1 = arr;
	//int *p2 = &arr[1];
	//int len = p2 - p1;
	//printf("%d\n", len);
	//system("pause");
	return EXIT_SUCCESS;
}
```



## 产生随机数

* 当调用函数时，需要关心5要素：
  * 头文件：包含指定的头文件

  * 函数名字：函数名字必须和头文件声明的名字一样
  * 功能：需要知道此函数能干嘛后才调用
  * 参数：参数类型要匹配
  * 返回值：根据需要接收返回值

```c
#include <time.h>
time_t time(time_t *t);
功能：获取当前系统时间
参数：常设置为NULL
返回值：当前系统时间, time_t 相当于long类型，单位为毫秒

#include <stdlib.h>
void srand(unsigned int seed);
功能：用来设置rand()产生随机数时的随机种子
参数：如果每次seed相等，rand()产生随机数相等
返回值：无

#include <stdlib.h>
int rand(void);
功能：返回一个随机数值
参数：无
返回值：随机数


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	time_t tm = time(NULL);//得到系统时间
	srand((unsigned int)tm);//随机种子只需要设置一次即可
	int r = rand();
	printf("r = %d\n", r);

	return 0;
}

```



| 函数            | 用法                                                         |
| --------------- | ------------------------------------------------------------ |
| gets(str);      | 从标准输入设备获取字符，并保存到s指定的内存空间，直到出现换行符或读到文件结尾为止。gets(str)允许输入的字符串含有空格，scanf(“%s”,str)不允许含有空格 |
| puts(str);      | 标准设备输出s字符串，在输出完成后自动输出一个'\n'            |
| strcpy(s1, s2); | 复制字符串 s2 到字符串 s1。                                  |
| strcat(s1, s2); | 连接字符串 s2 到字符串 s1 的末尾。                           |
| strlen(s1);     | 返回字符串 s1 的长度。                                       |
| strcmp(s1, s2); | 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。 |
| strchr(s1, ch); | 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。   |
| strstr(s1, s2)  | **;** 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。 |

## gets()

\#include <stdio.h>

char *gets(char *s);

功能：从标准输入读入字符，并保存到s指定的内存空间，直到出现换行符或读到文件结尾为止。

* 参数

  * s：字符串首地址

* 返回值
  * 成功：读入的字符串
  * 失败：NULL

* gets(str)与scanf(“%s”,str)的区别
  * gets(str)允许输入的字符串含有空格
  * scanf(“%s”,str)不允许含有空格

* 注意

  * 由于scanf()和gets()无法知道字符串s大小，必须遇到换行符或读到文件结尾为止才接收输入，因此容易导致字符数组越界(缓冲区溢出)的情况。

  ```c
  char str[100];
  
  printf("请输入str: ");
  
  gets(str);
  
  printf("str = %s\n", str);
  ```

## fgets()

\#include <stdio.h>

char *fgets(char *s, int size,FILE *stream);

功能：从stream指定的文件内读入字符，保存到s所指定的内存空间，直到出现换行字符、读到文件结尾或是已读了size - 1个字符为止，最后会自动加上字符 '\0' 作为字符串结束。

* 参数
  *  s：字符串
  * size：指定最大读取字符串的长度（size - 1）
  * stream：文件指针，如果读键盘输入的字符串，固定写为stdin

* 返回值
  * 成功：成功读取的字符串
  * 读到文件尾或出错： NULL

* fgets()在读取一个用户通过键盘输入的字符串的时候，同时把用户输入的回车也做为字符串的一部分。通过scanf和gets输入一个字符串的时候，不包含结尾的“\n”，但通过fgets结尾多了“\n”。fgets()函数是安全的，不存在缓冲区溢出的问题。

 ```c
char str[100];

printf("请输入str: ");

fgets(str, sizeof(str), stdin);

printf("str = \"%s\"\n", str);
 ```

## puts()

\#include <stdio.h>

int puts(const char *s);

功能：标准设备输出s字符串，在输出完成后自动输出一个'\n'。

* 参数
  * s：字符串首地址

* 返回值
  * 成功：非负数
  * 失败：-1

 ```c
#include <stdio.h>

int main()
{

printf("hello world");
puts("hello world");
return 0;

}
 ```

## fputs()

\#include <stdio.h>

int fputs(const char * str,FILE *stream);

功能：将str所指定的字符串写入到stream指定的文件中， 字符串结束符 '\0'  不写入文件。 

* 参数
  * str：字符串
  * stream：文件指针，如果把字符串输出到屏幕，固定写为stdout

* 返回值
  * 成功：0
  * 失败：-1

* fputs()是puts()的文件操作版本，但fputs()不会自动输出一个'\n'。

 ```c
printf("hello world");

puts("hello world");

fputs("hello world", stdout);
 ```

## strlen()

\#include <string.h>

size_t strlen(const charb*s);

功能：计算指定指定字符串s的长度，不包含字符串结束符‘\0’

* 参数
  * s：字符串首地址

* 返回值
  * 字符串s的长度
  * size_t为unsigned int类型

 ```c
char str[] = "abcdefg";
int n = strlen(str);
printf("n = %d\n", n);
 ```

## strcpy()

\#include <string.h>

char *strcpy(char *dest, const char *src);

* 功能：把src所指向的字符串复制到dest所指向的空间中，'\0'也会拷贝过去

* 参数
  * dest：目的字符串首地址
  * src：源字符首地址

* 返回值
  *  成功：返回dest字符串的首地址
  * 失败：NULL

* 注意
  * 如果参数dest所指的内存空间不够大，可能会造成缓冲溢出的错误情况。

 ```c
char dest[20] = "123456789";
char src[] = "hello world";
strcpy(dest, src);
printf("%s\n", dest);
 ```

## strncpy()

\#include <string.h>

char *strncpy(char *dest, const char *src, size_t n);

* 功能：把src指向字符串的前n个字符复制到dest所指向的空间中，是否拷贝结束符看指定的长度是否包含'\0'。

* 参数
  * dest：目的字符串首地址
  * src：源字符首地址

  * n：指定需要拷贝字符串个数

* 返回值
  * 成功：返回dest字符串的首地址
  * 失败：NULL

 ```c
char dest[20] ;
char src[] = "hello world";
strncpy(dest, src, 5);
printf("%s\n", dest);
dest[5] = '\0';
printf("%s\n", dest);
 ```

## strcat()

\#include <string.h>

char *strcat(char *dest,const char *src);

* 功能：将src字符串连接到dest的尾部，‘\0’也会追加过去

* 参数

  * dest：目的字符串首地址

  * src：源字符首地址

* 返回值：

  * 成功：返回dest字符串的首地址

  * 失败：NULL

 ```c
char str[20] = "123";

char *src = "hello world";

printf("%s\n", strcat(str, src));
 ```

### 实现strcat函数

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void mystrcat(char * arr,char * s1)
{
	//while (*arr)
	//	arr++;
	//while (*arr++ = *s1++);
	while (*arr)
		arr++;
	while (*s1)
	{
		*arr = *s1;
		arr++;
		s1++;
	}
	*arr = '\0';
}
int main09()
{
	char arr[100] = "hello";
	char * s1 = "world";
	mystrcat(arr, s1);
	printf("%s\n", arr);

	//system("pause");
	return EXIT_SUCCESS;
}
```



## strncat()

\#include <string.h>

char *strncat(char *dest, const char *src,size_t n);

* 功能：将src字符串前n个字符连接到dest的尾部，‘\0’也会追加过去

* 参数：
  * dest：目的字符串首地址
  * src：源字符首地址

  * n：指定需要追加字符串个数

* 返回值：
  * 成功：返回dest字符串的首地址

  * 失败：NULL

 ```c
char str[20] = "123";
char *src = "hello world";
printf("%s\n", strncat(str, src, 5));
 ```

## strcmp()

\#include <string.h>

int strcmp(const char *s1,const char *s2);

* 功能：比较 s1 和 s2 的大小，比较的是字符ASCII码大小。

* 参数
  * s1：字符串1首地址

  * s2：字符串2首地址

* 返回值
  * 相等：0

  * 大于：>0

  * 小于：<0

```c
char *str1 = "hello world";
char *str2 = "hello mike";

if (strcmp(str1, str2) == 0)
{
printf("str1==str2\n");
}
else if (strcmp(str1, str2) > 0)
{
printf("str1>str2\n");
}     
else
{
printf("str1<str2\n");
}
```



## strncmp()

\#include <string.h>

int strncmp(const char *s1,const char *s2,size_t n);

* 功能：比较 s1 和 s2 前n个字符的大小，比较的是字符ASCII码大小。

* 参数
  * s1：字符串1首地址
  * s2：字符串2首地址
  * n：指定比较字符串的数量

* 返回值：

  * 相等：0

  * 大于： > 0

  * 小于： < 0

```c
char *str1 = "hello world";
char *str2 = "hello mike";

if (strncmp(str1, str2, 5) == 0)
{
printf("str1==str2\n");
}
else if (strcmp(str1, "hello world") > 0)
{
printf("str1>str2\n");
}
else
{
printf("str1<str2\n");
}
```

## sprintf()

\#include <stdio.h>

int sprintf(char *_CRT_SECURE_NO_WARNINGS**,** const char *format, ...);

* 功能：根据参数format字符串来转换并格式化数据，然后将结果输出到str指定的空间中，直到出现字符串结束符 '\0'  为止。

* 参数

  * str：字符串首地址

  * format：字符串格式，用法和printf()一样

* 返回值

  * 成功：实际格式化的字符个数

  * 失败： - 1

 ```c
char dst[100] = { 0 };
int a = 10;
char src[] = "hello world";

printf("a = %d, src = %s", a, src);
printf("\n");
int len = sprintf(dst, "a = %d, src = %s", a, src);
printf("dst = \" %s\"\n", dst);
printf*("len = %d\n", len);
 ```

## sscanf()

\#include <stdio.h>

int sscanf(const char *str, const char *format, ...);

* 功能：从str指定的字符串读取数据，并根据参数format字符串来转换并格式化数据。

* 参数：

  * str：指定的字符串首地址

  * format：字符串格式，用法和scanf()一样

* 返回值：

  * 成功：参数数目，成功转换的值的个数

  * 失败： - 1

 ```c
char src[] = "a=10, b=20";
int a;
int b;

sscanf(src, "a=%d,  b=%d", &a, &b);
printf("a:%d, b:%d\n", a, b);
 ```

##  strchr()

\#include <string.h>

char *strchr(const char *s, int c);

* **功能**：在字符串s中查找字母c出现的位置

* **参数**
  * s：字符串首地址

  * c：匹配字母(字符)

* **返回值**
  * 成功：返回第一次出现的c地址

  * 失败：NULL

 ```c
char src[] = "ddda123abcd";
char *p = strchr(src, 'a');
printf("p = %s\n", p);
 ```

## strstr()

\#include <string.h>

char *strstr(const char *haystack,const char *needle);

* 功能：在字符串haystack中查找字符串needle出现的位置

* 参数
  * haystack：源字符串首地址

  * needle：匹配字符串首地址

* 返回值：

  * 成功：返回第一次出现的needle地址

  * 失败：NULL

 ```c
char src[] = "ddddabcd123abcd333abcd";

char *p = strstr(src, "abcd");

printf("p = %s\n", p);
 ```

### 实现strstr函数(两种方法)

```c
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
///*
//1、两个匹配的字符串 必须完全匹配  匹配个数 = 字符串长度
//2、如果配匹一个字符串，需要记录被匹配字符串地址
//3、如果匹配一半未成功 回到记录被匹配字符串地址+1
//4、如果匹配的被匹配字符串的结尾  匹配个数 不等于 字符串长度
//*/
//
//char * mystrstr(char * dest, char *src)
//{
//	int i = 0;
//	int j = 0;
//
//	//匹配个数
//	int count = 0;
//	int len = strlen(src);
//	char * p = NULL;
//	while (dest[i] != '\0')
//	{
//		//if (dest[i] == src[i]);
//
//		while (dest[i] == src[j] && dest[i])//匹配个数 = 字符串长度 l l     l o
//		{
//			if (!count)
//				//如果匹配成功一个字符  需要记录位置
//				p = &dest[i];
//			count++;
//			i++; 
//			j++;
//			//匹配成功
//			if (count == len)
//			{
//				return p;
//			}
//
//		}
//
//		//发生改变的值  i  j  count  p
//		if (count < len)
//		{
//			i = i - count;
//			j = 0;
//			//count 归 0
//			count = 0;
//			//continue;
//		}
//
//		i++;
//	}
//
//	//返回值结果
//	//return p;
//	return NULL;
//}
//
//int main()
//{
//
//	char *p = mystrstr("helllllo", "lllllo");
//	printf("%s\n", p);
//
//	system("pause");
//	return EXIT_SUCCESS;
//}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*
1、两个匹配的字符串 必须完全匹配  匹配个数 = 字符串长度
2、如果配匹一个字符串，需要记录被匹配字符串地址
3、如果匹配一半未成功 回到记录被匹配字符串地址+1
4、如果匹配的被匹配字符串的结尾  匹配个数 不等于 字符串长度
*/

char * mystrstr(char * dest, char *src)
{
	char * p = NULL;
	char * temp = src;
	while (*dest)//
	{
		p = dest;
		while (*dest == *temp && *dest)//匹配个数 = 字符串长度 l l     l o
		{
			dest++;
			temp++;
		}
		if (!*temp)//\0
			//if (*temp=='\0')//\0
			return p;
		else
			temp = src;
		dest = p;
		dest++;
	}

	//返回值结果
	//return p;
	return NULL;
}

int main07()
{

	char *p = mystrstr("helllo", "lol");
	printf("%s\n", p);

	system("pause");
	return EXIT_SUCCESS;
}
```



## strtok()

#include <string.h>

char *strtok(char *str,const char *delim);

* 功能：来将字符串分割成一个个片段。当strtok()在参数s的字符串中发现参数delim中包含的分割字符时, 则会将该字符改为\0 字符，当连续出现多个时只替换第一个为\0。

* 参数

  * str：指向欲分割的字符串

  * delim：为分割字符串中包含的所有字符

* 返回值

  * 成功：分割后字符串首地址

  * 失败：NULL

* 在第一次调用时：strtok()必需给予参数s字符串

* 往后的调用则将参数s设置成NULL，每次调用成功则返回指向被分割出片段的指针

 ```c
char a[100] = "adc*fvcv*ebcy*hghbdfg*casdert";
char *s = strtok(a, "*");//将"*"分割的子串取出

while (s != *NULL*)
{
printf("%s\n", s);
s = strtok(NULL, "*");
}
 ```

## atoi()

\#include <stdlib.h>

int atoi(const char *nptr);

* 功能：atoi()会扫描nptr字符串，跳过前面的空格字符，直到遇到数字或正负号才开始做转换，而遇到非数字或字符串结束符('\0')才结束转换，并将结果返回返回值。

* 参数：
  * nptr：待转换的字符串

* 返回值：成功转换后整数

* 类似的函数有：

  * atof()：把一个小数形式的字符串转化为一个浮点数。

  * atol()：将一个字符串转化为long类型

 ```c
char str1[] = "-10";
int num1 = atoi(str1);
printf("num1 = %d\n", num1);

char str2[] = "0.123";
double num2 = atof(str2);
printf("num2 = %lf\n", num2); 
 ```

# 结构体

## 定义结构	

```c
struct tag { 
    member-list
    member-list 
    member-list  
    ...
} variable-list ;
```

* tag 是结构体标签。

* member-list是标准的变量定义，比如 int i; 或者 float f，或者其他有效的变量定义。

* variable-list 结构变量，定义在结构的末尾，最后一个分号之前，您可以指定一个或多个结构变量。



## 结构体变量的初始化

```c
#include <stdio.h>

struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book = {"C 语言", "RUNOOB", "编程语言", 123456};
 
int main()
{
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
}
```

## 访问结构成员

> 为了访问结构的成员，我们使用**成员访问运算符（.）**。成员访问运算符是结构变量名称和我们要访问的结构成员之间的一个句号。您可以使用 **struct** 关键字来定义结构类型的变量

```c
#include <stdio.h>
#include <string.h>
 
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
 
int main( )
{
   struct Books Book1;        /* 声明 Book1，类型为 Books */
   struct Books Book2;        /* 声明 Book2，类型为 Books */
 
   /* Book1 详述 */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
 
   /* Book2 详述 */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   /* 输出 Book1 信息 */
   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n", Book1.book_id);
 
   /* 输出 Book2 信息 */
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);
 
   return 0;
}
```

```
Book 1 title : C Programming
Book 1 author : Nuha Ali
Book 1 subject : C Programming Tutorial
Book 1 book_id : 6495407
Book 2 title : Telecom Billing
Book 2 author : Zara Ali
Book 2 subject : Telecom Billing Tutorial
Book 2 book_id : 6495700
```

## 结构作为函数参数

```c
#include <stdio.h>
#include <string.h>
 
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
 
int main( )
{
   struct Books Book1;        /* 声明 Book1，类型为 Books */
   struct Books Book2;        /* 声明 Book2，类型为 Books */
 
   /* Book1 详述 */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
 
   /* Book2 详述 */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   /* 输出 Book1 信息 */
   printf( "Book 1 title : %s\n", Book1.title);
   printf( "Book 1 author : %s\n", Book1.author);
   printf( "Book 1 subject : %s\n", Book1.subject);
   printf( "Book 1 book_id : %d\n", Book1.book_id);
 
   /* 输出 Book2 信息 */
   printf( "Book 2 title : %s\n", Book2.title);
   printf( "Book 2 author : %s\n", Book2.author);
   printf( "Book 2 subject : %s\n", Book2.subject);
   printf( "Book 2 book_id : %d\n", Book2.book_id);
 
   return 0;
}
```

```
Book title : C Programming
Book author : Nuha Ali
Book subject : C Programming Tutorial
Book book_id : 6495407
Book title : Telecom Billing
Book author : Zara Ali
Book subject : Telecom Billing Tutorial
Book book_id : 6495700
```



## 指向结构的指针

```c
您可以定义指向结构的指针，方式与定义指向其他类型变量的指针相似，如下所示：

struct Books *struct_pointer;
现在，您可以在上述定义的指针变量中存储结构变量的地址。为了查找结构变量的地址，请把 & 运算符放在结构名称的前面，如下所示：

struct_pointer = &Book1;
为了使用指向该结构的指针访问结构的成员，您必须使用 -> 运算符，如下所示：

struct_pointer->title;
让我们使用结构指针来重写上面的实例，这将有助于您理解结构指针的概念：

实例
#include <stdio.h>
#include <string.h>
 
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
 
/* 函数声明 */
void printBook( struct Books *book );
int main( )
{
   struct Books Book1;        /* 声明 Book1，类型为 Books */
   struct Books Book2;        /* 声明 Book2，类型为 Books */
 
   /* Book1 详述 */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;
 
   /* Book2 详述 */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;
 
   /* 通过传 Book1 的地址来输出 Book1 信息 */
   printBook( &Book1 );
 
   /* 通过传 Book2 的地址来输出 Book2 信息 */
   printBook( &Book2 );
 
   return 0;
}
void printBook( struct Books *book )
{
   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}
```

```
Book title : C Programming
Book author : Nuha Ali
Book subject : C Programming Tutorial
Book book_id : 6495407
Book title : Telecom Billing
Book author : Zara Ali
Book subject : Telecom Billing Tutorial
Book book_id : 6495700
```

## 位域

有些信息在存储时，并不需要占用一个完整的字节，而只需占几个或一个二进制位。例如在存放一个开关量时，只有 0 和 1 两种状态，用 1 位二进位即可。为了节省存储空间，并使处理简便，C 语言又提供了一种数据结构，称为"位域"或"位段"。

所谓"位域"是把一个字节中的二进位划分为几个不同的区域，并说明每个区域的位数。每个域有一个域名，允许在程序中按域名进行操作。这样就可以把几个不同的对象用一个字节的二进制位域来表示。

典型的实例：

- 用 1 位二进位存放一个开关量时，只有 0 和 1 两种状态。
- 读取外部文件格式——可以读取非标准的文件格式。例如：9 位的整数。

### 位域的定义和位域变量的说明

位域定义与结构定义相仿，其形式为：

```
struct 位域结构名 
{

 位域列表

};
```

其中位域列表的形式为：

```
类型说明符 位域名: 位域长度 
```

例如：

struct bs{     int a:8;     int b:2;     int c:6; }data;

说明 data 为 bs 变量，共占两个字节。其中位域 a 占 8 位，位域 b 占 2 位，位域 c 占 6 位。

让我们再来看一个实例：

struct packed_struct {   unsigned int f1:1;   unsigned int f2:1;   unsigned int f3:1;   unsigned int f4:1;   unsigned int type:4;   unsigned int my_int:9; } pack;

在这里，packed_struct 包含了 6 个成员：四个 1 位的标识符 f1..f4、一个 4 位的 type 和一个 9 位的 my_int。

### 对于位域的定义尚有以下几点说明

- 一个位域存储在同一个字节中，如一个字节所剩空间不够存放另一位域时，则会从下一单元起存放该位域。也可以有意使某位域从下一单元开始。例如：

  struct bs{     unsigned a:4;     unsigned  :4;    /* 空域 */     unsigned b:4;    /* 从下一单元开始存放 */     unsigned c:4 }

  在这个位域定义中，a 占第一字节的 4 位，后 4 位填 0 表示不使用，b 从第二字节开始，占用 4 位，c 占用 4 位。

- 由于位域不允许跨两个字节，因此位域的长度不能大于一个字节的长度，也就是说不能超过8位二进位。如果最大长度大于计算机的整数字长，一些编译器可能会允许域的内存重叠，另外一些编译器可能会把大于一个域的部分存储在下一个字中。

- 位域可以是无名位域，这时它只用来作填充或调整位置。无名的位域是不能使用的。例如：

  struct k{     int a:1;     int  :2;    /* 该 2 位不能使用 */     int b:3;     int c:2; };

从以上分析可以看出，位域在本质上就是一种结构类型，不过其成员是按二进位分配的。

### 位域的使用

位域的使用和结构成员的使用相同，其一般形式为：

```
位域变量名.位域名
位域变量名->位域名
```

位域允许用各种格式输出。

请看下面的实例：

### 实例

```c
main(){
    struct bs{
        unsigned a:1;
        unsigned b:3;
        unsigned c:4;
    } bit,*pbit;
    bit.a=1;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.b=7;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    bit.c=15;    /* 给位域赋值（应注意赋值不能超过该位域的允许范围） */
    printf("%d,%d,%d\n",bit.a,bit.b,bit.c);    /* 以整型量格式输出三个域的内容 */
    pbit=&bit;    /* 把位域变量 bit 的地址送给指针变量 pbit */
    pbit->a=0;    /* 用指针方式给位域 a 重新赋值，赋为 0 */
    pbit->b&=3;    /* 使用了复合的位运算符 "&="，相当于：pbit->b=pbit->b&3，位域 b 中原有值为 7，与 3 作按位与运算的结果为 3（111&011=011，十进制值为 3） */
    pbit->c|=1;    /* 使用了复合位运算符"|="，相当于：pbit->c=pbit->c|1，其结果为 15 */
    printf("%d,%d,%d\n",pbit->a,pbit->b,pbit->c);    /* 用指针方式输出了这三个域的值 */
}
```

上例程序中定义了位域结构 bs，三个位域为 a、b、c。说明了 bs 类型的变量 bit 和指向 bs 类型的指针变量 pbit。这表示位域也是可以使用指针的。

## 结构体数组

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTITL 41
#define MAXAUTL 31
#define MAVXBKS 100

char * s_gets(char * st, int n);
struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main()
{
    struct book library[MAVXBKS];    //book类型的结构体数组
    int i;
    int index;
    printf("请问你要录入多少本书的信息\n");
    do
    {
        scanf("%d", &index);
    } while (index > MAVXBKS);
    getchar();
    for (i = 0; i < index; i++)
        {
        printf("请输入第%d本书的名称:\n",i+1);
        s_gets(library[i].title, MAXTITL);
        printf("输入其作者的名字:\n");
        s_gets(library[i].author, MAXAUTL);
        printf("请输入书本的价格:\n");
        scanf("%f", &library[i].value);
        getchar();
    }
    for (i = 0; i < index; i++)
    {
            printf("%d\t%s  是  %s 写的 定价为%f元\n", i,library[i].title, library[i].author, library[i].value);
    }
    system("pause");
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');    //查找换行符
        if (find)    //  查找地址不为空
            *find = '\0';    //在此处放入一个空字符
        else
            while (getchar() != '\n')
        continue;    //处理剩余字符
    }
    return ret_val;
}
```



## 结构体内存大小对齐原则

>  结构体中成员变量分配的空间是按照成员变量中占用空间最大的来作为分配单位,同样成员变量的存储空间也是不能跨分配单位的,如果当前的空间不足,则会存储到下一个分配单位中。

```c
#include <stdio.h>

typedef struct
{
    unsigned char a;
    unsigned int  b;
    unsigned char c;
} debug_size1_t;
typedef struct
{
    unsigned char a;
    unsigned char b;
    unsigned int  c;
} debug_size2_t;

int main(void)
{
    printf("debug_size1_t size=%lu,debug_size2_t size=%lu\r\n", sizeof(debug_size1_t), sizeof(debug_size2_t));
    return 0;
}
```

编译执行输出结果：

```c
debug_size1_t size=12,debug_size2_t size=8
```

结构体占用存储空间,以32位机为例

1.debug_size1_t 存储空间分布为a(1byte)+空闲(3byte)+b(4byte)+c(1byte)+空闲(3byte)=12(byte)。 1.debug_size2_t 存储空间分布为a(1byte)+b(1byte)+空闲(2byte)+c(4byte)=8(byte)。

* 结构体变量的首地址能够被其最宽基本类型成员的大小所整除。

* 结构体每个成员相对于结构体首地址的偏移量(offset)都是成员大小的整数倍，如有需要编译器会在成员之间加上填充字节(internal adding)。即结构体成员的末地址减去结构体首地址(第一个结构体成员的首地址)得到的偏移量都要是对应成员大小的整数倍。

* 结构体的总大小为结构体最宽基本类型成员大小的整数倍，如有需要编译器会在成员末尾加上填充字节。



# 共用体

## 定义共用体

```c
union [union tag]
{
   member definition;
   member definition;
   ...
   member definition;
} [one or more union variables];
```

>  **union tag** 是可选的，每个 member definition 是标准的变量定义，比如 int i; 或者 float f; 或者其他有效的变量定义。在共用体定义的末尾，最后一个分号之前，您可以指定一个或多个共用体变量，这是可选的

## 访问共用体成员

* 为了访问共用体的成员，我们使用**成员访问运算符（.）**。成员访问运算符是共用体变量名称和我们要访问的共用体成员之间的一个句号。您可以使用 **union** 关键字来定义共用体类型的变量

```c
#include <stdio.h>
#include <string.h>
 
union Data
{
   int i;
   float f;
   char  str[20];
};
 
int main( )
{
   union Data data;        
 
   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");
 
   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);
 
   return 0;
}
```

当上面的代码被编译和执行时，它会产生下列结果：

```
data.i : 1917853763
data.f : 4122360580327794860452759994368.000000
data.str : C Programming
```

## 结构体与共用体

* 结构体变量所占内存长度是各成员占的内存长度之和。每个成员分别占有其自己的内存单元。

* 共用体变量所占的内存长度等于最长的成员变量的长度。例如，教程中定义的共用体Data各占20个字节（因为char str[20]变量占20个字节）,而不是各占4+4+20=28个字节。

## 共用体作用

节省内存，有两个很长的数据结构，不会同时使用，比如一个表示老师，一个表示学生，如果要统计教师和学生的情况用结构体的话就有点浪费了！用共用体的话，只占用最长的那个数据结构所占用的空间，就足够了！

## 共用体应用场景

通信中的数据包会用到共用体:因为不知道对方会发一个什么包过来，用共用体的话就很简单了，定义几种格式的包，收到包之后就可以直接根据包的格式取出数据。



# 排序算法

## 冒泡排序

> 冒泡排序（英语：Bubble Sort）是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序（如从大到小、首字母从A到Z）错误就把他们交换过来

```c
#include <stdio.h>
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
int main() {
    int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    bubble_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}
```

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int arr[10] = { 7,4,2,3,5,8,9,6,1,10 };
	int len = sizeof(arr) / sizeof(arr[0]) - 1;
	//冒泡排序   从小到大
	//外层循环每次执行都能确定一个最大值
	for (int i = 0; i < len; i++)
	{
		//内层循环内次执行能确定两个数值中的最大值
		for (int j = 0; j < len - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				//两个数据交换位置
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	system("pause");
	return EXIT_SUCCESS;
}
```

### 冒泡排序优化算法

```c
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void bubble(int *arr, int len)
{
	int flag = 1;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				flag = 0;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		if (flag)
			return;
		flag = 1;
	}
}
int main()
{
	int arr[] = { 1,3,5,8,9,2,7,4,6,0 };
	bubble(arr,10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
	//system("pause");
	return EXIT_SUCCESS;
}
```



## 选择排序

> 选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理如下。首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。

```c
void swap(int *a,int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int arr[], int len) 
{
    int i,j;
 
    for (i = 0 ; i < len - 1 ; i++) 
    {
        int min = i;
        for (j = i + 1; j < len; j++)     //走訪未排序的元素
            if (arr[j] < arr[min])    //找到目前最小值
                min = j;    //紀錄最小值
           swap(&arr[min], &arr[i]);    //做交換
    }
}
```

## 插入排序

>插入排序（英语：Insertion Sort）是一种简单直观的排序算法。它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。插入排序在实现上，通常采用in-place排序（即只需用到 {\displaystyle O(1)} {\displaystyle O(1)}的额外空间的排序），因而在从后向前扫描过程中，需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。

```c
void insertion_sort(int arr[], int len){
    int i,j,temp;
    for (i=1;i<len;i++){
            temp = arr[i];
            for (j=i;j>0 && arr[j-1]>temp;j--)
                    arr[j] = arr[j-1];
            arr[j] = temp;
    }
}
```

## 希尔排序

希尔排序，也称递减增量排序算法，是插入排序的一种更高效的改进版本。希尔排序是非稳定排序算法。

希尔排序是基于插入排序的以下两点性质而提出改进方法的：

- 插入排序在对几乎已经排好序的数据操作时，效率高，即可以达到线性排序的效率
- 但插入排序一般来说是低效的，因为插入排序每次只能将数据移动一位

```c
void shell_sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap = gap >> 1)
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
}
```

## 归并排序

> 把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行。

**迭代法**

```c
int min(int x, int y) {
    return x < y ? x : y;
}
void merge_sort(int arr[], int len) {
    int* a = arr;
    int* b = (int*) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}
```

**递归法**

```c
void merge_sort_recursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}
void merge_sort(int arr[], const int len) {
    int reg[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}
```



## 快速排序

> 在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，再分别对小数区与大数区进行排序

**迭代法**

```c
typedef struct _Range {
    int start, end;
} Range;
Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void quick_sort(int arr[], const int len) {
    if (len <= 0)
        return; // 避免len等於負值時引發段錯誤（Segment Fault）
    // r[]模擬列表,p為數量,r[p++]為push,r[--p]為pop且取得元素
    Range r[len];
    int p = 0;
    r[p++] = new_Range(0, len - 1);
    while (p) {
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        int mid = arr[(range.start + range.end) / 2]; // 選取中間點為基準點
        int left = range.start, right = range.end;
        do
        {
            while (arr[left] < mid) ++left;   // 檢測基準點左側是否符合要求
            while (arr[right] > mid) --right; //檢測基準點右側是否符合要求
 
            if (left <= right)
            {
                swap(&arr[left],&arr[right]);
                left++;right--;               // 移動指針以繼續
            }
        } while (left <= right);
 
        if (range.start < right) r[p++] = new_Range(range.start, right);
        if (range.end > left) r[p++] = new_Range(left, range.end);
    }
}
```

**递归法**

```c
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
void quick_sort_recursive(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        swap(&arr[left], &arr[right]);
    }
    if (arr[left] >= arr[end])
        swap(&arr[left], &arr[end]);
    else
        left++;
    if (left)
        quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
void quick_sort(int arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}
```



















