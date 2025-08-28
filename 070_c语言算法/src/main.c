#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/**
 * c语言实现常见算法
 *     1.冒泡排序
 *     2.二分查找（要求数组数有序数组）
 */

/**
 * @param a a元素的地址
 * @param b b元素的地址
 */
void swap_number(int* ap, int* bp)
{
	if(ap == NULL || bp == NULL)
	{
		return;
	}
	int temp = *ap;
	*ap = *bp;
	*bp = temp;
}

/**
 * 冒泡排序算法模型
 *    外层循环控制比较轮数            比较轮数(从0开始) = 数组的长度 - 1
 *    内层循环控制每一轮比较次数       每一轮比较次数 = 数组长度 - 当前比较轮数(从0开始) -1
 */
void bubble_sort_test_1()
{
	int nums[] = { 3, 9, 7, 1, 5 };
	int length = sizeof(nums) / sizeof(nums[0]);
	// 获取比较轮数
	int round = length - 1;
	for(int r = 0; r < round; r++)
	{
        // 获取每一轮比较次数
        int compareTimes = length - r - 1;
        for(int c = 0; c < compareTimes; c++)
        {
            if(nums[c] > nums[c+1])
            {
                swap_number(&nums[c],&nums[c+1]);
            }
        }
	}
    for(int i = 0; i < length; i++)
    {
        printf("%2d ", nums[i]);
    }
}

/**
 * 定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素可以重复，并且使用冒泡排序对数组元素进行排序（基础版）
 */
