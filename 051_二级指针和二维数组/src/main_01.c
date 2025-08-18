#include <stdio.h>
#include <stdlib.h>

/**
 * 1.二维数组的定义
 * 	 二维数组可以看作是"数组的数组"，它在内存中以行优先的方式存储。
 * 2.二维数组的重要特性
 *   内存布局：二维数组在内存中是连续存储的，按行优先顺序排列
 *   数组名含义：数组名代表第一行的首地址
 *   传递给函数：传递二维数组给函数时，第二维的大小必须指定
 *   索引从0开始：行索引和列索引都从0开始
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
 * 二维数组的定义
 */
void two_dimensional_array_definition_test()
{
    // 方式1：使用一维数组方式进行初始化，系统会自动将一维数组识别成为二维数组
    int arr_1[2][3] = { 1, 2, 3, 4, 5, 6 };
    printf("二维数组arr_1中一维数组个数 = %d，一维数组中元素个数 = %d\n", sizeof(arr_1) / sizeof(arr_1[0]), sizeof(arr_1[0])/sizeof(arr_1[0][0]));

    // 方式2：完全初始化
    int arr_2[2][3] = { {1, 2, 3}, {4, 5, 6} };
    printf("二维数组arr_2中一维数组个数 = %d，一维数组中元素个数 = %d\n", sizeof(arr_2) / sizeof(arr_2[0]), sizeof(arr_2[0])/sizeof(arr_2[0][0]));

    // 方式3：部分初始化（未初始化元素默认为0）
    int arr_3[2][3] = { {1, 2}, {4} };
    printf("二维数组arr_3中一维数组个数 = %d，一维数组中元素个数 = %d\n", sizeof(arr_3) / sizeof(arr_3[0]), sizeof(arr_3[0])/sizeof(arr_3[0][0]));

    // 方式4：省略第一维大小
    int arr_4[][3] = { {1, 2, 3}, {4, 5, 6} };
    printf("二维数组arr_4中一维数组个数 = %d，一维数组中元素个数 = %d\n", sizeof(arr_4) / sizeof(arr_4[0]), sizeof(arr_4[0])/sizeof(arr_4[0][0]));

    // 方式4：逐个赋值
    int arr_5[2][3];
    printf("二维数组arr_5中一维数组个数 = %d，一维数组中元素个数 = %d\n", sizeof(arr_5) / sizeof(arr_5[0]), sizeof(arr_5[0])/sizeof(arr_5[0][0]));
    arr_5[0][0] = 1;
    arr_5[0][1] = 2;
    arr_5[0][2] = 3;
    arr_5[1][0] = 4;
    arr_5[1][1] = 5;
    arr_5[1][2] = 6;
}

/**
 * 遍历二维数组-使用二维数组作为参数（注意：第二维必须指定大小）
 */
void two_dimensional_array_traverse_1(int arr[][4], int rows)
{
    printf("方式1 - 使用二维数组作为参数:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            //printf("%d ", arr[i][j]);
            printf("%d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

/**
 * 遍历二维数组-使用指针作为参数
 */
void two_dimensional_array_traverse_2(int (*arr)[4], int rows)
{
    printf("方式2 - 使用指针作为参数:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

/**
 * 遍历二维数组-指针作为函数参数
 */
void two_dimensional_array_traverse_3(int *arr, int rows, int cols)
{
	printf("方式3 - 使用指针作为参数:\n");
	if(NULL == arr)
	{
		return;
	}
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%d ", *(arr + i * cols + j));
        }
        printf("\n");
    }
}

/**
 * 遍历二维数组
 */
void two_dimensional_array_traverse_test()
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    two_dimensional_array_traverse_1(arr, 3);
    two_dimensional_array_traverse_2(arr, 3);
    two_dimensional_array_traverse_3(*arr, 3, 4);
}

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
 * 二维数组与二级指针的关系
 */
void two_dimensional_array_double_pointer_test()
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // 不同的访问方式
    printf("二维数组元素访问方式:\n");

    // 1. 数组下标方式
    printf("arr[1][2] = %d\n", arr[1][2]);

    // 2. 指针方式
    printf("*(*(arr+1)+2) = %d\n", *(*(arr+1)+2));

    // 3. 混合方式
    printf("*(arr[1]+2) = %d\n", *(arr[1]+2));
    printf("*(*(arr+1)+2) = %d\n", *(*(arr+1)+2));

    printf("二维数组地址演示:\n");
    printf("arr地址: %p\n", arr);           // 数组首地址
    printf("arr[0]地址: %p\n", arr[0]);     // 第一行首地址
    printf("arr[0][0]地址: %p\n", &arr[0][0]); // 第一行第一个元素地址
    printf("&arr[0][0] + 1地址: %p\n", &arr[0][0] + 1); // 第一行第二个元素地址
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


#if 0
#endif
int main()
{
	two_dimensional_array_definition_test();
	//two_dimensional_array_traverse_test();
	//two_dimensional_array_sms_test();
	//two_dimensional_array_add_test();
	//two_dimensional_array_double_pointer_test();
	//double_pointer_simulate_two_dimensional_array_test();
	return 0;
}
