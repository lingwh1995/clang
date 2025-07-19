#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/**
 * size_t strlen(const char *_Str)：返回字符串的字节长度，不包括末尾的空字符'\0'
 */
void strlen_test()
{
    char* s1 = "hello";
    printf("strlen(s1) = %ld\n", strlen(s1));

    char s2[50] = "hello";
    printf("strlen(s2) = %ld\n", strlen(s2));
    printf("sizeof(s2) = %ld\n", sizeof(s2));
}

/**
 * 自定义方法计算字符串长度方式一
 *
 * @param str 要计算长度的字符串
 */
int my_strlen_1(const char* str)
{
    if(NULL == str)
    {
        return -1;
    }
    // 或
    //assert(NULL != str);
    int l = 0;
    while (str[l] != '\0')
    {
        l++;
    }
    return l;
}

/**
 * 测试自定义方法计算字符串长度方式一
 */
void my_strlen_1_test()
{
    const char* str = "hello world";
    int length = my_strlen_1(str);
    printf("自定义函数 length = %d\n", length);
}


/**
 * 自定义方法计算字符串长度方式二：利用指针相减的特性
 *
 * @param str 要计算长度的字符串
 */
int my_strlen_2(const char* str)
{
    if(NULL == str)
    {
        return -1;
    }
    // 或
    //assert(NULL != str);
    char* cp = (char*)str;
    while(*cp != '\0')
    {
        cp++;
    }
    return (int)(cp - str);
}

/**
 * 测试自定义方法计算字符串长度方式二：利用指针相减的特性
 */
void my_strlen_2_Test()
{
    const char* str = "hello world";
    int length = my_strlen_2(str);
    printf("自定义函数 length = %d\n", length);
}

/**
 * 字符串拷贝函数
 *
 * @param dest 目的字符串数组
 * @param src 源字符串数组
 * @return 返回拷贝后的目的地内存块的起始地址
 * @tips 1.必须要保证第一个参数的长度不小于第二个参数，否则虽然不会报错，但会溢出第一个字符串变量的边界，发生难以预料的结果。 2.第二个参数被const修饰，表示这个函数不会修改第二个字符串。
 * char * strcpy ( char * dest, const char * src )
 */
void strcpy_test()
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
    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);
    */

    char* p = NULL;

    // 使用strcpy()完成字符串赋值
    char src_1[] = "Hello, world!";
    // 特别注意：dest_1数组的长度要大于等于sizeof(src_1)，否则会出问题
    char dest_1[100];
    p = strcpy(dest_1, src_1);
    dest_1[0] = 'X';
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
    /**/
    // strcpy()的连续赋值
    char s1[] = "a1";
    char s2[] = "b2";
    char s3[] = "c3";
    strcpy(s1,strcpy(s2, s3));
    puts(s1);
    //printf("s1 = %s\n", s1);
}

/**
 * 自定义的字符串拷贝函数
 *
 * @param dest 目标字符串
 * @param src  源字符串
 * @return
 */
