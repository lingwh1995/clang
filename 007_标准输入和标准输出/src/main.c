//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>

/*
 * 标准输入:
 *	1.getchar()：输入单个字符，保存到字符变量中
 *  2.gets()：输入一行数据，保存到字符串变量中
 *  3.scanf()：格式化输入函数，一次可以输入多个数据，保存到多个变量中
 *		解决c4996 scanf警告：
 *			1.在.c文件第一行引入宏定义: #define _CRT_SECURE_NO_WARNINGS
 *			2.在.c文件第一行引入预编译指令:	#pragma warning(disable:4996)
 *		
 *	gets()和scanf()区别
 *		1.gets()接收的字符串中间可以有空格,scanf()接收的字符串中间不能有空格
 *		2.get()会清空缓冲区的换行符,scanf()不会清空缓冲区的换行符
 * 
 * 标准输出:
 *  1.putchar()：输出单个字符，返回值为输出的数值
 *  2.puts()：输出字符串，主要用于简单输出
 *  3.printf()：格式化输出函数，可输出常量、变量等,主要用于格式化输出
 * 
 * ASCII码形式输出和转义字符串输出：
 *	1.ASCII码形式输出: 将一个字符以ASCII码形式输出
 *  2.转义字符串输出: 输出转义后的字符
 * 
 * 
 * 关于double类型数据的特殊处理:
 *	输出double类型,使用%f即可: 而scanf读取double类型,必须使用%lf防止精度丢失
 */

/*
 * 测试getchar()
 */
void GetCharTest()
{
	printf("请输入单个字符: \n");
	char c = getchar();
	printf("字符类型输出: c = %c\n", c);
	printf("ASCII码输出: c = %d\n", c);
}

/*
 * 测试gets()
 */
void GetsTest1()
{
	printf("请输入字符串: \n");
	// 必须规定字符串的长度,否则会报异常
	char str[5] = "\0";
	gets(str);
	printf("str = %s\n", str);
}

/*
 * 测试gets()
 */
void GetsTest2()
{
	printf("请输入字符串: \n");
	// 必须规定字符串的长度,否则会报异常
	char str[30];
	// 一定要先将指针变量初始化
	char* string = str;
	// 也可以写成gets(str);
	gets(string);
	// 输出参数是已经定义好的"指针变量名"
	printf("%s\n", string);
}

/*
 * 测试scanf()
 */
void ScanfTest1()
{
	int i;
	float f;
	char c;
	printf("请输入字符串(使用空格隔开):\n");
	scanf("%d %f %c", &i, &f, &c);
	printf("i = %d, f = %f, c = %c\n", i, f, c);
}

/*
 * 测试scanf()
 */
void ScanfTest2()
{
	printf("请输入字符串: \n");
	// 必须规定字符串的长度,否则会报异常
	char str[30];
	scanf("%s", &str);
	printf("str = %s\n", str);
}

/*
 * 测试scanf()
 */
void ScanfTest3()
{
	printf("请输入double类型数据: \n");
	double d;
	scanf("%lf", &d);
	printf("d = %f\n", d);
}

/**
 * 测试scanf()返回值是 成功读取并正确赋值的变量数量
 */
void ScanfTest4()
{
    int i, j, k;
    k = scanf("%d %d", &i, &j);
    printf("k = %d\n", k);
}

/*
 * 测试get()和scanf()
 *	输入数据: i love you
 *  gets()接收到: i love you
 *  scanf()接收到: i
 */
void GetsAndScanfTest1()
{
	printf("请输入字符串(使用空格隔开): \n");
	char str_1[30];
	gets(str_1);
	printf("str_1 = %s\n", str_1);
	printf("请输入字符串(使用空格隔开): \n");
	// 必须规定字符串的长度,否则会报异常
	char str_2[30];
	scanf("%s", &str_2);
	printf("str_2 = %s\n", str_2);
}

/*
 * 测试get()和scanf()
 *  1.程序运行结果
 *		请输入数据:
 *		a
 *		str = a
 *		1
 *		c = 1
 *		c =
 *  2.get()会清空缓冲区的换行符,scanf()不会清空缓冲区的换行符
 */
void GetsAndScanfTest2()
{
	printf("请输入数据: \n");
	char str[30];
	gets(str);
	printf("str = %s\n", str);
	char c;
	scanf("%c",&c);
	printf("c = %c\n", c);
	// 第二个scanf()直接接收了缓冲区中的换行符,无法接收用户输入的内容
	scanf("%c", &c);
	printf("c = %c\n", c);
}

/*
 * 测试putchar()
 */
void PutCharTest()
{
	putchar('\101');//代表十进制的65，或者字母A
	putchar('\x42');//代表十进制的66，或者字母B,补充a为97
	char c = 'C';
	putchar(c);

	int sum = 0;
	sum = putchar('A');
	printf("%d", sum);

}

/*
 * 测试puts()
 */
void PutsTest()
{
	char name[] = "祖国!";
	// 用printf输出
	printf("%s\n", name);
	// 用puts()输出
	puts(name);
	// 直接输出字符串
	puts("我爱你!");
}

/*
 * 测试printf()
 */
void PrintfTest()
{
	// 输出不同进制
	int a = 10;
	printf("十进制=%d 八进制=%o 十六进制=%x\n", a, a, a);

	// 输出不同数据类型
	int b = 1;
	float f = 3.14;
	char c = 'a';
	printf("a = %d, f = %f, c = %c\n", b, f, c);

	// 设置输出宽度
	printf("%d%d\n", a, b);
	printf("%5d%d\n", a, b);
	printf("%-5d%d\n", a, b);
}

/*
 * ASCII码形式输出和转义字符串输出
 */
void AsciiPrintfAndEscapePrintfTest()
{
	/*
	 *ASCII码形式输出
	 */
	char c = 'a';
	// 输出字符常量
	printf("原字符a = %c\n", c);
	// 以ASCII码形式输出
	printf("原字符a的ASCII码 = %d\n", c);


	/**
	 * 转义字符串输出
	 */
	char c1 = '\t';
	printf("+%c+\n", c1);
	// 输出反斜杠
	printf("\\");
	printf("\n");
	// 输出双引号
	printf("\"");
	printf("\n");

	/**
	 * 8进制和16进制转义
	 *      8进制: \102
	 *      16进制: \x42
	 */
	printf("字符'B'的十进制表示:%d\n", 'B');
	printf("字符'B'(八进制数0102)的十进制表示:%d\n", 0102);
	printf("8进制的转义:\102\n");
	printf("16进制的转义:\x42\n");
}

/**
 * 计算三角形面积
 */
void CalcAreaofTriangle()
{
	printf("请输入三角形的三条边的长度:\n");
	float a = 0, b = 0, c = 0, p = 0, s = 0;
	scanf("%f %f %f", &a, &b, &c);
	p = (a + b + c) / 2;
	s = sqrt(p * (p - a) * (p - b) * (p - c));
	printf("三角形面积 s = %f", s);
}


#if 0
// 标准输入输出的基本测试
int main()
{
	//GetCharTest();
	//GetsTest1();
	//GetsTest2();
	//ScanfTest1();
	//ScanfTest2();
	//ScanfTest3();
	//ScanfTest4();
	//GetsAndScanfTest1();
	//GetsAndScanfTest2();
	//PutCharTest();
	//PutsTest();
	//PrintfTest();
	//AsciiPrintfAndEscapePrintfTest();
	CalcAreaofTriangle();
	return 0;
}
#endif
