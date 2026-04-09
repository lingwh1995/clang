#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SCORE_SIZE 3	 // 科目数量
#define MAX_STUDENT 100  // 最大学生数

typedef struct
{
	int id;
	char name[10];
	char gender[4];
	int age;
	float scores[SCORE_SIZE];
	float total_score;
	float avg_score;
} Student;

typedef struct
{
	// 前学生数量
	int current_count;
	// 容量
	int max_capacity;
	Student student_list[MAX_STUDENT];
} StudentManager, *PStudentManager;

void init_student_manager(StudentManager *p_student_manager)
{
	assert(p_student_manager != NULL);
	p_student_manager->current_count = 0;
	p_student_manager->max_capacity = MAX_STUDENT;
	memset(p_student_manager->student_list, 0, sizeof(Student) * p_student_manager->max_capacity);
}

int get_student_size(const StudentManager  *p_student_manager)
{
	assert(p_student_manager != NULL);
	return p_student_manager->current_count;
}

bool is_full(const StudentManager  *p_student_manager)
{
	assert(p_student_manager != NULL);
	return get_student_size(p_student_manager) == p_student_manager->max_capacity;
}

bool is_empty(const StudentManager  *p_student_manager)
{
	assert(p_student_manager != NULL);
	return get_student_size(p_student_manager) == 0;
}

Student input_student()
{
	Student student = { 0 };
	printf("请输入学生编号: \n");
	scanf("%d", &student.id);
	printf("请输入学生姓名: \n");
	scanf("%s", student.name);
	printf("请输入学生性别: \n");
	scanf("%s", student.gender);
	printf("请输入学生年龄: \n");
	scanf("%d", &student.age);
	printf("请输入学生分数: \n");
	for(int i = 0; i < SCORE_SIZE; i++)
	{
		printf("请输入科目 %d 的分数: \n", i+1);
		scanf("%f", &student.scores[i]);
		student.total_score += student.scores[i];
	}
	student.avg_score = student.total_score / SCORE_SIZE;
	return student;
}

bool add_student(StudentManager  *p_student_manager)
{
	assert(p_student_manager != NULL);
	if(is_full(p_student_manager))
	{
		return false;
	}
	const Student student = input_student();
	p_student_manager->student_list[p_student_manager->current_count] = student;
	p_student_manager->current_count += 1;
	return true;
}

void show_student(const StudentManager *p_student_manager)
{
	assert(p_student_manager != NULL);
	if (is_empty(p_student_manager))
	{
		printf("暂无学生信息！\n");
		return;
	}

	printf("学号   姓名   性别   年龄   语文   数学   英语   总分   平均分\n");
	for (int i = 0; i < p_student_manager->current_count; i++)
	{
		printf("%-8d %-8s %-8s %-8d", p_student_manager->student_list[i].id, p_student_manager->student_list[i].name,
			p_student_manager->student_list[i].gender, p_student_manager->student_list[i].age);
		for (int j = 0; j < SCORE_SIZE; j++)
		{
			printf("%-8.2f", p_student_manager->student_list[i].scores[j]);
		}
		printf("%8.2f", p_student_manager->student_list[i].total_score);
		printf("%8.2f", p_student_manager->student_list[i].avg_score);
	}
	printf("\n");
}

void save_student(const StudentManager *p_student_manager)
{
	assert(p_student_manager != NULL);
	// 二进制写文件
	FILE* p_file = fopen("student.txt", "wb");
	if (NULL == p_file)
	{
		printf("open file error\n");
		return;
	}
	// 把数组中的元素个数写进去
	fwrite(&p_student_manager->current_count, sizeof(int), 1, p_file);
	// 把数组写入
	fwrite(p_student_manager->student_list, sizeof(Student), p_student_manager->current_count, p_file);
	fclose(p_file);
	p_file = NULL;
}

void load_student(StudentManager *p_student_manager)
{
	assert(p_student_manager != NULL);
	// 二进制读文件
	FILE* p_file = fopen("student.txt", "rb");
	if (NULL == p_file)
	{
		printf("open file error\n");
		return;
	}
	fread(&p_student_manager->current_count, sizeof(int), 1, p_file);
	fread(p_student_manager->student_list, sizeof(Student), p_student_manager->current_count, p_file);
	fclose(p_file);
	p_file = NULL;
}

int find_id(const StudentManager *p_student_manager, int id)
{
	assert(p_student_manager != NULL);
	int pos = -1;
	for (int i = 0; i < p_student_manager->current_count; i++)
	{
		if (p_student_manager->student_list[i].id == id)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

int find_name(const StudentManager *p_student_manager, char *name)
{
	assert(p_student_manager != NULL);
	int pos = -1;
	for (int i = 0; i < p_student_manager->current_count; i++)
	{
		if (strcmp(p_student_manager->student_list[i].name, name) == 0)
		{
			pos = i;
			break;
		}
	}
	return pos;
}

int find_student(const StudentManager *p_student_manager)
{
	assert(p_student_manager != NULL);
	int id;
	char name[10];
	int select = 0;
	int pos = -1;
	do
	{
		printf("**********\n");
		printf("1. 按学号查询\n");
		printf("2. 按姓名查询\n");
		printf("0. 退出查询\n");
		printf("请选择功能: \n");
		printf("**********\n");
		scanf("%d", &select);
		switch (select)
		{
			case 0:
				printf("退出查询\n");
				break;
			case 1:
				scanf("%d", &id);
				if ((pos = find_id(p_student_manager, id)) != -1)
				{
					show_student(p_student_manager);
				}
				else
				{
					printf("无该学生信息！");
				}
				break;
			case 2:
				scanf("%d", &name);
				if ((pos = find_name(p_student_manager, name)) != -1)
				{
					show_student(p_student_manager);
				}
				else
				{
					printf("无该学生信息！");
				}
				break;
		}
	} while (select != 0);
}

int main()
{
	StudentManager student_manager;
	init_student_manager(&student_manager);
	load_student(&student_manager);
	int select = 0;
	do
	{
		printf("**********\n");
		printf("1. 增加学生\n");
		printf("2. 展示学生\n");
		printf("3. 查询学生\n");
		printf("0. 退出系统\n");
		printf("请选择功能: \n");
		printf("**********\n");
		scanf("%d", &select);
		switch (select)
		{
			case 0:
				printf("退出管理系统\n");
				break;
			case 1:
				add_student(&student_manager);
				break;
			case 2:
				show_student(&student_manager);
				break;
			case 3:
				show_student(&student_manager);
				break;
			default:
				printf("不支持该选项！");
				break;
		}
	} while (select != 0);
	add_student(&student_manager);
	show_student(&student_manager);
	save_student(&student_manager);
	return 0;
}
