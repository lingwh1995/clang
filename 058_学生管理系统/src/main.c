#include <stdio.h>

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
	float ave;
} student_t;

student_t students[STUDENT_SIZE];

int main()
{

	return 0;
}
