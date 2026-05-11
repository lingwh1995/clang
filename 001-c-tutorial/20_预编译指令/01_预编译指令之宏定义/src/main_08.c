#include <stdio.h>
#include <stdlib.h>

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

#define SWAP(a, b, type)  { type tmp = a; a = b; b = tmp; }

#if 0
int main()
{
    int a = 10, b = 20;
    //swap_int(&a, &b);
    SWAP(a, b , int);
    // 预处理后展开为
    //{ int tmp = x; x = y; y = tmp; }

    printf("a = %d, b = %d\n", a, b);
    double x = 10.10, y = 20.20;
    swap_double(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    return 0;
}
#endif