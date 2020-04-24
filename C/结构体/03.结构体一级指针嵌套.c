#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
};

struct Person **alloc_arr2(int len) {
	// 1. 在堆区创建一个结构体指针数组
	struct Person **arr = (struct Person **)malloc(sizeof(struct Person *)*len);  // arr:指向3个结构体指针
	//	int len_1 = sizeof(arr) / sizeof(arr[0]);  // error 1
	for (int i = 0;i < len;i++) {
		// 2. 在堆区给结构体指针数组中的每个结构体指针赋值
		arr[i] = (struct Person *)malloc(sizeof(struct Person));  // arr[i]:指向1个结构体
		// 3. 在堆区给结构体变量中的每个指针变量成员赋值
		arr[i]->name = (char *)malloc(sizeof(char)*32);
		sprintf(arr[i]->name, "name_%d", i+1);
		arr[i]->age = i + 18;
	}
	return arr;
}
// 打印结构体指针数组中每个结构体的成员
void print_arr(struct Person **arr, int len) {
	for (int i = 0;i < len;i++) {
		printf("%s %d\n", arr[i]->name, arr[i]->age);	
	}
}
// 释放全部堆区空间
struct Person **free_arr(struct Person **arr, int len) {
	if (arr == NULL || len <= 0) {
		perror("error");
		return NULL;
	}
	for (int i = 0;i < len;i++) {
		// 1. 先释放每个结构体中的指针成员
		if (arr[i]->name != NULL) {
			free(arr[i]->name);
			arr[i]->name = NULL;
		}
		// 2. 再释放结构体指针数组中的每个指针成员
		if (arr[i] != NULL) {
			free(arr[i]);
			arr[i] = NULL;
		}
	}
	// 3. 最后释放结构体二级指针
	free(arr);
	arr = NULL;
	
	return arr;
}

int main(int argc, char *argv[]) {
	int len = 3;
	struct Person **arr = NULL;  
	arr = alloc_arr2(len);
	print_arr(arr, len);
	arr = free_arr(arr, len);
//	printf("%d\n", arr);
	return 0;
}