#include <stdio.h>
#include <string.h>

/*
 * 结构体专题
 *
 * 1. 结构体是属性的集合
 * 2. 结构体定义时最后必须加分号，否则会报错
 * 3. 定义在main()之外的结构体称为全局结构体，定义在main()里面的结构体称为局部结构体
 * 4. typedef 定义的结构体类型首字母大写为 C 语言标准命名规范，用于与变量命名区分，直观标识该名称为自定义类型而非一个变量
 * 5. 定义结构体、结构体类型变量、结构体类型指针变量有以下几种方式
 * 		方式一：先定义结构体，再定义 结构体变量 和 结构体类型指针变量
 *			// 定义结构体(这个 Student 是结构体标签，不是别名)
 *			struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			};
 *
 *			// 定义 结构体类型变量
 *			struct Student student;
 *			// 定义 结构体类型指针变量
 *			struct Student *p_student;
 *
 *		方式二：定义结构体的同时定义 结构体变量 和 结构体类型指针变量
 *			// 匿名结构体(省略了标签名)
 *			struct
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			} student, *p_student;
 *
 *			// 带标签结构体(没有省略标签名) => 更推荐
 *			struct Student  // 标签名(可省略)
 *			{
 *				int id;
 *	 			char name[20];
 *				int age;
 *			} student, *p_student;
 *
 *		方式三：使用typedef关键字定义结构体，定义 结构体变量 和 结构体类型指针变量 时可以使用简化的方式声明
 * 			// 同时定义 结构体类型 和 结构体指针类型 (typedef + 匿名结构体) => 更推荐
 *			typedef struct
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			} Student, *PStudent;
 *
 *			// 同时定义 结构体类型 和 结构体指针类型 (typedef + 带标签结构体) => 不推荐，只有结构体自引用(如：链表)才加标签
 *			typedef struct Student
 *			{
 *				int id;
 *				char name[20];
 *				int age;
 *			} Student, *PStudent; ;
 *
 *			// 定义结构体类型变量
 *			Student student;
 *			// 定义结构体类型指针变量
 *			PStudent p_student;
 *
 * 5. 给结构体变量赋值有以下几种方式
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
 *			struct Student student = { 1, "张三", 18 };
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
 *			// 给字符串类型成员变量赋值
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
 *			struct Student *p_student = &student;
 *			// 使用指针解引用赋值
 *			(*p_student).id = 1;
 *			// 给字符串类型成员变量赋值
 *			strcpy((*p_student).name, "张三");
 *			(*p_student).age = 23;
 *
 *		方式五：使用指针配合箭头函数(成员选择符)赋值
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
 *			struct Student *p_student = &student;
 *			// 使用指针配合箭头函数(成员选择符)赋值
 *			p_student->id = 1;
 *			// 给字符串类型成员变量赋值
 *			strcpy(p_student->name, "张三");
 *			p_student->age = 23;
 *
 * 6. 访问结构体变量有以下几种方式
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
 *			struct Student *p_student = &student;
 *			printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", (*p_student).id, (*p_student).name, (*p_student).age);
 *
 *		方式三：使用指针配合箭头函数(成员选择符)访问
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
 *			struct Student *p_student = &student;
 *			printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", p_student->id, p_student->name, p_student->age);
 * 7. 结构体名和结构体类型名
 *    结构体名		Student
 *    结构体类型名	struct Student
 */

/**
 * 定义结构体、结构体类型变量(或结构体类型指针变量)方式一：先定义结构体，再定义结构体类型变量(或结构体类型指针变量)
 */ 
void define_struct_1()
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
	struct Student *p_student;

	student.id = 1;
	// 给字符串类型成员变量赋值
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);

	p_student = &student;
	p_student->id = 2;
	// 给字符串类型成员变量赋值
	strcpy(p_student->name, "李四");
	p_student->age = 23;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", p_student->id, p_student->name, p_student->age);
	printf("-------------------------------------\n");
}


/**
 * 定义结构体、结构体类型变量(或结构体类型指针变量)方式二：定义结构体的同时定义结构体类型变量(或结构体类型指针变量)
 */ 
