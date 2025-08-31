#include <stdio.h>

/**
 * 使用函数调用优化冒泡排序
 */

void swap_number(int* a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * 冒泡排序
 */
void bubble_sort(int* arr, int length)
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
				swap_number(&arr[j], &arr[j + 1]);
			}
		}
	}
}

/**
 * 打印数组
 */
void print_arr(int* arr, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d\n", arr[i]);
	}
}

#if 0
#endif
int main()
{
	int arr[] = { 5, 1, 9, 7, 3 };
	int length = sizeof(arr)/sizeof(arr[0]);
	// 冒泡排序
	bubble_sort(arr, length);
	// 打印数组
	print_arr(arr, length);
	return 0;
}

