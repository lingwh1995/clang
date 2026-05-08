#include <stdio.h>
#define ONE 1
#define TWO ONE + ONE
#define THREE ONE + TWO

/**
 * 预编译指令
 *
 * 1. 每个预编译指令都能要以#开头
 * 2. 每个预编译指令都要独占一行
 *
 * 预编译指令之宏定义
 *
 * c语言认为宏是一个字符串
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