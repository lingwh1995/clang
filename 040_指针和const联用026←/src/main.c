#include <stdio.h>

/*
 * const与指针的关系：使用const关键字限制指针或者指向的值为常量
 */

/**
 * 指向为常性的指针
 * const在*左边，表示指向的值是常量
 */
void PointerAndConstTest1() {
    int a = 10, b = 20;
    const int* p = &a;
    // 等价写法一
    //const int *p = &a;
    // 等价写法二
    //int const *p = &a;
    int c = *p;
    printf("c = %d\n", c);
    //无法解引用*p的值，这是不合法的，因为前面已经将指针p指向的值定义成一个常量了
    //*p = 100;
    p = &b;
}


/**
 * 常性指针
 * const在*右边，表示指针自身是一个常量
 */
void PointerAndConstTest2() {
    int a = 10, b = 20;
    int* const p = &a;

    int c = *p;
    printf("c = %d\n", c);
    //无法修改指针p的值，这是不合法的，因为前面已经将指针p定义成一个常量了
    //p = &b;
    *p = 100;
}


/**
 * 定义一个指针自身和指针的指向都是常量的常量
 *  起到保护指针自身和被指针指向的值的效果
 */
void PointerAndConstTest3() {
    int a = 10, b = 20;
    const int* const p = &a;
    //这种写法等价于上面一行
    //int const * const p = &a;

    int c = *p;
    printf("c = %d\n", c);

    //无法修改指针p的值,这是不合法的
    //p = &b;
    //无法解引用*pa的值,这是不合法的
    //*p = 100;
}

/**
 * 1.使用const修饰指针类型: 可以读取指针地址和指针指向的数据，但是不能改变指针所指向的值，这样可以保护指针指向的值
 * 2.被const修饰的常量值可以通过指针来修改
 */
void PointerAndConstTest4() {
    int a = 10, b = 20;
    const int c = 30;
    int* ap = &a;
    printf("a = %d\n", *ap);
    *ap = 100;
    printf("a = %d\n", *ap);

    const int* bp = &b;
    printf("b = %d\n", *bp);
    //不能改变指针指向的值，这对指针指向的值起到保护作用
    //*bp = 200;

    //指针修改常量的值
    int* cp = &c;
    printf("cp = %p\n", cp);
    *cp = 300;
    printf("c = %d\n", *cp);
}

#if 0
#endif
int main() {
	//PointerAndConstTest1();
	//PointerAndConstTest2();
	//PointerAndConstTest3();
    PointerAndConstTest4();
    return 0;
}
