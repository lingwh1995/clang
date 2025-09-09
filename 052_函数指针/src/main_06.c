#include<stdio.h>

/**
 * 基于函数指针实现打印不同数据类型的数组
 * 	注意： int类型指针可以转换为char类型指针，char类型指针也可以再反向转为int类型指针
 * 		  double类型指针可以转换为char类型指针，char类型指针也可以再反向转为double类型指针
 */

/**
 * 打印int类型数组
 */ 
void print_int_arr(const void* vp)
{
	// 将char类型指针还原为泛型指针（具体是int类型指针）
	printf("%d\t", *((int*)vp));
}

/**
 * 打印double类型数组
 */ 
void print_double_arr(const void* vp)
{
	// 将char类型指针还原为泛型指针（具体是double类型指针）
	printf("%.1f\t", *((double*)vp));
}

/**
 * 打印char类型数组
 */ 
void print_char_arr(const void* vp)
{
	// 将char类型指针还原为泛型指针（具体是char类型指针）
	printf("%c\t", *((char*)vp));
}

/**
 * 打印数组： 写法一
 * @param arr 要打印的数组
 * @param size 要打印的数组长度
 * @param data_type_size 对应的数据类型的长度
 * @param print 函数指针
 */
void print_arr(const void *arr, int size, int data_type_size, void (*print)(const void *))
{
	if(NULL == arr || NULL == print || size < 1 || data_type_size < 1)
	{
		return;
	}
	// 将泛型指针转换为char类型指针
	const char *cp = (const char*)arr;
	for(int i = 0; i < size; i++)
	{
		(*print)(cp);
		cp += data_type_size;
	}
	printf("\n");
}

/**
 * 打印数组： 写法二
 * @param arr 要打印的数组
 * @param size 要打印的数组长度
 * @param data_type_size 对应的数据类型的长度
 * @param print 函数指针
 */
/*
void print_arr(const void *arr, int size, int data_type_size, void (*print)(const void *))
{
	if(NULL == arr || NULL == print || size < 1 || data_type_size < 1)
	{
		return;
	}
	for(int i = 0; i < size; i++)
	{
		(*print)(arr);
		arr += data_type_size;
	}
	printf("\n");
}
*/
#if 0
int main()
{
	// 创建一个int类型数组
	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89 };
	int in = sizeof(ar) / sizeof(ar[0]);
	// 创建一个double类型数组
	double dr[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9 };
	int dn = sizeof(dr) / sizeof(dr[0]);
	// 创建一个char类型数组
	char cr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
	int cn = sizeof(cr) / sizeof(cr[0]);
	print_arr(ar, in, sizeof(int), print_int_arr);
	print_arr(dr, dn, sizeof(double), print_double_arr);
	print_arr(cr, cn, sizeof(char), print_char_arr);
	return 0;
}
#endif
