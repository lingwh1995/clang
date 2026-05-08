#include <stdio.h>
#include <stdlib.h>

// 使用 宏定义 + calloc 实现 简化calloc
#define CALLOC(num,type) ((type*)calloc((num),sizeof(type)))

int main()
{
    int* ip_calloc = (int*)calloc(10, sizeof(int));
    int* ip_CALLOC = CALLOC(10, int);

    char* cp_calloc = (char*)calloc(10, sizeof(char));
    char* cp_CALLOC = CALLOC(10, char);
    return 0;
}