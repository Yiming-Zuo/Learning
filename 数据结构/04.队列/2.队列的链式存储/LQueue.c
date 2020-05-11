#include <stdio.h>
#include "LQueue.h"

struct LQueue {
	struct LinkNode Header;  // 头结点 固定
	int size;
	struct LinkNode *p_tail;  // 尾结点 维护
};

LinkQueue init_queue(void) {
	struct LQueue *myqueue = malloc(sizeof(struct LQueue));
	if (myqueue == NULL) {
		return NULL;
	}
	myqueue->Header.next = NULL;
	myqueue->size = 0;
	myqueue->p_tail = &myqueue->Header;  // !刚开始尾结点指向头结点!
	return myqueue;
}

int push_queue(LinkQueue myqueue, void *data) {
	if (NULL == myqueue || NULL == data) {
		return -1;
	}
	struct LQueue *p = myqueue;
	struct LinkNode *p_new = data;
	p->p_tail->next = p_new;  // 尾插
	p_new->next = NULL;
	p->p_tail = p_new;
	p->size++;
	return 0;
}

int pop_queue(LinkQueue myqueue) {
	if (NULL == myqueue) {
		return -1;
	}
	struct LQueue *p = myqueue;
	if (p->size == 0) {
		return -1;
	}
	
	p->Header.next = p->Header.next->next;
	p->size--;
	if (p->size == 0) {
		p->Header.next=NULL;
		p->p_tail=&p->Header;
	}
	return 0;
}

void *front_queue(LinkQueue myqueue) {
	if (NULL == myqueue) {
		return NULL;
	}
	struct LQueue *p = myqueue;
	if (p->size == 0) {
		return NULL;
	}
	return p->Header.next;
}

void *back_queue(LinkQueue myqueue) {
	if (NULL == myqueue) {
		return NULL;
	}
	struct LQueue *p = myqueue;
	if (p->size == 0) {
		return NULL;
	}
	return p->p_tail;
}

int size_queue(LinkQueue myqueue) {
	if (NULL == myqueue) {
		return -1;
	}
	struct LQueue *p = myqueue;
	return p->size;
}

int isEmpety_queue(LinkQueue myqueue) {
	if (NULL == myqueue) {
		return -1;
	}
	struct LQueue *p = myqueue;
	if (p->size) {
		return 0;
	}
	return 1;
}

int destory_queue(LinkQueue myqueue) {
	if (NULL == myqueue) {
		return -1;
	}
	free(myqueue);
	return 0;
}