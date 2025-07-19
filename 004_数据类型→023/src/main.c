#include <stdio.h>
#include <stdbool.h>

/**
 * 章节内容：
 *   C语言数据类型
 *     1.基本数据类型：
 *       整型数据类型：short、int、long、long long
 *       	注意：short就是short int, long就是long int, long long就是long long int
 *       字符数据类型：char
 *       浮点型数据类型：float、double
 *       布尔类型：false=0、 true=1/非0
 *     2.构造数据类型
 *		 数组(Array)：一组相同类型元素的集合，可以是一维或多维。
 *		 结构体(Struct)：允许将不同类型的数据组合在一起，每个成员拥有独立的内存空间。
 *		 联合体(Union)：所有成员共享同一块内存空间，同一时间只能存储一种类型的数据。
 *		 ‌枚举(Enum)：用于定义一组命名的整数常量。
 *	   3.指针类型
 *	   	 指针(Pointer)：指向特定类型数据的指针，用于存储变量的内存地址，如int *p表示指向整数的指针。
 *	   4.空类型
 *	   	 void‌：表示没有类型，通常用于函数返回值、函数参数或通用指针。
 */


/**
 * 定义一个结构体Person
 */
struct Student
{
	// 学生id
	int id;
	// 学生姓名
	char name[20];
	// 学生年龄
	int age;
};


/**
 * 颜色枚举
 */
enum Color
{
	RED,	//默认为 0
	GREEN,	//默认为 1
	BLUE	//默认为 2
};


/**
 * 打印颜色
 *   使用枚举约束了case后面的值
 */
void print_color(enum Color color)
{
    switch (color)
    {
        case RED:
            printf("红色\n");
            break;
        case GREEN:
            printf("绿色\n");
            break;
        case BLUE:
            printf("蓝色\n");
            break;
        default:
            printf("参数不合法\n");
    }
}


int main()
{
	/**
	 * 不同数据类型占据的空间大小
	 */
	// short就是short int
    printf("short类型所占字节大小: %d\n", sizeof(short));
    printf("int类型所占字节大小: %d\n", sizeof(int));
    // long就是long int
    printf("long类型所占字节大小: %d\n", sizeof(long));
    printf("long int类型所占字节大小: %d\n", sizeof(long int));
    // long long就是long long int
    printf("long long类型所占字节大小: %d\n", sizeof(long long));
    printf("long long int类型所占字节大小: %d\n", sizeof(long long int));
    // 字符数据类型
    printf("char类型所占字节大小: %d\n", sizeof(char));
    // 浮点型数据类型
    printf("float类型所占字节大小: %d\n", sizeof(float));
    printf("double类型所占字节大小: %d\n", sizeof(double));
    printf("long double类型所占字节大小: %d\n", sizeof(long double));
    // 使用bool类型,C99中要引用 stdbool.h
    printf("bool类型所占字节大小: %d\n", sizeof(bool));
    printf("-------------------------------------\n");


    /**
     * 定义不同的数据类型的数据
     */
    // short类型
    short s_signed = -100;
    unsigned short s_unsigned = 100;
    printf("有符号 short: s_signed = %hd\n", s_signed);
    printf("无符号 short: s_unsigned = %hu\n", s_unsigned);

    // int类型
    int i_signed = -200;
    unsigned int i_unsigned = 200;
    printf("有符号 int: i_signed = %d\n", i_signed);
    printf("无符号 int: i_unsigned = %u\n", i_unsigned);

    // long类型
    long l_signed = -300L;  // 后缀L表示long类型
    unsigned long l_unsigned = 300L;  // 后缀L表示long类型
    printf("有符号 long: l_signed = %ld\n", l_signed);
    printf("无符号 long: l_unsigned = %lu\n", l_unsigned);

    // long long类型
    long long ll_signed = -400LL;  // 后缀LL表示long long类型
    unsigned long long ll_unsigned = 400LL;  // 后缀LL表示long long类型
    printf("有符号 long long: ll_signed = %lld\n", ll_signed);
    printf("无符号 long long: ll_signed = %llu\n", ll_unsigned);

    // float类型
    float f = 0.234f;
    printf("float 值 (默认): f = %f\n", f);
    printf("float 值 (2位小数): f = %.2f\n", f);
    printf("科学计数法: f = %e\n", f);

    // double类型
    float d = 0.456;
    printf("double 值 (默认): d = %lf\n", d);
    printf("double 值 (2位小数): d = %.2lf\n", d);
    printf("科学计数法: d = %e\n", d);

    // char类型
    char c1 = 'A'; // 等同于 char a = 65;
    char c2 = 'B'; // 等同于 char b = 66;
    printf("c1 + c2 = %d\n", c1 + c2); // 输出 131
    // 字符 '0'
    char c3 = '0';
    printf("c3 = %c\n", c3);
    printf("c3 = %d\n", c3);
    // 字符 '\0'，常用于标记字符串的结束位置
    char c4 = '\0';
    printf("c4 = %c\n", c4);
    printf("c4 = %d\n", c4);

    // 使用转义字符输出单引号
    char t = '\'';
    printf("%c\n", t);
    printf("-------------------------------------\n");


    // 数组(Array)
    int nums[] = { 10, 20, 30 };
    int i;
	int size = sizeof(nums)/sizeof(nums[0]);
    for(i = 0; i < size; i++)
    {
    	printf("%d ",nums[i]);
    }
    printf("\n");
    printf("-------------------------------------\n");


    // 结构体(Struct)
    struct Student alice = { 1,"Alice",18 };
    struct Student bob = { 2,"Bob",23 };
    struct Student student_arr[] = {
    		alice,
    		bob,
    		{ 3,"Charile",29 }
    };
    size = sizeof(student_arr)/sizeof(student_arr[0]);
    for(i = 0; i < size; i++)
    {
    	printf("学生编号：%d,学生姓名：%s,学生年龄：%d\n", student_arr[i].id, student_arr[i].name, student_arr[i].age);
    }
    printf("-------------------------------------\n");


    // 枚举(Enum)
    enum Color color = RED;
    printf("%d\n", color);
    print_color(color);
    // 注意：枚举可以像整型数组一样使用
    for(i=RED; i<=BLUE; i++)
    {
    	printf("%d\n", i);
    }
    printf("-------------------------------------\n");


    int a = 100;
    // 指针
    int* p = &a;
    printf("a的地址 = %p\n", p);
    int arr[5] = { 1,2,3,4,5 };
    // 数组的地址
    printf("数组的地址 = %p\n", &arr);
    printf("-------------------------------------\n");
    return 0;
}
