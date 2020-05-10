// 栈的链式存储：利用链表模拟栈的先进后出的数据结构
#include "lstack.h"

struct Lstack {
	struct LinkNode Header;
	int size;
};

Linkstack init_lstack(void) {
	struct Lstack *mystack = malloc(sizeof(struct Lstack));  // 包含头结点的空间
	mystack->Header.next = NULL;
	mystack->size = 0;
	return mystack;
}

int push_lstack(Linkstack mystack, void *data) {
	if (NULL == mystack || NULL == data) {
		return -1;
	}
	struct Lstack *p = mystack;
	struct LinkNode *p_new = data;  // 读取用户数据前四个字节
	// 头插
	p_new->next = p->Header.next;
	p->Header.next = p_new;
	p->size++;
	return 0;
}

int pop_lstack(Linkstack mystack) {
	if (NULL == mystack) {
		return -1;
	}
	struct Lstack *p = mystack;
	p->Header.next = p->Header.next->next;
	p->size--;
	return 0;
}

int sizeof_lstack(Linkstack mystack) {
	if (NULL == mystack) {
		return -1;
	}
	struct Lstack *p = mystack;
	return p->size;
}

int isEmpety(Linkstack mystack) {
	if (NULL == mystack) {
		return -1;
	}
	struct Lstack *p = mystack;
	if (p->size) {
		return 0;
	}
	return 1;
}

void *top_lstack(Linkstack mystack) {
	if (NULL == mystack) {
		return NULL;
	}
	struct Lstack *p = mystack;
	if (0 == p->size) {
		return NULL;
	}
	return p->Header.next;  // 返回结点（用户数据的首地址）
}

int destory_lstack(Linkstack mystack) {
	if (NULL == mystack) {
		return -1;
	}
	struct Lstack *p = mystack;
	p->Header.next = NULL;
	free(p);
	p = NULL;
	return 0;
}