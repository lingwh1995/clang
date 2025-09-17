#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>


/**
 * 注意：在sublime中运行此测试程序，eclipse控制台中无法正确的展示此程序运行效果
 */

#define ROWSIZE 20
#define COLSIZE 70
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
	system("cls");
	init_grid(ga);
	for(int i = 0; i < n; i++)
	{
		ga[px[i].row][px[i].col] = px[i].ch;
	}
	for(int i = 0; i < ROWSIZE; i++)
	{
		printf("%s \n", ga[i]);
	}
}

/**
 * 产生随机字符串
 */
void rand_letter(struct LetterNode* px, int n)
{
	if(NULL == px)
	{
		return;
	}
	srand(time(NULL));
	for(int i = 0; i < n; i++)
	{
		px[i].ch = rand() % 26 + 'a';
		px[i].row = 0;
		px[i].col = rand() % COLSIZE;
	}
}

int main()
{
	GridArray ga;
	char ch;
	struct LetterNode x[LETSIZE] = { 0 };

	rand_letter(x, LETSIZE);

	while(1)
	{
		show_grid(ga, x, LETSIZE);
		Sleep(1000);
		// _kbhit() 判断键盘是否有输入，有输入输入，返回真
		if(_kbhit())
		{
			//ch = getchar(); // 需要等待输入 \n
			ch = _getch(); // 无需等待输入 \n
			if(ch == x[0].ch)
			{
				x[0].ch = rand() % 26 + 'a';
				x[0].row = -1;
				x[0].col = rand() % COLSIZE;
			}
		}
		x[0].row++;
		if(x[0].row >= ROWSIZE)
		{
			printf("游戏结束\n");
		}
	}
	return 0;
}
