#include<stdio.h>

void print_arr(const void *arr, int n, int size)
{

}

int main()
{
	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89 };
	int in = sizeof(ar) / sizeof(ar[0]);
	double dr[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9 };
	int dn = sizeof(dr) / sizeof(dr[0]);
	int cr[] = { 'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd' };
	int cn = sizeof(cn) / sizeof(cn[0]);
	print_arr(ar, in, sizeof(int));
	print_arr(dr, dn, sizeof(double));
	print_arr(cr, cn, sizeof(char));
	return 0;
}
