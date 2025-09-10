/*
#include <stdio.h>
#include <string.h>

// 比较函数指针类型定义
typedef int (*compare_func)(const void* a, const void* b);

// 交换函数
void swap(void* a, void* b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

// 泛型冒泡排序函数
void bubble_sort(void* arr, size_t count, size_t size, compare_func compare) {
    char* array = (char*)arr;
    for (size_t i = 0; i < count - 1; i++) {
        for (size_t j = 0; j < count - 1 - i; j++) {
            // 比较相邻元素
            if (compare(array + j * size, array + (j + 1) * size) > 0) {
                // 交换元素
                swap(array + j * size, array + (j + 1) * size, size);
            }
        }
    }
}

// 整数比较函数
int compare_int(const void* a, const void* b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    return (ia > ib) - (ia < ib);
}

// 浮点数比较函数
int compare_float(const void* a, const void* b) {
    float fa = *(const float*)a;
    float fb = *(const float*)b;
    return (fa > fb) - (fa < fb);
}

// 字符串比较函数
int compare_string(const void* a, const void* b) {
    const char* sa = *(const char**)a;
    const char* sb = *(const char**)b;
    return strcmp(sa, sb);
}

// 结构体示例
typedef struct {
    int id;
    char name[50];
} Person;

// 按ID比较结构体
int compare_person_by_id(const void* a, const void* b) {
    const Person* pa = (const Person*)a;
    const Person* pb = (const Person*)b;
    return (pa->id > pb->id) - (pa->id < pb->id);
}

// 按姓名比较结构体
int compare_person_by_name(const void* a, const void* b) {
    const Person* pa = (const Person*)a;
    const Person* pb = (const Person*)b;
    return strcmp(pa->name, pb->name);
}

// 打印整数数组
void print_int_array(int* arr, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 打印浮点数组
void print_float_array(float* arr, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

// 打印字符串数组
void print_string_array(char** arr, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

// 打印Person数组
void print_person_array(Person* arr, size_t count) {
    for (size_t i = 0; i < count; i++) {
        printf("ID: %d, Name: %s\n", arr[i].id, arr[i].name);
    }
    printf("\n");
}

int main() {
    // 测试整数数组排序
    printf("=== 整数数组排序 ===\n");
    int int_arr[] = {64, 34, 25, 12, 22, 11, 90};
    size_t int_count = sizeof(int_arr) / sizeof(int_arr[0]);
    
    printf("排序前: ");
    print_int_array(int_arr, int_count);
    
    bubble_sort(int_arr, int_count, sizeof(int), compare_int);
    
    printf("排序后: ");
    print_int_array(int_arr, int_count);
    
    // 测试浮点数组排序
    printf("\n=== 浮点数组排序 ===\n");
    float float_arr[] = {3.14f, 2.71f, 1.41f, 1.73f, 0.57f};
    size_t float_count = sizeof(float_arr) / sizeof(float_arr[0]);
    
    printf("排序前: ");
    print_float_array(float_arr, float_count);
    
    bubble_sort(float_arr, float_count, sizeof(float), compare_float);
    
    printf("排序后: ");
    print_float_array(float_arr, float_count);
    
    // 测试字符串数组排序
    printf("\n=== 字符串数组排序 ===\n");
    char* str_arr[] = {"banana", "apple", "cherry", "date", "elderberry"};
    size_t str_count = sizeof(str_arr) / sizeof(str_arr[0]);
    
    printf("排序前: ");
    print_string_array(str_arr, str_count);
    
    bubble_sort(str_arr, str_count, sizeof(char*), compare_string);
    
    printf("排序后: ");
    print_string_array(str_arr, str_count);
    
    // 测试结构体数组排序
    printf("\n=== 结构体数组排序 ===\n");
    Person people[] = {
        {3, "Charlie"},
        {1, "Alice"},
        {4, "David"},
        {2, "Bob"}
    };
    size_t person_count = sizeof(people) / sizeof(people[0]);
    
    printf("按ID排序前:\n");
    print_person_array(people, person_count);
    
    bubble_sort(people, person_count, sizeof(Person), compare_person_by_id);
    
    printf("按ID排序后:\n");
    print_person_array(people, person_count);
    
    printf("按姓名排序:\n");
    bubble_sort(people, person_count, sizeof(Person), compare_person_by_name);
    print_person_array(people, person_count);
    
    return 0;
}
*/
