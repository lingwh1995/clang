#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

/**
 * 题目列表
 * 001.循环打印 a-g 方式一：不使用取余运算
 * 002.循环打印 a-g 方式二：使用取余运算
 * 003.求最大公约数 方式一：暴力穷举
 * 004.求最大公约数 方式二：辗转相除法
 * 005.求最大公约数 方式三：更相减损术(辗转相减法)
 * 006.求最小公倍数 方式一：暴力穷举
 * 007.求最小公倍数 方式二：利用最大公约数
 * 008.求最小公倍数 方式三：最小i值法
 * 009.输入三个整型数据，求最小值
 * 010.输入三个整型数据，求中间值
 * 011.输入三个整型数据，求最大值
 * 012.统计字符串中一共有多少个单词
 * 013.小球从100米落下,每次落地后跳回原来的高度一半，再落下，求它在第10次落下时共经过多少米?反弹高度是多少?
 * 014.有一对兔子，从出生后第三个月起每个月都生一对兔子，小兔子长到第三个月后又生一对兔子，假如兔子都不死，问每个月有多少对兔子?（递归求解）
 * 015.有一对兔子，从出生后第三个月起每个月都生一对兔子，小兔子长到第三个月后又生一对兔子，假如兔子都不死，问每个月有多少对兔子?（非递归求解）
 * 016.牛顿迭代法求平方根，要求两次求出的平方根的差的绝对值小于0.00001
 * 017.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数
 * 018.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数和该完数的因数（方式一：不使用结构体版）
 * 019.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数和该完数的因数（方式二：使用结构体版）
 * 020.打印九九乘法表
 * 021.找出用户输入的一串数字中的最大数，程序需要提示用户一个一个的输入，当用户输入0或负数时，程序显示已经输入的最大非负数
 * 022.随机生成1-100之间的数字请人猜，如果是猜对了结束游戏，如果猜错则继续猜并提示所猜的数是大于还是小于所指定的数，最终提示猜对所用次数
 * 023.多次输入年月日，输出最早的年月日（方式一）
 * 024.多次输入年月日，输出最早的年月日（方式二）
 * 025.冒泡排序算法模型
 * 026.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素可以重复，并且使用冒泡排序对数组元素进行排序（基础版）
 * 027.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素可以重复，并且使用冒泡排序对数组元素进行排序（优化版）
 * 028.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（for循环版）
 * 029.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（while循环版）
 * 030.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（查表版 方式一）
 * 031.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（查表版 方式二）
 */

/**
 * 001.循环打印 a-g 方式一：不使用取余运算
 */
void Question_001_LoopPrintAToG()
{
	char str[] = "abcdefg";
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		int k = i;
		for(int j = 0; j < len; j++)
		{
			printf("%c", str[k]);
			k = k + 1;
			if(k == len)
			{
				k = 0;
			}
		}
		printf("\n");
	}
}

/**
 * 002.循环打印 a-g 方式二：使用取余运算
 */
void Question_002_LoopPrintAToG()
{
	char str[] = "abcdefg";
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		int k = i;
		for(int j = 0; j < len; j++)
		{
			printf("%c", str[k]);
			k = k + 1;
			k =  k % len;
		}
		printf("\n");
	}
}

/**
 * 003.求最大公约数 方式一：暴力穷举
 * 		a.找出a和b中最小的数，把这个数赋值给c
 * 		b.第一个满足 a%c==0 && b%c==0 的数就是a和b的最大公约数
 */
void Question_003_GreatestCommonDivisor()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int c = a<b ? a : b;
	while(c>1)
	{
		if(a % c == 0 && b % c==0)
		{
			break;
		}
		c--;
	}
	printf("最大公约数 = %d", c);
}

/**
 * 004.求最大公约数 方式二：辗转相除法
 * 		公式：gcd(a,b) = gcd(b, a mod b);
 * 		     gcd(48,18) = gcd(18, 12);
 * 	    	 gcd(18,12) = gcd(12, 6);
 * 	         gcd(12,6)  = gcd(6, 0);
 */
void Question_004_GreatestCommonDivisor()
{
	int a, b, mod;
	scanf("%d %d", &a, &b);
	while(mod != 0)
	{
		mod = a % b;
		a = b;
		b = mod;
	}
	printf("最大公约数 = %d",a);
}

