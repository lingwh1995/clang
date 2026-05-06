#include <stdio.h>
#include <string.h>

#if 0
#endif
int main()
{
    char stra[] = { "this is a long string \
                        that is used \
                            as an example" };
    char strb[] = { "this is a long string"
                        "that is used"
                            "as an example" };
    printf("stra = %s \n", stra);
    printf("strb = %s \n", strb);
    printf("strlen(stra) = %d \n", strlen(stra));
    printf("strlen(strb) = %d \n", strlen(strb));
    return 0;
}