void define_struct_2()
{
	// 定义结构体的同时定义结构体类型变量(或结构体类型指针变量)
	struct Student
	{
		int id;
		char name[20];
		int age;
	} student, *p_student;

	student.id = 1;
	// 给字符串类型成员变量赋值
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);

	p_student = &student;
	p_student->id = 2;
	// 给字符串类型成员变量赋值
	strcpy(p_student->name, "李四");
	p_student->age = 23;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", p_student->id, p_student->name, p_student->age);
	printf("-------------------------------------\n");
}


/**
 * 定义结构体、结构体类型变量(或结构体类型指针变量)方式三：使用typedef关键字定义结构体，定义结构体类型变量(或结构体类型指针变量)时可以使用简化的方式声明
 */ 
void define_struct_3()
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
	Student *p_student;

	student.id = 1;
	// 给字符串类型成员变量赋值
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);

	p_student = &student;
	p_student->id = 2;
	// 给字符串类型成员变量赋值
	strcpy(p_student->name, "李四");
	p_student->age = 23;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", p_student->id, p_student->name, p_student->age);
	printf("-------------------------------------\n");
}


/**
 * 定义结构体、结构体类型变量(或结构体类型指针变量)方式四：定义匿名结构体类型变量(或结构体类型指针变量)(适用于临时使用结构体的情况)
 */ 
void define_struct_4()
{
	// 定义匿名结构体类型变量(或结构体类型指针变量)
	struct
	{
		int id;
		char name[20];
		int age;
	} student, *p_student;

	student.id = 1;
	// 给字符串类型成员变量赋值
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);

	p_student = &student;
	p_student->id = 2;
	// 给字符串类型成员变量赋值
	strcpy(p_student->name, "李四");
	p_student->age = 23;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", p_student->id, p_student->name, p_student->age);
	printf("-------------------------------------\n");
}


/**
 * 给结构体变量赋值方式一：直接赋值(使用.运算符赋值)
 */ 
void assignment_struct_1()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并赋值
	struct Student student = { 1, "张三", 18 };
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);
	printf("-------------------------------------\n");
}


/**
 * 给结构体变量赋值方式二：先定义结构体类型变量，后赋值(使用.运算符赋值)
 */ 
void assignment_struct_2()
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
	// 给字符串类型成员变量赋值
	strcpy(student.name, "张三");
	student.age = 18;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);
	printf("-------------------------------------\n");
}


/**
 * 给结构体变量赋值方式三：C99指定初始化器(可乱序赋值)
 */ 
void assignment_struct_3()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并使用C99指定初始化器赋值
	struct Student student = { .id=1, .age=18, .name="张三" };
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);
	printf("-------------------------------------\n");
}


/**
 * 给结构体变量赋值方式四：使用指针解引用赋值(指针需要进行初始化且初始化时不能指向NULL)
 */ 
void assignment_struct_4()
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
	struct Student *p_student = &student;
	// 使用指针解引用赋值
	(*p_student).id = 1;
	// 给字符串类型成员变量赋值
	strcpy((*p_student).name, "张三");
	(*p_student).age = 23;

	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", (*p_student).id, (*p_student).name, (*p_student).age);
	printf("-------------------------------------\n");
}


/**
 * 给结构体变量赋值方式五：使用指针配合箭头函数(成员选择符)赋值
 */ 
void assignment_struct_5()
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
	struct Student *p_student = &student;
	// 使用指针配合箭头函数(成员选择符)赋值
	p_student->id = 1;
	// 给字符串类型成员变量赋值
	strcpy(p_student->name, "张三");
	p_student->age = 23;

	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", (*p_student).id, (*p_student).name, (*p_student).age);
	printf("-------------------------------------\n");
}


/**
 * 访问结构体变量方式一：使用.运算符访问
 */ 
void visit_struct_1()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并赋值
	struct Student student = { 1, "张三", 18 };
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", student.id, student.name, student.age);
	printf("-------------------------------------\n");
}


/**
 * 访问结构体变量方式二：使用指针解引用访问
 */ 
void visit_struct_2()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并赋值
	struct Student student = { 1, "张三", 18 };
	struct Student *p_student = &student;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", (*p_student).id, (*p_student).name, (*p_student).age);
	printf("-------------------------------------\n");
}


