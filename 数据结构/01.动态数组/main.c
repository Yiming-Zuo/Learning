#include <stdio.h>
#include "dynamicArray.h"

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

int main(int argc, char *argv[]) {
	struct Person class[5] = {
			{ "关羽", 18 },
			{ "张飞", 17 },
			{ "刘备", 20 },
			{ "孙尚香", 14 },
			{ "孙权", 21 }
		};
		struct Person xiaohong = {"xiaohong", 13};
		struct dynamicArray *arr = init_arr(5);
		insert_arr(arr, &class[0], 0);
		insert_arr(arr, &class[1], 1);
		insert_arr(arr, &class[2], 2);
		insert_arr(arr, &class[3], 3);
		insert_arr(arr, &class[4], 4);
		printf("容量：%d 大小：%d\n", arr->capacity, arr->size);
		foreach_arr(arr, print_struct);
		printf("\n");
		
		insert_arr(arr, &xiaohong, 5);
		printf("容量：%d 大小：%d\n", arr->capacity, arr->size);
		foreach_arr(arr, print_struct);
		printf("\n");
		
		delete_ele(arr, 2);
		printf("容量：%d 大小：%d\n", arr->capacity, arr->size);
		foreach_arr(arr, print_struct);
		printf("\n");
		
		insert_arr(arr, &xiaohong, 5);
		foreach_arr(arr, print_struct);
		removeByValue(arr, &xiaohong, compare_struct);
		printf("容量：%d 大小：%d\n", arr->capacity, arr->size);
		foreach_arr(arr, print_struct);
		
		destory_arr(arr);
	//	printf("容量：%d 大小：%d\n", arr->capacity, arr->size);
	//	foreach_arr(arr, print_struct);

		return 0;
}