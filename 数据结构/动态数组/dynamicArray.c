/* 动态数组：将数组开辟到堆区，实现动态扩展
 * 需求：
 * 1.分文件编写，方便重复使用
 * 功能：
 * 1.初始化数组
 *  * 用户的数据类型无法确定
 *  * 用户的数据无法确定实在堆区还是栈上
 *  * 需要直接维护用户数据的地址(void *data)
 * 2.插入元素
 * 3.遍历数组
 * 4.删除元素
 * 5.销毁数组
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamicArray.h"

// 返回数组结构体指针
struct dynamicArray *init_arr(int capacity) {
	if (capacity <= 0) {
		return NULL;
	}
	struct dynamicArray *arr = malloc(sizeof(struct dynamicArray));
	arr->pAddr = malloc(sizeof(void *) * capacity);  // 二级指针申请地址用万能指针大小
	arr->capacity = capacity;
	arr->size = 0;
	return arr;
}


// 成功返回0
int insert_arr(struct dynamicArray *arr, void *data, int pos) {
	if (arr == NULL || data == NULL) {
		return -1;
	}
	// 如果数组容量已满（容量为5，插入5位置，已有01234）
	if (arr->size == arr->capacity) {
		// 1.重新申请空间
		void **newSpace = malloc(sizeof(void *) * arr->capacity * 2);
		// 2.复制原有数据到新空间
		memcpy(newSpace, arr->pAddr, sizeof(void *) * arr->capacity);
		// 3.释放原有空间
		free(arr->pAddr);
		// 4.改变指针走向
		arr->pAddr = newSpace;
		arr->capacity *= 2; 
	}
	if (pos < 0 || pos >= arr->capacity) {
		pos = arr->size;
	}
	// pos后的元素从后向前往后移动一位
	for(int i=arr->size; i>pos; i--) {
		arr->pAddr[i] = arr->pAddr[i-1];  // 空出来p[pos]
	}
	arr->pAddr[pos] = data;
	// 更新数组大小
	arr->size += 1;
	return 0;
}
// 遍历
void foreach_arr(struct dynamicArray *arr, void p_func(void *data)) {
	if (arr == NULL) {
		return;
	}
	for (int i=0; i<arr->size; i++) {
		p_func(arr->pAddr[i]);
	}
}
// 遍历的回调函数
void print_struct(void *data) {
	struct Person *p = data;
	printf("姓名：%s 年龄：%d\n", p->name, p->age); 
}
// 按位置删除元素
int delete_ele(struct dynamicArray *arr, int pos) {
	if (arr == NULL) {
		return -1;
	}
	if (pos >= arr->size || pos < 0) {
		pos = arr->size-1;
	}
	// free(arr->pAddr[pos]);  // 无需释放
	for (int i=pos; i<arr->size-1; i++) {
		arr->pAddr[i] = arr->pAddr[i+1];
	}
	arr->size -= 1;
	return 0;
}
// 按值方式删除元素
int removeByValue(struct dynamicArray *arr, void *value, int(*my_compare)(void *, void *)) {
	if (arr == NULL || value == NULL) {
		return -1;
	}
	for (int i=0; i<arr->size; i++) {
		// if (arr->pAddr == value) {  // 对比地址
		if (my_compare(arr->pAddr[i], value)) {  // 对比数据
			printf("删除第%d个元素\n", i);
			delete_ele(arr, i);  // 调用按位置删除函数
			i--;  // 按位置删除后下一个元素前移一位，需重新遍历第i个元素
		}
	}
	return 0;
}
int compare_struct(void *p_arr, void *p_value) {
	struct Person *p1 = p_arr;
	struct Person *p2 = p_value;
	if (strcmp(p1->name, p2->name)==0 && p1->age == p2->age) {
		return 1;
	}
	return 0;
}


// 销毁数组
int destory_arr(struct dynamicArray *arr) {
	if (arr == NULL) {
		return -1;
	}
	if (arr->pAddr != NULL) {
		free(arr->pAddr);
		arr->pAddr = NULL;
	}
	free(arr);
	arr = NULL;
	return 0;
}




#if 0
int main(void) {
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
	delete_ele(arr, 11);
	printf("容量：%d 大小：%d\n", arr->capacity, arr->size);
	foreach_arr(arr, print_struct);
	
	destory_arr(arr);
//	printf("容量：%d 大小：%d\n", arr->capacity, arr->size);
//	foreach_arr(arr, print_struct);

	return 0;
}
#endif