/**
 * 访问结构体变量方式三：使用指针配合箭头函数(成员选择符)访问
 */ 
void visit_struct_3()
{
	// 定义结构体
	struct Student
	{
		int id;
		char name[20];
		int age;
	};

	// 定义结构体类型变量并赋值
	struct Student student = { 1, "张三", 18 };
	struct Student *p_student = &student;
	printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", p_student->id, p_student->name, p_student->age);
	printf("-------------------------------------\n");
}


/**
 * 结构体数组
 */ 
void struct_array()
{
	struct Student
	{
		char id;
		char name[20];
		int age;
	};
	struct Student student1 = { 1, "张三", 18 };
	struct Student student2 = { 2, "李四", 23 };
	struct Student student3 = { 3, "王五", 25 };

	// 定义一个结构体数组
	struct Student students[] = { student1, student2, student3 };
	int len = sizeof(students) / sizeof(students[0]);
	for(int i = 0; i < len; i++)
	{
		printf("学号 = %d, 姓名 = %s, 年龄 = %d\n", students[i].id, students[i].name, students[i].age);
	}
	printf("-------------------------------------\n");
}

/**
 * 内存对齐
 */
void memory_alignment()
{
	/**
	 * 结构体名		Student
	 * 结构体类型名	struct Student
	 * 特别注意		最后的分号必须写，否则会报错
	 */
	struct Student
	{
		char id[20];	// 20字节
		char name[20];	// 20字节
		char sex[10];	// 10字节
		int age;		// 4字节
	};

	struct Student student = { "001", "张三", "男", 20 };
	printf("id = %s, name = %s, sex = %s, age = %d\n", student.id, student.name, student.sex, student.age);

	/**
	 * 为什么 sizeof(student) = 56 而不是 54 ?
	 *
	 * 核心原因：内存对齐（结构体补齐）
	 * 计算出来的 20+20+10+4 = 54 是纯数据大小，但 C 语言会自动做内存对齐：
	 *
	 * 	  int 类型要求起始地址是 4 的倍数
	 *    前三个成员总大小：20+20+10 = 50
	 *    50 不是 4 的倍数，编译器自动补齐 2 个空字节 → 变成 52
	 *    再加上 age 的 4 字节 → 56 字节
	 *
	 */
	printf("sizeof(student) = %d\n", sizeof(student));
	printf("-------------------------------------\n");
}

/**
 * 结构体成员初始值
 */
void struct_member_init_val()
{
	/**
	 * 结构体名		Student
	 * 结构体类型名	struct Student
	 * 特别注意		最后的分号必须写，否则会报错
	 */
	struct Student
	{
		char id[20];	// 20字节
		char name[20];	// 20字节
		char sex[10];	// 10字节
		int age;		// 4字节
	};

	struct Student s1 = { "001", "张三", "男", 20 };
	printf("s1 => id = %s, name = %s, sex = %s, age = %d\n", s1.id, s1.name, s1.sex, s1.age);

	// 如果不赋初始值，打印时会打印出随机值
	struct Student s2;
	printf("s2 => id = %s, name = %s, sex = %s, age = %d\n", s2.id, s2.name, s2.sex, s2.age);
	// 把s1的值赋给s2
	s2 = s1;
	printf("s2 => id = %s, name = %s, sex = %s, age = %d\n", s2.id, s2.name, s2.sex, s2.age);
	printf("-------------------------------------\n");
}

int main()
{
	// 定义结构体、结构体类型变量、结构体类型指针变量有以下几种方式
	define_struct_2();
	define_struct_3();
	define_struct_4();

	// 给结构体变量赋值有以下几种方式
	assignment_struct_1();
	assignment_struct_2();
	assignment_struct_3();
	assignment_struct_4();
	assignment_struct_5();

	// 访问结构体变量有以下几种方式
	visit_struct_1();
	visit_struct_2();
	visit_struct_3();

	// 结构体类型数组
	struct_array();
	// 内存补齐
	memory_alignment();
	// 结构体成员初始值
	struct_member_init_val();
	return 0;
}
