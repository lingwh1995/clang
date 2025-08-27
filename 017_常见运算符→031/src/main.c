//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

/**
 * C语言中的运算符分为以下几种
 *	1.算术运算符
 *	2.自增运算符，自减运算符
 *	3.关系运算符
 *	4.逻辑运算符
 *	5.位运算符
 *	6.逗号运算符
 *	7.运算优先级
 */
/**
 * 自增运算符
 * i++ : 先用后+
 * ++i : 先加后用
 */
void increment_operator()
{
	// i++
	int i = 10;
    printf("i: %d\n", i++);

    // ++i
    i = 10;
    printf("i: %d\n", ++i);

    i = 10;
    int j = ++i; // 等同于  i = 1 + i; j = i;
    printf("j: %d\n", j);
}

/**
 * 三目运算符
 */
void ternary_conditional_operator()
{
	int a, b, max;
	scanf("%d %d", &a, &b);
	max = a > b ? a : b;
	printf("max = %d\n", max);
}

/* 
 * 加等运算符
 */
void add_equal_operator()
{
	int nums[] = { 1, 2, 3, 4, 5 };
	int length = sizeof(nums) / sizeof(nums[0]);
	int sum = 0 ;
	for (int i = 0; i < length; i++)
	{
		sum += nums[i];
	}
	printf("sum = %d\n", sum);
}

/*
 * 乘等运算符
 */
void multiply_equal_operator()
{
	int nums[] = { 1, 2, 3, 4, 5 };
	int length = sizeof(nums) / sizeof(nums[0]);
	int sum = 1;
	for (int i = 0; i < length; i++)
	{
		sum *= nums[i];
	}
	printf("sum = %d\n", sum);
}

/**
 * 取余运算符
 */
void mod_operator()
{
	int i;
	for (i = 0; i < 100; i++)
	{
		if (i % 10 == 0)
		{
			printf("\n");
		}
		printf("%4d", i);
	}

	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 1)
		{
			printf("\n");
		}
		printf("%4d", i);
	}
}

/**
 * 位运算符
 * 	注意：1.在进行位运算时，不足8位(一个字节)时需要左补0，如 8 => 1000 => 0000 1000
 * 		 2.对二进制码左移或者右移的时候，都是对补码进行操作，不是对原码进行操作，如果是负数的话要先把补码转为反码(补码-1)，再把反码转为原码(符号位不变，其他位取反)
 * 		 3.左移运算时正数可能会变负数，负数也可能会变正数，主要要看使用什么数据类型接收结果，因为不同的数据类型占据的空间宽度是不同的，如果是char类型数据byte7是符
 * 		   号位，如果是short类型，byte15是符号位，如果是int类型，byte31是符号位
 * 			正数10左移 一位到四位 全过程
 * 					      二进制数        char类型  short类型
 * 			原始数据	0000 0000 0000 1010    10       10
 * 			左移一位	0000 0000 0001 0100    20       20
 * 			左移两位	0000 0000 0010 1000    40       40
 * 			左移三位	0000 0000 0101 0000    80       80
 * 			左移四位	0000 0000 1010 0000    -96	    160
 * 
 * 			负数-10左移 一位到四位 全过程
 * 					      二进制数        char类型  short类型
 * 			原始数据	1111 1111 1111 0110    -10      -10
 * 			左移一位	1111 1111 1110 1100    -20      -20
 * 			左移两位	1111 1111 1101 1000    -40      -40
 * 			左移三位	1111 1111 1011 0000    -80      -80
 * 			左移四位	1111 1111 0110 0000    96	  	-160
 *			
 * 			-10左移四位 => 获取补码 => 获取反码 => 获取原码 => 获取十进制数
 *          -10 => 转换为二进制 => 1111 1111 1111 0110 => 左移四位(得到负数补码) => 1111 1111 0110 0000 => 补码-1得到反码 => 1111 1111 0101 1111 
 * 					=> 符号位不变，其他位取反得到原码 => 1000 0000 1010 0000 => 使用short类型接收(byte15为符号位) => 1010 0000 * - 1 =>  -160
 */	
