#include "linkedlist.h"

// 初始化链表
//struct LList *init_ll(void) {
LinkedList init_ll(void) {
	// 开辟链接结构体空间
	struct LList *mylist = malloc(sizeof(struct LList));
	// 不需要开辟头结点结构体空间，如果结构体成员是结点结构体，那么空间已经开辟
	mylist->p_header = malloc(sizeof(struct LinkNode));
	// 头节点初始化
	mylist->p_header->data = NULL;
	mylist->p_header->next = NULL;
	
	mylist->size = 0;
	return mylist;
}
// 插入结点
int insert_node(LinkedList mylist, void *data, int pos) {
	struct LList *p = mylist;  // 将mylist还原成真实的链表结构体
	if (mylist == NULL) {
		return -1;
	}
	if (pos < 0 || pos > p->size) {
		pos = p->size;
	}
	struct LinkNode *p_new = malloc(sizeof(struct LinkNode));
	p_new->data = data;
	p_new->next = NULL;
	
	struct LinkNode *p_cur = p->p_header;  // 插入结点的前驱结点
	for (int i=0; i<pos; i++) {
		p_cur = p_cur->next;
	}
	p_new->next = p_cur->next;  // 先链接新结点和后置结点
	p_cur->next = p_new;  // 在链接前驱结点和新结点
	
	p->size += 1;
	return 0;
}
// 遍历链表
void foreach_ll(LinkedList mylist, void(*print_func)(void *)) {
	if (mylist == NULL) {
		return;
	}
	struct LList *p = mylist;
	struct LinkNode *p_cur = p->p_header->next;
	while (p_cur != NULL) {
		print_func(p_cur->data);
		p_cur = p_cur->next;
	}
}
// 删除结点（位置）
int remove_node(LinkedList mylist, int pos) {
	if (mylist == NULL) {
		return -1;
	}
	struct LList *p = mylist;
	if (pos < 0 || pos > p->size-1) {
		pos = p->size-1;
	}
	struct LinkNode *p_cur = p->p_header;  // 前驱结点
	for (int i=0; i<pos; i++) {
		p_cur = p_cur->next;
	}
	struct LinkNode *p_del = p_cur->next;  // 待删除结点
	p_cur->next = p_del->next;
	free(p_del);
	p_del = NULL;
	
	p->size -= 1;
	return 0;
}
// 删除结点（值）
int remove_node_data(LinkedList mylist, void *data, int(*compare_func)(void *, void *)) {
	if (mylist == NULL || data == NULL) {
		return -1;
	}
	struct LList *p = mylist;
	struct LinkNode *p_cur = p->p_header->next;  // 第0个元素
	int pos = 0;
	while (p_cur != NULL) {
		if (compare_func(p_cur->data, data)) {
			p_cur = p_cur->next;  // 先保存下一个结点
			remove_node(mylist, pos);  // 再删除当前结点
		} else {
			p_cur = p_cur->next;  // 进入下一结点
			pos++;  // 位置+1
		}
	}

	return 0;
}
// 查看链表长度
int sizeof_ll(LinkedList mylist) {
	if (mylist == NULL) {
		return -1;
	}
	struct LList *p = mylist;
	return p->size;
}
// 查看指定结点
void inquire_node(LinkedList mylist, int pos, void print_func(void *)) {
	if (mylist == NULL) {
		return;
	}
	struct LList *p = mylist;
	if (pos < 0 || pos > p->size-1) {
		printf("你傻了？\n");
		return;
	}
	struct LinkNode *p_cur = p->p_header->next;  // 0
	for (int i=0;i<pos;i++) {
		p_cur = p_cur->next;
	}
	print_func(p_cur->data);	
}
// 清空链表
int clear_ll(LinkedList mylist) {
	if (mylist == NULL) {
		return -1;
	}
	struct LList *p = mylist;
	struct LinkNode *p_cur = p->p_header->next;
	for (int i=0; i<p->size; i++) {
		struct LinkNode *p_tmp = p_cur->next;
		free(p_cur);
		p_cur = p_tmp;
	}
	p->p_header->next = NULL;
	p->size = 0;
	return 0;
}
// 销毁链表
int destory_ll(LinkedList mylist) {
	if (mylist == NULL) {
		return -1;
	}
	clear_ll(mylist);
	free(mylist);
	mylist = NULL;
	return 0;
}







//// 数组结构体成员
//struct Person {
//	char name[64];
//	int age;
//};
//// 遍历数组的回调函数
//void print_struct(void *data) {
//	struct Person *p = data;
//	printf("姓名：%s 年龄：%d\n", p->name, p->age); 
//}
//// 删除元素的回调函数
//int compare_struct(void *p_arr, void *p_value) {
//	struct Person *p1 = p_arr;
//	struct Person *p2 = p_value;
////	if (strcmp(p1->name, p2->name)==0 && p1->age == p2->age) {
////		return 1;
////	}
////	return 0;
//	return strcmp(p1->name, p2->name)==0 && p1->age == p2->age;
//}
//
//int main(void) {
//	struct Person xihong = {"西红", 18};
//	struct Person xiaohua = {"小花", 12};
//	// 初始化链表
//	LinkedList mylist = init_ll();
//	// 插入结点
//	insert_node(mylist, &xihong, -1);
//	insert_node(mylist, &xiaohua, -1);
//	insert_node(mylist, &xiaohua, -1);
//	insert_node(mylist, &xihong, 1);
//	insert_node(mylist, &xiaohua, 1);
//	insert_node(mylist, &xihong, -1);
//	// 遍历链表
//	foreach_ll(mylist, print_struct);
//	
//	printf("-------------\n");
//	remove_node(mylist, 6);
//	foreach_ll(mylist, print_struct);
//	
//	printf("-------------\n");
//	remove_node_data(mylist, &xihong, compare_struct);
//	foreach_ll(mylist, print_struct);
//	
//	printf("-------------\n");
//	inquire_node(mylist, 2, print_struct);
//	
//	printf("-------------\n");
//	clean_ll(mylist);
//	foreach_ll(mylist, print_struct);
//	
//	struct LList *p = mylist;
//	printf("%d\n", p->size);
//	
//	destory_ll(mylist);
////	foreach_ll(mylist, print_struct);
//	return 0;
//}