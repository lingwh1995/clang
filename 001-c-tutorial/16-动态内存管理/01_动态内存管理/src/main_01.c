#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 泛型交换函数 - 动态内存版
void swap(void *pa, void *pb, int size)
{
	void *temp = malloc(size);
	memcpy(temp, pa, size);
	memcpy(pa, pb, size);
	memcpy(pb, temp, size);
	free(temp);
	temp = NULL;
}

#if 0
#endif
int main()
{
	int a = 10, b = 20;
	swap(&a, &b, sizeof(int));
	printf("a = %d, b = %d\n", a, b);


	double x = 10.10, y = 20.20;
	swap(&x, &y, sizeof(double));
	printf("x = %.2f, y = %.2f\n", x, y);
	return 0;
}
