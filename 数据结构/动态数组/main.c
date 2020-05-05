#include <stdio.h>
#include "dynamicArray.h"

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