/**
 * 005.求最大公约数 方式三：更相减损术(辗转相减法)
 * 		公式：gcd(a, b) = gcd(b, a - b);
 * 		注意：a<b时，要先交换a、b两个数的位置再进行相减
 */
void Question_005_GreatestCommonDivisor()
{
	int a, b, diff;
	scanf("%d %d", &a, &b);
	while(diff != 0)
	{
        if(a < b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
		diff = a - b;
		a = b;
		b = diff;
	}
	printf("最大公约数 = %d",a);
}

/**
 * 006.求最小公倍数 方式一：暴力穷举
 */
void Question_006_LeastCommonMultiple()
{
	int a, b, lcm;
	scanf("%d %d", &a, &b);
	lcm = a > b ? a : b;
	while(true)
	{
		if(lcm%a==0 && lcm%b==0)
		{
			break;
		}
		++lcm;
	}
	printf("最小公倍数 = %d", lcm);
}

/**
 * 007.求最小公倍数 方式二：利用最大公约数 int lcm = a*b / gcd(a,b)
 */
int gcd(int a, int b)
{
	int mod;
	while(mod != 0)
	{
		mod = a % b;
		a = b;
		b = mod;
	}
	return a;
}
void Question_007_LeastCommonMultiple()
{
	int a, b, lcm;
	scanf("%d %d", &a, &b);
	lcm = a*b / gcd(a,b);
	printf("最小公倍数 = %d", lcm);
}

/**
 * 008.求最小公倍数 方式三：最小i值法
 */
void Question_008_LeastCommonMultiple()
{
	int a, b, lcm;
	scanf("%d %d", &a, &b);
	int i = 1;
	while(a*i % b != 0)
	{
		i++;
	}
	lcm = a * i;
	printf("最小公倍数 = %d", lcm);
}

/**
 * 009.输入三个整型数据，求最小值
 */ 
void Question_009_GetMinValue()
{
	printf("请输入三个整型数据，使用空格分隔:\n");
	int a, b, c, min;
	scanf("%d %d %d", &a, &b, &c);
	min = a < b ? a : b;
	min = min < c ? min : c;
	printf("min = %d\n", min);
}

/**
 * 010.输入三个整型数据，求中间值
 */ 
void Question_010_GetMidValue()
{
	printf("请输入三个整型数据，使用空格分隔:\n");
	int a, b, c, min, mid, max;
	scanf("%d %d %d", &a, &b, &c);
	// 求出三个数里面最小值
	min = a < b ? a : b;
	min = min < c ? min : c;
	// 求出三个数里面最大值
	max = a > b ? a : b;
	max = max > c ? max : c;
	mid = a + b + c - min - max;
	printf("mid = %d\n", mid);
}

/**
 * 011.输入三个整型数据，求最大值
 */ 
void Question_011_GetMaxValue()
{
	printf("请输入三个整型数据，使用空格分隔:\n");
	int a, b, c, max;
	scanf("%d %d %d", &a, &b, &c);
	max = a > b ? a : b;
	max = max > c ? max : c;
	printf("max = %d\n", max);
}

/**
 * 012.统计字符串中一共有多少个单词
 */ 
void Question_012_CountWord()
{
	char str[] = " one  two   three    four     five ";
    int j;
    int c = str[0] == ' ' ? 0 : 1;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ')
        {
            if(j == 0)
            {
                c++;
            }
            j++;
        }
        else
        {
            j = 0;
        }
    }
    printf("单词个数 = %d\n", c);
}

/**
 * 013.小球从100米落下,每次落地后跳回原来的高度一半，再落下，求它在第10次落下时共经过多少米?反弹高度是多少?
 */
void Question_013_BallFalls()
{
    //下落经过的总高度
    double sumHeight = 100.00;
    //每一次的反弹高度
    double currentJumpHeight = sumHeight / 2;
    for (int i = 2; i <= 10; i++)
    {
        sumHeight = sumHeight + currentJumpHeight * 2;
        currentJumpHeight = currentJumpHeight / 2;
    }
    printf("经过的总高度 sumHeight = %f\n", sumHeight);
    printf("第10次反弹高度 currentJumpHeight = %f\n", currentJumpHeight);
}

