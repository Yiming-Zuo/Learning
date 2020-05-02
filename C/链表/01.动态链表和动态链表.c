#include <stdio.h>
#include <stdlib.h>

// 定义节点结构体
struct LinkNode {
	int num;  // 数据域
	struct LinkNode *next;  // 结构域
};

// 1 静态链表
void func01(void) {
	// 创建节点
	struct LinkNode node1 = { 10, NULL };
	struct LinkNode node2 = { 20, NULL };
	struct LinkNode node3 = { 30, NULL };
	struct LinkNode node4 = { 40, NULL };
	struct LinkNode node5 = { 50, NULL };
	// 建立节点之间的关系
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	// 遍历链表
	struct LinkNode *pCurrent = &node1;
	while (pCurrent != NULL) {
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}
}
// 2 动态链表
void func02(void) {
	// 为节点申请栈区空间
	struct LinkNode *p1 = malloc(sizeof(struct LinkNode));
	struct LinkNode *p2 = malloc(sizeof(struct LinkNode));
	struct LinkNode *p3 = malloc(sizeof(struct LinkNode));
	struct LinkNode *p4 = malloc(sizeof(struct LinkNode));
	struct LinkNode *p5 = malloc(sizeof(struct LinkNode));
	// 建立节点间关系
	p1->num = 100;
	p1->next = p2;
	p2->num = 200;
	p2->next = p3;
	p3->num = 300;
	p3->next = p4;
	p4->num = 400;
	p4->next = p5;
	p5->num = 500;
	p5->next = NULL;
	// 遍历节点
	struct LinkNode *pCurrent = p1;
	while (pCurrent != NULL) {
		printf("%d\n", pCurrent->num);
		pCurrent = pCurrent->next;
	}
	// 释放栈区空间
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
}

int main(int argc, char *argv[]) {
//	func01();
	func02();
}