#ifndef MYLIB_2_H
#define MYLIB_2_H
/*
 * 从数组中查找当前值,查找到返回数组索引,查找不到返回-1
 * @param *arr 代表数组的指针
 * @param n 当前元素在目标数组中的索引
 * @param num 要确定是否存在于当前数组中的值
 */
int FindValueV3(const* arr, int n, int num);

/*
 * 初始化数组
 * @param *arr 代表数组的指针
 * @param length 数组长度
 */
extern void InitArrV3(int* arr, int length);

/*
 * 交换两个数
 * @param *ap 代表第一个数的指针
 * @param *bp 代表第二个数的指针
 */
extern void SwapV3(int* ap, int* bp);

/*
 * 冒泡排序
 * @param *arr 代表数组的指针
 * @param length 数组长度
 */
extern void BubbleSortV3(int* arr, int length);

/*
 * 打印数组
 * @param *arr 代表数组的指针
 * @param length 数组长度
 */
extern void PrintArrV3(int* arr, int length);
#endif // !MYLIB_2_H