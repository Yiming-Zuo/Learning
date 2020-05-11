#include "SeqQueue.h"
#include "dynamicArray.h"

SeqQueue init_queue(void) {
	struct dynamicArray *myqueue = init_arr(MAX);
	return myqueue;
}

int push_queue(SeqQueue myqueue, void *data) {
	if (NULL == myqueue || NULL == data) {
		return -1;
	}
	struct dynamicArray *p = myqueue;
	if (p->size == MAX) {
		return -1;
	}
	insert_arr(myqueue, data, p->size);  // 尾插
	return 0;
}

int pop_queue(SeqQueue myqueue) {
	if (NULL == myqueue) {
		return -1;
	}
	struct dynamicArray *p = myqueue;
	if (p->size == 0) {
		return -1;
	}
	delete_ele(p, 0);  // 头删
	return 0;
}

void *front_queue(SeqQueue myqueue) {
	if (NULL == myqueue) {
		return NULL;
	}
	struct dynamicArray *p = myqueue;
	if (p->size == 0) {
		return NULL;
	}
	return p->pAddr[0];
}

void *back_queue(SeqQueue myqueue) {
	if (NULL == myqueue) {
		return NULL;
	}
	struct dynamicArray *p = myqueue;
	if (p->size == 0) {
		return NULL;
	}
	return p->pAddr[p->size-1];
}

int size_queue(SeqQueue myqueue) {
	if (NULL == myqueue) {
		return -1;
	}
	struct dynamicArray *p = myqueue;
	return p->size;
}

int isEmpety_queue(SeqQueue myqueue) {
	if (NULL == myqueue) {
		return -1;
	}
	struct dynamicArray *p = myqueue;
	if (p->size) {
		return 0;
	}
	return 1;
}

int destory_queue(SeqQueue myqueue) {
	if (NULL == myqueue) {
		return -1;
	}
	struct dynamicArray *p = myqueue;
	destory_arr(p);
	return 0;
}
