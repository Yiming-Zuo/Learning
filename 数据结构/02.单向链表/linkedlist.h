/* 链表
 *  1. 初始化链表
 *  2. 插入结点
 *  3. 遍历链表
 *  4. 删除结点
 *  5. 查看指定结点
 *  6. 清空链表
 *  7. 销毁链表
*/
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// void * 别名
// 隐藏真正的链表结构体的属性
typedef void * LinkedList;
// 结点结构体
struct LinkNode {
	void *data;
	struct LinkNode *next;
};
// 链表结构体
struct LList {
	struct LinkNode *p_header;  // 头结点
	int size;  // 结点个数
};

LinkedList init_ll(void); // 初始化链表
int insert_node(LinkedList mylist, void *data, int pos); // 插入结点
void foreach_ll(LinkedList mylist, void(*print_func)(void *)); // 遍历链表
int remove_node(LinkedList mylist, int pos);  // 删除结点（位置）
int remove_node_data(LinkedList mylist, void *data, int(*compare_func)(void *, void *));  // 删除结点（值）
int sizeof_ll(LinkedList mylist);  // 查看链表长度
void inquire_node(LinkedList mylist, int pos, void print_func(void *));  // 查看指定结点
int clear_ll(LinkedList mylist);  // 清空链表
int destory_ll(LinkedList mylist);  // 销毁链表