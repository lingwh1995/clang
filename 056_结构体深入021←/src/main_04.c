#include <stdio.h>

struct Node {
    char cha;
    int ia;
    char chb;
    double dx;
    char str[5];
    int ib;
};

int main()
{
    struct Node x;
    int dist = (char*)&x.ib - (char*)&x;
    printf("%d \n", dist);
    return 0;
}
// 00 13 38
