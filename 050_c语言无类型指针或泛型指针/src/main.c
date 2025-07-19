#include <stdio.h>

/**
 * 通用类型指针使用
 */
void void_type_pointer_1()
{
    int a = 10;
    int arr[10] = { 12, 23, 34, 45, 56 };
    double dx = 12.23;
    char* cp = NULL;
    int* s = &a;

    // 定义一个无类型指针
    void* vp = NULL;
    vp = &a;
    vp = &arr;
    vp = arr;
    vp = &dx;

    vp = cp;
    vp = &s; // 二级指针
}

/**
 * 通用类型指针使用
 */
void void_type_pointer_2()
{
    int a = 10;
    int* ip = NULL;
    char ch = 'a';
    char* cp = NULL;
    // 定义一个无类型指针
    void* vp = NULL;

    //*vp = 100;  // void* 不能解引用
    //vp = vp + 1;  // vp不能加1

    vp = &a;
    // 把无类型指针转为int*类型指针
    ip = (int*)vp;
    printf("ip = %p\n", ip);

    vp = &ch;
    // 把无类型指针转为char*类型指针
    cp = (char*)vp;
    printf("cp = %p\n", cp);
}

int main()
{
    void_type_pointer_1();
    void_type_pointer_2();
    return 0;
}