void bitwise_operator()
{
	// 8的二进制位 1000
	// 1的二进制位 0001
	int a = 8, b = 1;
	printf("a = %d, b = %d\n\n", a, b);
	/**
	 * 与运算 - & - AND
	 *
	 * a	8	0000 1000
	 * &	&	&
	 * b	1	0000 0001
	 * 		=	=
	 * 		0	0000 0000
	 */
	printf("a & b = %d\n", a & b);
	// a = a & b; 可以简写为 a &= b;

	/**
	 * 或运算 - | - OR
	 *
	 * a	8	0000 1000
	 * |	|	|
	 * b	1	0000 0001
	 * =	=	=
	 * 		9	0000 1001
	 */
	printf("a | b = %d\n", a | b);
	// a = a | b; 可以简写为 a |= b;

	/**
	 * 异或运算(不同为1，相同为0) - ^ - XOR
	 *
	 * a	8	0000 1000
	 * ^	^	^
	 * b	1	0000 0001
	 * =	=	=
	 * 		9	0000 1001
	 */
	printf("a ^ b = %d\n", a ^ b);
	// a = a ^ b; 可以简写为 a ^= b;

	/**
	 * 非运算(1为0，0为1) - ~ - NOT
	 *
	 * a	8	0000 1000
	 * ~	~	~
	 * =	=	=
	 * 		-9	1111 0001
	 */
	printf("  ~ a = %d\n", ~a);

	/**
	 * 左移运算符 - << : 相当于在原来基础上扩大一倍
	 *
	 * a	8	0000 1000
	 * <<	<<	<<
	 * 1    1   1
	 * =	=	=
	 * 		16	0001 0000
	 */
	printf("%d << 1 = %d\n", a, a << 1);
	printf("-%d << 1 = %d\n", a, -a << 1);

	/**
	 * 右移运算符 - >> : 相当于在原来基础上缩小一倍
	 *
	 * a	8	0000 1000
	 * >>	>>	>>
	 * 1    1   1
	 * =	=	=
	 * 		4	0000 0100
	 */
	printf("%d >> 1 = %d\n", a, a >> 1);
	printf("-%d >> 1 = %d\n", a, -a >> 1);
	printf("---------------\n");
}

/**
 * 正数左移1到4位，当左移四位时分别使用 char 和 short 接收
 */
void positive_number_left_shift()
{
	char ch = 10;
	// 左移1位
	char r1 = ch << 1;
	printf("10 << 1 = %d\n", r1);

	// 左移2位
	char r2 = ch << 2;
	printf("10 << 2 = %d\n", r2);

	// 左移3位
	char r3 = ch << 3;
	printf("10 << 3 = %d\n", r3);

	// 左移4位
	char r4 = ch << 4;
	printf("10 << 4 = %d\n", r4);

	// 左移4位，注意：这里使用shor类型来接收了，而不是使用char类型来接收，即使左移4位，也不会越界的
	short r44 = ch << 4;
	printf("10 << 4 = %d\n", r44);

}

/**
 * 负数左移1到4位，当左移四位时分别使用 char 和 shor 接收
 */
void negative_number_left_shift()
{
	char ch = -10;
	
	// 左移1位
	char r1 = ch << 1;
	printf("-10 << 1 = %d\n", r1);
 
	// 左移2位
	char r2 = ch << 2;
	printf("-10 << 2 = %d\n", r2);
 
	// 左移3位
	char r3 = ch << 3;
	printf("-10 << 3 = %d\n", r3);
 
	// 左移4位
	char r4 = ch << 4;
	printf("-10 << 4 = %d\n", r4);
 
	// 左移4位，注意：这里使用shor类型来接收了，而不是使用char类型来接收，即使左移4位，也不会越界的
	short r44 = ch << 4;
	printf("-10 << 4 = %d\n", r44);
}
 
int main()
{
	//increment_operator();
	//ternary_conditional_operator();
	//add_equal_operator();
	//multiply_equal_operator();
	//mod_operator();
	//bitwise_operator();
	//positive_number_left_shift();
	negative_number_left_shift();
}
