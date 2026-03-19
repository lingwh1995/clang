# include<stdio.h>

/**
 * 递归解决问题
 *
 * 1. 递归的本质
 *    把大问题拆成更小的、相同结构的子问题，直到不能拆（到达终止条件），再回溯计算结果。
 *
 * 2. 递归必须满足的 3 个条件(缺一不可)
 *    有明确的终止条件不然会无限递归 → 栈溢出 → 程序崩溃。
 *    子问题比原问题规模更小例如：sum(n) → sum(n-1)。
 *    子问题能回溯得到原问题解子问题解 + 当前值 = 最终结果。
 */

/**
 * 循环实现累加计算 1 + 2 + 3 + 4 + 5
 */
int sum_loop(int n)
{
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += i;
	}
	return sum;
}

/**
 * 递归实现累加计算  1 + 2 + 3 + 4 + 5
 *
 * 1. 函数
 * 	  sum(n) = n + sum(n-1)
 *
 * 2. 终止
 *    sum(0) = 0
 *
 * 3. 递归树(单链，没有分叉)：
 *    sum(5)
 *     ↓
 *    sum(4)
 *     ↓
 *    sum(3)
 *     ↓
 *    sum(2)
 *     ↓
 *    sum(1)
 *     ↓
 *    sum(0) = 0
 *
 * 4. 回溯计算
 *    sum(1) = 1 + sum(0) = 1
 *    sum(2) = 2 + sum(1) = 3
 *    sum(3) = 3 + sum(2) = 6
 *    sum(4) = 4 + sum(3) = 10
 *    sum(5) = 5 + sum(4) = 15
 */
int sum_recursion(int n)
{
    // 终止条件
    if (n == 0)
    {
        return 0;
    }
    // 递归调用
    return n + sum_recursion(n - 1);
}

/**
 * 循环实现求第 n 个斐波那契数  0、1、1、2、3、5、8、13、21 ...
 * F(0)=0, F(1)=1, F(n)=F(n-1)+F(n-2)
 */
int fib_loop(int n)
{
    if (n < 0)
    {
        return -1;
    }

    if (n <= 1)
    {
    	return n;
    }

    // F(i-2)
    int a = 0;
    // F(i-1)
    int b = 1;
    int c;

    for (int i = 2; i <= n; ++i) {
    	// F(i) = F(i-1) + F(i-2)
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

/**
 * 递归实现求第 n 个斐波那契数  0、1、1、2、3、5、8、13、21 ...
 *
 * 1. 函数
 *    fib(n) = fib(n-1) + fib(n-2)
 *
 * 2. 终止
 *    fib(0)=0, fib(1)=1
 *
 * 3. 递归树(二叉树，大量重复计算)
 *                fib(5)
 *             /          \
 *          fib(4)       fib(3)
 *         /     \       /    \
 *      fib(3)  fib(2) fib(2) fib(1)
 *      /    \
 *    fib(2) fib(1)
 *
 * 4. 回溯计算
 *    fib(1)=1, fib(0)=0
 *    fib(2) = fib(0)+fib(1) = 0 + 1 = 1
 *    fib(3) = fib(1)+fib(2) = 1 + 1 = 2
 *    fib(4) = fib(2)+fib(3) = 1 + 2 = 3
 *    fib(5) = fib(3)+fib(4) = 2 + 3 = 5
 */
int fib_recursion(int n)
{
	if(n <= 1)
	{
		return n;
	}
	else
	{
		return fib_recursion(n-2) + fib_recursion(n-1);
	}
}

int get_max_num(int arr)
{

	return 0;
}

void print_arr(const int* arr, int length)
{
	if(arr == NULL || length < 0)
	{
		return;
	}

	for(int i = 0; i < length; i++)
	{
		printf("%d\n", arr[i]);
	}
}

int main()
{
	int sum = sum_loop(5);
	printf("循环实现累加计算 sum = %d\n", sum);
	sum = sum_recursion(5);
	printf("递归实现累加计算 sum = %d\n", sum);

	int fib = fib_loop(5);
	printf("循环实现求第 n 个斐波那契数 fib = %d\n", fib);
	fib = fib_recursion(5);
	printf("递归实现求第 n 个斐波那契数 fib = %d\n", fib);

	int arr[] = { 1, 5, 3, 9, 7, 6 };
	int length = sizeof(arr) / sizeof(int);
	print_arr(arr, length);
	return 0;
}
