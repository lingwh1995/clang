#include <stdio.h>

/**
 * 指针的加减
 */


/**
 * 指针想减运算
 */
void PointerSub()
{
    int nums[] = { 1, 2, 3, 4, 5 };
    int len = sizeof(nums)/sizeof(nums[0]);
    int* pF = &nums[0];
    int* pL = &nums[0 + len - 1];
    printf("pL - pF = %lld\n", pL - pF);
    //printf("%d", sizeof(nums)/sizeof(nums[0]));
}

int main()
{
    PointerSub();
    return 0;
}