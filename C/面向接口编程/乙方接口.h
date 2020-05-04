#ifndef JIAFANG_H
#define JIAFANG_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Player {
	char name[64];
	int level;
	int exp;
};

// 初始化游戏
// void **:创建玩家(申请void *)
void init_game(void **p, char *name);
// 战斗 胜利返回1，失败返回0
int fight(void *player, int gameDiff);
// 查看玩家信息
void print_player(void *player);
// 离开游戏
void exit_game(void *player);

// 判断玩家是否胜利，返回获得经验值
int isWin(int winRate, int expRate);

#endif