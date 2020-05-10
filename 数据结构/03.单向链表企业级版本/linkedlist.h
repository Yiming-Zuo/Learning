/* 单向链表企业级版本：
 *  用户数据的前四个字节是结点结构体，记录了下一个结点的地址
 *  结点结构体只维护指针域
 *  链表结构体：头结点、大小
*/
#pragma onece

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 结点结构体
struct LinkNode {
	struct LinkNode *next;  // 只维护指针域
};
// 链表结构体
struct LList {
	struct LinkNode Header;  // 不是指针的话不需要再额外开辟空间
	int size;
};
typedef void * LinkedList;

// 初始化链表
LinkedList init_ll(void);
// 插入元素
int insert_ele(LinkedList mylist, int pos, void *data);
// 遍历链表
void foreach_ll(LinkedList mylist, void(*print_func)(struct LinkNode *));
// 删除元素（位置）
int remove_ele(LinkedList mylist, int pos);
// 删除元素（值）
int remove_value(LinkedList mylist, void *data, int(*compare_func)(void *, void *));
// 销毁链表
int destory_ll(LinkedList mylist);