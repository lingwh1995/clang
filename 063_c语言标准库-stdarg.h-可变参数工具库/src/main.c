#include<stdio.h>
#include<stdarg.h>

/**
 * 可变参数
 */
void Varargs(int n, ...) {
    va_list args;
    va_start(args, n);

    for (int i = 0; i < n; i++) {
        int value = va_arg(args, int);
        printf("%d ", value);
    }

    va_end(args);
    printf("\n");
}

int main() {
    Varargs(3, 1, 2, 3);  // 输出：1 2 3
    Varargs(5, 4, 5, 6, 7, 8);  // 输出：4 5 6 7 8
    return 0;
}
