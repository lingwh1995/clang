#include <stdio.h>
#include <stdlib.h>

/**
 * 1.二维数组版学生管理系统
 * 2.二维数组相加
 * 3.二级指针模拟二维数组
 */

// 学生个数
#define STUDENTS 3
// 课程个数
#define SUBJECTS 4

// 行数
#define ROWS 3
// 列数
#define COLS 3


/**
 * 二维数组版学生管理系统测试
 */
void two_dimensional_array_sms_test()
{
    // 存储3个学生4门课程的成绩
    char names[STUDENTS][10] = { "张三", "李四", "王五" };
    float scores[STUDENTS][SUBJECTS] = {
        {85.5, 90.0, 78.5, 92.0},
        {76.0, 88.5, 82.0, 79.5},
        {92.5, 85.0, 90.5, 88.0}
    };

    // 计算每个学生的平均成绩
    printf("学生成绩单:\n");
    printf("姓名\t语文\t数学\t英语\t物理\t平均分\n");
    printf("---------------------------------------------\n");

    for(int i = 0; i < STUDENTS; i++)
    {
        float sum = 0;
        printf("%-10s\t", names[i]);
        for(int j = 0; j < SUBJECTS; j++)
        {
            printf("%.1f\t", scores[i][j]);
            sum += scores[i][j];
        }
        float average = sum / SUBJECTS;
        printf("%.2f\n", average);
    }
}

/**
 * 二维数相加测试
 */
void two_dimensional_array_add_test()
{
    int arr_1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int arr_2[ROWS][COLS] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int arr_result[ROWS][COLS];
    for(int i = 0; i < ROWS; i++)
    {
    	for(int j = 0; j < COLS; j++)
    	{
    		arr_result[i][j] = arr_1[i][j] + arr_2[i][j];
    	}
    }
    printf("二维数组相加结果：\n");
    for(int i = 0; i < ROWS; i++)
    {
    	for(int j = 0; j < COLS; j++)
    	{
    		printf("arr_result[%d][%d] = %d\t", i, j, arr_result[i][j]);
    	}
    	printf("\n");
    }
}

/**
 * 二级指针模拟二维数组
 */
void double_pointer_simulate_two_dimensional_array_test()
{
    // 使用二级指针创建类似二维数组的结构
    int rows = 3, cols = 4;

    // 1. 分配二级指针数组
    int** arr = (int**)malloc(rows * sizeof(int*));
    printf("分配了 %d 个指针的空间\n", rows);

    // 2. 为每一行分配内存
    for(int i = 0; i < rows; i++)
    {
    	arr[i] = (int*)malloc(cols * sizeof(int));
        printf("第 %d 行分配了 %d 个整数的空间\n", i, cols);
    }

    // 3. 初始化数据
    int value = 1;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
        	arr[i][j] = value++;
        }
    }

    // 4. 访问数据
    printf("\n使用二级指针访问数据:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    // 5. 展示内存布局(非连续)
    printf("\n内存地址演示(非连续存储):\n");
    for(int i = 0; i < rows; i++)
    {
        printf("第 %d 行起始地址: %p\n", i, arr[i]);
    }

    // 6. 释放内存
    for(int i = 0; i < rows; i++)
    {
        free(arr[i]);  // 释放每行内存
        printf("释放第 %d 行内存\n", i);
    }
    free(arr);  // 释放指针数组
    printf("释放指针数组内存\n\n");
}

/**
 * 根据
 */
void print_two_dimensional_array_by_one_dimensional_array_test()
{
	int arr[] = { 1, 3, 0, 2 };
	int rows = 4;
	int cols = 4;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			if(arr[i] == j)
			{
				printf("%s\t", "o");
			}
			else
			{
				printf("%s\t", "#");
			}
		}
		printf("\n");
	}
}

#if 0
int main()
{
	//two_dimensional_array_sms_test();
	//two_dimensional_array_add_test();
	//double_pointer_simulate_two_dimensional_array_test();
	print_two_dimensional_array_by_one_dimensional_array_test();
	return 0;
}
#endif
