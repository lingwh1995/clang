/*
#include <stdio.h>
#include <string.h>

// 比较函数指针类型定义
typedef int (*compare_func)(const void* a, const void* b);

// 交换函数
void swap(void* a, void* b, size_t size) {
    if (a == b) return;
    
    char* pa = (char*)a;
    char* pb = (char*)b;
    char temp;
    
    for (size_t i = 0; i < size; i++) {
        temp = pa[i];
        pa[i] = pb[i];
        pb[i] = temp;
    }
}

// 泛型冒泡排序函数
void bubble_sort(void* arr, size_t count, size_t size, compare_func compare) {
    if (count <= 1) return;
    
    char* array = (char*)arr;
    int swapped;
    
    for (size_t i = 0; i < count - 1; i++) {
        swapped = 0;
        for (size_t j = 0; j < count - 1 - i; j++) {
            if (compare(array + j * size, array + (j + 1) * size) > 0) {
                swap(array + j * size, array + (j + 1) * size, size);
                swapped = 1;
            }
        }
        // 如果没有发生交换，说明已经有序
        if (!swapped) break;
    }
}

// 通用比较函数包装器，用于实现降序排序
typedef struct {
    compare_func original_compare;
    int reverse;  // 1表示降序，0表示升序
} compare_wrapper_data;

int reverse_compare_wrapper(const void* a, const void* b, compare_wrapper_data* wrapper) {
    int result = wrapper->original_compare(a, b);
    return wrapper->reverse ? -result : result;
}

// 降序比较函数生成器
compare_func make_reverse_compare(compare_func original) {
    // 这里简化处理，实际应用中可能需要更复杂的实现
    static compare_wrapper_data wrapper;
    wrapper.original_compare = original;
    wrapper.reverse = 1;
    return (compare_func)&wrapper;  // 简化示例，实际需要更复杂的实现
}

// 整数比较函数
int compare_int_asc(const void* a, const void* b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

// 整数降序比较函数
int compare_int_desc(const void* a, const void* b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ib > ia) - (ib < ia);
}

void print_int_array(int* arr, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    printf("=== 升序和降序排序 ===\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t count = sizeof(arr) / sizeof(arr[0]);
    
    printf("原数组: ");
    print_int_array(arr, count);
    
    // 升序排序
    bubble_sort(arr, count, sizeof(int), compare_int_asc);
    printf("升序: ");
    print_int_array(arr, count);
    
    // 降序排序
    bubble_sort(arr, count, sizeof(int), compare_int_desc);
    printf("降序: ");
    print_int_array(arr, count);
    
    return 0;
}
*/
