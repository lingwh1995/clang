#include <stdio.h>
#include <stdlib.h>

/**
 * 1.二维数组的定义
 * 2.二维数组的遍历
 * 3.二维数组学生管理系统
 * 4.二维数组与指针
 */
#define STUDENTS 3
#define SUBJECTS 4

/**
 * 二维数组的定义
 */
void two_dimensional_array_definition_test()
{
    // 方式1：完全初始化
    int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // 方式2：部分初始化（未初始化元素默认为0）
    int arr2[2][3] = {{1, 2}, {4}};

    // 方式3：省略第一维大小
    int arr3[][3] = {{1, 2, 3}, {4, 5, 6}};

    // 方式4：逐个赋值
    int arr4[2][3];
    arr4[0][0] = 1;
    arr4[0][1] = 2;
    arr4[0][2] = 3;
    arr4[1][0] = 4;
    arr4[1][1] = 5;
    arr4[1][2] = 6;
}

/**
 * 二维数组遍历测试
 */
void two_dimensional_array_traverse_test()
{
	// 声明并初始化一个4*2的二维数组，代表该二维数组一共有4个一维数组，每个一维数组中有两个元素
	int arr[4][2] = {
			{ 1, 2 },
			{ 3, 4 },
			{ 5, 6 },
			{ 7, 8 }
	};

	// 通过观察内存地址可以发现，二维数组中每个一维数组中的每个元素在内存存储在连续的空间，二维数组中每个一维数组在内存中也是存储连续的空间
	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for(int j = 0; j < sizeof(arr[i]) / sizeof(arr[i][0]); j++) {
			printf("arr[%d][%d] = %d, &arr[%d][%d] = %p\n", i, j, arr[i][j], i, j, &arr[i][j]);
		}
		printf("\n");
	}
}


/**
 * 二维数版学生管理系统测试
 */
void two_dimensional_array_sms_test()
{
    // 存储3个学生4门课程的成绩
    char names[STUDENTS][20] = { "张三", "李四", "王五" };
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
 * 二级指针模拟二维数组
 */
void two_dimensional_array_double_pointer_test()
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
 * 二维数组与指针测试
 */
void two_dimensional_array_and_pointer_test()
{
	// 声明并初始化一个4*2的二维数组，代表该二维数组一共有4个一维数组，每个一维数组中有两个元素
	int arr[4][2] = {
			{ 1, 2 },
			{ 3, 4 },
			{ 5, 6 },
			{ 7, 8 }
	};

	int** arr_p = arr;
	// 通过观察内存地址可以发现，二维数组中每个一维数组中的每个元素在内存存储在连续的空间，二维数组中每个一维数组在内存中也是存储连续的空间
	for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		for(int j = 0; j < sizeof(arr[i]) / sizeof(arr[i][0]); j++) {
			printf("arr[%d][%d] = %d, &arr[%d][%d] = %p\n", i, j, arr[i][j], i, j, &arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	//two_dimensional_array_definition_test();
	//two_dimensional_array_traverse_test();
	//two_dimensional_array_sms_test();
	//two_dimensional_array_and_pointer_test();
	two_dimensional_array_double_pointer_test();
	return 0;
}
