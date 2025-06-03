#include <stdio.h>
#include <stdbool.h>

/**
 * bool类型
 *  1.在C语言中,0为假,非0都为真,一般用1来代表true
 *  2.printf不能直接输出bool,需要转换为整形输出
 */

/**
 * C语言中判断真或假
 */
void JudgeTrueOrFalse(int n)
{
    if(n)
    {
    	printf("为真...\n");
    }
    else
    {
    	printf("为假...\n");
    }
}

/*
 * C语言中判断真或假测试
 */
void JudgeTrueOrFalseTest()
{
    //在C语言中,0为假,非0都为真
    int n = 0;
    JudgeTrueOrFalse(n);

    n = 1;
    JudgeTrueOrFalse(n);

    n = -1;
    JudgeTrueOrFalse(n);
}

/*
 * stdbool.h测试
 */
void StdboolTest()
{
    //如果要使用bool，需要引入 stdbool.h
    bool b = false;
    if (b)
    {
        printf("为真...\n");
    }
    else
    {
       printf("为假...\n"); 
    }
    printf("b_1 = %d\n", b);

    b -= 1;
    //下面一行输出1，为什么不输出-1,因为 0-1=-1 ,-1非0是true,true值为1
    printf("b_2 = %d\n", b);

    b -= 1;
    //上面得到的b=1, 1-1=0,所以输出0
    printf("b_3 = %d\n", b);

    b -= 1;
    //上面得到的b=0, 0-1=-1,-1非0是true,true值为1
    //上面得到的b=1, 1-1=0,所以输出0
    printf("b_4 = %d\n", b);

    //一些不好判断为真还是为假的值
    bool i = 0; //false
    bool j = '0'; //true
    bool k = '\0'; //空字符,ASCII码为0,false
    bool l = NULL; //false
    bool m = ' '; //空格 32 true

    //输出bool
    bool x = false;
    bool y = true;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
}

/**
 * C99中提供的Bool类型
 */ 
void C99BoolTest()
{
    bool b = true;
    printf("true = %d 代表 真\n",b);
    b = false;
    printf("false = %d 代表 假\n",b);
}

#if 0
int main()
{
	//JudgeTrueOrFalseTest();
    //StdboolTest();
    C99BoolTest();
    return 0;
}
#endif