#include <stdio.h>

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

int main()
{
	// 使用 . 访问
	struct Student s1 = { "001", "张三", "男", 23, { 2026, 3, 20}};
	printf("id = %s\n", s1.id);
	printf("name = %s\n", s1.name);
	printf("sex = %s\n", s1.sex);
	printf("age = %d\n", s1.age);
	printf("birthday = %d年%d月%d日\n", s1.birthday.year, s1.birthday.month, s1.birthday.day);
	printf("-------------------------------------\n");

	// 使用 -> 访问
	struct Student* sp = &s1;
	printf("id = %s\n", (*sp).id);
	printf("name = %s\n", (*sp).name);
	printf("sex = %s\n", sp->sex);
	printf("age = %d\n", sp->age);
	printf("birthday = %d年%d月%d日\n", sp->birthday.year, sp->birthday.month, sp->birthday.day);
	return 0;
}
