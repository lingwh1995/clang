#include <stdio.h>
#include <string.h>

/**
 * 创建候选人结构体
 */
typedef struct
{
	char name[20];
	int votes;
} Candidate;

/**
 * 给候选人投票
 */
void vote_for_candidate(Candidate *candidates, int len)
{
	if(candidates == NULL || len == 0)
	{
		return;
	}
	char name[20];
	while(printf("请输入候选人姓名:\n"), scanf("%s", &name), name[0] != '#')
	{
		for(int i = 0; i < len; i++)
		{
			if(strcmp(name, candidates[i].name) == 0)
			{
				candidates[i].votes++;
				break;
			}
		}
	}
}

/**
 * 打印投票结果
 */
void printf_vote_result(Candidate *candidates, int len)
{
	printf("投票结果\n");
	if(candidates == NULL || len == 0)
	{
		return;
	}
	for(int i = 0; i < len; i++)
	{
		printf("姓名 %s -> %d\n", candidates[i].name, candidates[i].votes);
	}
}

/**
 * 投票程序
 */
void vote()
{
	Candidate candidates[3] = {
		{ "zs", 0 },
		{ "ls", 0 },
		{ "ww", 0 },
	};
	int len = sizeof(candidates) / sizeof(candidates[0]);
	// 给候选人投票
	vote_for_candidate(candidates, len);
	// 打印投票结果
	printf_vote_result(candidates, len);
}

int main()
{
	//vote();
	return 0;
}
