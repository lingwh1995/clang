#include <stdio.h>

/**
 * 打印数字的二进制原码补码反码
 * 	正数：原码、补码、反码是一样的
 * 	负数：
 * 		原码
 * 		反码：原码按位取反，符号位不变
 * 		补码：在反码的基础上加1
 */
void PrintBinaryString(int n)
{
	for(int i=7; i>=0; i--)
	{
		printf("%d", (n>>i) & 1);
	}
	printf("\n");
}

int main()
{
	int n = 5;
	// 打印5的二进制原码
	printf("5  的二进制原码  ");
	PrintBinaryString(n);
	// 打印5的二进制反码
	printf("5  的二进制反码  ");
	PrintBinaryString(n);
	// 打印5的二进制补码
	printf("5  的二进制补码  ");
	PrintBinaryString(n);

	printf("-----------------------\n");

	// 打印-5的二进制原码
	printf("-5 的二进制原码  ");
	PrintBinaryString((1 << 7) | n);
	// 打印-5的二进制反码
	printf("-5 的二进制反码  ");
	PrintBinaryString(~n);
	// 打印-5的二进制补码
	printf("-5 的二进制补码  ");
	PrintBinaryString(-n);
	return 0;
}
