// 利用动态数组实现队列先进先出的数据结构
#pragma once
#include <stdio.h>

#define MAX 1024

typedef void * SeqQueue;

SeqQueue init_queue(void);  // 初始化队列
int push_queue(SeqQueue myqueue, void *data);  // 入队
int pop_queue(SeqQueue myqueue);  // 出队
void *front_queue(SeqQueue myqueue);  // 返回队头元素
void *back_queue(SeqQueue myqueue);  // 返回队尾元素
int size_queue(SeqQueue myqueue);  // 返回队列大小
int isEmpety_queue(SeqQueue myqueue);  // 判断队列是否为空
int destory_queue(SeqQueue myqueue); // 销毁队列