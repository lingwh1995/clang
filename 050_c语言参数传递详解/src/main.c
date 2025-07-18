#include <stdio.h>

void fun1()
{
    int a = 10;
    int arr[10] = { 12, 23, 34, 45, 56 };
    double dx = 12.23;
    char* cp = NULL;
    int* s = &a;

    void* vp = NULL;
    vp = &a;
    vp = &arr;
    vp = arr;
    vp = &dx;

    vp = cp;
    vp = &s; // 二级指针
}

void fun2()
{
    int a = 10;
    int* ip = NULL;
    char ch = 'a';
    char* cp = NULL;
    void* vp = &a;

    //*vp = 100;  // void* 不能解引用
    //vp = vp + 1;  // vp不能加1

    ip = (int*)vp;
    vp = &ch;

    cp = (char*)vp;
}

int main()
{
    fun1();
    fun2();
    return 0;
}