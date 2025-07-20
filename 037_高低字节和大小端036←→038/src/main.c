#include<stdio.h>
#include<stdbool.h>

/**
 * 判断大端和小端
 * 	小端：返回1，说明数据的低字节在内存的低地址存放，简记：小低低
 *	大端：返回0，说明数据的低字节在内存的高地址存放，简记：大低高
 *
 * x86架构的CPU（包括Intel和AMD的处理器）采用‌小端模式（Little-Endian）‌存储数据
 */
void big_end_or_little_end_1()
{
	int i = 1;
	// 获取整形指针
	int* ip = &i;
	// 整形指针转为char类型指针
	char* cp = (char*)ip;
	char c = *cp;
	// 等同于 char* cp = (char*)&ip;

	if(c == 0)
	{
		printf("BIG_END\n");
	}
	if(c == 1)
	{
		printf("LITTLE_END\n");
	}
}

/**
 * 判断大端和小端
 * 	小端：返回1，说明数据的低字节在内存的低地址存放
 *	大端：返回0，说明数据的低字节在内存的高地址存放
 */
void big_end_or_little_end_2()
{
	int i = 1;
	// (char)i : 强转为 char 类型，实际就是取 i 在内存中第一个字节的数据
	char c = (char)i;

	if(c == 0)
	{
		printf("BIG_END\n");
	}
	if(c == 1)
	{
		printf("LITTLE_END\n");
	}

}

void big_end_and_little_end_test()
{
	int a = 10, b = 20, c = 30, d = 40;
	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("&c = %p\n", &c);
	printf("&d = %p\n", &d);
}

int main()
{
	/**
	 * 高低字节
	 * 	十六进制： 0x80 00 00 0a
	 * 	0x80就是高字节，0x0a就是低字节
	 *
	 * 高低地址
	 * 	低地址：内存中数据的起始位置，存储数据的开始部分。
	 * 	高地址：内存中数据的结束位置，存储数据的末尾部分。
	 *
	 * 大小端
	 * 	大端模式：低址存放高位字节，高地址存放低字节（大低高），0x12345678存储为12 34 56 78
	 * 	小端模式：低地址存放低字节，高地址存放高字节（小低低），0x12345678存储为78 56 34 12
	 */

	/**
	 * 大小端判断
	 * 	int i = 1;
	 * 	大端模式：低址存放高位字节，高地址存放低字节
	 * 	int i = 0x00000001;
	 * 	高字节 <------------------ 低字节
	 * 	低地址 ------------------> 高地址
	 * 	0x00  |  0x00  |  0x00  |  0x01
	 *
	 * 	小端模式：低地址存放低字节，高地址存放高字节
	 * 	int i = 0x01000000;
	 * 	高字节 <------------------ 低字节
	 * 	低地址 ------------------> 高地址
	 * 	0x01  |  0x00  |  0x00  |  0x00
	 */
	big_end_or_little_end_1();
	//big_end_or_little_end_2();
    //big_end_and_little_end_test();
	return 0;
}