char* my_strcpy_1(char* dest, const char* src)
{
    if(NULL == dest || NULL == src)
    {
        return NULL;
    }
    // 或
    //assert(NULL != str1 && NULL != str2);
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/**
 * 自定义方法编写算法实现字符串拷贝
 */
void my_strcpy_1_test()
{
    char src[] = "hello world";
    char dest[25];
    my_strcpy_1(dest, src);
    printf("dest = %s\n", dest);
}

/**
 * 自定义的字符串拷贝函数
 *
 * @param dest 目标字符串
 * @param src  源字符串
 * @return
 */
char* my_strcpy_2(char* dest, const char* src)
{
    if(NULL == dest || NULL == src)
    {
        return NULL;
    }
    // 或
    //assert(NULL != str1 && NULL != str2);
    // 把const char*类型转为char*
    char* ptr = (char*)dest;
    // 当复制到结尾符 '\0' 的时候，代码相当于 while('\0')， '\0' 的ASCII码是0，所以为假
    while (*dest++ = *src++);
    return ptr;
}

/**
 * 自定义方法编写算法实现字符串拷贝
 */
void my_strcpy_2_test()
{
    char src[] = "hello world";
    char dest[25];
    my_strcpy_2(dest, src);
    printf("dest = %s\n", dest);
}

/**
* 字符串拷贝函数
*
* @param dest 目的字符串数组
* @param src 源字符串数组
* @param n 要复制的字符数
* @return 返回拷贝后的目的地内存块的起始地址
* @tips 1.第三个参数n定义了复制的最大字符数。如果达到最大字符数以后，源字符串仍然没有复制完，就会停止复制，这时目的字符串结尾将没有终止符'\0'，这一点务必
*         注意。如果源字符串的字符数小于n，则strncpy()的行为与strcpy()完全一致。需要手动在dest字符串中添加结尾符'\0'
*       2.strncpy()也可以用来拷贝部分字符串
* char * strncpy( char * dest, const char * src, size_t n );
*/
void strncpy_test_1()
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
void strncpy_test_2()
{
    char src[] = "Hello, world!";
    char dest[5];
    strncpy(dest, src, sizeof(dest) - 1);
    printf("dest = %s\n", dest);
}

/**
 * strncpy()：演示拷贝部分字符串
 */
void strncpy_test_3()
{
    char src[] = "Hello, world!";
    char dest[50];
    strncpy(dest, src, 5);
    printf("dest = %s\n", dest);
}

/**
 * 函数用于连接字符串，接受两个字符串作为参数，把第二个字符串的副本添加到第一个字符串的末尾。这个函数会改变第一个字符串，但是第二个字符串不变。
 *
 * @param str1 第一个字符串（字符数组类型的字符串变量）
 * @param str2 第二个字符串（字符数组类型的字符串变量）
 * @return 拼接后第一个字符串
 * @tips 1.参数要为字符数组类型的字符串变量，不能为指针类型的字符串变量，如果使用指针类型的字符串变量，会报错
 * char* strcat(char* str1, const char* str2);
 */
void strcat_test()
{
    char str1[12] = "hello";
    char str2[6] = "world";
    strcat(str1, str2);
    puts(str1); // "helloworld"

    char str3[12] = "hello";
    char str4[6] = "world";
    char str5[6] = "abc";
    strcat(strcat(str3, str4), str5);
    puts(str3); // "helloworldabc"
}

/**
 * 自定义方法实现字符串拷贝
 */
char* my_strcat_1(char* dest, const char* src)
{
    if(NULL == dest || NULL == src)
    {
        return NULL;
    }
    char* cp = dest + strlen(dest);
    strcpy(cp, src);
    return dest;
}

/**
 * 测试自定义方法实现字符串连接
 */
void my_strcat_1_test()
{
    char str1[12] = "hello";
    char str2[6] = "world";
    my_strcat_1(str1, str2);
    puts(str1); // "helloworld"
}

/**
 * 自定义方法实现字符串拷贝
 */
char* my_strcat_2(char* dest, const char* src)
{
    if(NULL == dest || NULL == src)
    {
        return NULL;
    }
    while(*dest != '\0')
    {
        dest++;
    }
    while(*dest = *src)
    {
        // 打印的是右边的值，因为是将右边的值赋值给左边的值
        printf("%c\n", (*dest = *src));
        dest++;
        src++;
    }
    return dest;
}

/**
 * 测试自定义方法实现字符串连接
 */
void my_strcat_2_test()
{
    char str1[12] = "hello";
    char str2[6] = "world";
    my_strcat_2(str1, str2);
    puts(str1); // "helloworld"
}

/**
 * 函数用于连接字符串，接受两个字符串作为参数，把第二个字符串的副本添加到第一个字符串的末尾。这个函数会改变第一个字符串，但是第二个字符串不变。
 *
 * @param str1 第一个字符串（字符数组类型的字符串变量）
 * @param str2 第二个字符串（字符数组类型的字符串变量）
 * @param count 最大添加的字符数
 * @return 拼接后第一个字符串
 * @tips 1.参数要为字符数组类型的字符串变量，不能为指针类型的字符串变量，如果使用指针类型的字符串变量，会报错
 *       2.strncat()总是会在拼接结果的结尾，自动添加空字符\0，所以第三个参数的最大值，应该是str1的变量长度减去str1的字符串长度，再减去1
 * char* strcat(char* str1, const char* str2, size_t count);
 */
void strncat_test_1()
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
void strncat_test_2()
{
    char str1[10] = "Monday";
    char str2[8] = "Tuesday";
    strncat(str1, str2, 3);
    puts(str1); // "MondayTue"
}

/**
 * memcpy()：数组复制
 */
void memcpy_test_1()
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
void memcpy_test_2()
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
void strcmp_test()
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

/**
 * 自定义方法实现字符串比较
 *
 * @param str1 第一个字符串
 * @param str2 第二个字符串
 */
int my_strcmp_1(const char* str1, const char* str2)
{
    if(NULL == str1 || NULL == str2)
    {
        return -1;
    }
    // 或
    //assert(NULL != str1 && NULL != str2);
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

/**
 * 测试自定义方法实现字符串比较
 */
void my_strcmp_1_test()
{
    const char* str1 = "abcde";
    const char* str2 = "abcde";
    int r = my_strcmp_1(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abxde";
    r = my_strcmp_1(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abcdea";
    r = my_strcmp_1(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abxde";
    str2 = "abcde";
    r = my_strcmp_1(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcdea";
    str2 = "abcde";
    r = my_strcmp_1(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
}

/**
 * 自定义方法实现字符串比较
 *
 * @param str1 第一个字符串
 * @param str2 第二个字符串
 */
int my_strcmp_2(const char* str1, const char* str2)
{
    if(NULL == str1 || NULL == str2)
    {
        return -1;
    }
    // 或
    //assert(NULL != str1 && NULL != str2);
    int k = 0;
    while (((k = *str1 -*str2) == 0) && *str1++ && *str2++);
    return k;
}

/**
 * 测试自定义方法实现字符串比较
 */
void my_strcmp_2_test()
{
    const char* str1 = "abcde";
    const char* str2 = "abcde";
    int r = my_strcmp_2(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abxde";
    r = my_strcmp_2(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abcdea";
    r = my_strcmp_2(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abxde";
    str2 = "abcde";
    r = my_strcmp_2(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcdea";
    str2 = "abcde";
    r = my_strcmp_2(str1, str2);
    printf("str1和str2比较结果： %d\n", r);
}

/**
 * strncmp()：字符串比较（实际上是按位比较字符的ASCII码）
 */
void strncmp_test()
{
    const char* str1 = "abcde";
    const char* str2 = "abcde";
    int r = strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abxde";
    r = strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abcdea";
    r = strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abxde";
    str2 = "abcde";
    r = strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcdea";
    str2 = "abcde";
    r = strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
}

/**
 * 自定义方法实现字符串中前n个字符比较
 *
 * @param str1 第一个字符串
 * @param str2 第二个字符串
 * @param n 比较到第几个位置就结束比较
 */
int my_strncmp(const char* str1, const char* str2, size_t n)
{
    if(NULL == str1 || NULL == str2 || 0 == n)
    {
        return -1;
    }
    // 或
    //assert(NULL != str1 && NULL != str2 && 0 != n);
    while (--n > 0 && *str1 != '\0' && *str2 != '\0' && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

/**
 * 测试自定义方法实现字符串中前n个字符比较
 */
void my_strncmp_test()
{
    const char* str1 = "abcde";
    const char* str2 = "abcde";
    int r = my_strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abxde";
    r = my_strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcde";
    str2 = "abcdea";
    r = my_strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abxde";
    str2 = "abcde";
    r = my_strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
    str1 = "abcdea";
    str2 = "abcde";
    r = my_strncmp(str1, str2, 3);
    printf("str1和str2比较结果： %d\n", r);
}

/**
 * 从头到尾在一个字符串中查找给定字符的第一个匹配之处
 *
 * @param str 给定字符串
 * @param c 给定字符
 * @return 如果找到字符c，则返回指向该字符在字符串中第一次出现位置的指针。如果未找到字符c，则返回NULL指针。
 * char *strchr (const char *str, int c)
 */
void strchr_test()
{
    const char* str = "abccde";
    char* p = strchr(str, 'c');
    printf("数组地址 = %p\n", str);
    printf("字符地址 = %p\n", p);
    if(NULL != p)
    {
        printf("%c\n", *p);
    }
    else
    {
        printf("字符串中没有这个字符...\n");
    }
}

/**
 * 自定义方法实现从头到尾在一个字符串中查找给定字符的第一个匹配之处
 *
 * @param str
 * @param c
 * @return
 */
char* my_strchr(const char *str, int c)
{
    if(NULL == str)
    {
        return NULL;
    }
    // 特别注意这个写法：需要把str做一个类型转化，把const char*转成char*类型
    char* p = (char*)str;
    while ('\0' != *p && *p != c)
    {
        p++;
    }
    if('\0' == *p)
    {
        p = NULL;
    }
    return p;
}

/**
 * 测试自定义方法实现从头到尾在一个字符串中查找给定字符的第一个匹配之处
 */
void my_strchr_test()
{
    const char* str = "abccde";
    char* p = my_strchr(str, 'c');
    printf("数组地址 = %p\n", str);
    printf("字符地址 = %p\n", p);
    if(NULL != p)
    {
        printf("%c\n", *p);
    }
    else
    {
        printf("字符串中没有这个字符...\n");
    }
}

/**
 * char *strchr (const char *str, int c)：从尾到头在一个字符串中查找给定字符的第一个匹配之处
 */
void strrchr_test()
{
    const char* str = "abccde";
    char* p = strrchr(str, 'c');
    printf("数组地址 = %p\n", str);
    printf("字符地址 = %p\n", p);
    if(NULL != p)
    {
        printf("%c\n", *p);
    }
    else
    {
        printf("字符串中没有这个字符...\n");
    }
}

/**
 * 自定义方法实现从尾到头在一个字符串中查找给定字符的第一个匹配之处
 *
 * @param str
 * @param c
 * @return
 */
char* my_strrchr_1(const char *str, int c)
{
    if(NULL == str)
    {
        return NULL;
    }
    // 特别注意这个写法：需要把str做一个类型转化，把const char*转成char*类型
    char* p = (char*)str;
    p = p + strlen(str) - 1;
    // 注意：字符串是以 '\0' 结尾的，所以最后一个字符 = *(str-1)
    while ((str-1) != p)
    {
        if(*p == c)
        {
            return p;
        }
        p--;
    }
    return NULL;
}

/**
 * 测试自定义方法实现从头到尾在一个字符串中查找给定字符的第一个匹配之处
 */
void my_strrchr_1_test()
{
    const char* str = "abccde";
    char* p = my_strrchr_1(str, 'c');
    printf("数组地址 = %p\n", str);
    printf("字符地址 = %p\n", p);
    if(NULL != p)
    {
        printf("%c\n", *p);
    }
    else
    {
        printf("字符串中没有这个字符...\n");
    }
}

/**
 * 自定义方法实现从尾到头在一个字符串中查找给定字符的第一个匹配之处
 *
 * @param str
 * @param c
 * @return
 */
char* my_strrchr_2(const char *str, int c)
{
    if(NULL == str)
    {
        return NULL;
    }
    // 特别注意这个写法：需要把str做一个类型转化，把const char*转成char*类型
    char* p = (char*)str;
    p = p + strlen(str);
    // 注意：字符串是以 '\0' 结尾的，所以最后一个字符 = *(str-1)
    while (str != p)
    {
        if(*(p - 1) == c)
        {
            return p - 1;
        }
        p--;
    }
    return NULL;
}

/**
 * 测试自定义方法实现从头到尾在一个字符串中查找给定字符的第一个匹配之处
 */
void my_strrchr_2_test()
{
    const char* str = "abccde";
    char* p = my_strrchr_2(str, 'c');
    printf("数组地址 = %p\n", str);
    printf("字符地址 = %p\n", p);
    if(NULL != p)
    {
        printf("%c\n", *p);
    }
    else
    {
        printf("字符串中没有这个字符...\n");
    }
}

/**
 * char *strchr (const char *str, const char *substr)： 从尾到头在一个字符串中查找给定子串的第一个匹配之处
 */
void strstr_test()
{
    const char *str = "onetwothree";
    const char *substr = "two";
    char* p = strstr(str,substr);
    if(NULL != p)
    {
        printf("%s\n", p);
    }
    else
    {
        printf("不匹配\n");
    }
}

/**
 * 自定义方法实现从尾到头在一个字符串中查找给定子串的第一个匹配之处
 *
 * @param str 给定字符串
 * @param substr 给定子串
 * @return 如果找到子符substr，则返回指向该子串在字符串中第一次出现位置的指针。如果未找到子串substr，则返回NULL指针。
 */
char* my_strstr_1(const char *str, const char *substr) {
    if (NULL == str || NULL == substr) {
        return NULL;
    }
    if(strlen(str) < strlen(substr))
    {
        return NULL;
    }
    int m = strlen(str);
    int n = strlen(substr);
    for(int i = 0; i < m - n + 1; i++)
    {
        // 每次开始比较时j指针回退到0位置
        int j = 0;
        // 每次开始比较时k指针的值取i指针的之，且将k指针回退到0位置，
        int k = i;
        while (str[k] == substr[j] && j < n)
        {
            k++;
            j++;
        }
        if(j == n)
        {
            return (char *) str + i;
        }
    }
    return NULL;
}

/**
 * 测试自定义方法实现从尾到头在一个字符串中查找给定子串的第一个匹配之处
 */
void my_strstr_1_test()
{
    const char *str = "abccabcabbc";
    const char *substr = "abca";
    char* p = my_strstr_1(str,substr);
    if(NULL != p)
    {
        printf("%s\n", p);
    }
    else
    {
        printf("不匹配\n");
    }
}

/**
 * 自定义方法实现从尾到头在一个字符串中查找给定子串的第一个匹配之处
 *
 * @param str 给定字符串
 * @param substr 给定子串
 * @return 如果找到子符substr，则返回指向该子串在字符串中第一次出现位置的指针。如果未找到子串substr，则返回NULL指针。
 */
char* my_strstr_2(const char *str, const char *substr) {
    if (NULL == str || NULL == substr) {
        return NULL;
    }
    if(strlen(str) < strlen(substr))
    {
        return NULL;
    }
    int m = strlen(str);
    int n = strlen(substr);
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if(str[i] == substr[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if(j == n)
    {
        return (char *)str + i - j;
    }
    return NULL;
}

/**
 * 测试自定义方法实现从尾到头在一个字符串中查找给定子串的第一个匹配之处
 */
void my_strstr_2_test()
{
    const char *str = "abccabcabbc";
    const char *substr = "cca";
    char* p = my_strstr_2(str,substr);
    if(NULL != p)
    {
        printf("%s\n", p);
    }
    else
    {
        printf("不匹配\n");
    }
}

/**
 * 测试将字符串转换为小写格式
 */
void strlwr_test()
{
    char s[] = "AbC";
    printf("s = %s\n", strlwr(s));
}

/**
 * 测试将字符串转换为大写格式
 */
void strupr_test()
{
    char s[] = "AbC";
    printf("s = %s\n", strupr(s));
}

/**
 * 测试字符串复制函数strdup
 * 注意事项：
 *     strdup 的可移植性：非C标准函数，需确保环境支持（如Windows需 _strdup）
 *     内存泄漏：strdup 返回的指针必须用 free() 释放
 *     错误处理：strdup 可能返回 NULL，需检查后再使用
 */
void strdup_test()
{
    const char* original = "Hello World!";
    char *duplicate = strdup(original);
    if(NULL != duplicate)
    {
        printf("original  = %s\n", original);
        printf("duplicate = %s\n", duplicate);
        // strdup使用malloc分配内存，因此要使用free函数来释放这块儿内存，以避免内存泄漏
        free(duplicate);
    }
    else
    {
        printf("Memory allocate failed\n");
    }
}

/**
 * 自定义方法实现strdup方式字符串复制
 *
 * @param	str
 * @return
 */
char* my_strdup(const char* str)
{
    if(NULL == str)
    {
        return NULL;
    }
    int len = strlen(str) + 1;
    char* dest = (char*)malloc(sizeof(char) * len);
    strcpy(dest, str);
    return dest;
}

/**
 * 测试自定义方法实现strdup方式字符串复制
 */
void my_strdup_test()
{
    const char* original = "Hello World!";
    char *duplicate = my_strdup(original);
    if(NULL != duplicate)
    {
        printf("original  = %s\n", original);
        printf("duplicate = %s\n", duplicate);
        // strdup使用malloc分配内存，因此要使用free函数来释放这块儿内存，以避免内存泄漏
        free(duplicate);
    }
    else
    {
        printf("Memory allocate failed\n");
    }
}

/**
 * void *memset(void *s, int c, size_t n): 初始化内存的"万能函数"，通常为新申请的内存进行初始化工作
 */
void memset_test()
{
	char str[10];
	// 使用数字10填充
	memset(str, 10, sizeof(str));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", str[i]);
	}
	printf("\n");

	// 使用字符'a'填充
	memset(str, 'a', sizeof(str));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", str[i]);
	}
	printf("\n");

	// 使用数字0填充
	memset(str, 0, sizeof(str));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", str[i]);
	}
	printf("\n");
}

/**
 * 自定义方法实现 memset
 *
 * @param vp 泛型指针
 * @param ch 要填充的类型
 * @param ch 要填充的长度
 */
char* my_memset(void* vp, unsigned char ch, size_t count)
{
	assert(vp != NULL);
	unsigned char* cp = (unsigned char*)vp;
	for(int i = 0; i < count; i++)
	{
		//cp[i] = ch; // *(cp+i) = ch;
		*cp = ch;
		cp = cp + 1;
	}
	return vp;
}

/**
 * 测试自定义方法实现 memset
 */
char* my_memset_test()
{
	char str[10];
	// 使用数字10填充
	my_memset(str, 10, sizeof(str));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", str[i]);
	}
	printf("\n");

	// 使用字符'a'填充
	my_memset(str, 'a', sizeof(str));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", str[i]);
	}
	printf("\n");

	// 使用数字0填充
	my_memset(str, 0, sizeof(str));
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", str[i]);
	}
	printf("\n");
}



/**
 * int memcmp(const void *str1, const void *str2, size_t n): 用于比较两块内存区域前n个字节内容的函数
 */
void memcmp_test()
{


}

/**
 * 自己实现的用于比较两块内存区域前n个字节内容的函数
 */
void my_memcmp(const void *str1, const void *str2, size_t n)
{

}

/**
 * 测试自己实现的用于比较两块内存区域前n个字节内容的函数
 */
void my_memcmp_test()
{

}

int main()
{
    //strlen_test();
    //my_strlen_1_test();
    //my_strlen_2_Test();
    //strcpy_test();
    //my_strcpy_1_test();
    //my_strcpy_2_test();
    //strncpy_test_1();
    //strncpy_test_2();
    //strncpy_test_3();
    //strcat_test();
    //my_strcat_1_test();
    //my_strcat_2_test();
    //strncat_test_1();
    //strncat_test_2();
	//memcpy_test_1();
	//memcpy_test_2();
    //strcmp_test();
    //my_strcmp_1_test();
    //my_strcmp_2_test();
    //strncmp_test();
    //my_strncmp_test();
    //strchr_test();
    //my_strchr_test();
    //strrchr_test();
    //my_strrchr_1_test();
    //my_strrchr_2_test();
    //strstr_test();
    //my_strstr_1_test();
    //my_strstr_2_test();
    //my_strstr_2_test();
    //strlwr_test();
    //strupr_test();
    //strdup_test();
    //my_strdup_test();
	//memset_test();
	my_memset_test();
	return 0;
}
