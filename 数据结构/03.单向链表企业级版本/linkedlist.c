#include "linkedlist.h"

// 初始化链表
LinkedList init_ll(void) {
	struct LList *mylist = malloc(sizeof(struct LList));
	mylist->Header.next = NULL;
	mylist->size = 0;
	return mylist;
}
// 插入元素
int insert_ele(LinkedList mylist, int pos, void *data) {
	if (mylist == NULL) {
		return -1;
	}

	struct LList *p = mylist;
	if (pos<0 || pos>p->size) {
		pos = p->size;
	}
	struct LinkNode *p_cur = &p->Header;  // 前驱结点
	for (int i=0; i<pos; i++) {
		p_cur = p_cur->next;
	}
	// 读取用户数据前四个字节
	struct LinkNode *p_user = data;
	p_user->next = p_cur->next;
	p_cur->next = p_user;
	
	p->size++;
	return 0;
}
// 遍历链表
void foreach_ll(LinkedList mylist, void(*print_func)(struct LinkNode *)) {
	if (mylist == NULL) {
		return;
	}
	struct LList *p = mylist;
	// 取出用户数据前4个字节
	struct LinkNode *p_cur = p->Header.next;
	for (int i=0; i<p->size; i++) {
		print_func(p_cur);  // p_cur就是用户数据的首地址，也是结点的首地址
		p_cur = p_cur->next;
	}
}
// 删除元素（位置）
int remove_ele(LinkedList mylist, int pos) {
	if (NULL == mylist) {
		return -1;
	}
	struct LList *p = mylist;
	if (pos<0 || pos > p->size-1) {
		printf("你傻了？\n");
		return -1;
	}
	struct LinkNode *p_cur = &p->Header;
	for (int i=0;i<pos;i++) {
		p_cur = p_cur->next;
	}
	p_cur->next = p_cur->next->next;
	p->size--;
	return 0;
}
// 删除元素（值）
int remove_value(LinkedList mylist, void *data, int(*compare_func)(void *, void *)) {
	if (NULL == mylist || NULL == data) {
		return -1;
	}
	struct LList *p = mylist;
	struct LinkNode *p_pre = &p->Header;
	for (int i=0; i<p->size; i++) {
		if (compare_func(p_pre->next, data)) {
			p_pre->next = p_pre->next->next;
			p->size--;
			break;
		}
		p_pre = p_pre->next;
	}
	return 0;
}
// 销毁链表
int destory_ll(LinkedList mylist) {
	if (NULL == mylist) {
		return -1;
	}
	free(mylist);
	mylist = NULL;
	return 0;
}