/**
 * 递归求解
 * 014.有一对兔子，从出生后第三个月起每个月都生一对兔子，小兔子长到第三个月后又生一对兔子，假如兔子都不死，问每个月有多少对兔子?
 * 月份     1       2       3       4       5       6       7       8
 * 对数     1       1       2       3       5       8       13      21
 */
int RabbitCount(int m)
{
	if(m == 1 || m == 2)
	{
		return 1;
	}
	return RabbitCount(m-1) + RabbitCount(m-2);
}

void Question_014_RabbitCount_Recursion()
{
	int m = 8;
	int totalRabbit = RabbitCount(m);
	printf("第%d个月兔子总数 = %d\n", m, totalRabbit);
}

/**
 * 非递归求解
 * 015.有一对兔子，从出生后第三个月起每个月都生一对兔子，小兔子长到第三个月后又生一对兔子，假如兔子都不死，问每个月有多少对兔子?
 * 月份     1       2       3       4       5       6       7       8
 * 对数     1       1       2       3       5       8       13      21
 */
void Question_015_RabbitCount_No_Recursion()
{
    //c代表后续月份兔子个数
    int a = 1, b = 1, c = 1, m = 10;
    for (int i = 3; i <= m; ++i)
    {
        c = a + b;
        a = b;
        b = c;
    }
    printf("第%d个月的兔子对数 = %d\n", m, c);
}

/**
 * 016.牛顿迭代法求平方根，要求两次求出的平方根的差的绝对值小于0.00001
 */
void Question_016_NewtonRaphson_Method_Sqrt()
{
	double d;
    printf("请输入一个浮点类型数据：\n");
    scanf("%lf", &d);
    printf("d = %lf\n", d);
	double x0 = d / 2;
	double x1 = (x0 + d/x0) / 2;
	while(fabs(x0-x1) > 0.00001)
	{
		x0 = x1;
		x1 = (x0 + d/x0) / 2;
	}
	printf("%f的平方根是 = %f\n", d, x1);
}

/**
 * 017.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数
 */
void Question_017_PerfectNumber()
{
    int n = 1000;
    for (int i = 2; i <= n; i++)
    {
        int sum = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                sum = sum + j;
            }
        }
        if (sum == i)
        {
            printf("%d\n", i);
        }
    }
}

/**
 * 018.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数和该完数的因数（方式一）
 */
void Question_018_PerfectNumberFactor()
{
    int n = 1000;
    for (int i = 2; i <= n; i++)
    {
        int sum = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                sum = sum + j;
            }
        }
        if (sum == i)
        {
            printf("%d => ", i);
            for (int x = 1; x <= i/2; x++)
            {
                if (i % x == 0)
                {
                    printf("%d ", x);
                }
            }
            printf("\n");
        }
    }
}

/**
 * 019.如果一个数等于它的因子之和，则这个数称为完数 6 = 1 + 2 + 3，找出1000以内的所有完数和该完数的因数（方式二）
 */
void Question_019_PerfectNumberFactor()
{
    int n = 1000;
    for (int i = 2; i <= n; i++)
    {
        int sum = 1;
        int factor[30] = {1};
        int index = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                sum = sum + j;
                factor[index++] = j;
            }
        }
        if (sum == i)
        {
            printf("%d => ", i);
            for (int x = 0; x < index; x++)
            {
            	printf("%d ", factor[x]);
            }
            printf("\n");
        }
    }
}

/**
 * 020.打印九九乘法表
 */
void Question_020_MultiplicationTable()
{
	for(int i=1; i<=9; i++)
	{
		for(int j=1; j<=i; j++)
		{
			printf("%d * %d =%3d\t", j, i, i*j);
		}
		printf("\n");
	}
}

/**
 * 021.找出用户输入的一串数字中的最大数，程序需要提示用户一个一个的输入，当用户输入0或负数时，程序显示已经输入的最大非负数
 */
void Question_021_GetMaxInputValue()
{
    int input, max=0;
    while(input>0)
    {
        printf("请输入一个数字：\n");
        scanf("%d", &input);
        max = input > max ? input : max;
    }
    printf("max = %d\n", max);

}

