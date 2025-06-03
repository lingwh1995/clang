#include <stdio.h>
#include <time.h>
#include <assert.h>
#define ARSIZE 100

/*
 * 使用函数实现模块化设计 V1.0：使用单文件结构,所有工具函数提取到当前文件中
 * 使用断言校验参数
 *	断言和if else区别: 断言不通过会弹出窗口,if else不会弹出窗口
 * 函数设计原则
 *	函数功能越小越好
 *  要对参数的合法性进行校验,如要判断指针是否为空
 */

/*
 * 初始化数组
 * @param *arr 代表数组的指针
 * @param length 数组长度 
 */
void InitArrV1(int *arr, int length)
{
	//使用传统if else 判断参数是否合法
	//if (NULL == arr || length < 1) return;
	//使用断言判断参数是否合法,表达式为真,继续向下执行,表达式为假,弹出窗提示
	assert(NULL != arr && length >= 1);
	srand((unsigned)time(NULL));
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

/*
 * 交换两个数
 * @param *ap 代表第一个数的指针
 * @param *bp 代表第二个数的指针
 */
void SwapV1(int *ap, int *bp)
{
	//使用传统if else 判断参数是否合法
	//if (NULL == ap || NULL == bp) return;
	//使用断言判断参数是否合法,表达式为真,继续向下执行,表达式为假,弹出窗提示
	assert(NULL != ap && NULL != bp);
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}

/*
 * 冒泡排序
 * @param *arr 代表数组的指针
 * @param length 数组长度 
 */
void BubbleSortV1(int *arr, int length)
{
	//使用传统if else 判断参数是否合法
	//if (NULL == arr || length < 1) return;
	//使用断言判断参数是否合法,表达式为真,继续向下执行,表达式为假,弹出窗提示
	assert(NULL != arr && length >= 1);
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 -i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				SwapV1(&arr[j], &arr[j+1]);
			}
		}
	}
}

/*
 * 打印数组
 * @param *arr 代表数组的指针
 * @param length 数组长度 
 */
void PrintArrV1(int* arr, int length)
{
	//使用传统if else 判断参数是否合法
	//if (NULL == arr || length < 1) return;
	//使用断言判断参数是否合法,表达式为真,继续向下执行,表达式为假,弹出窗提示
	assert(NULL != arr && length >= 1);
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", arr[i]);
	}
}

#if 0
int main()
{
	int arr[ARSIZE] = { 0 };
	int* pArr = NULL;
	int val = 0;
	if (0 == val)
	{
		pArr = &arr;
	}
	InitArrV1(pArr, ARSIZE);
	BubbleSortV1(pArr, ARSIZE);
	PrintArrV1(pArr, ARSIZE);
	return 0;
}
#endif // 0