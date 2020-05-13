#include <stdio.h>
#include <stdlib.h>
#include "乙方接口.h"

// 函数指针
// 初始化游戏
// void **:创建玩家(申请void *)
typedef void(*INIT_GAME)(void **player, char *name);
// 战斗 胜利返回1，失败返回0
typedef int(*FIGHT_GAME)(void *player, int gameDiff);
// 查看玩家信息
typedef void(*PRINT_GAME)(void *player);
// 离开游戏
typedef void(*EXIT_GAME)(void *player);

void playGame(INIT_GAME init, FIGHT_GAME fight, PRINT_GAME printGame, EXIT_GAME exitGame) {
	void *player = NULL;
	char name[64] = "";
	printf("请输入玩家姓名：");
	scanf("%s", name);
	getchar();  // 吃掉输入流（缓冲区）的回车
	// 初始化游戏
	init(&player, name);
	
	int diff = -1;
	while (1) {
		system("clear");  // 清屏
		
		printf("请选择游戏难度（1:简单 2:普通 3:困难）：");
		scanf("%d", &diff);
		// 战斗
		int ret = fight(player, diff);
		if (ret) {
			printf("战斗胜利！\n");
			printGame(player);
		} else {
			printf("👎你死了");
			break;
		}
	}
	// 退出游戏
	exitGame(player);	
}

int main(int argc, char *argv[]) {
	playGame(init_game, fight, print_player, exit_game);
	return 0;
}