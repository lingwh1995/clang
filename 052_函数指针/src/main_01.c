#include <stdio.h>

/**
 * 基于函数指针实现函数回调（即把函数作为参数传递）
 */

typedef int (*PFUN)(int, int);

// 声明min()函数
int min(int, int);

// 声明max()函数
int max(int, int);

// 声明call_fun_1()函数
int call_fun_1(int, int, int (*pfun)(int, int));

// 声明call_fun_2()函数
int call_fun_2(int, int, PFUN pfun);

#if 0
int main()
{
	int a = 10, b = 20;
	// 使用函数回调（正常定义函数指针版）调用获取最小值函数
	int min_value = call_fun_1(a, b, min);
	printf("正常定义函数指针版 min_value = %d\n", min_value);
	// 使用函数回调（正常定义函数指针版）调用获取最大值函数
	int max_value = call_fun_1(a, b, max);
	printf("正常定义函数指针版 max_value = %d\n", max_value);

	a = 100, b = 200;
	// 使用函数回调（typedef简化函数指针定义版）调用获取最小值函数
	min_value = call_fun_2(a, b, min);
	printf("typedef简化函数指针定义版 min_value = %d\n", min_value);
	// 使用函数回调调（typedef简化函数指针定义版）用获取最大值函数
	max_value = call_fun_2(a, b, max);
	printf("typedef简化函数指针定义版 max_value = %d\n", max_value);
	return 0;
}
#endif

/**
 * 函数回调1：正常定义函数指针版
 * @param a
 * @param b
 * @param pfun 被回调的函数
 */
int call_fun_1(int a, int b, int (*pfun)(int, int))
{
	if(NULL == pfun)
	{
		return -1;
	}
	// 通过函数指针调用函数
	return (*pfun)(a, b); // => return pfun(a, b);
}

/**
 * 函数回调2： typedef简化函数指针定义版
 * @param a
 * @param b
 * @param pfun 被回调的函数
 */
int call_fun_2(int a, int b, PFUN pfun)
{
	if(NULL == pfun)
	{
		return -1;
	}
	// 通过函数指针调用函数
	return (*pfun)(a, b); // => return pfun(a, b);
}

/**
 * 求两个数中最小值
 * @param a
 * @param b
 */
int min(int a, int b)
{
	return a > b ? b : a;
}

/**
 * 求两个数中最大值
 * @param a
 * @param b
 */
int max(int a, int b)
{
	return a > b ? a : b;
}
