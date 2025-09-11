#include<stdio.h>
#include<stdbool.h>
#include<string.h>

/**
 * 基于函数指针实现对不同数据类型的数组进行冒泡排序
 */


// 结构体 + typedef简化结构体定义 方式一
/*
// 定义一个结构体
struct Student
{
	int id,
	char[] name,
	int age
};

// 使用typedef简化结构体定义
typedef struct Person Person;
*/


// （匿名）结构体 + typedef简化结构体定义
typedef struct
{
	int id;
	char name[20];
	int age;
} Student;


/**
 * 打印整型数组
 */ 
void print_int_arr_4(const void* vp)
{
	printf("%d\t", *(int*)vp);
}

/**
 * 打印float类型数组
 */ 
void print_float_arr_4(const void* vp)
{
	printf("%.2f\t", *(float*)vp);
}

/**
 * 打印double类型数组
 */ 
void print_double_arr_4(const void* vp)
{
	printf("%.2f\t", *(double*)vp);
}

/**
 * 打印字符数组
 */ 
void print_char_arr_4(const void* vp)
{
	printf("%c\t", *(char*)vp);
}

/**
 * 打印字符串数组
 * 特别注意： 这里的vp是一个二级指针
 */ 
void print_str_arr_4(const void* vp)
{
    char** s = (char**)vp;  // 正确的类型转换
    printf("%s\t", *s);     // 打印字符串内容
}


/**
 * 打印结构体数组
 */ 
void print_struct_arr_4(const void* vp)
{
	const Student* pStudent = (const Student*)vp;
	printf("%d，%s，%d\t", pStudent -> id, pStudent -> name, pStudent -> age);
}

/**
 * 打印数组（泛型方法）
 */
void print_arr_4(const void *vp, int size, int data_type_size, void (*print)(const void *), int print_type)
{
	printf("冒泡排序%s => ", print_type == 0 ? "前" : "后");
	if(NULL == vp || NULL == print || size < 1 || data_type_size < 1)
	{
		return;
	}
	const char *cp = (const char *)vp;
	for(int i = 0; i < size; i++)
	{
		(*print)(cp);
		cp += data_type_size;
	}
	printf("\n");
}

// 交换函数
void swap(void* ap, void* bp, int size)
{
    char temp[size];
    memcpy(temp, ap, size);
    memcpy(ap, bp, size);
    memcpy(bp, temp, size);
}

/**
 * 比较两个int类型数据的大小
 */
bool compare_int(const void* ap, const void* bp)
{
	const int* iap = (const int*)ap;
	const int* ibp = (const int*)bp;
	if(*iap > *ibp)
	{
		return true;
	}
	return false;
}


/**
 * 泛型冒泡排序
 */
void bubble_sort_3(const void* vp, int length, int size, bool (*compare)(const void*, const void*))
{
	char* cp = (char*)vp;
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i -1; j++)
		{
			if((*compare)(&cp[j], &cp[j + size]))
			{
				swap(&cp[j], &cp[j + size], size);
			}
		}
	}
}

#if 0
#endif
int main()
{
	// 定义整型数组
	int ir[] = {64, 34, 25, 12, 22, 90, 11};
	int in = sizeof(ir) / sizeof(ir[0]);
	// 冒泡排序前
	print_arr_4(ir, in, sizeof(int), print_int_arr_4, 0);
	// 冒泡排序
	bubble_sort_3(ir, in, sizeof(int), compare_int);
	// 冒泡排序后
	print_arr_4(ir, in, sizeof(int), print_int_arr_4, 1);

	// 定义float类型数组
	float fr[] = { 3.14f, 2.71f, 1.41f, 1.73f, 0.57f };
	int fn = sizeof(fr) / sizeof(fr[0]);
	// 冒泡排序前
	print_arr_4(fr, fn, sizeof(float), print_float_arr_4, 0);
	// 冒泡排序后


	// 定义double类型数组
	double dr[] = { 5.24, 2.18, 3.43, 7.76, 0.58 };
	int dn = sizeof(dr) / sizeof(dr[0]);
	// 冒泡排序前
	print_arr_4(dr, dn, sizeof(double), print_double_arr_4, 0);
	// 冒泡排序后


	//定义字符数组
	char cr[] = { 'k', 'a', 'i', 'b', 'd' };
	int cn = sizeof(cr) / sizeof(cr[0]);
	// 冒泡排序前
	print_arr_4(cr, cn, sizeof(char), print_char_arr_4, 0);
	// 冒泡排序后


	//定义字符串数组（这里实际上是定义了一个二维数组）
	char* str[] = { "banana", "apple", "cherry", "orange", "pear" };
	int sn = sizeof(str) / sizeof(str[0]);
	// 冒泡排序前
	print_arr_4(str, sn, sizeof(str[0]), print_str_arr_4, 0);
	// 冒泡排序后


	//定义结构体数组
	Student persons[] = {
		{ 1, "张三", 18 },
		{ 2, "李四", 20 },
		{ 3, "王五", 22 }
	};
	int structn = sizeof(persons) / sizeof(persons[0]);
	// 冒泡排序前
	print_arr_4(persons, structn, sizeof(persons[0]), print_struct_arr_4, 0);
	// 冒泡排序后


	// 测试整数数组排序
    // printf("=== 整数数组排序 ===\n");
    // int int_arr[] = {64, 34, 25, 12, 22, 11, 90};
    // size_t int_count = sizeof(int_arr) / sizeof(int_arr[0]);
    
    // printf("排序前: ");
    // print_int_array(int_arr, int_count);
    
    // bubble_sort(int_arr, int_count, sizeof(int), compare_int);
    
    // printf("排序后: ");
    // print_int_array(int_arr, int_count);
    
    // 测试浮点数组排序
    // printf("\n=== 浮点数组排序 ===\n");
    // float float_arr[] = {3.14f, 2.71f, 1.41f, 1.73f, 0.57f};
    // size_t float_count = sizeof(float_arr) / sizeof(float_arr[0]);
    
    // printf("排序前: ");
    // print_float_array(float_arr, float_count);
    
    // bubble_sort(float_arr, float_count, sizeof(float), compare_float);
    
    // printf("排序后: ");
    // print_float_array(float_arr, float_count);
    
    // // 测试字符串数组排序
    // printf("\n=== 字符串数组排序 ===\n");
    // char* str_arr[] = {"banana", "apple", "cherry", "date", "elderberry"};
    // size_t str_count = sizeof(str_arr) / sizeof(str_arr[0]);
    
    // printf("排序前: ");
    // print_string_array(str_arr, str_count);
    
    // bubble_sort(str_arr, str_count, sizeof(char*), compare_string);
    
    // printf("排序后: ");
    // print_string_array(str_arr, str_count);
    
    // // 测试结构体数组排序
    // printf("\n=== 结构体数组排序 ===\n");
    // Person people[] = {
    //     {3, "Charlie"},
    //     {1, "Alice"},
    //     {4, "David"},
    //     {2, "Bob"}
    // };
    // size_t person_count = sizeof(people) / sizeof(people[0]);
    
    // printf("按ID排序前:\n");
    // print_person_array(people, person_count);
    
    // bubble_sort(people, person_count, sizeof(Person), compare_person_by_id);
    
    // printf("按ID排序后:\n");
    // print_person_array(people, person_count);
    
    // printf("按姓名排序:\n");
    // bubble_sort(people, person_count, sizeof(Person), compare_person_by_name);
    // print_person_array(people, person_count);

	return 0;
}
