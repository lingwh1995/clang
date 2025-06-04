#include <stdio.h>

 /**
  * break测试
  *  跳出当前循环
  */
void BreakTest()
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            break;
        }
        printf("i = %d\n", i);
    }
}


/**
 * continue测试
 *  正常使用continue
 */
void ContinueTest1()
{
    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            continue;
        }
        printf("i = %d\n", i);
    }
}


/**
 * continue测试
 *  正常使用continue,注意i++的位置
 */
void ContinueTest2()
{
    for (int i = 0; i < 10; )
    {
        i++;
        if (i == 5)
        {
            printf("不会进入死循环...\n");
            continue;
        }
        printf("i = %d\n", i);
    }
}


/**
 * continue测试
 *  在for循环中跳出当前循环实际上是跳到for循环的第三个表达式上,这里for循环中第三个表达式没有对i值做任何改变
 *      所以看起来效果和break相同,但实际上是进入了死循环中
 *  注意i++的位置
 *
 */
void ContinueTest3()
{
    for (int i = 0; i < 10; )
    {
        if (i == 5)
        {
            printf("会进入死循环...\n");
            continue;
        }
        i++;
        printf("i = %d\n", i);
    }
}


/**
 * continue测试
 *  正常使用continue
 */
void ContinueTest4()
{
    int n = 0;
    while (n < 10)
    {
        n++;
        if (n == 5)
        {
        	printf("不会进入死循环...\n");
            continue;
        }
        printf("n = %d\n", n);
    }
}


/**
 * continue测试
 *  在for循环中跳出当前循环实际上是跳到while循环的表达式上,无法执行到 n++ 这个语句
 *  所以看起来效果和break相同,但是实际上是死循环
 *
 */
void ContinueTest5()
{
    int n = 0;
    while (n < 10)
    {
        if (n == 5)
        {
            printf("会进入死循环...\n");
            continue;
        }
        n++;
        printf("n = %d\n", n);
    }
}


int main()
{
    //BreakTest();
    //ContinueTest1();
    //ContinueTest2();
	//ContinueTest3();
	//ContinueTest4();
    ContinueTest5();
    return 0;
}
