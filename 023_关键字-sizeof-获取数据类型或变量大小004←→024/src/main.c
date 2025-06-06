#include <stdio.h>
#include <string.h>

/**
 * sizeof:返回一个无符号的整型数据
 * 	sizeof(pointer) 只反映指针自身的大小，不是它指向的数据的大小
 */

int main()
{
    int a = 10;
    //指针类型的数据在32位系统下占4个字节，64位系统下占8个字节
    char* cp = NULL;
    double* dp = NULL;
    char str[10];
    int arr[10];
    printf("sizeof(a) = %llu\n", sizeof(a));
    printf("sizeof(cp) = %llu\n", sizeof(cp));
    printf("sizeof(cp) = %llu\n", sizeof(char *));
    printf("sizeof(dp) = %llu\n", sizeof(dp));
    printf("sizeof(double*) = %llu\n", sizeof(double*));
    printf("sizeof(str) = %llu\n", sizeof(str));
    //字符串(字符数组)类型末尾有一个额外的\0,会多占据一个字节
    printf("sizeof(\"ufe\") = %llu\n", sizeof("ufe"));
    printf("sizeof(arr) = %llu\n", sizeof(arr));
    printf("----------------------------------------\n");

    int nums[] = { 10,20,30,40,50 };
    printf("sizeof(nums[0]) = %llu\n", sizeof(nums[0]));
    printf("sizeof(nums) = %llu\n", sizeof(nums));
    printf("----------------------------------------\n");

    char stra[10] = { "tulun" };
    char strb[10] = { 't','u','l','u','n' };
    char strc[] = { "tulun" };
    char strd[] = { 't','u','l','u','n' };
    printf("sizeof(stra) = %llu\n", sizeof(stra));
    printf("sizeof(strb) = %llu\n", sizeof(strb));
    printf("sizeof(strc) = %llu\n", sizeof(strc));
    printf("sizeof(strd) = %llu\n", sizeof(strd));

    printf("strlen(stra) = %llu\n", strlen(stra));
    printf("strlen(strb) = %llu\n", strlen(strb));
    printf("strlen(strc) = %llu\n", strlen(strc));
    // 为什么打印的长度值是10，因为是 strc长度 + strd长度，因为 strd 没有 '\0'，这里最后是使用了 strc 中的 '\0' 作为结束符
    printf("strlen(strd) = %llu\n", strlen(strd));
    printf("----------------------------------------\n");
	return 0;
}
