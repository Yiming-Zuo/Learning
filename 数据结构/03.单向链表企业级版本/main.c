#include <stdio.h>
#include "linkedlist.h"

// 用户数据，首地址包含结点结构体，记录了下一个结点地址
struct Person {
//	int a;  // 也是4个字节
	struct LinkNode Node;
	char name[64];
	int age;
};
// 遍历链表的回调函数
void print_struct(struct LinkNode *data) {
	if (data == NULL) {
		return;
	}
	struct Person *p = (struct Person *)data;
	printf("姓名：%s 年龄：%d\n", p->name, p->age);
}
// 删除元素的回调函数
int compare_struct(void *p_arr, void *p_value) {
	struct Person *p1 = p_arr;
	struct Person *p2 = p_value;
	return strcmp(p1->name, p2->name)==0 && p1->age == p2->age;
}


int main(int argc, char *argv[]) {
	struct Person xixi = {NULL, "嘻嘻", 18};
	struct Person haha = {NULL, "哈哈", 19};
	struct Person shabi = {NULL, "傻逼", 12};
	LinkedList mylist = init_ll();
	insert_ele(mylist, 0, &xixi);
	insert_ele(mylist, 2, &haha);
	insert_ele(mylist, 1, &shabi);
	foreach_ll(mylist, print_struct);
	printf("--------------------------------\n");
	remove_ele(mylist, 1);
	foreach_ll(mylist, print_struct);
	printf("--------------------------------\n");
	remove_value(mylist, &xixi, compare_struct);
	foreach_ll(mylist, print_struct);
	printf("--------------------------------\n");
	destory_ll(mylist);
	return 0;
}