#include <stdio.h>


/**
* typedef:
*  1.C语言允许为一个数据类型起一个新的别名，它本身是一种存储类的关键字，与auto、extern、mutable、static、register等关键字不能同时出现在一个表达式中
*  2.给已有的类型起一个别名的，我们可以把一切合法的定义的变量(普通数据类型的变量/指针变量)转换为类型，如:
*      double d; 本意是定义了一个double类型的变量d
*      typedef double d; 转换后意思是给double这个数据类型起了一个别名,相当于把d由一个变量转换成为了一个类型
*  3.typedef不是类似于宏定义的类型替换,只是给是类型的重命名，起一个别名而已
*  4.typedef常和枚举和结构体结合使用
*/

// 宏定义和typedef的对比
#define MINT int *
typedef int* PINT;


void typedef_test()
{
    // 正常定义
    unsigned char c;
    unsigned short s;
    unsigned int i;
    unsigned long long ll;
    int array[10];

    // 使用typedef起简化别名
    typedef unsigned char uint_8;
    typedef unsigned short uint_16;
    typedef unsigned int uint_32;
    typedef unsigned long long uint_64;
    typedef int Array[10];

    //使用数据类型的简化别名定义数据
    uint_8 tc;
    uint_16 ts;
    uint_32 ti;
    uint_64 tll;
    //在下面打端点,使用使用debug模式查看数据类型,控制台中可以明确查看到数据类型为数组
    Array nums = { 1,2,3,4 };
    printf("unsigned char: sizeof(c)= %d, sizeof(tc)= %d\n", sizeof(c), sizeof(tc));
    printf("unsigned short: sizeof(s)= %d, sizeof(ts)= %d\n", sizeof(s), sizeof(ts));
    printf("unsigned int: sizeof(i)= %d, sizeof(ti)= %d\n", sizeof(i), sizeof(ti));
    printf("unsigned long: sizeof(ll)= %d, sizeof(tll)= %d\n", sizeof(ll), sizeof(tll));
}


/**
 * typedef和结构体结合使用方式一:
 */
struct Student
{
    char id[32];
    char name[20];
    int age;
};
typedef struct Student Student;
typedef struct Student* PStudent;

/**
 * typedef和结构体结合使用方式二:
 */
typedef struct User
{
    char id[32];
    char name[20];
    int age;
} User, *PUser;


/**
 * 测试typedef和结构体结合使用
 */
void typedef_with_struct_test()
{
    /**
     * 测试 typedef和结构体结合使用方式一:
     */
    Student student;
    PStudent pStudent = &student;

    /**
     * 测试 typedef和结构体结合使用方式二:
     */
    User user;
    PUser pUser = &user;
}

/**
 * 宏定义和typedef的对比
 */ 
void macrodefine_and_typedef()
{
    // 相当于 int *a; int b; 宏只是做字符串替换
    MINT a, b;
    printf("hello\n");
    // 相当于 int *i, int *j;
    PINT i, j;
    printf("world\n");
}

int main()
{
    //typedef_test();
    //typedef_with_struct_test();
    macrodefine_and_typedef();
    return 0;
}
