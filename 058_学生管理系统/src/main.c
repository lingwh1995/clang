#include <stdio.h>
#include <stdbool.h>

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
} student_t;


typedef struct
{
	// 学生数量
	int cur_size;
	// 容量
	int max_size;
	student_t students[STUDENT_SIZE];
} student_man_t, *p_student_man_t;


void init_student_man(student_man_t *p_student_man)
{
	assert(p_student_man != NULL);
	p_student_man->cur_size = 0;
	p_student_man->max_size = STUDENT_SIZE;
	memset(p_student_man->students, 0, sizeof(student_man_t) * p_student_man->max_size);
}

int get_student_size(const student_man_t  *p_student_man)
{
	assert(p_student_man != NULL);
	return p_student_man->cur_size;
}

bool is_full(const student_man_t  *p_student_man)
{
	assert(p_student_man != NULL);
	return get_student_size(p_student_man) == p_student_man->max_size;
}

bool is_empty(const student_man_t  *p_student_man)
{
	assert(p_student_man != NULL);
	return get_student_size(p_student_man) == 0;
}

student_t input_student()
{
	student_t input_student;
	printf("please input student id: \n");
	scanf("%d", &input_student.id);
	printf("please input student name: \n");
	scanf("%s", &input_student.name);
	printf("please input student sex: \n");
	scanf("%s", &input_student.sex);
	printf("please input student age: \n");
	scanf("%d", &input_student.age);
	printf("please input student score: \n");
	for(int i = 0; i < SCORE_SIZE; i++)
	{
		printf("please input score %d: \n", i);
		scanf("%.2f", &input_student.score);
		input_student.sum += input_student.sum + input_student.score[i];
	}
	input_student.avg = input_student.sum / SCORE_SIZE;
	return input_student;
}

bool add_student(const student_man_t  *p_student_man)
{
	assert(p_student_man != NULL);
	if(is_full(p_student_man))
	{
		return false;
	}
	student_t input_student = input_student();
	p_student_man->students[p_student_man->cur_size] = input_student;
	p_student_man->cur_size += 1;
	return false;
}

void show_student(const student_man_t  *p_student_man)
{
	assert(p_student_man != NULL);
	for(int i = 0; i < p_student_man->cur_size; i++)
	{
		printf("%d", p_student_man->students[i].id);
		printf("%s", p_student_man->students[i].name);
		printf("%s", p_student_man->students[i].sex);
		printf("%d", p_student_man->students[i].age);
		for(int j = 0; j < SCORE_SIZE; j++)
		{
			printf("%.2f", p_student_man->students[i].score[j]);
		}
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
	student_man_t student_man;
	init_student_man(&student_man);
	show_student(&student_man);
	return 0;
}
