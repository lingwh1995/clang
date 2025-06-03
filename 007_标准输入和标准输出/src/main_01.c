#include <stdio.h>
#include <string.h>

/**
 * 标准输入和EOF
 */


 /**
 * 标准输入测试
 */
void StdinAndEOFTest1()
{
    printf("请输入,按回车结束:\n");
    int sum = 0;
    while (getchar() != '\n')
    {
        sum++;
    }
    printf("sum = %d\n", sum);
}


/**
 * 标准输入和EOF测试
 */
void StdinAndEOFTest2()
{
    printf("请输入,输入 Ctrl+C 结束:\n");
    int sum = 0;
    while (getchar() != EOF)
    {
        sum++;
    }
    printf("sum = %d\n", sum);
}


/**
 * 标准输入测试
 *  接收单个字符: 不管输入多少个字符,都只会接收第一个字符
 */
void StdinAndEOFTest3()
{
    printf("请输入:\n");
    char ch = getchar();
    printf("ch = %c\n", ch);
}


/**
 * 标准输入测试：接收多个字符(输入Ctrl+C结束)
 *
 */
void StdinAndEOFTest4()
{
    printf("请输入:\n");
    char ch = '\0';
    //为什么getchar()可以放在while后面的大括号中,来接收多个字符,因为getchar()有一个缓冲区机制

    //错误写法
    //while (ch = getchar() != '\n')
    //{
    //正确写法
    //while ((ch = getchar()) != '\n')
    //{
    while ((ch = getchar()) != EOF)
    {
        printf("ch = %c\n", ch); 
    }
}


/**
 * 标准输入测试：接收多个字符串(输入Ctrl+C结束)
 *    输入水果名称，通过水果名称判断是不是最喜爱的运动，如果输入的是 apple 就是最喜爱的水果
 */
void StdinAndEOFTest5()
{
    printf("请输入名称:\n");
    char fruitName;
    while (scanf("%s", &fruitName) != EOF)
    {
        if(strcmp(&fruitName,"apple") == 0)
        {
            printf("是最喜爱的水果\n");
        }
        else
        {
            printf("不是最喜爱的水果\n");
        }
    }
}


/**
 * 标准输入测试：接收多个数字(输入Ctrl+C结束)
 *    输入IQ值，通过IQ值判断是不是Genius，IQ>=140是Genius
 */
void StdinAndEOFTest6()
{
    printf("请输入IQ值:\n");
    int IQ;
    while (scanf("%d", &IQ) != EOF)
    {
        if(IQ >= 140)
        {
            printf("Genius\n");
        }
        else
        {
            printf("Not Genius\n");
        }
    }
}

/**
 * 打印时左对齐和右对齐
 */
void StdinAndEOFTest7()
{
	// 左对齐
	printf("%2d\n", 1);
	printf("%2d\n", 5);
	printf("%2d\n", 10);
	printf("%2d\n", 20);
	// 右对齐
	printf("%-2d\n", 1);
	printf("%-2d\n", 5);
	printf("%-2d\n", 10);
	printf("%-2d\n", 20);
}

#if 0
int main()
{
    //StdinAndEOFTest1();
	//StdinAndEOFTest2();
    //StdinAndEOFTest3();
    //StdinAndEOFTest4();
	//StdinAndEOFTest5();
	//StdinAndEOFTest6();
	StdinAndEOFTest7();
}
#endif