#include "../inc/stdaef.h"
#include "../inc/student_manager.h"

int main()
{
	StudentManager student_manager;
	init_student_manager(&student_manager);
    load_student_from_file(&student_manager);
	int select = 0;
	do
	{
		printf("**********\n");
		printf("1. 增加学生\n");
		printf("2. 展示学生\n");
		printf("3. 查询学生\n");
		printf("4. 删除学生\n");
		printf("5. 修改学生\n");
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
				find_student(&student_manager);
				break;
			case 4:
				delete_student(&student_manager);
				break;
			case 5:
				modify_student(&student_manager);
				break;
			default:
				printf("不支持该选项！");
				break;
		}
	} while (select != 0);
    write_student_to_file(&student_manager);
	return 0;
}
