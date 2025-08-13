#include <stdio.h>

/**
 * 二级指针：指向指针的指针
 */


/**
 * 二级指针基础知识
 */
void double_pointer_basic_test()
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


    int c = 30;
    int *p3 = &c;
    int **pp3 = &p3;
    printf("二级指针演示:\n");
    printf("c的值: %d， 地址: %p\n", c, &c);
    printf("p3的值: %p， 地址: %p\n", p3, &p3);
    printf("pp3的值: %p， pp3指向的值: %p, 二级指针解引用: %d\n", pp3, *pp3, **pp3);
}

#if 0
int main()
{
	double_pointer_basic_test();
	return 0;
}
#endif

