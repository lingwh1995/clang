#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#if 0
#endif
/**
 * 打字母游戏第二版
 * 		随机产生十个字母从屏幕上方向下落，玩家输入字母，如果和显示的字母相同，就消去字母，游戏会再随机产生一个字母，使屏幕中的字母个数保持十个，继续游戏，如果有一个字母落出屏幕，玩家失败，游戏结束。
 *
 * 注意事项
 *		在sublime中运行此测试程序，eclipse控制台中无法正确的展示此程序运行效果
 */

#define ROWSIZE 20 	   // 行数
#define COLSIZE 70 	   // 列数
#define LETSIZE 10  	   // 下落的字母数
#define GRDI_CHAR '.'  // 棋盘填充字符

/**
 * 定义字母结构体
 */
struct Letter
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
		memset(ga[i], GRDI_CHAR, sizeof(char) * COLSIZE);
		ga[i][COLSIZE] = '\0';
	}
}

/**
 * 打印网格
 */
void show_grid(GridArray ga, struct Letter* pl, int n)
{
	if(NULL == pl)
	{
		return;
	}
	system("cls");
	init_grid(ga);
	for(int i = 0; i < n; i++)
	{
		ga[pl[i].row][pl[i].col] = pl[i].ch;
	}
	for(int i = 0; i < ROWSIZE; i++)
	{
		printf("%s \n", ga[i]);
	}
}

/**
 * 产生随机字符串
 */
void rand_letter(struct Letter* pl, int n)
{
	if(NULL == pl)
	{
		return;
	}
	srand(time(NULL));
	for(int i = 0; i < n; i++)
	{
		pl[i].ch = rand() % 26 + 'a';
		pl[i].row = 0;
		pl[i].col = rand() % COLSIZE;
	}
}

int main()
{
	GridArray ga;
	char ch;
	struct Letter letter[LETSIZE] = { 0 };

	rand_letter(letter, LETSIZE);

	while(1)
	{
		show_grid(ga, letter, LETSIZE);
		// _kbhit() 判断键盘是否有输入，有输入输入，返回真
		if(_kbhit())
		{
			//ch = getchar(); // 需要等待输入 \n
			ch = _getch(); // 无需等待输入 \n
			for(int i = 0; i < LETSIZE; i++)
			{
				if(ch == letter[i].ch)
				{
					letter[i].ch = rand() % 26 + 'a';
					letter[i].row = -1;
					letter[i].col = rand() % COLSIZE;
				}
			}
		}
		for(int i = 0; i < LETSIZE; i++)
		{
			if(letter[i].row >= ROWSIZE)
			{
				printf("游戏结束\n");
				return 0;
			}
			letter[i].row++;
		}
		Sleep(1000);
	}
	return 0;
}

