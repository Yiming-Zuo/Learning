#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef void * sstack;

// 放到.c文件中，隐藏结构体
//struct SStack {
//	void *data[MAX];
//	int size;
//};

sstack init_sstack(void);
int push_sstack(sstack p, void *data);
int pop_sstack(sstack p);
int sizeof_sstack(sstack p);
int isEmpety(sstack p);
void top_sstack(sstack p, void(*print_func)(void *));
int destory_sstack(sstack p);