#include <stdio.h>
// 求绝对值
#define ABS(a) (a) < 0 ? -(a) : (a)
// 求最大值
#define MAX(a,b)  ((a)>(b)?(a):(b))
// 求最小值
#define MIN(a,b)  ((a)<(b)?(a):(b))
// 平方
#define SQR(x)    ((x)*(x))

int abs(int a)
{
    return a < 0 ? -a : a;
}

/**
 * 宏函数
 *
 * 1.宏元和变元之间不能有空格
 * 2.可以提高函数运行速度
 */
#if 0
#endif
int main()
{
    int a = -10;
    printf("ABS(a) = %d, ABS(-a) = %d\n", ABS(a), ABS(-a));
    printf("abs(a) = %d, abs(-a) = %d\n", abs(a), abs(-a));

    int x = 10;
    int y = 20;
    printf("MAX(x,y) = %d\n", MAX(x,y));
    printf("MIN(x,y) = %d\n", MIN(x,y));
    printf("SQR(x) = %d\n", SQR(x));
    return 0;
}