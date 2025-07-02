#include <stdio.h>
#include <string.h>

/**
 * 指针的加减
 */


/**
 * 指针相减运算结果 = 十六进制地址相减之差转换为十进制数 / sizeof(数据类型)
 */
void PointerSubIntArr()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    // 数组首元素地址
    int* pF = &arr[0];
    // 数组尾元素地址
    int* pL = &arr[4];
    printf("pL - pF = %d\n", (int)(pL - pF));
    printf("pF - pL = %d\n", (int)(pF - pL));

    // 数组结束位置（尾元素地址+1）地址
    int* pE = &arr[5];
    printf("pE - pF = %d\n", (int)(pE - pF));
}

/**
 * 指针相减运算结果 = 十六进制地址相减之差转换为十进制数 / sizeof(数据类型)
 */
void PointerSubStr()
{
    const char* str = "hello";
    char* cp = (char*)str;
    // 这个变量和循环遍历无关，只是为了更方便的查看打印信息
    int index = 0;
    // 注意观察字符串中最后一个字符的地址
    while(*cp != '\0')
    {
        // printf("str[%d] = %c\n", index, *cp);
        printf("str[%d] = %p\n", index, cp);
        cp++;
        index++;
    }
    printf("str = %p\n", str);
    // 注意观察cp的地址是字符串中最后一个字符的地址再+1
    printf("cp = %p\n", cp);
    // 所以这里可以直接使用 cp 和 str 的差值作为字符串长度
    int len = (int)(cp - str);
    printf("字符串长度 = %d", len);
}

int main()
{
    // 使用整型数组 1.观察遍历数组时指针的变化 2.观察指针的相减
    PointerSubIntArr();
    // 使用字符串 1.观察遍历数组时指针的变化 2.观察指针的相减
    //PointerSubStr();
    return 0;
}