/**
 * 022.随机生成1-100之间的数字请人猜，如果是猜对了结束游戏，如果猜错则继续猜并提示所猜的数是大于还是小于所指定的数，最终提示猜对所用次数
 */ 
void Question_022_GuessNumber()
{
    srand((unsigned)time(NULL));
    int r = rand() % 10;
    printf("r = %d\n", r);
    printf("请输入:\n");
    int i = 0;
    int times = 0;
    while (1)
    {
        times++;
        scanf("%d", &i);
        if (i > r)
        {
            printf("你猜大了,当前输入值:%d\n", i);
        }
        else if (i < r)
        {
            printf("你猜小了,当前输入值:%d\n", i);
        }
        else
        {
            printf("你猜正确了,当前输入值:%d\n", i);
            break;
        }
    }
    printf("共猜了%d次才猜正确\n", times);
}


/**
 * 判断当前年份是否是闰年(闰年全年366天，2月29天，平年全年365天，2月28天)
 * @param year 当前年份
 */ 
bool IsLeapYear(int year)
{
    return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}

/**
 * 获取当前月份有多少天
 * @param year 当前年份
 * @param month 当前月份
 */ 
int GetCurrentMonthDays(int year, int month)
{
    int days = 31;
    switch(month)
    {
        case 2:
            days = IsLeapYear(year) ? 29 : 28;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
    }
    return days;
}

/**
 * 023.多次输入年月日，输出最早的年月日（方式一：不使用结构体版）
 */
void Question_023_GetEarliestInputDate()
{
	int year = 1, month = 1, day = 1;
	int myear = INT_MAX, mmonth = 12, mday = 31;
	while(true)
	{
		bool flag = false;
		printf("输入年月日，格式yyyy/mm/dd：\n");
		scanf("%d/%d/%d", &year, &month, &day);
		// 判断输入的年月日是否合法
		if(year <=0 || month <=0 || day <=0)
		{
			break;
		}
		// 判断输入的月是否合法
		if(month < 1 || month > 12)
		{
			break;
		}
		// 判断输入的日是否合法
		if(day < 1 || day > GetCurrentMonthDays(year,month))
		{
			break;
		}
		if(year < myear)
		{
			flag = true;
		}
		else if(year == myear || month < mmonth)
		{
			flag = true;
		}
		else if(year == myear || month == mmonth || day < mday)
		{
			flag = true;
		}
		if(flag)
		{
			myear = year;
			mmonth = month;
			mday = day;
		}
	}
	printf("最早的是日期是：%d/%d/%d\n", myear, mmonth, mday);
}

/**
 * 024.多次输入年月日，输出最早的年月日（方式二：使用结构体版）
 */
void Question_024_GetEarliestInputDate()
{
	typedef struct
	{
		int year;
		int month;
		int day;
	} Date;
	Date inputVal = { 1,1,1 };
	Date min = { INT_MAX,12,31 };
	while(true)
	{
		bool flag = false;
		printf("输入年月日，格式yyyy/mm/dd：\n");
		scanf("%d/%d/%d", &inputVal.year, &inputVal.month, &inputVal.day);
		// 判断输入的年月日是否合法
		if(inputVal.year <=0 || inputVal.month <=0 || inputVal.day <=0)
		{
			break;
		}
		// 判断输入的月是否合法
		if(inputVal.month < 1 || inputVal.month > 12)
		{
			break;
		}
		// 判断输入的日是否合法
		if(inputVal.day < 1 || inputVal.day > GetCurrentMonthDays(inputVal.year,inputVal.month))
		{
			break;
		}
		if(inputVal.year < min.year)
		{
			flag = true;
		}
		else if(inputVal.year == min.year || inputVal.month < min.month)
		{
			flag = true;
		}
		else if(inputVal.year == min.year || inputVal.month == min.month || inputVal.day < min.day)
		{
			flag = true;
		}
		if(flag)
		{
			min.year = inputVal.year;
			min.month = inputVal.month;
			min.day = inputVal.day;
		}
	}
	printf("最早的是日期是：%d/%d/%d\n", min.year, min.month, min.day);
}

/**
 * @param a a元素的地址
 * @param b b元素的地址
 */
