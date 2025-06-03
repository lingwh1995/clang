#include <stdio.h>

/*
 * 1.C语言中的三种循环:
 *  while
 *  do while
 *  for
 *
 * 2.while循环和for循环的区别:
 * 	while循环进入下一轮循环的控制条件是全部写在方法体中
 *  for循环控制下一轮循环的条件是一部分写在for后面，另一部分写在方法体中的，所以while非常适合处理控制下一轮是否继续进行
 *
 * 3.while循环和for循环分别实现打印偶数
 *  for循环实现打印偶数分析: 由于i++ 和 方法体中逻辑共同作用才能实现
 *    for(int i=0; i<100; i++)
 *    {
 *        if(i % 2 ==0)
 *        {
 *            printf("%d\n", i);
 *        }
 *    }
 *
 *  while循环实现打印偶数分析: 只控制方法体中i++执行 就可以实现
 *    int i = 0;
 *    while(i<100)
 *    {
 *        printf("%d\n", i);
 *        i = i+2;
 *    }
 */

/*
 * while循环测试
 */
void WhileLoopTest()
{
    int i = 0;
    while (i < 10)
    {
        printf("%d\n", i);
        // 如果屏蔽掉下面一行,则会是死循环
        i++;
    }
}

/*
 * do while循环测试
 */
void DoWhileLoopTest()
{
    int i = 0;
    do
    {
        printf("%d\n", i);
        i++;
    } while (i < 10);
}

/*
 * for循环测试
 */
void ForLoopTest()
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", i);
    }
    printf("------------------\n");
}

#if 0
int main()
{
	//WhileLoopTest();
	//DoWhileLoopTest();
    ForLoopTest();
}
#endif
