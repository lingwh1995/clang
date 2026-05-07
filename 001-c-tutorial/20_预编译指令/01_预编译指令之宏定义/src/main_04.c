#include <stdio.h>
#define MARKSTR(s) #s
#define CONCAT(a,b) a##b
#define CHAR(x) char ch_##x[]=#x
#define TO_STR(x) #x

/**
 * 宏运算符
 * #  字符串化运算符（stringify operator），只能用于单个参数
 * #@ 字符串运算符
 * ## 链接运算符（token pasting operator），将两个参数直接拼接成一个记号
 */
#if 0
int main()
{
    printf(MARKSTR(hello world!\n));

    int xy = 100;
    printf("%d\n", CONCAT(x, y));
    printf("%s\n", "hello", "world");

    CHAR(a);
    // char ch_a[]="a";
    printf("%s\n", ch_a);

    const char* str = TO_STR(b);
    printf("%c\n", str[0]);
    return 0;
}
#endif