/* 案例四：实现任意数组排序（冒泡排序、选择排序）
 * 1. 通过(数组指针+size*i)找到第i个元素的指针
 * 1. 申请size字节的堆区空间存放中间值
 * 2. 通过内存拷贝size字节实现数组中的元素交换
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char name[64];
	int age;
};
/* ---------- mySort ---------- */
int compareInt(void *p_i, void *p_j) {
	int *p1 = p_i;
	int *p2 = p_j;
#if 0
	if (*p1 > *p2) {
		return 1;
	} else {
		return 0;
	}
#endif
	return (*p1 > *p2);
}

int compareFloat(void *p_i, void *p_j) {
	float *p1 = p_i;
	float *p2 = p_j;
	if (*p1 > *p2) {
		return 1;
	} else {
		return 0;
	}
}

int comparePerson(void *p_i, void *p_j) {
	struct Person *p1 = p_i;
	struct Person *p2 = p_j;
	if (p1->age > p2->age) {
		return 1;
	} else {
		return 0;
	}
}
// 冒泡排序
void mySort1(void *p_arr, int len, int size, int(*p_func)(void *, void *)) {
	void *tmp = malloc(size);
	for (int i=0;i<len;i++) {
		void *p_i = p_arr + size*i;
		for (int j=i+1;j<len;j++) {
			void *p_j = p_arr + size*j;
			if (p_func(p_i, p_j)) {
				// 通过内存拷贝实现交换
				memcpy(tmp, p_i, size);
				memcpy(p_i, p_j, size);
				memcpy(p_j, tmp, size);	
			}
		}
	}
	if (tmp != NULL) {
		free(tmp);
		tmp = NULL;
	}
}
// 选择排序
void mySort2(void *p_arr, int len, int size, int(*p_func)(void *, void *)) {
	void *tmp = malloc(size);
	for (int i=0;i<len;i++) {
		int min = i;
		for (int j=i+1;j<len;j++) {
			void *p_min = p_arr + size*min;
			void *p_j = p_arr + size*j;
			if (p_func(p_min, p_j)) {
				min = j;
			}
		}
		if (min != i) {
			void *p_min = p_arr + size*min;
			void *p_i = p_arr + size*i;
			// 通过内存拷贝实现交换
			memcpy(tmp, p_i, size);
			memcpy(p_i, p_min, size);
			memcpy(p_min, tmp, size);
		}
	}

	if (tmp != NULL) {
		free(tmp);
		tmp = NULL;
	}
}
/* ---------- print_arr ---------- */
void print_int(void *p_data) {
	int *p = p_data;
	printf("%d ", *p);
}

void print_float(void *p_data) {
	float *p = p_data;
	printf("%.1f ", *p);
}

void print_Person(void *p_data) {
	struct Person *p = p_data;
	printf("%s:%d\n", p->name, p->age);
}

void print_arr(void *p_arr, int len, int size, void(*p_func)(void *)) {
	for (int i=0;i<len;i++) {
		void *p = p_arr + i*size;
		p_func(p);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	// int
	int arr_int[5] = {23, 55, 22, 11, 66};
	mySort1(arr_int, 5, sizeof(int), compareInt);
	print_arr(arr_int, 5, sizeof(int), print_int);
	// float
	float arr_f[6] = {23.2, 34.3, 12.2, 66.4, 22.3, 22.1};
	mySort1(arr_f, 5, sizeof(int), compareFloat);
	print_arr(arr_f, 5, sizeof(int), print_float);
	// struct Person
	struct Person class[5] = {
		{ "jerry", 23 },
		{ "tom", 22 },
		{ "pony", 13 },
		{ "jack", 25 },
		{ "tony", 21 }
	};
	mySort2(class, 5, sizeof(struct Person), comparePerson);
	print_arr(class, 5, sizeof(struct Person), print_Person);
	return 0;
}