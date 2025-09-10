#include<stdio.h>

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
 */ 
void print_str_arr_4(const void* vp)
{
//	char* s = (char*)vp;
//	printf("%p\t", s);
//	printf("%s\t", *s);
    char** s = (char**)vp;  // 正确的类型转换
    printf("%s\t", *s);     // 打印字符串内容
}


/**
 * 打印结构体数组
 */ 
void print_struct_arr_4(const void* vp)
{
	const Student* pStudent = (const Student*)vp;
	printf("编号： %d， 姓名： %s， 年龄： %d\n", pStudent -> id, pStudent -> name, pStudent -> age);
}

/**
 * 打印数组（泛型方法）
 */
void print_arr_4(const void *vp, int size, int data_type_size, void (*print)(const void *))
{
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

#if 0
#endif
int main()
{
	// 定义整型数组
	int ir[] = {64, 34, 25, 12, 22, 11, 90};
	int in = sizeof(ir) / sizeof(ir[0]);
	// 排序前
	print_arr_4(ir, in, sizeof(int), print_int_arr_4);
	// 排序后


	// 定义float类型数组
	float fr[] = { 3.14f, 2.71f, 1.41f, 1.73f, 0.57f };
	int fn = sizeof(fr) / sizeof(fr[0]);
	// 排序前
	print_arr_4(fr, fn, sizeof(float), print_float_arr_4);
	// 排序后


	// 定义double类型数组
	double dr[] = { 3.14, 2.71, 1.41, 1.73, 0.57 };
	int dn = sizeof(dr) / sizeof(dr[0]);
	// 排序前
	print_arr_4(dr, dn, sizeof(double), print_double_arr_4);
	// 排序后


	//定义字符数组
	char cr[] = { 'k', 'a', 'i', 'b', 'd' };
	int cn = sizeof(cr) / sizeof(cr[0]);
	// 排序前
	print_arr_4(cr, cn, sizeof(char), print_char_arr_4);
	// 排序后


	//定义字符串数组
	char* str[] = { "banana", "apple", "cherry", "orange", "pear" };
	int sn = sizeof(str) / sizeof(str[0]);
	// 排序前
	print_arr_4(str, sn, sizeof(str[0]), print_str_arr_4);
	// 排序后


	//定义结构体数组
	Student persons[] = {
		{ 1, "张三", 18 },
		{ 2, "李四", 20 },
		{ 3, "王五", 22 }
	};
	int structn = sizeof(persons) / sizeof(persons[0]);
	// 排序前
	print_arr_4(persons, structn, sizeof(persons[0]), print_struct_arr_4);
	// 排序后


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
