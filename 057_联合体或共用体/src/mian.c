#include <stdio.h>
#include <string.h>
#include <stdint.h>

/**
 * 共用体/联合体特征： 所有的成员变量共用同一段内存空间
 */

/**
 * 共用体/联合体 入门
 */
void union_test_1()
{
	union
	{
		int i;
		char ch[4];
	} data;
	
	// 一般情况下，要使用哪个类型的数据初始化共用体，定义共用体就把哪个类型放在最前面定义，也可以不放在前面
	data.i = 0x12345678;
	printf("data.i = 0x%x\n", data.i);
	printf("data.ch[0] = 0x%x, data.ch[1] = 0x%x\n", data.ch[0], data.ch[1]);
	
	data.ch[0] = 'a';
	data.ch[1] = 'b';
	printf("data.i = 0x%x\n", data.i);
	
	/**
	 * 16进制数
	 * 0x30 -> '0'
	 * 0x31 -> '1'
	 * 0x32 -> '2'
	 * 0x33 -> '3'
	 */
	data.i = 0x30313233;
	printf("data.ch[0] = %c, data.ch[1] = %c\n", data.ch[0], data.ch[1]);
	printf("-------------------------------------\n");
}

/**
 * 共用体/联合体 共用同一段内存空间
 */
void union_test_2()
{
	union
	{
		int i;
		short s;
		char c;
	} data;

	// 一般情况下，要使用哪个类型的数据初始化共用体，定义共用体就把哪个类型放在最前面定义，也可以不放在前面
	data.i = 0x12345678;
	printf("data.i = 0x%x\n", data.i);
	printf("data.s = 0x%x\n", data.s);
	printf("data.c = 0x%x\n", data.c);
	printf("-------------------------------------\n");
}

/**
 * 使用 共用体/联合体 判断大小端
 */
void union_test_3()
{
	union
	{
		short s;
		char ch[2];
	} data;

	data.s = 0x0001;
	if(data.ch[0] == 1)
	{
		printf("LITTLE_END\n");
	}
	else
	{
		printf("BIG_END\n");
	}
	printf("-------------------------------------\n");
}

/**
 * 共用体/联合体 + 结构体 经典用法，类似与js/python中对 addr 进行解构，想实现这个目的，但是没成功实现
 */
void union_test_4()
{
	union
	{
		unsigned int addr;
		unsigned char seg_4, seg_3, seg_2, seg_1;
	} data;

	data.addr = 0x12345678;
	printf("%u %u %u %u\n", data.seg_4, data.seg_3, data.seg_2, data.seg_1);
	printf("-------------------------------------\n");
}

/**
 * 共用体/联合体 + 结构体(哑元) 经典用法，实现类似与js/python中对 addr 进行解构，想实现这个目的，也成功实现了
 */
void union_test_5()
{
	union
	{
		unsigned int addr;
		// 这是一个匿名结构体，官方术语称为结构
		struct
		{
			unsigned char seg_4, seg_3, seg_2, seg_1;
		};
	} data;

	data.addr = 0x12345678;
	printf("%u %u %u %u\n", data.seg_4, data.seg_3, data.seg_2, data.seg_1);
	printf("-------------------------------------\n");
}

/**
 * 共用体/联合体 + 结构体(哑元) 经典用法，实现把 int 格式 ip 地址转换为字符串格式 ip 地址
 * 自己的写法，仅实现了功能，总体来说不够专业
 */
union
{
	unsigned int addr;
	// 这是一个匿名结构体，官方术语称为结构
	struct
	{
		unsigned char seg_4, seg_3, seg_2, seg_1;
	};
} ip_u;

/**
 * 整型 ip 转换为字符串型 ip
 */
void int_ip_to_str_ip_1(unsigned int int_ip, char *str_ip)
{
	if(str_ip == NULL)
	{
		return;
	}
	ip_u.addr = int_ip;
	sprintf(str_ip, "%u.%u.%u.%u", ip_u.seg_1, ip_u.seg_2, ip_u.seg_3, ip_u.seg_4);
}

void union_test_6()
{
	unsigned int int_ip = 2148205343;
	printf("int_ip = %x\n", int_ip);
	char str_ip[20] = { 0 };
	int_ip_to_str_ip_1(int_ip, str_ip);
	printf("str_ip = %s\n", str_ip);
	printf("-------------------------------------\n");
}


/**
 * 共用体/联合体 + 结构体(哑元) 经典用法，实现把 int 格式 ip 地址转换为字符串格式 ip 地址
 * 最经典最专业的写法
 */
// 专业写法：用 typedef 定义IP联合体
typedef union {
    uint32_t addr;
    struct {
        uint8_t seg_4;
        uint8_t seg_3;
        uint8_t seg_2;
        uint8_t seg_1;
    } seg;
} ip_t;

/**
 * 整型 ip 转换为字符串型 ip
 */
void int_ip_to_str_ip_2(uint32_t int_ip, char *str_ip, int len)
{
    if (str_ip == NULL || len < 16)
    {
        return;
    }

    ip_t ip_u;
    ip_u.addr = int_ip;

    // 安全的格式化输出
    snprintf(str_ip, len, "%u.%u.%u.%u",
             ip_u.seg.seg_1,
             ip_u.seg.seg_2,
             ip_u.seg.seg_3,
             ip_u.seg.seg_4);
}

/**
 * 字符串型 ip 转换为整型 ip
 */
uint32_t str_ip_to_int_ip(const char *str_ip)
{
    if (str_ip == NULL)
    {
        return 0;
    }

    uint32_t uint_seg_1, uint_seg_2, uint_seg_3, uint_seg_4;
    ip_t ip_u;

    sscanf(str_ip, "%u.%u.%u.%u", &uint_seg_1, &uint_seg_2, &uint_seg_3, &uint_seg_4);

    // 用你的 union 装回去
    ip_u.seg.seg_1 = (uint8_t)uint_seg_1;
    ip_u.seg.seg_2 = (uint8_t)uint_seg_2;
    ip_u.seg.seg_3 = (uint8_t)uint_seg_3;
    ip_u.seg.seg_4 = (uint8_t)uint_seg_4;

    // 直接返回 32 位整数IP
    return ip_u.addr;
}

void union_test_7()
{
    uint32_t int_ip = 2148205343;
    printf("int_ip = %x\n", int_ip);
    char str_ip[20] = { 0 };
    int_ip_to_str_ip_2(int_ip, str_ip, sizeof(str_ip));
    printf("str_ip = %s\n", str_ip);

    // 重新给 str_ip 赋值
    strcpy(str_ip, "128.11.3.32");
    int_ip = str_ip_to_int_ip(str_ip);
    printf("int_ip = %u\n", int_ip);
}

int main()
{
	union_test_1();
	union_test_2();
	union_test_3();
	union_test_4();
	union_test_5();
	union_test_6();
	union_test_7();
	return 0;
}
