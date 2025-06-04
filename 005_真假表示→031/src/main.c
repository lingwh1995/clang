#include <stdio.h>
#include <stdbool.h>


/**
 * 判断真假
 * 		C语言中0代表假，非0代表真，如1就代表真
 */
void JudgeTrueOrFalse(int i)
{
	if(i)
	{
		printf("i = %d 代表 真\n",i);
	}
	else
	{
		printf("i = %d 代表 假\n",i);
	}
}


/**
 * C99中提供的Bool类型
 */ 
void C99Bool()
{
	bool b = true;
	printf("true = %d 代表 真\n",b);
	b = false;
	printf("false = %d 代表 假\n",b);
}


int main()
{
	int i = 0;
	JudgeTrueOrFalse(i);
	i = 1;
	JudgeTrueOrFalse(i);
	i = -1;
	JudgeTrueOrFalse(i);
	
	C99Bool();
}
