#include "mylib_2.h"
#include <time.h>
#include <assert.h>

/*
 * 从数组中查找当前值,查找到返回数组索引,查找不到返回-1
 * @param *arr 代表数组的指针
 * @param n 当前元素在目标数组中的索引
 * @param val 要确定是否存在于当前数组中的值
 */
/*
int FindValueV3(const* arr, int n, int val)
{
	assert(NULL != arr);
	if (n < 1) return -1;
	int position = -1;
	for (int i = 0; i < n; i++) {
		if (val == arr[i]) {
			position = i;
		}
	}
	return position;
}
*/
int FindValueV3(const* arr, int n, int val)
{
	assert(NULL != arr);
	if (n < 1) return -1;
	int position = n - 1;
	while (position >= 0 && arr[position] != val)
	{
		position--;
	}
	return position;
}

/*
 * 初始化数组
 * @param *arr 代表数组的指针
 * @param length 数组长度
 */
void InitArrV3(int* arr, int length)
{
	//使用传统if else 判断参数是否合法
	//if (NULL == arr || length < 1) return;
	//使用断言判断参数是否合法,表达式为真,继续向下执行,表达式为假,弹出窗提示
	assert(NULL != arr && length >= 1);
	srand((unsigned)time(NULL));
	int i = 0;
	while (i < 100)
	{
		int r = rand() % 100 + 1;
		int position = FindValueV3(arr, i, r);
		if (position == -1)
		{
			arr[i] = r;
			i++;
		}
	}
}

/*
 * 交换两个数
 * @param *ap 代表第一个数的指针
 * @param *bp 代表第二个数的指针
 */
void SwapV3(int* ap, int* bp)
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
void BubbleSortV3(int* arr, int length)
{
	//使用传统if else 判断参数是否合法
	//if (NULL == arr || length < 1) return;
	//使用断言判断参数是否合法,表达式为真,继续向下执行,表达式为假,弹出窗提示
	assert(NULL != arr && length >= 1);
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				SwapV3(&arr[j], &arr[j + 1]);
			}
		}
	}
}

/*
 * 打印数组
 * @param *arr 代表数组的指针
 * @param length 数组长度
 */
void PrintArrV3(int* arr, int length)
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