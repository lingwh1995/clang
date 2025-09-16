#include <stdio.h>

/**
 * 冒泡排序基础版
 */

/**
 * 交换两个数字
 */
void swap_number_1(int* a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * 冒泡排序
 */
void bubble_sort_1(int* arr, int length)
{
	if(NULL == arr || length < 2)
	{
		return;
	}
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				swap_number_1(&arr[j], &arr[j + 1]);
			}
		}
	}
}

/**
 * 打印数组
 */
void print_arr_1(int* arr, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d\n", arr[i]);
	}
}

#if 0
int main()
{
	int arr[] = { 5, 1, 9, 7, 3 };
	int length = sizeof(arr)/sizeof(arr[0]);
	// 冒泡排序
	bubble_sort_1(arr, length);
	// 打印数组
	print_arr_1(arr, length);
	return 0;
}
#endif

