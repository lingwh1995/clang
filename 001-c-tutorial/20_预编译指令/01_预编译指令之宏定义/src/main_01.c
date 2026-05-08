#include <stdio.h>
#define ONE 1
#define TWO (ONE + ONE)
#define THREE (ONE + TWO)

/**
 * 宏定义经典应用场景
 *
 * 1. 定义数组的大小
 * 2. 定义常量如圆周率
 *      #define PI 3.14
 * 3. 定义状态
 *      #define OK      0
 *      #define ERROR   -1
 * 4. 定义一些简单宏函数
 *      求最大值
 *      求最小值
 *      求最绝对值
 */

#if 0
int main()
{
    printf("宏 ONE = %d\n", ONE);
    printf("宏 TWO = %d\n", TWO);
    printf("宏 THREE = %d\n", THREE);

    // int a = 1;
    int a = ONE;
    // int b = 1 + 1 * 2;
    int b = TWO * 2;
    // int c = 1 + 1 + 1 * 3;
    int c = THREE * 3;
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    return 0;
}
#endif