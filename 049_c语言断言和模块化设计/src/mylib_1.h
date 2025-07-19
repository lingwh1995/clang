#ifndef MYLIB_1_H
#define MYLIB_1_H
/*
 * 初始化数组
 * @param *arr 代表数组的指针
 * @param length 数组长度
 */
extern void init_arr_2(int* arr, int length);

/*
 * 交换两个数
 * @param *ap 代表第一个数的指针
 * @param *bp 代表第二个数的指针
 */
extern void swap_2(int* ap, int* bp);

/*
 * 冒泡排序
 * @param *arr 代表数组的指针
 * @param length 数组长度
 */
extern void bubble_sort_2(int* arr, int length);

/*
 * 打印数组
 * @param *arr 代表数组的指针
 * @param length 数组长度
 */
extern void print_arr_2(int* arr, int length);
#endif // !MYLIB_1_H
