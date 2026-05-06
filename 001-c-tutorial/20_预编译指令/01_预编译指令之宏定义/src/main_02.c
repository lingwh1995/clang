#include <stdio.h>
#define ERROR_MSG "standard error on input!"

#if 0
#endif
int main()
{
    char str[] = { "hello "ERROR_MSG };
    printf("%s \n", str);
    printf("%s \n", ERROR_MSG);
    // 特别注意： 宏定义的字符串可以不使用%s输出，直接就输出
    printf(ERROR_MSG);
    return 0;
}