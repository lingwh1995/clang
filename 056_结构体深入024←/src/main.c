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
	struct Student s1 = { "001", "张三", "男", 23, { 2026, 3, 20}};
	printf("id = %s, name = %s, sex = %s, age = %d, birthday = %d年%d月%d日",
			s1.id, s1.name, s1.sex, s1.age, s1.birthday.year, s1.birthday.month, s1.birthday.day);
	return 0;
}
