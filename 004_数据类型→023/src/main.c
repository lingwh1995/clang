#include <stdio.h>
#include <stdbool.h>

/**
 * 章节内容：
 *   C语言数据类型
 *     1.基本数据类型：
 *       整型数据类型：short、int、long、long long
 *       	注意：short就是short int, long就是long int, long long就是long long int
 *       字符数据类型：char
 *       浮点型数据类型：float、double
 *       布尔类型：false=0、 true=1/非0
 *     2.构造数据类型
 *		 数组(Array)：一组相同类型元素的集合，可以是一维或多维。
 *		 结构体(Struct)：允许将不同类型的数据组合在一起，每个成员拥有独立的内存空间。
 *		 联合体(Union)：所有成员共享同一块内存空间，同一时间只能存储一种类型的数据。
 *		 ‌枚举(Enum)：用于定义一组命名的整数常量。
 *	   3.指针类型
 *	   	 指针(Pointer)：指向特定类型数据的指针，用于存储变量的内存地址，如int *p表示指向整数的指针。
 *	   4.空类型
 *	   	 void‌：表示没有类型，通常用于函数返回值、函数参数或通用指针。
 *	   5.数据类型转换
 *	   	 从小范围数据类型转换为大范围数据类型，符号位扩展取决于原数据类型，而不是目标数据类型
 */


/**
 * 定义一个结构体Person
 */
struct Student
{
	// 学生id
	int id;
	// 学生姓名
	char name[20];
	// 学生年龄
	int age;
};


/**
 * 颜色枚举
 */
enum Color
{
	RED,	//默认为 0
	GREEN,	//默认为 1
	BLUE	//默认为 2
};


/**
 * 打印颜色
 *   使用枚举约束了case后面的值
 */
void print_color(enum Color color)
{
    switch (color)
    {
        case RED:
            printf("红色\n");
            break;
        case GREEN:
            printf("绿色\n");
            break;
        case BLUE:
            printf("蓝色\n");
            break;
        default:
            printf("参数不合法\n");
    }
}

/**
 * 不同数据类型占据的空间大小
 */
void data_type_size()
{

	// short就是short int
    printf("short类型所占字节大小: %d\n", sizeof(short));
    printf("int类型所占字节大小: %d\n", sizeof(int));
    // long就是long int
    printf("long类型所占字节大小: %d\n", sizeof(long));
    printf("long int类型所占字节大小: %d\n", sizeof(long int));
    // long long就是long long int
    printf("long long类型所占字节大小: %d\n", sizeof(long long));
    printf("long long int类型所占字节大小: %d\n", sizeof(long long int));
    // 字符数据类型
    printf("char类型所占字节大小: %d\n", sizeof(char));
    // 浮点型数据类型
    printf("float类型所占字节大小: %d\n", sizeof(float));
    printf("double类型所占字节大小: %d\n", sizeof(double));
    printf("long double类型所占字节大小: %d\n", sizeof(long double));
    // 使用bool类型,C99中要引用 stdbool.h
    printf("bool类型所占字节大小: %d\n", sizeof(bool));
    printf("-------------------------------------\n");
}

/**
 * 定义基本的数据类型
 */
void definition_basic_data_type()
{
    // short类型
    short s_signed = -100;
    unsigned short s_unsigned = 100;
    printf("有符号 short: s_signed = %hd\n", s_signed);
    printf("无符号 short: s_unsigned = %hu\n", s_unsigned);

    // int类型
    int i_signed = -200;
    unsigned int i_unsigned = 200;
    printf("有符号 int: i_signed = %d\n", i_signed);
    printf("无符号 int: i_unsigned = %u\n", i_unsigned);

    // long类型
    long l_signed = -300L;  // 后缀L表示long类型
    unsigned long l_unsigned = 300L;  // 后缀L表示long类型
    printf("有符号 long: l_signed = %ld\n", l_signed);
    printf("无符号 long: l_unsigned = %lu\n", l_unsigned);

    // long long类型
    long long ll_signed = -400LL;  // 后缀LL表示long long类型
    unsigned long long ll_unsigned = 400LL;  // 后缀LL表示long long类型
    printf("有符号 long long: ll_signed = %lld\n", ll_signed);
    printf("无符号 long long: ll_signed = %llu\n", ll_unsigned);

    // float类型
    float f = 0.234f;
    printf("float 值 (默认): f = %f\n", f);
    printf("float 值 (2位小数): f = %.2f\n", f);
    printf("科学计数法: f = %e\n", f);

    // double类型
    float d = 0.456;
    printf("double 值 (默认): d = %lf\n", d);
    printf("double 值 (2位小数): d = %.2lf\n", d);
    printf("科学计数法: d = %e\n", d);

    // char类型
    char c1 = 'A'; // 等同于 char a = 65;
    char c2 = 'B'; // 等同于 char b = 66;
    printf("c1 + c2 = %d\n", c1 + c2); // 输出 131
    // 字符 '0'
    char c3 = '0';
    printf("c3 = %c\n", c3);
    printf("c3 = %d\n", c3);
    // 字符 '\0'，常用于标记字符串的结束位置
    char c4 = '\0';
    printf("c4 = %c\n", c4);
    printf("c4 = %d\n", c4);

    // 使用转义字符输出单引号
    char t = '\'';
    printf("%c\n", t);
    printf("-------------------------------------\n");
}

