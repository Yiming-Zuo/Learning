#include "linkedlist.h"

struct LinkNode *init_linkedlist(void) {
	// 创建头节点
	struct LinkNode *p_header = malloc(sizeof(struct LinkNode));
	p_header->next = NULL;
	// 添加节点
	struct LinkNode *p_tail = p_header;
	int num = -1;
	while (1) {
		printf("请输入数值：\n");
		scanf("%d", &num);
		if (num == -1) {
			break;
		}
		struct LinkNode *p = malloc(sizeof(struct LinkNode));
		p->num = num;
		p->next = NULL;
		p_tail->next = p;
		p_tail = p;
	}
	return p_header;
}

int foreach_linkedlist(struct LinkNode *p_header) {
	if (p_header == NULL) {
		return -1;
	}
	struct LinkNode *p_cur = p_header->next;
	printf("------开始遍历链表------\n");
	while (p_cur != NULL) {
		printf("%d\n", p_cur->num);
		p_cur = p_cur->next;
	}
	
	return 0;
}

int insert_node_right(struct LinkNode *p_header, int oldVal, int newVal) {
	if (p_header == NULL) {
		return -1;
	}
	struct LinkNode *p_cur = p_header->next;
	while (p_cur != NULL) {
			if (oldVal == p_cur->num) {
				struct LinkNode *p_new = malloc(sizeof(struct LinkNode));
				p_new->num = newVal;
				struct LinkNode *tmp = p_cur->next;
				p_cur->next = p_new;
				p_new->next = tmp;
				return 0;
			}
			p_cur = p_cur->next;
		}
		
	return -2;
}

int insert_node_left(struct LinkNode *p_header, int oldVal, int newVal) {
	if (p_header == NULL) {
		return -1;
	}
	struct LinkNode *p_cur = p_header;
	while (p_cur != NULL) {
			if (oldVal == p_cur->next->num) {
				struct LinkNode *p_new = malloc(sizeof(struct LinkNode));
				p_new->num = newVal;
				struct LinkNode *tmp = p_cur->next;
				p_cur->next = p_new;
				p_new->next = tmp;
				return 0;
			}
			p_cur = p_cur->next;
		}
		
	return -2;
}

int del_node(struct LinkNode *p_header, int delVal) {
	if (p_header == NULL) {
		return -1;
	}
	struct LinkNode *p_pre = p_header;
	struct LinkNode *p_cur = p_header->next;
	while (p_cur != NULL) {
		if (p_cur->num == delVal) {
			p_pre->next = p_cur->next;
			free(p_cur);
			return 0;
		}
		p_pre = p_cur;
		p_cur = p_cur->next;
	}
	
	return -2;
}

int clear_ll(struct LinkNode *p_header) {
	if (p_header == NULL) {
		return -1;
	}
	struct LinkNode *p_cur = p_header->next;
	while (p_cur != NULL) {
		struct LinkNode *p_next = p_cur->next;  // 记录释放节点链接的节点地址
		free(p_cur);  // 释放当前节点
		p_cur = p_next;  // 节点往后移动
	}
	p_header->next = NULL;
	printf("------链表清空成功------\n");
	
	return 0;
}

int destory_ll(struct LinkNode *p_header) {
	if (p_header == NULL) {
		return -1;
	}
	struct LinkNode *p_cur = p_header;
	while (p_cur != NULL) {
		struct LinkNode *p_next = p_cur->next;  // 记录释放节点链接的节点地址
		free(p_cur);  // 释放当前节点
		p_cur = p_next;  // 节点往后移动
	}
	printf("------链表销毁成功------\n");
	
	return 0;
}