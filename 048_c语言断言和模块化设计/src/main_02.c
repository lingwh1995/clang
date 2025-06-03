#include <stdio.h>
#include "mylib_2.h"
#define ARSIZE 100

/*
 * 使用函数实现模块化设计 V3.0：使用多文件结构,将工具函数提取到mylib_2.h和mylib_2.c中(去除数组中重复元素版本)
 * 使用断言校验参数
 *	断言和if else区别: 断言不通过会弹出窗口，if else不会弹出窗口
 * 函数设计原则
 *	函数功能越小越好
 *  要对参数的合法性进行校验，如要判断指针是否为空
 */

#if 0
#endif
int main()
{
	int arr[ARSIZE] = { 0 };
	int* pArr = NULL;
	int val = 0;
	if (0 == val)
	{
		pArr = &arr;
	}
	InitArrV3(pArr, ARSIZE);
	BubbleSortV3(pArr, ARSIZE);
	PrintArrV3(pArr, ARSIZE);
	return 0;
}
