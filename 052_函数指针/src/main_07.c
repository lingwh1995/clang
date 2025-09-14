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
typedef struct Student Student;
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
void print_arr_4(const void *vp, int size, int data_type_size, void (*print)(const void *), char* data_type_name, int print_type)
{
	printf("%s类型数组冒泡排序%s => ", data_type_name, print_type == 0 ? "前" : "后");
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
 * 比较两个float类型数据的大小
 */
bool compare_float(const void* ap, const void* bp)
{
	const float* fap = (const float*)ap;
	const float* fbp = (const float*)bp;
	if(*fap > *fbp)
	{
		return true;
	}
	return false;
}

/**
 * 比较两个double类型数据的大小
 */
bool compare_double(const void* ap, const void* bp)
{
	const double* dap = (const double*)ap;
	const double* dbp = (const double*)bp;
	if(*dap > *dbp)
	{
		return true;
	}
	return false;
}

/**
 * 比较两个char类型数据的大小
 */
bool compare_char(const void* ap, const void* bp)
{
	const char* cap = (const char*)ap;
	const char* cbp = (const char*)bp;
	if(*cap > *cbp)
	{
		return true;
	}
	return false;
}

/**
 * 比较两个字符串类型数据的大小
 */
bool compare_str(const void* ap, const void* bp)
{
	const char** sap = (const char**)ap;
	const char** sbp = (const char**)bp;
	if(strcmp(*sap, *sbp) > 0)
	{
		return true;
	}
	return false;
}

/**
 * 比较两个结构体类型数据的大小（按id）
 */
bool compare_struct_by_id(const void* ap, const void* bp)
{
	const Student* stu_ap = (const Student*)ap;
	const Student* stu_bp = (const Student*)bp;
	if(stu_ap->id > stu_bp->id)
	{
		return true;
	}
	return false;
}

/**
 * 比较两个结构体类型数据的大小（按姓名）
 */
bool compare_struct_by_name(const void* ap, const void* bp)
{
	const Student* stu_ap = (const Student*)ap;
	const Student* stu_bp = (const Student*)bp;
	if(strcmp(stu_ap->name, stu_bp->name) > 0)
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
            void* current = cp + j * size;
            void* next = cp + (j + 1) * size;
            if((*compare)(current, next))
            {
                swap(current, next, size);
            }
		}
	}
}

#if 0
int main()
{
	// 定义整型数组
	int ir[] = {64, 34, 25, 12, 22, 90, 11};
	int in = sizeof(ir) / sizeof(ir[0]);
	// 冒泡排序前
	print_arr_4(ir, in, sizeof(int), print_int_arr_4, "int", 0);
	// 冒泡排序
	bubble_sort_3(ir, in, sizeof(int), compare_int);
	// 冒泡排序后
	print_arr_4(ir, in, sizeof(int), print_int_arr_4, "int", 1);

	// 定义float类型数组
	float fr[] = { 3.14f, 2.71f, 1.41f, 1.73f, 0.57f };
	int fn = sizeof(fr) / sizeof(fr[0]);
	// 冒泡排序前
	print_arr_4(fr, fn, sizeof(float), print_float_arr_4, "float", 0);
	// 冒泡排序
	bubble_sort_3(fr, fn, sizeof(float), compare_float);
	// 冒泡排序后
	print_arr_4(fr, fn, sizeof(float), print_float_arr_4, "float", 1);


	// 定义double类型数组
	double dr[] = { 5.24, 2.18, 3.43, 7.76, 0.58 };
	int dn = sizeof(dr) / sizeof(dr[0]);
	// 冒泡排序前
	print_arr_4(dr, dn, sizeof(double), print_double_arr_4, "double", 0);
	// 冒泡排序
	bubble_sort_3(dr, dn, sizeof(double), compare_double);
	// 冒泡排序后
	print_arr_4(dr, dn, sizeof(double), print_double_arr_4, "double", 1);


	//定义字符数组
	char cr[] = { 'k', 'a', 'i', 'b', 'd' };
	int cn = sizeof(cr) / sizeof(cr[0]);
	// 冒泡排序前
	print_arr_4(cr, cn, sizeof(char), print_char_arr_4, "char", 0);
	// 冒泡排序
	bubble_sort_3(cr, cn, sizeof(char), compare_char);
	// 冒泡排序后
	print_arr_4(cr, cn, sizeof(char), print_char_arr_4, "char", 1);


	//定义字符串数组（这里实际上是定义了一个二维数组）
	char* str[] = { "ban\0ana", "apple", "cherry", "orange", "pear" };
	int sn = sizeof(str) / sizeof(str[0]);
	// 冒泡排序前
	print_arr_4(str, sn, sizeof(str[0]), print_str_arr_4, "字符串", 0);
	// 冒泡排序
	bubble_sort_3(str, sn, sizeof(str[0]), compare_str);
	// 冒泡排序后
	print_arr_4(str, sn, sizeof(str[0]), print_str_arr_4, "字符串", 1);


	//定义结构体数组
	Student students[] = {
		{ 1, "zhangsan", 18 },
		{ 3, "lisi", 20 },
		{ 2, "wangwu", 22 }
	};
	int structn = sizeof(students) / sizeof(students[0]);
	// 冒泡排序前
	print_arr_4(students, structn, sizeof(students[0]), print_struct_arr_4, "结构体", 0);
	//bubble_sort_3(students, structn, sizeof(students[0]), compare_struct_by_id);
	bubble_sort_3(students, structn, sizeof(students[0]), compare_struct_by_name);
	// 冒泡排序后
	print_arr_4(students, structn, sizeof(students[0]), print_struct_arr_4, "结构体", 1);
	return 0;
}
#endif
