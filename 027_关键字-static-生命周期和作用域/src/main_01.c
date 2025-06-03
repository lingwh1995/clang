#include <stdio.h>
#include "mylib.h"

#if 0
#endif
int main()
{
    //下面三行代码放开会报错
    /*
    printf("其他文件中的静态全局变量: %d\n", gi_in_other_file_static);
    printf("其他文件中的静态全局常量: %d\n", gc_in_other_file_static);
    AddInOtherFileStatic(0, 0);
    */

    printf("其他文件中的静态全局变量: %d\n", gi_in_other_file_ordinary);
    printf("其他文件中的静态全局常量: %d\n", gc_in_other_file_ordinary);
    AddInOtherFileOrdinary(0, 0);
	return 0;
}

