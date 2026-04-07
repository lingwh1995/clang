#include <stdio.h>

#define STUSIZE 100
#define SCSIZE 3

struct student_s
{
	int id;
	char name[10];
	char sex[4];
	int age;
	float score[SCSIZE];
	float sum;
	float ave;
};

struct student_s data[STUSIZE];

int main()
{

	return 0;
}
