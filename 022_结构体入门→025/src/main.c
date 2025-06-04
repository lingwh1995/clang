#include <stdio.h>
#include <string.h>

/*
 * 1.结构体是属性的集合
 * 2.结构体定义时最后必须加分号，否则会报错
 * 3.定义在main()之外的结构体称为全局结构体，定义在main()里面的结构体称为局部结构体 
 * 4.定义结构体、结构体类型变量、结构体类型指针变量有以下几种方式
 * 		方式一：先定义结构体,再定义结构体变量(或结构体类型指针变量)
 *			// 定义结构体
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			// 定义结构体类型变量
 *			struct Student student;
 *			// 定义结构体类型指针变量
 *			struct Student* pStudent;
 *
 *		方式二：定义结构体的同时定义结构体变量(或结构体类型指针变量)
 *			// 定义结构体的同时定义结构体类型变量(或结构体类型指针变量)
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			} student, * pStudent;
 *
 *		方式三：使用typedef关键字定义结构体，定义结构体变量(或结构体类型指针变量)时可以使用简化的方式声明
 * 			// 定义结构体
 *			typedef struct
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			} Student;
 *
 *			// 定义结构体类型变量
 *			Student student;
 *			// 定义结构体类型指针变量
 *			Student* pStudent;
 *
 *		方式四：定义匿名结构体(适用于临时使用结构体的情况)
 *			// 定义匿名结构体类型变量(或结构体类型指针变量)
 *			struct
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			} student, * pStudent;
 *
 * 5.给结构体变量赋值有以下几种方式
 *		方式一：直接赋值(使用.运算符赋值)
 *			// 定义结构体
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			// 定义结构体类型变量并赋值
 *			struct Student student = { 1,"张三", 18 };
 *
 *		方式二：先定义结构体类型变量，后赋值(使用.运算符赋值)
 *			// 定义结构体
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			// 定义结构体类型变量
 *			struct Student student;
 *			// 给结构体类型变量赋值
 *			student.id = 1;
 *			strcpy(student.name, "张三");
 *			student.age = 18;
 *
 *		方式三：C99指定初始化器(可乱序赋值)
 *			// 定义结构体
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			// 定义结构体类型变量并使用C99指定初始化器赋值
 *			struct Student student = {.id=1, .age=18, .name="张三"};
 *
 *		方式四：使用指针解引用赋值(指针需要进行初始化且初始化时不能指向NULL)
 *			// 定义结构体
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			struct Student student = {};
 *
 *			// 定义结构体类型指针变量
 *			struct Student* pStudent = &student;
 *			// 使用指针解引用赋值
 *			(*pStudent).id = 1;
 *			strcpy((*pStudent).name, "张三");
 *			(*pStudent).age = 23;
 *
 *		方式五：使用指针配合箭头函数赋值
 *			// 定义结构体
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			struct Student student = {};
 *
 *			// 定义结构体类型指针变量
 *			struct Student* pStudent = &student;
 *			// 使用指针配合箭头函数赋值
 *			pStudent->id = 1;
 *			strcpy(pStudent->name, "张三");
 *			pStudent->age = 23;
 *
 * 6.访问结构体变量有以下几种方式
 * 		方式一：使用.运算符访问
 *			// 定义结构体
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			// 定义结构体类型变量并赋值
 *			struct Student student = { 1,"张三", 18 };
 *			printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);
 *
 * 		方式二：使用指针解引用访问
 * 			// 定义结构体
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			// 定义结构体类型变量并赋值
 *			struct Student student = { 1,"张三", 18 };
 *			struct Student* pStudent = &student;
 *			printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", (*pStudent).id, (*pStudent).name, (*pStudent).age);
 *
 *		方式三：使用指针配合箭头函数访问
 *			// 定义结构体
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			// 定义结构体类型变量并赋值
 *			struct Student student = { 1,"张三", 18 };
 *			struct Student* pStudent = &student;
 *			printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", pStudent->id, pStudent->name, pStudent->age);
 */

/**
 * 定义结构体、结构体类型变量(或结构体类型指针变量)方式一：先定义结构体,再定义结构体类型变量(或结构体类型指针变量)
 */ 
void DefineStruct_1()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量
	struct Student student;
	// 定义结构体类型指针变量
	struct Student* pStudent;

	student.id = 1;
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);

	pStudent = &student;
	pStudent->id = 2;
	strcpy(pStudent->name, "李四");
	pStudent->age = 23;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", pStudent->id, pStudent->name, pStudent->age);
}


/**
 * 定义结构体、结构体类型变量(或结构体类型指针变量)方式二：定义结构体的同时定义结构体类型变量(或结构体类型指针变量)
 */ 
void DefineStruct_2()
{
	// 定义结构体的同时定义结构体类型变量(或结构体类型指针变量)
	struct Student
	{
		int id;
		char name[20];
		int age;
	} student, * pStudent;

	student.id = 1;
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);

	pStudent = &student;
	pStudent->id = 2;
	strcpy(pStudent->name, "李四");
	pStudent->age = 23;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", pStudent->id, pStudent->name, pStudent->age);
}