void SwapNumber(int* ap, int* bp)
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
 * 025.冒泡排序算法模型
 *      外层循环控制比较轮数            比较轮数(从0开始) = 数组的长度 - 1 
 *      内层循环控制每一轮比较次数       每一轮比较次数 = 数组长度 - 当前比较轮数(从0开始) -1
 */
void Question_025_BubbleSort()
{
	int nums[] = { 3,9,7,1,5 };
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
                SwapNumber(&nums[c],&nums[c+1]);
            }
        }
	}
    for(int i = 0; i < length; i++)
    {
        printf("%2d ", nums[i]);
    }
}

/**
 * 026.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素可以重复，并且使用冒泡排序对数组元素进行排序（基础版）
 */
void Question_026_BubbleSort()
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
                SwapNumber(&nums[j], &nums[j + 1]);
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
 * 027.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素可以重复，并且使用冒泡排序对数组元素进行排序（优化版）
 */
void Question_027_BubbleSort()
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
                SwapNumber(&nums[j], &nums[j + 1]);
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
int FindValue(int* nums, int k, int value)
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
 * 028.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（for循环版）
 */
void Question_028_BubbleSort()
{
	int nums[100] = { 0 };
	int length = sizeof(nums) / sizeof(nums[0]);
	// 生成100个不重复随机数
	srand((unsigned)time(NULL));
	for(int i = 0; i < length; i++)
	{
		int r = rand() % length + 1;
		if(FindValue(nums,i,r) == -1)
		{
			nums[i] = r;
		}
		else
		{
			// 如果FindValue()返回值不为-1,则说明数组中已经有一个元素的值和r相等,则让i--,这是很巧妙的处理方法
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
				SwapNumber(&nums[j], &nums[j+1]);
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
 * 029.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（while循环版）
 */
void Question_029_BubbleSort()
{
	int nums[100] = { 0 };
	int length = sizeof(nums) / sizeof(nums[0]);
	// 生成100个不重复随机数
	srand((unsigned)time(NULL));
	int i = 0;
	while(i < length)
	{
		int r = rand() % length + 1;
		if(FindValue(nums,i,r) == -1)
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
				SwapNumber(&nums[j], &nums[j+1]);
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
 * 030.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（查表版 方式一）
 */
void Question_030_BubbleSort()
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
				SwapNumber(&nums[j], &nums[j+1]);
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
 * 031.定义大小为100的整形数组，使用随机函数给数组元素赋值，数值范围1-100，数组中元素不可以重复，并且使用冒泡排序对数组元素进行排序（查表版 方式二）
 */
void Question_031_BubbleSort()
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


int main()
{
	// 测试执行效率，使用以下方法
	/*
	  long start, end;
	  start = time(NULL);
	  end = time(NULL);
	  printf("花费时间 = %ld s\n", (end - start));
	 */

	//Question_001_LoopPrintAToG();
	//Question_002_LoopPrintAToG();
	//Question_003_GreatestCommonDivisor();
	//Question_004_GreatestCommonDivisor();
	//Question_005_GreatestCommonDivisor();
	//Question_006_LeastCommonMultiple();
	//Question_007_LeastCommonMultiple();
	//Question_008_LeastCommonMultiple();
	//Question_009_GetMinValue();
	//Question_010_GetMidValue();
	//Question_011_GetMaxValue();
	//Question_012_CountWord();
	//Question_013_BallFalls();
	//Question_014_RabbitCount_Recursion();
	//Question_015_RabbitCount_No_Recursion();
	//Question_016_NewtonRaphson_Method_Sqrt();
	//Question_017_PerfectNumber();
	//Question_018_PerfectNumberFactor();
	//Question_019_PerfectNumberFactor();
	//Question_020_MultiplicationTable();
	//Question_021_GetMaxInputValue();
    //Question_022_GuessNumber();
    //Question_023_GetEarliestInputDate();
	//Question_024_GetEarliestInputDate();
	//Question_025_BubbleSort();
	//Question_026_BubbleSort();
	//Question_027_BubbleSort();
	//Question_028_BubbleSort();
	Question_029_BubbleSort();
	//Question_030_BubbleSort();
	//Question_031_BubbleSort();
	return 0;
}
