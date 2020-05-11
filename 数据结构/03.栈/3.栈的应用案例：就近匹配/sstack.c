/* 栈的顺序存储：利用数组模拟出栈先进后出的数据结构
 * struct SStack *init_sstack(void);  // 初始化栈
 * int push_sstack(struct SStack *mystack, void *data);  // 入栈
 * int pop_sstack(struct SStack *mystack)  // 出栈
 * int sizeof_sstack(struct SStack *mystack);  // 查看栈大小
 * int isEmpety(struct SStack *mystack)  // 判断栈是否为空
 * void top_sstack(struct SStack *mystack, void(*print_func)(void *))  // 查看栈顶元素
 * int destory_sstack(struct SStack *mystack)  // 销毁栈
 */
#include "sstack.h"

struct SStack {
	void *data[MAX];
	int size;
};

sstack init_sstack(void) {
	struct SStack *mystack = malloc(sizeof(struct SStack));
	memset(mystack->data, 0, sizeof(void *)*MAX);  // 数组清零
	mystack->size=0;
	return mystack;
}

int push_sstack(sstack p, void *data) {
	if (NULL == p || NULL == data) {
		return -1;
	}
	struct SStack *mystack = p;
	// 判断栈是否已满
	if (mystack->size == MAX) {
		return -2;
	}
	mystack->data[mystack->size]=data;
	mystack->size++;
	return 0;
}

int pop_sstack(sstack p) {
	if (NULL == p) {
		return -1;
	}
	struct SStack *mystack = p;
	// 判断栈是否为空
	if (mystack->size == 0) {
		return -1;
	}
	mystack->data[mystack->size-1]=NULL;
	mystack->size--;
	return 0;
}

int sizeof_sstack(sstack p) {
	if (NULL == p) {
			return -1;
	}
	struct SStack *mystack = p;
	return mystack->size;
}

int isEmpety(sstack p) {
	if (NULL == p) {
			return -1;
	}
	struct SStack *mystack = p;
	if (mystack->size) {
		return 0;
	}
	return 1;
}

void *top_sstack(sstack p) {
	if (NULL == p) {
			return NULL;
	}
	struct SStack *mystack = p;
	// 判断栈是否为空
	if (mystack->size == 0) {
		return NULL;
	}
	return mystack->data[mystack->size-1];
}

int destory_sstack(sstack p) {
	if (NULL == p) {
			return -1;
	}
	struct SStack *mystack = p;
	free(mystack);
	mystack = NULL;
	return 0;
}