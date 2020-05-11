#pragma once

#include <stdio.h>
#include <stdlib.h>

struct LinkNode {
	struct LinkNode *next;
};

typedef void * Linkstack;

Linkstack init_lstack(void);  // 初始化栈
int push_lstack(Linkstack mystack, void *data);  // 入栈
int pop_lstack(Linkstack mystack);  // 出栈
int sizeof_lstack(Linkstack mystack);  // 查看栈大小
int isEmpety(Linkstack mystack);  // 判断栈是否为空
void *top_lstack(Linkstack mystack);  // 返回栈顶元素
int destory_lstack(Linkstack mystack);  // 销毁栈