/**
 * 定义数组数据类型
 */
void definition_array_data_type()
{
    // 数组(Array)
    int nums[] = { 10, 20, 30 };
    int i;
	int size = sizeof(nums)/sizeof(nums[0]);
    for(i = 0; i < size; i++)
    {
    	printf("%d ",nums[i]);
    }
    printf("\n");
    printf("-------------------------------------\n");
}

/**
 * 定义结构体数据类型
 */
void definition_struct_data_type()
{
    // 结构体(Struct)
    struct Student alice = { 1,"Alice",18 };
    struct Student bob = { 2,"Bob",23 };
    struct Student student_arr[] = {
    		alice,
    		bob,
    		{ 3, "Charile", 29 }
    };
    int size = sizeof(student_arr)/sizeof(student_arr[0]);
    for(int i = 0; i < size; i++)
    {
    	printf("学生编号：%d,学生姓名：%s,学生年龄：%d\n", student_arr[i].id, student_arr[i].name, student_arr[i].age);
    }
    printf("-------------------------------------\n");
}

/**
 * 定义枚举数据类型
 */
void definition_enum_data_type()
{
    // 枚举(Enum)
    enum Color color = RED;
    printf("%d\n", color);
    print_color(color);
    // 注意：枚举可以像整型数组一样使用
    for(int i=RED; i <= BLUE; i++)
    {
    	printf("%d\n", i);
    }
    printf("-------------------------------------\n");
}

/**
 * 定义指针数据类型
 */
void definition_pointer_data_type()
{
    int a = 100;
    // 指针
    int* p = &a;
    printf("a的地址 = %p\n", p);
    int arr[5] = { 1, 2, 3, 4, 5 };
    // 数组的地址
    printf("数组的地址 = %p\n", &arr);
    printf("-------------------------------------\n");
}


/**
 * 数据类型转换案例1
 */
void data_type_conversion_1()
{
	int i = 0x12345678;
	// 显式转换
//	short s = (short)i;
//	char c = (char)i;
	// 隐式转换
	short s = i;
	char c = i;
	printf("i = %x, s = %x, c = %x\n", i, s ,c);
	printf("-------------------------------------\n");
}

/**
 * 数据类型转换案例2
 */
void data_type_conversion_2()
{
	// char a = -5         的二进制 => 原码 1000 0101 => 反码 1111 1010 => 补码 1111 1011 => int a（负数左边补1） => 1111 1111 1111 1111 1111 0101
	char a = -5;
	// unsigned int b = 10 的二进制 => 原码 0000 1010 => 反码 0111 0101 => 补码 0111 0111 => int b（正数左边补0） => 0000 0000 0000 0000 0000 1010
	unsigned int b = 10;
	if(a > b)
	{
		//printf("%x > %x \n", a, b);
		printf("%d > %d \n", a, b);
	}
	else
	{
		//printf("%x < %x \n", a, b);
		printf("%d < %d \n", a, b);
	}
	printf("-------------------------------------\n");
}


/**
 * 数据类型转换案例3
 */
void data_type_conversion_3()
{
	/**
	 * char a = 100 的二进制 => 原码 0110 0100 => 反码 0110 0100 => 补码   0110 0100
	 * 																	  +
	 * char b = 200 的二进制 => 原码 1100 1000 => 反码 1100 1000 => 补码   1100 1000
	 *
	 * 运算结果  c 												=> 补码 1 0010 1100 => 截取最低位1个字节 => 0010 1100 => 十进制的44
	 *
	 * char a = 100 的二进制 => 补码 0110 0100 => int a 的二进制补码  0000 0000 0000 0000 0000 0000 0110 0100
	 * 															     +
	 * char b = 200 的二进制 => 补码 1100 1000 => int b 的二进制补码  1111 1111 1111 1111 1111 1111 1100 1000
	 *
	 * 运算结果  a + b 		 		 		  => int c 的二进制补码 10000 0000 0000 0000 0000 0000 0010 1100  => 十进制的44
	 */
	char a = 100;
	char b = 200;
	char c = a + b;
	printf("c = %d, a + b = %d\n", c, a + b);

	/**
	 * unsigned char x = 100 的二进制 => 原码 0110 0100 => 反码 0110 0100 => 补码   0110 0100
	 * 																	 	       +
	 * unsigned char y = 200 的二进制 => 原码 1100 1000 => 反码 1100 1000 => 补码   1100 1000
	 *
	 * 运算结果												             => 补码 1 0010 1100 => 截取最低位1个字节 => 0010 1100 => 十进制的44
	 *
	 * unsigned char x = 100 的二进制 => 补码 0110 0100 => int x 的二进制补码 0000 0000 0000 0000 0000 0000 0110 0100
	 * 															             +
	 * unsigned char x = 200 的二进制 => 补码 1100 1000 => int x 的二进制补码 0000 0000 0000 0000 0000 0000 1100 1000
	 *
	 * 运算结果  x + y 		 		 		  	       => int z 的二进制补码 0000 0000 0000 0000 0000 0001 0010 1100  => 十进制的300
	 */
	unsigned char x = 100;
	unsigned char y = 200;
	unsigned char z = x + y;
	printf("z = %d, x + y = %d\n", z, x + y);
	printf("-------------------------------------\n");
}


