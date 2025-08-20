#include <stdio.h>

/**
 * 二级指针：指向指针的指针
 */


/**
 * 二级指针基础知识
 */
void double_pointer_test()
{
	int a = 10, b = 20;
	printf("a = %d, &a = %p\n", a, &a);
	printf("b = %d, &b = %p\n", b, &b);
	int* p1 = &a;
	printf("p1 = %p, &p1 = %d\n", p1, &p1);
	int* p2 = NULL;
	printf("p2 = %d, &p2 = %d\n", p2, &p2);

	int** s = &p1;
	printf("*s = %p\n", *s);
	printf("**s = %d\n", **s);

	// *s => *&p1 => p1
	*s = &a;
	// **s = **&p1 => *p1 => a
	**s = 100; // a = 10;
	printf("*s = %p\n", *s);
	printf("a = %d, &a = %p\n", a, &a);

	s = &p2;
	// *s => *&p2 => p2
	*s = &b; // p2 = &b;
	printf("p2 = %p, &p2 = %d\n", p2, &p2);
	// **s => **&p2 => *p2 => b
	**s = 200;	// b = 200;
	printf("b = %d, &b = %p\n", b, &b);

	s = &p1;
	printf("s = %p\n", s);
	// s + 1 = s + sizeof(int*) * 1
	printf("s + 1 = %p\n", s + 1);
	printf("**s = %d\n", **s);

    int c = 30;
    int *p3 = &c;
    int **pp3 = &p3;
    printf("二级指针演示:\n");
    printf("c的值: %d， 地址: %p\n", c, &c);
    printf("p3的值: %p， 地址: %p\n", p3, &p3);
    printf("pp3的值: %p， pp3指向的值: %p, 二级指针解引用: %d\n", pp3, *pp3, **pp3);
}


/**
 * 一维数组和一级指针
 */
void one_dimensional_array_add_one_pointer_test()
{
	// 使用一维数组演示使用指针指向整个数组，而不是使用指针指向数组的首元素
	int arr[4] = { 1, 2, 3, 4 };
	printf("sizeof(arr) = %d\n", sizeof(arr));
	// p指向的是数组首元素地址，而非整个数组
	int* p = arr; // 等同于 int* p = &arr;
	printf("sizeof(p) = %d\n", sizeof(p)); // 4个字节，32位系统指针占据4个字节，64位系统指针占据8个字节
	printf("sizeof(*p) = %d\n", sizeof(*p)); // 4个字节，*p 这里代表一维数组中第一个元素
	printf("p = %p\n", p);
	printf("p + 1 = %p\n", p + 1); // p + 1 增加了4个字节
	// s指向整个数组的地址，使用debug模式观察 *s 的值可以看到 *s 的值就是整个数组
	int (*s)[4] = &arr;
	printf("sizeof(s) = %d\n", sizeof(s)); // 4个字节，32位系统指针占据4个字节，64位系统指针占据8个字节
	printf("sizeof(*s) = %d\n", sizeof(*s)); // 16个字节，*s 这里代表整个一维数组
	printf("s = %p\n", s);
	printf("s + 1 = %p\n", s + 1); // s + 1增加了16个字节，因为s指向的是整个一维数组
}

/**
 * 二维数组和二级指针
 */
void two_dimensional_array_add_double_pointer_test_1()
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    printf("sizeof(arr) = %d\n", sizeof(arr));
    // 首元素地址
    int (*p)[4] = arr;
    printf("sizeof(*p) = %d\n", sizeof(*p));
    // 整个二维数组地址，使用debug模式观察 *s 的值可以看到 *s 的值就是整个二维数组
    int (*s)[3][4] = &arr;
    printf("sizeof(*s) = %d\n", sizeof(*s));
    // 二维数组中第一个一维数组的大小
    printf("sizeof(**s) = %d\n", sizeof(**s));
    // 4个字节，二维数组中第一个一维数组中第一个整形元素的大小
    printf("sizeof(***s) = %d\n", sizeof(***s));
}


/**
 * 二维数组和二级指针
 */
void two_dimensional_array_add_double_pointer_test_2()
{
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    // p代表二维数组中第一个元素的地址，就是二维数组中第一个一维数组的地址
    int (*p)[4] = &arr[1];
    // s代表二维数组中第一个元素，就是二维数组中第一个一维数组的首元素的地址
    int* s = arr[1];
    printf("二维数组中第一个一维数组的首元素 = %d\n", *s);
    printf("p[1][3] = %d \n", p[1][3]); // p[1][3] => *(p[1] + 3) => *(*(p + 1) + 3)
    printf("s[3] = %d \n", s[3]); // s[3] => *(s + 3)
}

#if 0
#endif
int main()
{
	//double_pointer_test();
    //one_dimensional_array_add_one_pointer_test();
	//two_dimensional_array_add_double_pointer_test_1();
	two_dimensional_array_add_double_pointer_test_2();
	return 0;
}
