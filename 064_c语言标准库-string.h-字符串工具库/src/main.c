#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * strlen(str)：函数返回字符串的字节长度，不包括末尾的空字符'\0'
 */
void StrlenTest()
{
    char* str = "hello";
    int len = strlen(str);
    printf("len = %d\n", 5);

    char s[50] = "hello";
    printf("%llu\n", strlen(s));
    printf("%llu\n", sizeof(s));
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
    StrlenTest();
	//MemcpyTest1();
	MemcpyTest2();
	return 0;
}
