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
 * 自定义方法计算字符串长度
 */
int Strlen(const char* str)
{
    if(NULL == str)
    {
        return -1;
    }
    int l = 0;
    while (str[l] != '\0')
    {
        l++;
    }
    return l;
}

/**
 * 测试自定义方法计算字符串长度
 */
void MyStrlenTest()
{
    const char* str = "hello world";
    int length = Strlen(str);
    printf("自定义函数 length = %d\n", length);
}

/**
 * @desc 字符串拷贝函数
 * @param dest 目的字符串数组
 * @param src 源字符串数组
 * @return 返回拷贝后的目的地内存块的起始地址
 * @tips 1.必须要保证第一个参数的长度不小于第二个参数，否则虽然不会报错，但会溢出第一个字符串变量的边界，发生难以预料的结果。 2.第二个参数被const修饰，表示这个函数不会修改第二个字符串。
 * char * strcpy ( char * dest, const char * src )
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
    p = strcpy(dest_2 + 7, src_2);
    // 使用puts()输出字符串
    /*
    puts(src_2);
    puts(dest_2);
    puts(p);
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
 * 自定义的字符串拷贝函数
 * @param dest 目标字符串
 * @param src  源字符串
 * @return
 */
char* Strcpy(char* dest, const char* src)
{
    char* ptr = dest;
    while (*dest++ = *src++);
    return ptr;
}

/**
 * 自己编写算法实现字符串拷贝
 */
void MyStrcpyTest()
{
    char src[] = "hello world";
    char dest[25];
    Strcpy(dest, src);
    printf("dest = %s\n", dest);
}

/**
* @desc 字符串拷贝函数
* @param dest 目的字符串数组
* @param src 源字符串数组
* @param n 要复制的字符数
* @return 返回拷贝后的目的地内存块的起始地址
* @tips 1.第三个参数n定义了复制的最大字符数。如果达到最大字符数以后，源字符串仍然没有复制完，就会停止复制，这时目的字符串结尾将没有终止符'\0'，这一点务必
*         注意。如果源字符串的字符数小于n，则strncpy()的行为与strcpy()完全一致。需要手动在dest字符串中添加结尾符'\0'
*       2.strncpy()也可以用来拷贝部分字符串
* char * strncpy( char * dest, const char * src, size_t n );
*/
void StrncpyTest()
{
    char* p = NULL;

    // 使用strncpy()完成字符串赋值
    char src_1[] = "Hello, world!";
    // 特别注意：dest_1数组的长度要大于等于sizeof(src_1)，否则会出问题
    char dest_1[100];
    p = strncpy(dest_1, src_1, 14);
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

    // 使用strncpy()完成字符串赋值：从s2的第7个位置开始接收拷贝过来的字符串 BEST
    char* src_2 = "BEST";
    char dest_2[40] = "Be the best that you can be.";
    p = strncpy(dest_2 + 7, src_2, 4);
    // 使用puts()输出字符串
    /*
    puts(src_2);
    puts(dest_2);
    puts(p);
    */
    // 使用printf()输出字符串
    printf("src_2 = %s\n", src_2);
    printf("dest_2 = %s\n", dest_2);
    printf("p = %s\n", p);
}

/**
 * strncpy()：演示src字符串的长度超过了dest字符串的长度，参数n的最大值 sizeof(dest) - 1，因为要留一个字节的空间存储结尾符 '\0'
 */
void StrncpyTips1Test()
{
    char src[] = "Hello, world!";
    char dest[5];
    strncpy(dest, src, sizeof(dest) - 1);
    printf("dest = %s\n", dest);
}

/**
 * strncpy()：演示拷贝部分字符串
 */
void StrncpyTips2Test()
{
    char src[] = "Hello, world!";
    char dest[50];
    strncpy(dest, src, 5);
    printf("dest = %s\n", dest);
}

/**
 * @desc 函数用于连接字符串，接受两个字符串作为参数，把第二个字符串的副本添加到第一个字符串的末尾。这个函数会改变第一个字符串，但是第二个字符串不变。
 * @param str1 第一个字符串（字符数组类型的字符串变量）
 * @param str2 第二个字符串（字符数组类型的字符串变量）
 * @return 拼接后第一个字符串
 * @tips 1.参数要为字符数组类型的字符串变量，不能为指针类型的字符串变量，如果使用指针类型的字符串变量，会报错
 * char* strcat(char* str1, const char* str2);
 */
void StrcatTest()
{
    char str1[12] = "hello";
    char str2[6] = "world";
    strcat(str1, str2);
    puts(str1); // "helloworld"
}

/**
 * @desc 函数用于连接字符串，接受两个字符串作为参数，把第二个字符串的副本添加到第一个字符串的末尾。这个函数会改变第一个字符串，但是第二个字符串不变。
 * @param str1 第一个字符串（字符数组类型的字符串变量）
 * @param str2 第二个字符串（字符数组类型的字符串变量）
 * @param count 最大添加的字符数
 * @return 拼接后第一个字符串
 * @tips 1.参数要为字符数组类型的字符串变量，不能为指针类型的字符串变量，如果使用指针类型的字符串变量，会报错
 *       2.strncat()总是会在拼接结果的结尾，自动添加空字符\0，所以第三个参数的最大值，应该是str1的变量长度减去str1的字符串长度，再减去1
 * char* strcat(char* str1, const char* str2, size_t count);
 */
void StrncatTest()
{
    char str1[12] = "hello";
    char str2[6] = "world";
    strncat(str1, str2, 3);
    puts(str1); // "hellowor"
}

/**
 * 下面示例中，str1的变量长度是10，字符长度是6，两者相减后再减去1，得到3，表明str1最多可以再添加3个字符，所以得到的结果是MondayTue。
 * 注意：即使count的值设置为5，大于3了，程序可执行，并且不会报错，但是拼接出来的str1没有结尾符'\0'，这个只是一个字符数组，并不是一个字符串，由此可见，c语言很自由，很多地方依赖程序员自己控制
 */
void StrncatTips2Test()
{
    char str1[10] = "Monday";
    char str2[8] = "Tuesday";
    strncat(str1, str2, 3);
    puts(str1); // "MondayTue"
}

/**
 * memcpy()：数组复制
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
 * memcpy()：数组复制
 */
void MemcpyTest2()
{
	char src[] = "hello world";
	char* dest = (char*)malloc((int)sizeof(char) * (int)sizeof(src));;

	/**
	 * void* memcpy(void *dest, const void *src, size_t n)
	 * dest-- 指向用于存储复制内容的目标数组，类型强制转换为 void* 指针
     * src -- 指向要复制的数据源，类型强制转换为 void* 指针
     * n-- 要被复制的字节数
	 */
	memcpy(dest, src, (int)sizeof(char) * (int)sizeof(src));
	printf("dest = %s\n", dest);
}

/**
 * strcmp()：字符串比较（实际上是按位比较字符的ASCII码）
 */
void StrCmpTest()
{
    const char* str1 = "abcde";
    const char* str2 = "abcde";
    int r = strcmp(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abxde";
    r = strcmp(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abcdea";
    r = strcmp(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abxde";
    str2 = "abcde";
    r = strcmp(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcdea";
    str2 = "abcde";
    r = strcmp(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
}

int main()
{
    //StrlenTest();
    //MyStrlenTest();
    //StrcpyTest();
    //MyStrcpyTest();
    //StrncpyTest();
    //StrncpyTips1Test();
    //StrncpyTips2Test();
    //StrcatTest();
    //StrncatTest();
    //StrncatTips2Test();
	//MemcpyTest1();
	//MemcpyTest2();
    StrCmpTest();
	return 0;
}
