#include <stdio.h>
#define bool int
#define false 0
#define true 1

/*
 * 使用 宏定义 实现自定义bool
 *
 * 推荐指数 1颗星
 */
#if 0
int main()
{
    bool b = true;
    if(b)
    {
        printf("为真...\n");
    }
    else
    {
        printf("为假...\n");
    }
    printf("b = %d\n", b);
    return 0;
}
#endif