/**
 * 数据类型转换案例4
 */
void data_type_conversion_4()
{
	char c = 128;
	unsigned char uc = 128;
	unsigned short us = 0;
	/**
	 * 			 char c => 1000 0000 => short  c   1111 1111 1000 0000
	 *       			   						   +
	 * unsigned char uc => 1000 0000 => short uc   0000 0000 1000 0000
	 * unsigned short us  			 =>			 1 0000 0000 0000 0000 => 截最取低位2个字节 => 0000 0000 0000 0000 => 十六进制 0
	 */
	us = c + uc;
	printf("us = %x\n", us);


	/**
	 *           char c => 1000 0000 => unsigned char  c => 1000 0000 => short  c  0000 0000 1000 0000
	 *       			                          						           +
	 * unsigned char uc => 1000 0000 => unsigned char uc => 1000 0000 => short uc  0000 0000 1000 0000
	 * unsigned short us  						                      =>		   0000 0001 0000 0000 => 截最取低位2个字节 => 0000 0001 0000 0000 => 十六进制 100
	 */
	us = (unsigned char)c + uc;
	printf("us = %x\n", us);


	/**
	 * 		    char  c => 1000 0000 => char  c => 1000 0000 => short  c   1111 1111 1000 0000
	 *       			                           						   +
	 * unsigned char uc => 1000 0000 => char uc => 1000 0000 => short uc   1111 1111 1000 0000
	 * unsigned short us  			 						 =>			 1 1111 1111 0000 0000 => 截最取低位2个字节 => 1111 1111 0000 0000 => 十六进制 ff00
	 */
	us = c + (char)uc;
	printf("us = %x\n", us);


	/**
	 * 			char  c => 1000 0000 => unsigned short c => 1111 1111 1000 0000 => unsigned short  c   1111 1111 1000 0000
	 *       			                          		    +
	 * unsigned char uc => 1000 0000 => unsigned char uc => 1000 0000 		    => unsigned short uc   0000 0000 1000 0000
	 * unsigned short us  			 											=>		             1 0000 0000 0000 0000 => 截最取低位2个字节 => 0000 0000 0000 0000 => 十六进制 100
	 */
	// 特别注意： 符号位的扩展取决于原数据类型而不是目标数据类型，如这里将 char(原数据类型) => unsigned short(目标数据类型)，符号位的扩展取决于 原数据类型char
	us = (unsigned short)c + uc;
	printf("us = %x\n", us);
	printf("-------------------------------------\n");
}

/**
 * 数据类型转换案例5
 */
void data_type_conversion_5()
{
	int i = 10;
	char c = 'a';
	//printf("c = %d\n", c);
	// i 和 c 比较时首先把 char类型数据c 转换为整型数据 97，再做比较
	if(i > c)
	{
		printf("i > c\n");
	}
	else
	{
		printf("i < c\n");
	}
}

/**
 * 数据类型转换案例6
 */
void data_type_conversion_6()
{
	int i = 10;
    double d = 12.23;
	printf("d = %.2f\n", d);
	// i 和 d 比较时首先把 整形数据 i 转换为double型数据 10.00，再做比较
	if(i > d)
	{
		printf("i > d\n");
	}
	else
	{
		printf("i < d\n");
	}
}

/**
 * 数据类型转换案例7
 */
void data_type_conversion_7()
{
	int i = 10;
    double d = 100.23;
	char ch = 'a';
    ch = d;
    printf("ch = %c\n", ch);
}

// 运算时 char c 先转换为 int 类型数据 97， int i 转换为 char 类型数据 d
double fun(int a, char ch)
{
    // 然后把 char ch 转换为 int 类型数据 100，最后再把计算结果整形数据 197 转换为 double 类型数据 197.000000
    double d = a + ch;
    return d;
}

/**
 * 数据类型转换案例8
 */
void data_type_conversion_8()
{
	char c = 'a';
	int i = 100;
    double d = fun(c, i);
    printf("%f\n", d);
}

int main()
{
	data_type_size();
	definition_basic_data_type();
	definition_array_data_type();
	definition_struct_data_type();
	definition_enum_data_type();
	definition_pointer_data_type();
	data_type_conversion_1();
	data_type_conversion_2();
	data_type_conversion_3();
	data_type_conversion_4();
	data_type_conversion_5();
    data_type_conversion_6();
    data_type_conversion_7();
    data_type_conversion_8();
    return 0;
}
