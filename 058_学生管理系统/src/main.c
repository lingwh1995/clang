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
	printf("please input student id: \n");
	scanf("%d", &student.id);
	printf("please input student name: \n");
	scanf("%s", &student.name);
	printf("please input student gender: \n");
	scanf("%s", &student.gender);
	printf("please input student age: \n");
	scanf("%d", &student.age);
	printf("please input student score: \n");
	for(int i = 0; i < SCORE_SIZE; i++)
	{
		printf("please input score %d: \n", i);
		scanf("%.2f", &student.scores[i]);
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
	Student student = input_student();
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

	for (int i = 0; i < p_student_manager->current_count; i++)
	{
		printf("\n========= 第 %d 个学生 =========\n", i + 1);
		printf("学号：%d\n", p_student_manager->student_list[i].id);
		printf("姓名：%s\n", p_student_manager->student_list[i].name);
		printf("性别：%s\n", p_student_manager->student_list[i].gender);
		printf("年龄：%d\n", p_student_manager->student_list[i].age);

		printf("成绩：");
		for (int j = 0; j < SCORE_SIZE; j++)
		{
			printf("%.2f ", p_student_manager->student_list[i].scores[j]);
		}
		printf("\n总分：%.2f\n", p_student_manager->student_list[i].total_score);
		printf("平均分：%.2f\n", p_student_manager->student_list[i].avg_score);
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
	init_student_manager(&student_manager);
	add_student(&student_manager);
	show_student(&student_manager);
	return 0;
}
