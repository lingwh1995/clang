#include <stdio.h>
#include <string.h>
#include <math.h>

/**
 * 章节内容:
 *  1.2进制/8进制/16进制 -> 10进制
 *      2进制 -> 10进制
 *          1010 = 1*2^3 + 0*2^2 + 1*2^1 + 0*2^0
 *      8进制 -> 10进制
 *          1010 = 1*8^3 + 0*8^2 + 1*8^1 + 0*8^0
 *      16进制 -> 10进制
 *          1010 = 1*16^3 + 0*16^2 + 1*16^1 + 0*16^0
 *  2.10进制 -> 2进制/8进制/16进制(贪心算法转换)
 *
 *      十进制    103  103   39    7    7    7    3    1
 *              -----*-----*-----*-----*-----*-----*-----*-----*
 *                128    64    32    16     8     4     2     1
 *      差         -25    39     7    -8    -1     3     1     0
 *      二进制       0     1     1     0     0     1     1     1
 *      八进制       0     1  /  1     0     0  /  1     1     1  # 从右往左,每三位2进制就是一位8进制
 *                    1               4                  7
 *     十六进制      0     1     1     0  /  0     1     1     1
 *                           6                        7          # 从右往左,每四位2进制就是一位16进制
 *      103(10) = 1100111(2) = 0147(8) = 0x67(16)
 *
 */


/**
 * 十进制数转换成二进制数
 */
void decToBin(int dec)
{
	// 存放二进制位的数组
	int binary[32];
	int i = 0;
	do
	{
		binary[i] = dec % 2;
		i++;
		dec /= 2;
	}while(dec > 0);

	// 获取整型数组真实长度
	int len = i;
	char binaryStr[len+1];
	// 设置字符串以 '\0' 结尾
	binaryStr[len] = '\0';
	for(i=1; i<=len; i++)
	{
	    // 把整型数组转换成字符串
		sprintf(binaryStr, "%s%d", binaryStr, binary[len-i]);
	}
	printf("%s\n", binaryStr);
}


/**
 * 二进制数转换成十进制数
 */
int binTodec(char *binaryStr)
{
	int len = strlen(binaryStr);
    char binaryArr[len];
    strcpy(binaryArr, binaryStr);

    int dec = 0;
	for(int i = 0; i < len; i++)
	{
		int r = (binaryArr[i] - '0') * (int)pow(2,len-i-1);
		dec += r;
	}
	return dec;
}


/**
 * 十进制数转换成二进制数贪心算法版
 * TODO 将二进制字符串转为八进制数和十六进制数
 */
void decToBinGreedy(int dec)
{
	int n = 0;
	do
	{
		n++;
	}while((2 << n) < dec);

	// 数组长度每4位一补齐，确保 (数组长度-1)%4 == 0
	int length = (n+2) % 4 == 0 ? n + 2 : 4 - (n+2) % 4 + n + 2;
	printf("length = %d\n",length);
	// 数组的长度 +1 是为了存放字符串的结束标识 '\0'
	char bin[length + 1];

	int i = 0;
	printf("n = %d\n",n);
	// 修正n的值，确保 (n+2) % 4 = 0,这样左边不足4位会补0
	n = (n+2) % 4 == 0 ? n : 4 - (n+2) % 4 + n;
	do
	{
		// 如果 n == -1，则将与 dec 比较的值设置为 1，否则将这个值设置为 2 << n
		if(dec >= (n == -1 ? 1 : 2 << n))
		{
			bin[i] = '1';
			dec = dec - (2 << n);
		}
		else
		{
			bin[i] = '0';
		}
		n--;
		i++;
	}while(n >= -1);
	// 设置字符串结尾为 '\0'
	bin[i] = '\0';
	printf("i = %d\n",i);
	printf("%s\n",bin);
}


int main()
{
    int i = 100;
    // %d：十进制整数
    printf("十进制表示 i = %d\n", i);
    // %o：八进制整数
    printf("八进制表示 i = %o\n", i);
	// %#o：显示前缀0的八进制整数
    printf("八进制表示(显示前缀0) i = %#o\n", i);
    // %x：十六进制整数
    printf("十六进制表示 i = %x\n", i);
    // %#x：显示前缀0x的十六进制整数
    printf("十六进制表示(显示前缀0x) i = %#x\n", i);
    // %#X：显示前缀0X的十六进制整数
    printf("十六进制表示(显示前缀0X) i = %#X\n", i);
    printf("-------------------------------------\n");


    int b = 0b10;
    printf("十进制表示 b = %d\n", b);
    int o = 010;
    printf("十进制表示 o = %d\n", o);
    int h = 0x10;
    printf("十六进制表示 o = %d\n", h);
    printf("-------------------------------------\n");


    printf("2进制1010  = 1*2^3 + 0*2^2 + 1*2^1 + 0*2^0 = 8 + 0 + 2 + 0 = 10\n");
    printf("8进制1010  = 1*8^3 + 0*8^2 + 1*8^1 + 0*8^0 = 512 + 0 + 8 + 0 = 520\n");
    printf("16进制1010 = 1*16^3 + 0*16^2 + 1*16^1 + 0*16^0 = 4096 + 0 + 16 + 0 = 4112\n");
    printf("-------------------------------------\n");


    int dec = 11;
    decToBin(dec);

    char binaryStr[] = "1010";
    dec = binTodec(binaryStr);
    printf("二进制数 %s 转换成十进制数是 %d \n", binaryStr, dec);

    dec = 103;
    decToBinGreedy(dec);
    return 0;
}