/**
 * 定义结构体、结构体类型变量(或结构体类型指针变量)方式三：使用typedef关键字定义结构体，定义结构体类型变量(或结构体类型指针变量)时可以使用简化的方式声明
 */ 
void DefineStruct_3()
{
	// 定义结构体
	typedef struct
	{
		int id;
		char name[20];
		int age;
	} Student;

	// 定义结构体类型变量
	Student student;
	// 定义结构体类型指针变量
	Student* pStudent;

	student.id = 1;
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);

	pStudent = &student;
	pStudent->id = 2;
	strcpy(pStudent->name, "李四");
	pStudent->age = 23;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", pStudent->id, pStudent->name, pStudent->age);
}


/**
 * 定义结构体、结构体类型变量(或结构体类型指针变量)方式四：定义匿名结构体类型变量(或结构体类型指针变量)(适用于临时使用结构体的情况)
 */ 
void DefineStruct_4()
{
	// 定义匿名结构体类型变量(或结构体类型指针变量)
	struct
	{
		int id;
		char name[20];
		int age;
	} student, * pStudent;

	student.id = 1;
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);

	pStudent = &student;
	pStudent->id = 2;
	strcpy(pStudent->name, "李四");
	pStudent->age = 23;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", pStudent->id, pStudent->name, pStudent->age);
}


/**
 * 给结构体变量赋值方式一：直接赋值(使用.运算符赋值)
 */ 
void AssignmentStruct_1()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并赋值
	struct Student student = { 1,"张三", 18 };
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);
}


/**
 * 给结构体变量赋值方式二：先定义结构体类型变量，后赋值(使用.运算符赋值)
 */ 
void AssignmentStruct_2()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量
	struct Student student;
	// 给结构体类型变量赋值
	student.id = 1;
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);
}


/**
 * 给结构体变量赋值方式三：C99指定初始化器(可乱序赋值)
 */ 
void AssignmentStruct_3()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并使用C99指定初始化器赋值
	struct Student student = {.id=1, .age=18, .name="张三"};
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);
}


/**
 * 给结构体变量赋值方式四：使用指针解引用赋值(指针需要进行初始化且初始化时不能指向NULL)
 */ 
void AssignmentStruct_4()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	struct Student student = {};

	// 定义结构体类型指针变量
	struct Student* pStudent = &student;
	// 使用指针解引用赋值
	(*pStudent).id = 1;
	strcpy((*pStudent).name, "张三");
	(*pStudent).age = 23;

	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", (*pStudent).id, (*pStudent).name, (*pStudent).age);
}


/**
 * 给结构体变量赋值方式五：使用指针配合箭头函数赋值
 */ 
void AssignmentStruct_5()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	struct Student student = {};

	// 定义结构体类型指针变量
	struct Student* pStudent = &student;
	// 使用指针配合箭头函数赋值
	pStudent->id = 1;
	strcpy(pStudent->name, "张三");
	pStudent->age = 23;

	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", (*pStudent).id, (*pStudent).name, (*pStudent).age);
}


/**
 * 访问结构体变量方式一：使用.运算符访问
 */ 
void VisitStruct_1()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并赋值
	struct Student student = { 1,"张三", 18 };
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);
}


/**
 * 访问结构体变量方式二：使用指针解引用访问
 */ 
void VisitStruct_2()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并赋值
	struct Student student = { 1,"张三", 18 };
	struct Student* pStudent = &student;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", (*pStudent).id, (*pStudent).name, (*pStudent).age);
}


/**
 * 访问结构体变量方式三：使用指针配合箭头函数访问
 */ 
void VisitStruct_3()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并赋值
	struct Student student = { 1,"张三", 18 };
	struct Student* pStudent = &student;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", pStudent->id, pStudent->name, pStudent->age);
}


/**
 * 结构体数组
 */ 
void StructArray()
{
	struct Student
	{
		char id;
		char name[20];
		int age;
	};
	struct Student student1 = { 1,"张三", 18 };
	struct Student student2 = { 2,"李四", 23 };
	struct Student student3 = { 3,"王五", 25 };

	// 定义一个结构体数组
	struct Student students[] = { student1, student2, student3 };
	int len = sizeof(students) / sizeof(students[0]);
	for(int i = 0; i < len; i++)
	{
		printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", students[i].id, students[i].name, students[i].age);
	}
}


int main()
{
	// 定义结构体、结构体类型变量、结构体类型指针变量有以下几种方式
	//DefineStruct_2();
	//DefineStruct_3();
	//DefineStruct_4();

	// 给结构体变量赋值有以下几种方式
	//AssignmentStruct_1();
	//AssignmentStruct_2();
	//AssignmentStruct_3();
	//AssignmentStruct_4();
	//AssignmentStruct_5();

	// 访问结构体变量有以下几种方式
	//VisitStruct_1();
	//VisitStruct_2();
	VisitStruct_3();

	// 结构体类型数组
	//StructArray();
	return 0;
}
