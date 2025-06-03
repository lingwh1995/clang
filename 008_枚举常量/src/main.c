# include <stdio.h>

/**
 * 章节内容:
 * 		枚举常量: 枚举常量是整型数据，默认从0开始
 */


int main()
{
    /**
     * 枚举常量(枚举也是一种常量)
     *  注意:枚举常量的值只能是整形数据
     */
    enum sex
    {
        MALE, // 男性
        FEMALE, // 女性
        SECRET // 保密
    };
    printf("MALE = %d\n", MALE);
    printf("FEMALE = %d\n", FEMALE);
    printf("SECRET = %d\n", SECRET);

    enum week
    {
        MON = 1,
        TUE = 2,
        WED = 3
    };
    enum week wk;
    wk = MON;
    printf("wk = %d\n", wk);
    wk = TUE;
    printf("wk = %d\n", wk);

    enum animal
    {
        DOG = 5,
        CAT,
        SHEEP
    };

    printf("DOG = %d\n", DOG);
    printf("CAT = %d\n", CAT);
    printf("SHEEP = %d\n", SHEEP);
    return 0;
}
