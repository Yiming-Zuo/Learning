#include <stdio.h>
#include "linkedlist.h"

// 数组结构体成员
struct Person {
	char name[64];
	int age;
};
// 遍历数组的回调函数
void print_struct(void *data) {
	struct Person *p = data;
	printf("姓名：%s 年龄：%d\n", p->name, p->age); 
}
// 删除元素的回调函数
int compare_struct(void *p_arr, void *p_value) {
	struct Person *p1 = p_arr;
	struct Person *p2 = p_value;
//	if (strcmp(p1->name, p2->name)==0 && p1->age == p2->age) {
//		return 1;
//	}
//	return 0;
	return strcmp(p1->name, p2->name)==0 && p1->age == p2->age;
}

int main(void) {
	struct Person xihong = {"西红", 18};
	struct Person xiaohua = {"小花", 12};
	// 初始化链表
	LinkedList mylist = init_ll();
	// 插入结点
	insert_node(mylist, &xihong, -1);
	insert_node(mylist, &xiaohua, -1);
	insert_node(mylist, &xiaohua, -1);
	insert_node(mylist, &xihong, 1);
	insert_node(mylist, &xiaohua, 1);
	insert_node(mylist, &xihong, -1);
	// 遍历链表
	foreach_ll(mylist, print_struct);
	printf("%d\n", sizeof_ll(mylist));
	
	printf("-------------\n");
	remove_node(mylist, 6);
	foreach_ll(mylist, print_struct);
	printf("%d\n", sizeof_ll(mylist));
	
	printf("-------------\n");
	remove_node_data(mylist, &xihong, compare_struct);
	foreach_ll(mylist, print_struct);
	printf("%d\n", sizeof_ll(mylist));
	
	printf("-------------\n");
	inquire_node(mylist, 2, print_struct);
	
	printf("-------------\n");
	clear_ll(mylist);
	foreach_ll(mylist, print_struct);
	printf("%d\n", sizeof_ll(mylist));
	
	destory_ll(mylist);
//	foreach_ll(mylist, print_struct);
	return 0;
}