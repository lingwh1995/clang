# include <stdio.h>

/*
 * 当使用数组作为函数的形参时，数组名退化成指针
 */

/**
 * 形参的数据类型为数组时是如何处理的
 *  *当使用数组作为函数的形参时，数组名退化成指针(这里的指针就是数组首元素的地址)，目的是为了节省空间和时间
 *      如果是把整个数组复制一份传递给函数，那么会浪费巨大的空间，假如要传递一个长度为50000的数组，那么就需要额外开辟这么大的空间供函数使用
 */

 //下面方法是错误的，无法正确打印出数组中每一个元素，因为sizeof(nums)求的是指针的长度，32位系统为4个字节， 4/4 = 1，所以只能打印数组中第一个元素
/**
 * 打印数组
 * @param nums 代表数组的指针
 *
 * 注意：当参数为数组时， [] 和 * 可以互相替换， int nums[] 和 int* nums效果是相同的
 */
//void PrintArr1(int nums[])  // 写法一 不推荐
//void PrintArr1(int nums[5]) // 写法二 不推荐
void PrintArr1(int* nums)	  // 写法三	推荐
{
	// 这里实际上求的是指针的长度
	printf("sizeof(nums) = %d\n", sizeof(nums));
    int length = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", nums[i]);
    }
    printf("------------------------------\n");
}


/**
 * 打印数组
 * @param nums 代表数组的指针
 * @param n 数组的长度
 */
void PrintArr2(int* nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", nums[i]);
    }
    printf("------------------------------\n");
}

/**
 * 使用指针和while循环打印数组
 */
void PrintArrayByWhileLoop(int* start, int* end)
{
	while(start < end)
	{
		// 可以观察到int类型指针每次+1，内存空间便宜的值为4
		printf("start => %p, end => %p\n", start, end);
		printf("%d\n", *start);
		start++;
	}
	printf("------------------------------\n");
}

#if 0
#endif
int main()
{
    int nums[] = { 1,2,3,4,5 };
    // 参数是数组名，也就是数组首元素地址
    PrintArr1(nums);
    int length = sizeof(nums) / sizeof(nums[0]);
    // 参数是数组名，也就是数组首元素地址
    PrintArr2(nums, length);
    PrintArrayByWhileLoop(nums, nums+length);
    return 0;
}
