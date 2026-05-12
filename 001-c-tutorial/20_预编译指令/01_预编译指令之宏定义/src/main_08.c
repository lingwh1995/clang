#include <stdio.h>

void swap_int(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

void swap_double(double *pa, double *pb)
{
    double tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

/**
 * 注意事项
 *
 * 1. 这里不传递地址，因为替换后的代码在一个代码块中，而不是在另一个函数中
 * 2. 使用异或运算不传递类型也能交换，不过仅适用于整数
 *    #define SWAP_XOR(a, b)  { (a) ^= (b); (b) ^= (a); (a) ^= (b); }
 * 3. 使用typeof或__typeof__关键字，可以实现自动推断数据类型，可以实现不传递类型也能交换
 *    #define SWAP_TYPEOF(a, b)  { typeof(a) tmp = a; a = b; b = tmp; }
 *    #define SWAP_TYPEOF(a, b)  { __typeof__(a) tmp = a; a = b; b = tmp; }
 *
 * typeof发展历史
 *
 * 1. C89/C99/C11/C17 中 typeof 都是编译器扩展
 * 2. C23 标准化了 typeof，但 C23 刚刚发布（2023年），普及还需要时间
 */

// 通用的交换函数（必须传递数据类型）
#define SWAP(a, b, type)  { type tmp = a; a = b; b = tmp; }
// 不传递数据类型完成交换，但是只能用于整数
#define SWAP_XOR(a, b)  { (a) ^= (b); (b) ^= (a); (a) ^= (b); }
// 不传递数据类型完成交换，需要依赖编译器
#ifdef _MSC_VER // _MSC_VER 是 MSVC 编译器预定义的宏
#define SWAP_TYPEOF(a, b)  { __typeof__(a) tmp = a; a = b; b = tmp; } // Microsoft 编译器
#else
#define SWAP_TYPEOF(a, b)  { typeof(a) tmp = a; a = b; b = tmp; } // GCC/Clang 编译器
#endif

#if 0
#endif
int main()
{
    int a = 10, b = 20;
    // 传统方式交换
    //swap_int(&a, &b);

    // 宏方式交换（需要传递数据类型）
    //SWAP(a, b , int);  // 预处理后展开为 { int tmp = a; a = b; b = tmp; }

    // 宏方式交换（不用传递数据类型）
    SWAP_TYPEOF(a, b);
    printf("a = %d, b = %d\n", a, b);

    double x = 10.10, y = 20.20;
    // 传统方式交换
    //swap_double(&x, &y);

    // 宏方式交换（需要传递数据类型）
    //SWAP(x, y , double); // 预处理后展开为 { double tmp = x; x = y; y = tmp; }

    // 宏方式交换（不用传递数据类型）
    SWAP_TYPEOF(x, y);
    printf("x = %.2f, y = %.2f\n", x, y);
    return 0;
}