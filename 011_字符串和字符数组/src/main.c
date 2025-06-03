#include <stdio.h>
#include <string.h>

/*
 * 字符串: 
 *  1.在C语言中，没有字符串类型数据,可以使用特殊的字符数组来代替字符串,字符串实际上是使用空字符\0结尾的一维字符数组
 *  2.为什么字符串所占的空间大小比字符串长度大1?
 *      因为计算空间大小的时候最后面加了一个\0用于标识字符串这是一个字符串,方便和字符数组进行区分,这
 *      个\0占用了一字节的空间,所以计算出来的字符串的空间大小比长度大了1
 *  
 * 字符数组: 	由字符组成的数组
 */

/*
 * 字符串的定义
 */
void StringBasic()
{
    // 定义一个字符串:方式1
	//char s1[] = { "hello" };
    // 定义一个字符串:方式2(字符数组 + \0)
    //char s1[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    // 定义一个字符串:方式3(省略大括号)
    char s1[] = "hello";
    int len = strlen(s1);
    int size = sizeof(s1);
    // 获取字符串的长度
    printf("字符串s的长度 = %d\n", len);
    // 获取字符串所占的空间大小，包括字符串长度和末尾的 '\0'
    printf("字符串s所占的空间大小 = %d\n", size);

    // 输出转义字符+字符串
    char s2[] = { "hello\"C语言\"world" };
    printf("输出转义字符+字符串 = %s", s2);
}

/*
 * 字符数组的定义 + 字符串和字符数组的区别
 */
void StringAndCharArray()
{
    // 普通字符数组
    char c1[] = { 'h', 'e', 'l', 'l', 'o' };
    // 乱码，因为没有'\0'结束符
    printf("c1 = %s\n", c1);

    // 定义一个字符串,以 '\0' 结尾
    char s1[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    printf("s1 = %s\n", s1);

    // 字符串处理以'\0'作为结束符,后面的'c', 'l', 'a', 'n', 'g'不会输出
    char s2[] = { 'h', 'e', 'l', 'l', 'o', '\0', 'c', 'l', 'a', 'n', 'g', '\0' };
    printf("s2 = %s\n", s2);
}

/**
 * 遍历字符串方式一
 */
void ForeachString1()
{
    char str[] = "hello";
    for (int i= 0; i < strlen(str); i++)
    {
        printf("%c\n", str[i]);
        printf("%p\n", &str[i]);
    }
}

/**
 * 遍历字符串方式二
 */
void ForeachString2()
{
    char str[] = "world";
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c\n", str[i]);
        printf("%p\n", &str[i]);
    }
}

int main()
{
	StringBasic();
	//StringAndCharArray();
	//ForeachString1();
	//ForeachString2();
	return 0;
}
