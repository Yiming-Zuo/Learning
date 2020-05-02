#pragma onece

#include <stdio.h>
#include <stdlib.h>

struct LinkNode {
	int num;
	struct LinkNode *next;
};

struct LinkNode *init_linkedlist(void);  // 创建链表，返回头节点
int foreach_linkedlist(struct LinkNode *p_header);  // 遍历链表
int insert_node_right(struct LinkNode *p_header, int oldVal, int newVal);  // 插入节点
int insert_node_left(struct LinkNode *p_header, int oldVal, int newVal);
int del_node(struct LinkNode *p_header, int delVal);  // 删除节点
int clear_ll(struct LinkNode *p_header);  // 清空链表（保留头节点）
int destory_ll(struct LinkNode *p_header);  // 销毁链表