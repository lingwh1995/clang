#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <assert.h>

/**
 * 字符串转int类型数据函数
 *
 * int atoi(const char *str)
 * @param str 要被转换的字符串
 * @return    转换后的返回的int类型数据
 *
 * 优点：
 * 	 1.简洁快速：atoi()使用简单，能够快速将一个字符串转换为整数，适合简单的字符串解析任务
 * 	 2.自动跳过空白字符：在进行转换时，atoi()会自动跳过字符串开头的空格和其他空白字符
 * 缺点：
 *   1.没有错误处理：如果输入的字符串无法转换为有效的整数，atoi()会返回0，但无法明确区分是无效输入还是有效输入为0（如 "0"）
 *   2.无法处理溢出：atoi()不能处理数字溢出的情况。如果字符串表示的数字超出int类型的范围，atoi()的结果可能是不确定的
 *   3.不支持进制：atoi()只支持十进制字符串的转换，而不像strtol()函数那样支持多进制解析
 * 替代方案：strtol()
 */
void atoi_test()
{
	// 将字符串类型正整数转换为int类型正整数
	char* str = "100";
	int i = atoi(str);
	printf("i = %d\n", i);

	// 将字符串类型负整数转换为int类型负整数
	str = "-100";
	i = atoi(str);
	printf("i = %d\n", i);

	// 将字符串类型正整数+字母转换为int类型正整数，字符串"123abc"会转换成数字123
	str = "123abc";
	i = atoi(str);
	printf("i = %d\n", i);

	// 将字符串类型正整数+字母转换为int类型正整数，字符串"4 5 6"会转换成数字4
	str = "4 5 6";
	i = atoi(str);
	printf("i = %d\n", i);

	// 将字符串类型正整数+字母转换为int类型正整数，字符串" 7 8 9"会转换成数字7
	str = " 7 8 9";
	i = atoi(str);
	printf("i = %d\n", i);
}

/**
 * 字符串转int类型数据函数
 *
 * long int strtol(const char *str, char **endptr, int base)
 * @param str 要转换为长整数的字符串
 * @param endptr 对类型为 char* 的对象的引用，其值由函数设置为 str 中数值后的下一个字符
 * @param base 基数，必须介于2和36（包含）之间，或者是特殊值0。如果base为0，则会根据字符串的前缀来判断进制：如果字符串以 '0x' 或 '0X' 开头，则将其视为十六进制；如果字符串以 '0' 开头，则将其视为八进制；否则将其视为十进制。
 */
void strtol_test()
{
    char str[] = "123abc";
    char *endptr;
    long num = strtol(str, &endptr, 10);

    if (*endptr != '\0')
    {
    	printf("转换失败：输入字符串不是一个有效的整数。已转换部分：%ld\n", num);
		printf("转换失败：输入字符串不是一个有效的整数。未转换部分：%s\n", endptr);
	}
    else
	{
		printf("转换结果：%ld\n", num);
	}
}

/**
 * 自定义的字符串转int类型数据函数
 *
 * @param str 要被转换的字符串
 * @return    转换后的返回的int类型数据
 */
//void my_atoi(const char *str)
//{
//	if(NULL == str)
//	{
//		return;
//	}
//	char* pstr = (char *)str;
//	while(*pstr != '\0')
//	{
//        /*
//         * 遇到第一个字符'1'时，num = 0 * 10 + (1 - '0') = 0 + 1 = 1
//         * 遇到第二个字符'2'时，num = 1 * 10 + (2 - '0') = 10 + 2 = 12
//         * 遇到第三个字符'3'时，num = 12 * 10 + (3 - '0') = 120 + 3 = 123
//         */
//		//int i = *pstr - '0';
//		//2 * 10 + 3 * (10 ^ 0)
//		//printf("%d ", i);
//		int number = 0;
//		int step = pstr - str;
//		for(int i = step; i >= 0; i--)
//		{
//			int temp = str[i] - '0';
//			number += temp * pow(10,i);
//			//printf("%d ", str[i] - '0');
//		}
//		printf("number = %d", number);
//		//printf("\n");
//		//printf("%d", pstr - str);
//		pstr++;
//	}
//}

///**
// * 测试自定义的字符串转int类型数据函数
// */
//void my_atoi_test()
//{
//	//char* str = "-12345a";
//	char* str = "12345";
//	my_atoi(str);
//}

int my_atoi(const char* str)
{
	int sum = 0;
	assert(str != NULL);
	while(*str != '\0')
	{
		sum = sum * 10 + *str - '0';
        printf("%d ", sum);
		str++;
	}
	return sum;
}

/**
 * 测试自定义的字符串转int类型数据函数
 */
void my_atoi_test()
{
	//char* str = "-12345a";
	char* str = "12345";
	printf("%d ", my_atoi(str));
}

/**
 * strtol()函数应用案例
 */
int str2i(const char *str, char split, char **endptr)
{
	if(NULL == str || NULL == endptr)
	{
		return -1;
	}
    int result = strtol(str, endptr, 10);
    if (*endptr != NULL)
    {
        if (**endptr == split)
        {
            *endptr += 1;
        }
    }
    return result;
}

/**
 * strtol()函数应用案例测试
 */
void str2i_test()
{
    char *str = "1,2,3,4,5";
    char *end = NULL;
    int res[5] = { 0 };
    char *pstr = str;

    for (int i = 0; i < 5; i++)
    {
        res[i] = str2i(pstr, ',', &end);
        pstr = end;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", res[i]);
    }
}


int main()
{
	//atoi_test();
	my_atoi_test();
	//strtol_test();
	//str2i_test();
	return 0;
}
