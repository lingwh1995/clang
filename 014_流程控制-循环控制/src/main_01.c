#include <stdio.h>
#include <string.h>

/**
 * 循环打印a-g
 *  不使用取模实现
 */
void PrintAToG1()
{
    char str[] = "abcdefg";
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = 0; j < n; j++)
        {
            printf("%c", str[k]);
            k = k + 1;
            if (k == n)
            {
                k = 0;
            }
        }
        printf("\n");
    }
}

/**
 * 循环打印a-g
 *  使用取模实现
 */
void PrintAToG2()
{
    char str[] = "abcdefg";
    int n = strlen(str);
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = 0; j < n; j++)
        {
            printf("%c", str[k]);
            k = (k + 1) % n;
        }
        printf("\n");
    }
}

/**
 * 死循环
 */
void DeadLoopTest1()
{
    for (;;)
    {
        printf("死循环\n");
    }
}

/**
 * 死循环
 */
void DeadLoopTest2()
{
    while (1)
    {
        printf("死循环\n");
    }
}

#if 0
int main()
{
    PrintAToG1();
    //PrintAToG2();
	//DeadLoopTest1();
    //DeadLoopTest2();
    return 0;
}
#endif
