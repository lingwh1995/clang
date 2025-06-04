#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char* Hex2ByteArr(char *puchMsg);
void PrintDecAndHex(int crcDec);
unsigned short CRC_CCITT_XModem(unsigned char *puchMsg, unsigned int usDataLen);


int main()
{
    char *hex = "000199999999999999999101250428110500ffb9001c1f383636383737303739373532343238383938363038353831303234343031343434323000000042433935434e560101000126799175";
    unsigned char *byteArr = Hex2ByteArr(hex);
    int len = strlen(hex) / 2;

    // CRC_CCITT_XModem
	unsigned short crcDec = CRC_CCITT_XModem(byteArr,len);
	PrintDecAndHex(crcDec);
	return 0;
}

/**
 * 十六进制字符串转字节数组
 * @param puchMsg	要进行crc计算的字符串
 */ 
unsigned char* Hex2ByteArr(char *puchMsg)
{
	int len = strlen(puchMsg);
	// 分配足够的空间存储字节数组
	unsigned char* bytes = malloc(len / 2);
	for(int i = 0; i < len; i = i + 2)
	{
		// 把十六进制字符每两位组成一个字符串
		char hexbuff[3];
		hexbuff[0] = puchMsg[i];
		hexbuff[1] = puchMsg[i+1];
		hexbuff[2] = '\0';
		// 将每两个字符转换为字节
		bytes[i/2] = (unsigned char)strtol(hexbuff, NULL, 16);
	}
	return bytes;
}

/**
 * 打印十进制和十六进制crc的值
 * @param crcDec 十进制crc的值
 */ 
void PrintDecAndHex(int crcDec)
{
	printf("crc  十进制 = %d\n",crcDec);
	char crcHex[50];
    sprintf(crcHex, "%x", crcDec);
    printf("crc十六进制 = %s\n", crcHex);
}

/**
 * CRC_CCITT_XModem
 * @param puchMsg 要进行crc计算的字符串
 * @param usDataLen 要进行crc计算的字符串的长度
 */ 
unsigned short CRC_CCITT_XModem(unsigned char *puchMsg, unsigned int usDataLen)
{
	unsigned short wCRCin = 0x0000;
	unsigned short wCPoly = 0x1021;
	unsigned char wChar = 0;

	while (usDataLen--)
	{
		wChar = *(puchMsg++);
		wCRCin ^= (wChar << 8);
		for (int i = 0; i < 8; i++)
		{
			if (wCRCin & 0x8000)
				wCRCin = (wCRCin << 1) ^ wCPoly;
			else
				wCRCin = wCRCin << 1;
		}
	}
	return (wCRCin);
}
