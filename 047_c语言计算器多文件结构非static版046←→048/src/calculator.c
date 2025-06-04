//使用多文件结构(模块化设计)编写计算器程序:函数实现部分
#include <stdbool.h>
#include <stdio.h>
#include "calculator.h"

//声明本文件中的函数
int Add_Int(int a, int b);
int Sub_Int(int a, int b);
int Mul_Int(int a, int b);
int Div_Int(int a, int b);
void Show(int a, int b, char op, int result);

/*
 * 进行计算的方法,不能使用static修饰,因为这是本程序唯一对外暴露的接口
 * @param a 计算参数1
 * @param b 计算参数2
 * @param op 运算符
 */
void Calc(int a, int b, char op)
{
	int result = 0;
	bool bIsShow = true;
	switch (op)
	{
		case '+':
			result = Add_Int(a, b);
			break;
		case '-':
			result = Sub_Int(a, b);
			break;
		case '*':
			result = Mul_Int(a, b);
			break;
		case '/':
			if (b == 0)
			{
				bIsShow = false;
				printf("div by zeron error!\n");
			}
			else
			{
				result = Div_Int(a, b);
			}
			break;
		default:
			bIsShow = false;
			printf("op input error!\n");
			break;
	}
	if (bIsShow)
	{
		Show(a, b, op, result);
	}
}

/*
 * 加法，如果不想被外部调用,使用static修饰
 * @param a 计算参数1
 * @param b 计算参数2
 */

int Add_Int(int a, int b)
{
	return a + b;
}

/*
 * 减法，如果不想被外部调用,使用static修饰
 * @param a 计算参数1
 * @param b 计算参数2
 */

int Sub_Int(int a, int b)
{
	return a - b;
}

/*
 * 乘法，如果不想被外部调用,使用static修饰
 * @param a 计算参数1
 * @param b 计算参数2
 */

int Mul_Int(int a, int b)
{
	return a * b;
}

/*
 * 除法，如果不想被外部调用,使用static修饰
 * @param a 计算参数1
 * @param b 计算参数2
 */

int Div_Int(int a, int b)
{
	return a / b;
}

/*
 * 显示结果，如果不想被外部调用,使用static修饰
 * @param a 计算参数1
 * @param b 计算参数2
 * @param op 运算符
 * @param result 计算结果
 */

void Show(int a, int b, char op, int result)
{
	printf("%d %c %d = %d\n", a, op, b, result);
}
