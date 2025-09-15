#include <stdio.h>
#include <string.h>

#define ROWSIZE 20
#define COLSIZE 35
#define LETSIZE 1

struct LetterNode
{
	char ch;
	int row;
	int col;
};

typedef char GridArray[ROWSIZE][COLSIZE+1];

void init_grid(GridArray ga)
{
	for(int i=0; i < ROWSIZE; i++)
	{
		memset(ga[i], '', sizeof(char) * COLSIZE);
		ga[i][COLSIZE] = '\0';
	}
}

int main()
{
	GridArray ga;
	struct LetterNode x[LETSIZE] = { 0 };
	init_grid(ga);
	show_grid();
	return 0;
}
