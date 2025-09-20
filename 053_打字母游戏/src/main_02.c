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
 * 		随机产生十个字母从屏幕上方向下落，玩家输入字母，如果和显示的字母相同，就消去字母，游戏会再随机产生一个字母（小写字母/小写字母和大写字母），使屏幕中的字母个数保持十个，继续游戏，如果有一个字母落出屏幕，玩家失败，游戏结束。
 *
 * 注意事项
 *		在sublime中运行此测试程序，eclipse控制台中无法正确的展示此程序运行效果
 */

#define ROWSIZE 20 	   // 行数
#define COLSIZE 70 	   // 列数
#define LETSIZE 10     // 下落的字母数
#define GRDI_CHAR '.'  // 棋盘填充字符
#define SPEED 2000 	   // 下落速度

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
 * 打印网格（添加分数显示功能）
 */
void show_grid(GridArray ga, struct Letter* pla, int n, int score)
{
	if(NULL == pla)
	{
		return;
	}
	system("cls");
	init_grid(ga);

	// 显示下落的字母
	for(int i = 0; i < n; i++)
	{
		// 确保字母在有效范围内才显示
		if(pla[i].row >= 0 && pla[i].row < ROWSIZE &&
		   pla[i].col >= 0 && pla[i].col < COLSIZE)
		{
			ga[pla[i].row][pla[i].col] = pla[i].ch;
		}
	}

	// 打印网格和分数
	for(int i = 0; i < ROWSIZE; i++)
	{
		// 在每行右侧显示分数信息
		if(i == 0)
		{
			printf("%s  Score: %d\n", ga[i], score);
		}
		else if(i == 1)
		{
			printf("%s  Letters: %d\n", ga[i], n);
		}
		else
		{
			printf("%s\n", ga[i]);
		}
	}
}

/**
 * 产生随机字符
 */
void rand_letter(struct Letter* pl)
{
	if(NULL == pl)
	{
		return;
	}
	if(rand() % 2 == 0)
	{
		pl->ch = rand() % 26 + 'a';
	}
	else
	{
		pl->ch = rand() % 26 + 'A';
	}
	pl->row = 0;

    // 特别注意： 可能会出现 col 值重复的情况
	pl->col = rand() % COLSIZE;
}

/**
 * 产生随机字符
 */
void rand_letters(struct Letter* pla, int n)
{
	if(NULL == pla)
	{
		return;
	}
	int col_table[COLSIZE] = { 0 };
	srand(time(NULL));
	int i = 0;
	while(i < n)
	{
        // 随机生成小写字母
        //letter[i].ch = rand() % 26 + 'a';

        // 随机生成小写或大写字母
		rand_letter(&pla[i]);
		// 查表法去重
		if(col_table[pla[i].col] == 0)
		{
			col_table[pla[i].col] = 1;
			i++;
		}
	}
}

int main()
{
	GridArray ga;
	char ch;
	struct Letter letter_arr[LETSIZE] = { 0 };
	int score = 0;  // 添加分数变量

	rand_letters(letter_arr, LETSIZE);

	while(1)
	{
		show_grid(ga, letter_arr, LETSIZE, score);  // 传递分数参数
		// _kbhit() 判断键盘是否有输入，有输入，返回真
		if(_kbhit())
		{
			//ch = getchar(); // 需要等待输入 \n，才能获取到输入缓冲区中的内容
			ch = _getch(); // 无需等待输入 \n，直接就可以获取到输入缓冲区中的内容
			printf("当前输入的字符： %c\n", ch);
			for(int i = 0; i < LETSIZE; i++)
			{
				if(ch == letter_arr[i].ch)
				{
				    // 随机生成小写或大写字母
					rand_letter(&letter_arr[i]);
					letter_arr[i].row = 0;  // 重置行位置
					score++;  // 增加分数
					break;
				}
			}
		}
		for(int i = 0; i < LETSIZE; i++)
		{
			letter_arr[i].row++;
			if(letter_arr[i].row >= ROWSIZE)
			{
				printf("游戏结束\n");
				printf("最终得分: %d\n", score);
				return 0;
			}
		}
		Sleep(SPEED);
	}
	return 0;
}