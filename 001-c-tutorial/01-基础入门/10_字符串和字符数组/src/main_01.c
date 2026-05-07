#include <stdio.h>
#include <string.h>

#if 0
#endif
int main()
{
    // 使用续行符把多行拼接在一起
    char stra[] = { "this is a long string \
                        that is used \
                            as an example" };
    // 不使用续行符把多行拼接在一起
    char strb[] = { "this is a long string"
                        "that is used"
                            "as an example" };
    printf("stra = %s \n", stra);
    printf("strb = %s \n", strb);
    printf("strlen(stra) = %llu \n", strlen(stra));
    printf("strlen(strb) = %llu \n", strlen(strb));
    return 0;
}