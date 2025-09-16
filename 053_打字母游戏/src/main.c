#include <stdio.h>
#include <string.h>

#define ROWSIZE 20
#define COLSIZE 35
#define LETSIZE 1

/**
 * 定义字母结构体
 */
struct LetterNode
{
	char ch;
	int row;
	int col;
};

typedef char GridArray[ROWSIZE][COLSIZE+1];

/**
 * 初始化网格
 */
void init_grid(GridArray ga)
{
	for(int i=0; i < ROWSIZE; i++)
	{
		memset(ga[i], '#', sizeof(char) * COLSIZE);
		ga[i][COLSIZE] = '\0';
	}
}

/**
 * 打印网格
 */
void show_grid(GridArray ga)
{
	for(int i=0; i < ROWSIZE; i++)
	{
		for(int j = 0; j < COLSIZE; j++)
		{
			printf("%c", ga[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	GridArray ga;
	//struct LetterNode x[LETSIZE] = { 0 };
	init_grid(ga);
	show_grid(ga);
	return 0;
}
