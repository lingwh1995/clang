//#include<stdio.h>
//
///**
// * 基于函数指针实现对不同数据类型的数组进行冒泡排序
// */
//
///**
// * 交换两个数
// */
//void swap_number(int *ap, int *bp)
//{
//	int temp = *ap;
//	*ap = *bp;
//	*bp = temp;
//}
//
///**
// * 打印数组
// */
//void print_arr_generic(int *arr, int length)
//{
//	for(int i = 0; i< length; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//}
//
///**
// * 冒泡排序
// */
//void bubble_sort(const void* vp, int length, int size)
//{
//	for(int i = 0; i < length - 1; i++)
//	{
//		for(int j = 0; j < length - 1 - i; j++)
//		{
//			if(arr[j] > arr[j + 1])
//			{
//				swap_number(&arr[j], &arr[j + 1]);
//			}
//		}
//	}
//}
//#if 0
//int main()
//{
//	int ar[] = { 9, 5, 3, 1, 6, 8 };
//	int an = sizeof(ar) / sizeof(ar[0]);
//	bubble_sort(ar, an, sizeof(int));
//	print_arr_generic(ar, an);
//	return 0;
//}
//#endif
