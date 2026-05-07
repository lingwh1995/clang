#include <stdio.h>
#define ABS(a) (a) < 0 ? -(a) : (a) //宏元和变元之间不能有空格

int abs(int a)
{
    return a < 0 ? -a : a;
}

/**
 * 带参数的宏(类似于函数的宏)： 可以提高函数运行速度
 */
#if 0
int main()
{
    int a = -10;
    printf("ABS(a) = %d, ABS(-a) = %d\n", ABS(a), ABS(-a));
    printf("abs(a) = %d, abs(-a) = %d\n", abs(a), abs(-a));
    return 0;
}
#endif