#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define STUDENT_SIZE 100
#define SCORE_SIZE 3

typedef struct
{
	int id;
	char name[10];
	char sex[4];
	int age;
	float score[SCORE_SIZE];
	float sum;
	float avg;
} Student;


typedef struct
{
	// 学生数量
	int cur_size;
	// 容量
	int max_size;
	Student students[STUDENT_SIZE];
} StudentManager, *PStudentManager;


void init_student_man(StudentManager *p_student_manager)
{
	assert(p_student_manager != NULL);
	p_student_manager->cur_size = 0;
	p_student_manager->max_size = STUDENT_SIZE;
	memset(p_student_manager->students, 0, sizeof(Student) * p_student_manager->max_size);
}

int get_student_size(const StudentManager  *p_student_manager)
{
	assert(p_student_manager != NULL);
	return p_student_manager->cur_size;
}

bool is_full(const StudentManager  *p_student_manager)
{
	assert(p_student_manager != NULL);
	return get_student_size(p_student_manager) == p_student_manager->max_size;
}

bool is_empty(const StudentManager  *p_student_manager)
{
	assert(p_student_manager != NULL);
	return get_student_size(p_student_manager) == 0;
}

Student input_student()
{
	Student student;
	// 清空脏数据
	memset(&student, 0, sizeof(student));
	printf("please input student id: \n");
	scanf("%d", &student.id);
	printf("please input student name: \n");
	scanf("%s", &student.name);
	printf("please input student sex: \n");
	scanf("%s", &student.sex);
	printf("please input student age: \n");
	scanf("%d", &student.age);
	printf("please input student score: \n");
	for(int i = 0; i < SCORE_SIZE; i++)
	{
		printf("please input score %d: \n", i);
		scanf("%.2f", &student.score[i]);
		student.sum += student.score[i];
	}
	student.avg = student.sum / SCORE_SIZE;
	return student;
}

bool add_student(StudentManager  *p_student_manager)
{
	assert(p_student_manager != NULL);
	if(is_full(p_student_manager))
	{
		return false;
	}
	Student student = input_student();
	p_student_manager->students[p_student_manager->cur_size] = student;
	p_student_manager->cur_size += 1;
	return true;
}
/*
void show_student(const StudentManager  *p_student_manager)
{
	assert(p_student_man != NULL);
	for(int i = 0; i < p_student_manager->cur_size; i++)
	{
		printf("%d", p_student_manager->students[i].id);
		printf("%s", p_student_manager->students[i].name);
		printf("%s", p_student_manager->students[i].sex);
		printf("%d", p_student_manager->students[i].age);
		for(int j = 0; j < SCORE_SIZE; j++)
		{
			printf("%.2f", p_student_manager->students[i].score[j]);
		}
	}
}*/
void show_student(const StudentManager *p_student_manager)
{
	assert(p_student_manager != NULL);
	if (is_empty(p_student_manager))
	{
		printf("暂无学生信息！\n");
		return;
	}

	for (int i = 0; i < p_student_manager->cur_size; i++)
	{
		printf("\n========= 第 %d 个学生 =========\n", i + 1);
		printf("学号：%d\n", p_student_manager->students[i].id);
		printf("姓名：%s\n", p_student_manager->students[i].name);
		printf("性别：%s\n", p_student_manager->students[i].sex);
		printf("年龄：%d\n", p_student_manager->students[i].age);

		printf("成绩：");
		for (int j = 0; j < SCORE_SIZE; j++)
		{
			printf("%.2f ", p_student_manager->students[i].score[j]);
		}
		printf("\n总分：%.2f\n", p_student_manager->students[i].sum);
		printf("平均分：%.2f\n", p_student_manager->students[i].avg);
	}
}

//init_student_man;
//add_student;
//show_student;
//save_student;
//load_student;
//find_student_by_id;
//find_student_by_name;
//find_student;
//del_student;

int main()
{
	StudentManager student_manager;
	init_student_man(&student_manager);
	show_student(&student_manager);
	return 0;
}
