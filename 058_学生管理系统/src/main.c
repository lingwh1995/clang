#include <stdio.h>

#define STUSIZE 100
#define SCSIZE 3

typedef struct
{
	int id;
	char name[10];
	char sex[4];
	int age;
	float score[SCSIZE];
	float sum;
	float ave;
} student_t;

student_t students[STUSIZE];

int main()
{

	return 0;
}
