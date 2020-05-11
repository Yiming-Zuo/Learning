// 使用链表实现队列先进先出的数据结构
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef void * LinkQueue;

struct LinkNode {
	struct LinkNode *next;
};

LinkQueue init_queue(void);  // 初始化队列
int push_queue(LinkQueue myqueue, void *data);  // 入队
int pop_queue(LinkQueue myqueue);  // 出队
void *front_queue(LinkQueue myqueue);  // 返回队头元素
void *back_queue(LinkQueue myqueue);  // 返回队尾元素
int size_queue(LinkQueue myqueue);  // 返回队列大小
int isEmpety_queue(LinkQueue myqueue);  // 判断队列是否为空
int destory_queue(LinkQueue myqueue); // 销毁队列