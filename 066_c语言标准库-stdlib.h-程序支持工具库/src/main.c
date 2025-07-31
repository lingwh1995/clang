#include<stdio.h>
#include<stdlib.h>

/**
 * 字符串转int类型数据函数
 *
 * int atoi (const char * str)
 * @param str 要被转换的字符串
 * @return    转换后的返回的int类型数据
 */
void atoi_test()
{
	char* str = "100";
	int i = atoi(str);
	printf("i = %d\n", i);

	str = "-100";
	i = atoi(str);
	printf("i = %d\n", i);
}

int main()
{
	atoi_test();
	return 0;
}
