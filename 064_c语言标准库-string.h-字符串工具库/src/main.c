#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * size_t strlen(const char *_Str)：返回字符串的字节长度，不包括末尾的空字符'\0'
 */
void StrlenTest()
{
    char* s1 = "hello";
    printf("strlen(s1) = %llu\n", strlen(s1));

    char s2[50] = "hello";
    printf("strlen(s2) = %llu\n", strlen(s2));
    printf("sizeof(s2) = %llu\n", sizeof(s2));
}

/**
 * @desc 字符串拷贝函数
 * @param destination 目的字符串数组
 * @param source 源字符串数组
 * @return 返回指向目标字符串destination的指针
 * @tips 1.必须要保证第一个参数的长度不小于第二个参数，否则虽然不会报错，但会溢出第一个字符串变量的边界，发生难以预料的结果。 2.第二个参数被const修饰，表示这个函数不会修改第二个字符串。
 * char * strcpy ( char * destination, const char * source )
 */
void StrcpyTest()
{
    // 错误的字符串复制方式一：因为字符串一旦定义，字符串的地址值不能再发生改变，定义后再去赋值编译无法通过
    /*
    char str1[10];
    char str2[10];
    str1 = "abc"; // 报错
    str2 = str1;  // 报错
    */

    // 错误的字符串复制方式二：只是将s1所代表的地址值赋值给s2了，并没有将s1指向的内容复制给s2
    /*
    char* s1;
    char* s2;
    s1 = "abc";
    s2 = s1;
    */

    char* p = NULL;

    // 使用strcpy()完成字符串赋值
    char src_1[] = "Hello, world!";
    printf("sizeof(src_1) = %llu\n", sizeof(src_1));
    // 特别注意：dest_1数组的长度要大于等于sizeof(src_1)，否则会出问题
    char dest_1[100];
    p = strcpy(dest_1, src_1);
    dest_1[0] = 'O';
    // 使用puts()输出字符串
    /*
    puts(src_1);
    puts(dest_1);
    puts(p);
    */
    // 使用printf()输出字符串
    printf("src_1 = %s\n", src_1);
    printf("dest_1 = %s\n", dest_1);
    printf("p = %s\n", p);
    printf("---------------------\n");

    // 使用strcpy()完成字符串赋值：从s2的第7个位置开始接收拷贝过来的字符串 BEST
    char* src_2 = "BEST";
    char dest_2[40] = "Be the best that you can be.";
    // strcpy()返回的是一个指针，指向拷贝开始的位置。
    p = strcpy(dest_2 + 7, src_2);
    // 使用puts()输出字符串
    /*
    puts(src_2); // BEST
    puts(dest_2); // Be the BEST
    puts(p); // BEST
    */
    // 使用printf()输出字符串
    printf("src_2 = %s\n", src_2);
    printf("dest_2 = %s\n", dest_2);
    printf("p = %s\n", p);

    /**
     * strcpy()的第一个参数最好是一个已经声明的数组，而不是声明后没有进行初始化的字符指针。
     */
    /*
    char* str;
    strcpy(str, "hello world"); // 错误
    */
}

/**
 * 测试memcpy()函数
 */
void MemcpyTest1()
{
	int src[] = { 1,2,3,4,5,6,7,8,9,0 };
	int dest[20] = { 0 };

	/**
	 * void* memcpy(void *dest, const void *src, size_t n)
	 * dest-- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针
	 * src -- 指向要复制的数据源，类型强制转换为 void* 指针
	 * n-- 要被复制的字节数
	 */
	memcpy(dest, src, 16); // 会复制 1,2,3,4 这四个数，因为一个int类型数据占4个字节

	//此处的16代表着16个字节，而我们访问的数组是int型，所以此处拷贝的是4个元素
	for (int i = 0; i < 20; i++)
	{
		printf("%d ", dest[i]);
	}
}

/**
 * 测试memcpy()函数
 */
void MemcpyTest2()
{
	char src[] = "hello world";
	char* dest = (char*)malloc(sizeof(char) * sizeof(src));;

	/**
	 * void* memcpy(void *dest, const void *src, size_t n)
	 * dest-- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针
     * src -- 指向要复制的数据源，类型强制转换为 void* 指针
     * n-- 要被复制的字节数
	 */
	memcpy(dest, src, sizeof(char) * sizeof(src));
	printf("dest = %s\n", dest);
}

int main()
{
    //StrlenTest();
    StrcpyTest();
	//MemcpyTest1();
	//MemcpyTest2();
	return 0;
}
