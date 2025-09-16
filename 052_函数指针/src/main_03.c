#include <stdio.h>
#include <stdbool.h>

/**
 * 使用函数指针优化冒泡排序
 */

/**
 * 交换两个数字
 */
void swap_number_2(int* a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * 判断a是否大于b
 */
bool greater(int a, int b)
{
	return a > b;
}

/**
 * 判断a是否小于b
 */
bool less(int a, int b)
{
	return a < b;
}

/**
 * 冒泡排序
 */
void bubble_sort_2(int* arr, int length, int (*compare)(int, int))
{
	if(NULL == arr || length < 2)
	{
		return;
	}
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i - 1; j++)
		{
			if(compare(arr[j], arr[j + 1]))
			{
				swap_number_2(&arr[j], &arr[j + 1]);
			}
		}
	}
}

/**
 * 打印数组
 */
void print_arr_2(int* arr, int length)
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
	//bubble_sort_2(arr, length, greater);
	bubble_sort_2(arr, length, less);
	// 打印数组
	print_arr_2(arr, length);
	return 0;
}
#endif