void bubble_sort_test_2()
{
    int nums[100] = { 0 };
    int length = sizeof(nums) / sizeof(nums[0]);
    srand((unsigned)time(NULL));
    // 生成100个可重复随机数
    for (int i = 0; i < length; i++)
    {
        nums[i] = rand() % length + 1;
    }
    // 冒泡排序
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                swap_number(&nums[j], &nums[j + 1]);
            }
        }
    }
    // 打印数组
    for (int i = 0; i < length; i++)
    {
        printf("%3d ", nums[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
}

/**
 * 定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素可以重复，并且使用冒泡排序对数组元素进行排序（优化版）
 */
void bubble_sort_test_3()
{
    int nums[100] = { 0 };
    int length = sizeof(nums) / sizeof(nums[0]);
    // 生成100个可重复随机数
    srand((unsigned)time(NULL));
    for (int i = 0; i < length; i++)
    {
        nums[i] = rand() % length + 1;
    }
    // 冒泡排序
    for (int i = 0; i < length - 1; i++)
    {
    	// 本轮循环是否没有进行元素交换，如果没有进行元素交换，说明当前数组是有序数组
    	bool isNotExchange = true;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
            	isNotExchange = false;
                swap_number(&nums[j], &nums[j + 1]);
            }
        }
        if (isNotExchange)
        {
            break;
        }
    }
    // 打印数组
    for (int i = 0; i < length; i++)
    {
        printf("%3d ", nums[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
}

/**
 * @param nums 数组nums的地址
 * @param k 查找重复元素结束索引
 * @param value 需要判断是否重复的元素
 */
int find_value(int* nums, int k, int value)
{
	int position = -1;
	for(int i = 0; i < k; i++)
	{
		if(nums[i] == value)
		{
			position = i;
		}
	}
	return position;
}

/**
 * 定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（for循环版）
 */
void bubble_sort_test_4()
{
	int nums[100] = { 0 };
	int length = sizeof(nums) / sizeof(nums[0]);
	// 生成100个不重复随机数
	srand((unsigned)time(NULL));
	for(int i = 0; i < length; i++)
	{
		int r = rand() % length + 1;
		if(find_value(nums,i,r) == -1)
		{
			nums[i] = r;
		}
		else
		{
			// 如果find_value()返回值不为-1,则说明数组中已经有一个元素的值和r相等,则让i--,这是很巧妙的处理方法
			i--;
		}
	}
	// 冒泡排序
	for(int i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i - 1; j++)
		{
			if(nums[j] > nums[j+1])
			{
				swap_number(&nums[j], &nums[j+1]);
			}
		}
	}
	// 打印数组
	for (int i = 0; i < length; i++)
    {
        printf("%3d ", nums[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
}

/**
 * 定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（while循环版）
 */
void bubble_sort_test_5()
{
	int nums[100] = { 0 };
	int length = sizeof(nums) / sizeof(nums[0]);
	// 生成100个不重复随机数
	srand((unsigned)time(NULL));
	int i = 0;
	while(i < length)
	{
		int r = rand() % length + 1;
		if(find_value(nums,i,r) == -1)
		{
			nums[i] = r;
			i++;
		}
	}

	// 冒泡排序
	for(i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i - 1; j++)
		{
			if(nums[j] > nums[j+1])
			{
				swap_number(&nums[j], &nums[j+1]);
			}
		}
	}
	// 打印数组
	for (i = 0; i < length; i++)
    {
        printf("%3d ", nums[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
}

/**
 * 定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（查表版 方式一）
 */
void bubble_sort_test_6()
{
	int nums[100] = { 0 };
	int length = sizeof(nums) / sizeof(nums[0]);
	// 创建表
	int table[101] = { 0 };

	// 生成100个不重复随机数
	srand((unsigned)time(NULL));
	int i = 0;
	while(i < length)
	{
		int r = rand() % length + 1;
		if(table[r] == 0)
		{
			nums[i] = r;
			i++;
			table[r] = 1;
		}
	}

	// 冒泡排序
	for(i = 0; i < length - 1; i++)
	{
		for(int j = 0; j < length - i - 1; j++)
		{
			if(nums[j] > nums[j+1])
			{
				swap_number(&nums[j], &nums[j+1]);
			}
		}
	}
	// 打印数组
	for (i = 0; i < length; i++)
    {
        printf("%3d ", nums[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
}

/**
 * 定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（查表版 方式二）
 */
void bubble_sort_test_7()
{
	int nums[100] = { 0 };
	int length = sizeof(nums) / sizeof(nums[0]);
	// 创建表
	int table[101] = { 0 };

	// 生成100个不重复随机数
	srand((unsigned)time(NULL));
	int i = 0;
	while(i < length)
	{
		int r = rand() % length + 1;
		if(table[r] == 0)
		{
			i++;
			table[r] = r;
		}
	}

	// 不需要排序，因为按照上面的操作流程，table数组中存放的数据天然是有序的

	// 复制数组
	for(i = 0; i < length; i++)
	{
		nums[i] = table[i+1];
	}

	// 打印数组
	for (int i = 0; i < length; i++)
    {
        printf("%3d ", nums[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
}

/**
 * 二分查找法：在数组中查询输入值的索引位置，如果没有查询到返回-1
 */
int binary_search_find_value(const int* arr, int n, int val)
{
	if(NULL == arr || n < 1)
	{
		return -1;
	}
	int position = -1;
	int left = 0, right = n - 1;
	while(left <= right)
	{
		// 注意： 这里的mid定义成局部变量就可以
		int mid = (left + right) / 2;
		printf("left = %d, right = %d, mid = %d\n", left, right, mid);
		if(arr[mid] > val)
		{
			right = mid - 1;
		}
		else if(arr[mid] < val)
		{
			left = mid + 1;
		}else {
			position = mid;
			break;
		}

	}
	return position;
}

/**
 * 测试二分查找 => 查找108在数组中的位置
 *
 *  0    1    2    3    4    5    6    7    8    9    10   11
 *
 * 第一轮： left = 0, right = 11, mid = (left + right) / 2 = (0 + 11) / 2 = 5
 * 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112
 *  ↑						 ▲				  		       ↑
 *
 * 第二轮： left = mid + 1 = 5 + 1 = 6, right = 11, mid = (left + right) / 2 = (6 + 11) / 2 = 8
 * 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112
 *  						      ↑			▲  		       ↑
 *
 * 第三轮： left = 6, right = mid - 1 = 8 - 1 = 7, mid = (left + right) / 2 = (6 + 7) / 2 = 6
 * 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112
 *  						     ↑ ▲   ↑
 *
 * 第四轮： left = mid + 1 = 6 + 1 = 7, right  7, mid = (left + right) / 2 = (7 + 7) / 2 = 7
 * 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112
 *  						          ↑▲↑
 *
 */
void binary_search_find_value_test()
{
//	int arr[] = { 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112 };
//	int val = 108;
	int arr[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100, 110, 120 };
	int val = 95;
	int n = sizeof(arr) / sizeof(arr[0]);
	int i = binary_search_find_value(arr, n, val);
	printf("%d在数组中的索引位置i = %d\n", val, i);
}

int main()
{
	//bubble_sort_test_1();
	//bubble_sort_test_2();
	//bubble_sort_test_3();
	//bubble_sort_test_4();
	//bubble_sort_test_5();
	//bubble_sort_test_6();
	//bubble_sort_test_7();
	binary_search_find_value_test();
	return 0;
}
