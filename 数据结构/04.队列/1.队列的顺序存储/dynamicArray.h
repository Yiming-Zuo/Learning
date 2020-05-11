/* 动态数组：将数组开辟到堆区，存放每一个元素，实现动态扩展
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
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 动态数组结构体
struct dynamicArray {
	void **pAddr;  // 维护真实数组的指针（堆区）
	int capacity;  // 数组容量
	int size;  // 数组大小
};

// 初始化数组
struct dynamicArray *init_arr(int capacity);
// 插入元素
int insert_arr(struct dynamicArray *arr, void *data, int pos);
// 遍历数组
void foreach_arr(struct dynamicArray *arr, void p_func(void *data));
// 删除元素
int delete_ele(struct dynamicArray *arr, int pos);  // 位置
int removeByValue(struct dynamicArray *arr, void *value, int(*my_compare)(void *, void *));  // 值
// 销毁数组
int destory_arr(struct dynamicArray *arr);