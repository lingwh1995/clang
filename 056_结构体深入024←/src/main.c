#include <stdio.h>
#include <string.h>

/**
 * 嵌套结构体测试
 */
void nested_structure_test()
{
	struct Date
	{
		int year;
		int month;
		int day;
	};

	/**
	 * 在结构体中使用另一个结构体作为成员变量
	 */
	struct Student
	{
		char id[20];
		char name[20];
		char sex[8];
		int age;
		struct Date birthday;
	};

	// 使用 . 访问
	struct Student s1 = { "001", "张三", "男", 23, { 2026, 3, 20}};
	printf("id = %s\n", s1.id);
	printf("name = %s\n", s1.name);
	printf("sex = %s\n", s1.sex);
	printf("age = %d\n", s1.age);
	printf("birthday = %d年%d月%d日\n", s1.birthday.year, s1.birthday.month, s1.birthday.day);
	printf("-----------------\n");

	// 使用 -> 访问
	struct Student *sp = &s1;
	printf("id = %s\n", (*sp).id);
	printf("name = %s\n", (*sp).name);
	printf("sex = %s\n", sp->sex);
	printf("age = %d\n", sp->age);
	printf("birthday = %d年%d月%d日\n", sp->birthday.year, sp->birthday.month, sp->birthday.day);
	printf("-------------------------------------\n");
}

// -----------------------------------------------------------------------------------
// 定义结构体类型和结构体指针类型
typedef struct
{
	char id[20];
	char name[20];
	char sex[8];
	int age;
} Student, *PStudent;

/**
 * 使用指针打印结构体
 */
void pointer_print_structure(const Student *student)
{
	if(student == NULL)
	{
		return;
	}
	/**
	 * -> 就是 (* ). 的简化写法
	 */
	printf("id = %s\n", (*student).id);
	printf("name = %s\n", (*student).name);
	printf("sex = %s\n", student->sex);
	printf("age = %d\n", student->age);
}

/**
 * 使用指针给结构体赋值
 */
void pointer_input_structure(Student *student)
{
	if(student == NULL)
	{
		return;
	}
	/**
	 * 特别注意
	 *
	 * 1. student->id 的意思是：用结构体指针，访问它指向的结构体里的 id 成员，所以 student->id = 指针指向的结构体
	 *    中的 id 成员
	 * 2. 之所以是student->name而不是&student->name，因为student->name 类型是 char[20]，在传参时，自动退化成指
	 *    针，所以直接写 student->name 就等于传了地址
	 * 3. ->(成员选择符)的优先级高于&(取地址符)，所以 &student->age 实际上相当于 &(student->age)
	 */
	printf("请输入student id:\n");
	scanf("%s", student->id);
	printf("请输入student name:\n");
	scanf("%s", student->name);
	printf("请输入student sex:\n");
	scanf("%s", student->sex);
	printf("请输入student age:\n");
	scanf("%d", &student->age);
}

void pointer_print_structure_test()
{
	Student student = { "002", "李四", "男", 20 };
	PStudent p_student = &student;
	// 只有数组才名才能在不去地址的情况下直接当成指针用，其他类型数据不行，要取地址才能用
	pointer_print_structure(p_student);
	printf("-------------------------------------\n");
}

/**
 * 给结构体赋值并打印赋值后的结构体
 */
void pointer_input_and_print_structure_test()
{
	Student student = { 0 };
	PStudent p_student = &student;
	pointer_input_structure(p_student);
	pointer_print_structure(p_student);
	printf("-------------------------------------\n");
}
// -----------------------------------------------------------------------------------


// -----------------------------------------------------------------------------------
// 使用指针打印结构体数组 方式一
/*
void pointer_print_structure_arr(const Student *p_student_arr, int len)
{
	if(p_student_arr == NULL)
	{
		return;
	}
	for(int i = 0; i < len; i++)
	{
		printf("id = %s ", p_student_arr[i].id);
		printf("name = %s ", p_student_arr[i].name);
		printf("sex = %s ", p_student_arr[i].sex);
		printf("age = %d\n", p_student_arr[i].age);
	}
}
*/

// 使用指针打印结构体数组 方式二
void pointer_print_structure_arr(const Student *p_student_arr, int len)
{
	if(p_student_arr == NULL)
	{
		return;
	}
	for(int i = 0; i < len; i++)
	{
		printf("id = %s ", p_student_arr->id);
		printf("name = %s ", p_student_arr->name);
		printf("sex = %s ", p_student_arr->sex);
		printf("age = %d\n", p_student_arr->age);
		p_student_arr++;
	}
}

/**
 * 使用指针打印结构体数组测试
 */
void pointer_print_structure_arr_test()
{
	// 定义结构体数组
	Student student_arr[] = {
			{ "001", "张三", "男", 18 },
			{ "002", "李四", "女", 20 },
			{ "003", "王五", "男", 24 },
			{ "006", "赵六", "女", 28 },
	};
	int len = sizeof(student_arr) / sizeof(student_arr[0]);
	/**
	 * 特别注意：
	 * 	  PStudent p_student_arr = &student_arr; 错误写法  &student_arr代表的是整个数组的地址
	 * 	  PStudent p_student_arr = student_arr;  正确写法  student_arr 代表的是数组首元素地址
	 */
	PStudent p_student_arr = student_arr;
	pointer_print_structure_arr(p_student_arr, len);
	printf("-------------------------------------\n");
}
// -----------------------------------------------------------------------------------


// -----------------------------------------------------------------------------------
/**
 * 使用指针查找结构体测试
 */
int pointer_find_structure(const Student *p_student_arr, int len, char *name)
{
	int position = -1;
	if(p_student_arr == NULL || name == NULL)
	{
		return position;
	}
	for(int i = 0; i < len; i++)
	{
		if(strcmp(p_student_arr[i].name, name) == 0)
		{
			printf("id = %s ", p_student_arr[i].id);
			printf("name = %s ", p_student_arr[i].name);
			printf("sex = %s ", p_student_arr[i].sex);
			printf("age = %d\n", p_student_arr[i].age);
			position = i;
		}
	}
	return position;
}

void pointer_find_structure_test()
{
	// 定义结构体数组
	Student student_arr[] = {
			{ "001", "张三", "男", 18 },
			{ "002", "李四", "女", 20 },
			{ "003", "王五", "男", 24 },
			{ "006", "赵六", "女", 28 },
	};
	int len = sizeof(student_arr) / sizeof(student_arr[0]);
	/**
	 * 特别注意：
	 * 	  PStudent p_student_arr = &student_arr; 错误写法  &student_arr代表的是整个数组的地址
	 * 	  PStudent p_student_arr = student_arr;  正确写法  student_arr 代表的是数组首元素地址
	 */
	const PStudent p_student_arr = student_arr;
	char *name = "王五";
	int position = pointer_find_structure(p_student_arr, len, name);
	printf("索引位置 = %d\n", position);
	printf("-------------------------------------\n");
}
// -----------------------------------------------------------------------------------


#if 0
int main()
{
	nested_structure_test();
	pointer_print_structure_test();
	//pointer_input_and_print_structure_test();
	pointer_print_structure_arr_test();
	pointer_find_structure_test();
	return 0;
}
#endif
