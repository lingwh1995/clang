#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/**
 * 逻辑运算符: &&/|| 会短路
 * 逗号表达式:
 *  1.运算优先级最低
 *  2.分为两种情况
 *      不加括号: 从右往左执行,取最左边的表达式的运算结果
 *      加括号: 从左往右执行,取最右边的表达式的运算结果
 *  特别注意:
 *      不管是取最左边还是最右边的运算结果,所有的表达式都会执行,只是执行顺序从左到右或者从右到左
 *
 */

 /*
  * 逻辑运算符测试
  */
void relational_operator_test()
{
	int a = 1, b = 2, c = 3;
	int i = a < b < c;
	//a < b => true(1) ,1 < 3 => true => 1
	printf("%d\n", i);

	// 短路 与 expression1 && expression2,只有expression1为真时才执行expression2,expression1为假不会执行expression2
	// 短路 或 同理,同样会短路
	int x = 100, y = 10;
	if (x < 20 && ++y)
	{

	}
	printf("y = %d\n", y);
}

/*
 * 逗号表达式测试
 *  验证加括号和不加括号最终结果取值区别：不加括号最终取最左边表达式计算结果,加括号最终取最右边表达式计算结果
 *  特别注意：不加括号和加括号，表达式执行顺序都是从左往右依次执行，只是根据是否加括号决定取最右边和最左边的表达式的计算结果
 */
void comma_expression_test_1()
{
	int a = 3, b = 5, c = 7;
	int i = 0;
	// 取最左边的表达式的运算结果
	i = a + b, b += 3, c += 8;
	printf("i = %d, b= %d\n", i, b);

	int x = 3, y = 5, z = 7;
	int j = 0;
	// 取最右边的表达式的运算结果
	j = (x + y, y += 3, z += 8);
	printf("j = %d, y = %d\n", j, y);

	int m = 5, n = -5;
	// 死循环效果
//    while (m > 0)
//    {
//        printf("死循环......\n");
//    }
	// 非死循环效果
	while (m > 0, n > 0)
	{
		printf("死循环......\n");
	}
}

/*
 * 逗号表达式测试
 *  验证并非只是执行最左边或者最右边的表达式,而是执行所有的表达式
 */
void comma_expression_test_2()
{
	int a = 3, b = 5, c = 7;
	int i = 0;
	// 取最左边的表达式的运算结果
	i = b = a + b, b += 3, c += 8;
	printf("i = %d, b= %d\n", i, b);

	int x = 3, y = 5, z = 7;
	int j = 0;
	// 取最右边的表达式的运算结果
	j = (y = x + y, y += 3, z += 8);
	printf("j = %d, y = %d\n", j, y);
}

/*
 * 逗号表达式测试
 *  逗号表达式实际应用
 *  特别注意：不加括号和加括号，表达式执行顺序都是从左往右依次执行，只是根据是否加括号决定取最右边和最左边的表达式的计算结果
 */
void comma_expression_test_3()
{
	int x = 0;
	if (printf("请输入一个数字:\n"), scanf("%d", &x), x > 0)
	{
		printf("输入的值大于0\n");
	}else {
		printf("输入的值小于0\n");
	}
}

int main()
{
	relational_operator_test();
	//comma_expression_test_1();
	//comma_expression_test_2();
	//comma_expression_test_3();
	return 0;
}
