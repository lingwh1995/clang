#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * 比较两个int类型数据的大小
 * @param pa
 * @param pb
 * @return
 */
int comp_int(const void* pa, const void* pb)
{
	const int* ipa = (const int*)pa;
	const int* ipb = (const int*)pb;
	if(*ipa > *ipb)
	{
		return 1;
	}
	else if(*ipa < *ipb)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

/**
 * 比较两个double类型数据的大小
 * @param pa
 * @param pb
 * @return
 */
int comp_double(const void* pa, const void* pb)
{
	const double* dpa = (const double*)pa;
	const double* dpb = (const double*)pb;
	if(*dpa > *dpb)
	{
		return 1;
	}
	else if(*dpa < *dpb)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

/**
 * 比较两个char类型数据的大小
 * @param pa
 * @param pb
 * @return
 */
int comp_char(const void* pa, const void* pb)
{
	const char* cpa = (const char*)pa;
	const char* cpb = (const char*)pb;
	if(*cpa > *cpb)
	{
		return 1;
	}
	else if(*cpa < *cpb)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

/**
 * 比较两个字符串的大小
 * @param pa
 * @param pb
 * @return
 */
int comp_str(const void* pa, const void* pb)
{
	const char** spa = (const char**)pa;
	const char** spb = (const char**)pb;
	return strcmp(*spa, *spb);
}

/**
 * 打印整形数组
 */
void print_int_arr_5(int* arr, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

/**
 * 打印double类型数组
 */
void print_double_arr_5(double* arr, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%.2f\t", arr[i]);
	}
	printf("\n");
}


/**
 * 打印char类型数组
 */
void print_char_arr_5(char* arr, int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%c\t", arr[i]);
	}
	printf("\n");
}

/*
 * 打印字符串类型数组
 */
void print_str_arr_5(const char* arr[], int length)
{
	for(int i = 0; i < length; i++)
	{
		printf("%s\t", arr[i]);
	}
	printf("\n");
}

#if 0
int main()
{
	// 对整型数组进行快速排序
	int ar[] = { 34, 56, 89, 12, 90, 100, 45, 23 };
	int in = sizeof(ar) / sizeof(ar[0]);
	qsort(ar, in, sizeof(int), comp_int);
	print_int_arr_5(ar, in);

	// 对double型数组进行快速排序
	double dr[] = { 2.6, 2.8, 3.7, 4.6, 7.2 };
	int dn = sizeof(dr) / sizeof(dr[0]);
	qsort(dr, dn, sizeof(double), comp_double);
	print_double_arr_5(dr, dn);

	// 对char型数组进行快速排序
	char cr[] = { 'b', 'e', 'c', 'a', 'd' };
	int cn = sizeof(cr) / sizeof(cr[0]);
	qsort(cr, cn, sizeof(char), comp_char);
	print_char_arr_5(cr, cn);

	// 对字符串数组进行排序
	const char* str[] = { "bcd", "acd", "abc", "efg", "def"};
	int sn = 5;
	qsort(str, sn, sizeof(char*), comp_str);
	print_str_arr_5(str, sn);
	return 0;
}
#endif
