#include "乙方接口.h"

// 初始化游戏
// void **:创建玩家(申请void *)
void init_game(void **p, char *name) {
	struct Player *player = (struct Player *)malloc(sizeof(struct Player));
	strcpy(player->name, name);
	player->level = 0;
	player->exp = 0;
	*p = player;
}

// 战斗 胜利加经验并返回1，失败返回0
int fight(void *player, int gameDiff) {
	struct Player *p = player;
	int add_exp = 0;
	switch (gameDiff) {
		case 1:
			add_exp = isWin(90, 1);
			break;
		case 2:
			add_exp = isWin(50, 2);
			break;
		case 3:
			add_exp = isWin(30, 3);
			break;
		default:
			break;
	}
	p->exp += add_exp;
	p->level = p->exp / 10;
	
	if (add_exp) {
		return 1;
	} else {
		return 0;
	}
}
// 判断玩家是否胜利，返回获得经验值
int isWin(int winRate, int expRate) {
	int radom = rand()%100+1;  // 1-100
	if (radom <= winRate) {
		return expRate*10;
	} else {
		return 0;
	}
}

// 查看玩家信息
void print_player(void *player) {
	struct Player *p = player;
	printf("玩家姓名：%s\n", p->name);
	printf("玩家等级：%d\n", p->level);
	printf("玩家经验：%d\n", p->exp);
}

// 离开游戏
void exit_game(void *player) {
	if (player == NULL) {
		return;
	}
	free(player);
	player = NULL;
}