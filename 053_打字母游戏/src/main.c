#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

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
void show_grid(GridArray ga, struct LetterNode* px, int n)
{
	if(NULL == px)
	{
		return;
	}
	//system("cls");
    printf("------------------\n");
	init_grid(ga);
	for(int i = 0; i < n; i++)
	{
		ga[px[i].row][px[i].col] = px[i].ch;
	}
	for(int i=0; i < ROWSIZE; i++)
	{
//        for(int j = 0; j < COLSIZE + 1; j++)
//        {
//            printf("%c", ga[i][j]);
//        }
//        printf("\n");
		printf("%s \n", ga[i]);
	}
}

int main()
{
	GridArray ga;
	struct LetterNode x[LETSIZE] = { 0 };

	x[0].row = 1;
	x[0].col = 5;
	x[0].ch = '0';

	for(int i = 0; i < 5; i++)
	{
		show_grid(ga, x, LETSIZE);
		x[0].row++;
		Sleep(1000);
	}
    //show_grid(ga, x, LETSIZE);
	return 0;
}
