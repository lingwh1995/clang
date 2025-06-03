#include<stdio.h>

/**
 * 定义一个函数
 */
void Print(int a)
{
	printf("%d\n", a);
}

int main()
{
	/**
	 * 1.c语言可以通过指针获取函数，注意接收类型
	 * 2.变量print_ptr是一个函数指针，它指向函数Print()的地址，函数Print()的地址可以用&Print获得
	 * 3.(*print_ptr)一定要写在圆括号里面，否则函数参数(int)的优先级高于*，整个式子就会变成void* print_ptr(int)
	 */
	void (*print_ptr)(int) = &Print;
	
	// (*print_ptr)(10); 等同于 Print(10);
	(*print_ptr)(10);
	Print(10);

	/**
	 * c语言函数名本身就是指向函数的指针，通过函数名就能获取函数地址。也就是说，Print和&Print代表的含义是相同的。
	 * 因为函数名本身就是指向函数的指针，所以下面两个两种写法表达的意义是相同的
	 * 	void (*print_ptr)(int) = &Print;
	 *  等同于
	 *  void (*print_ptr)(int) = Print;
	 */ 
	printf("print_ptr = %p\n", print_ptr);
	printf("Print = %p\n", Print);
	printf("&Print = %p\n", &Print);

	// 综上所述，对于任意函数，都有五种调用函数的写法。
	// 写法一
	Print(10);
	// 写法二
	(*Print)(10);
	// 写法三
	(&Print)(10);
	// 写法四
	(*print_ptr)(10);
	// 写法五
	print_ptr(10);
}
