#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Teacher {
	char *name;
	char **students;
};
// 为结构体内二级指针成员申请空间
char **alloc_students(int i) {
	char **tmp = (char **)malloc(sizeof(char *)*3);  // 堆区字符串二级指针
	for (int j=0;j<3;j++) {
		tmp[j] = (char *)malloc(sizeof(char)*32);  // 堆区字符串指针
		sprintf(tmp[j], "student_%d_%d", i+1, j+1);
	}
	return tmp;
}
// 结构体申请空间
struct Teacher **alloc_space(int len) {
	struct Teacher **tmp = (struct Teacher **)malloc(sizeof(struct Teacher) * len);  // 堆区结构体二级指针
	for (int i=0;i<len;i++) {
		tmp[i] = (struct Teacher *)malloc(sizeof(struct Teacher));  // 堆区结构体一级指针
		tmp[i]->name = (char *)malloc(sizeof(char)*32);
		sprintf(tmp[i]->name, "teacher_%d", i+1);
		tmp[i]->students = alloc_students(i);
	}
	return tmp;
}
// 打印
void print_arr(struct Teacher **arr, int len) {
	for (int i=0;i<len;i++) {
		printf("%s\n", arr[i]->name);
		for (int j=0;j<3;j++) {
			printf("%s ", (arr[i]->students)[j]);
			printf("\n");
		}
	}
}
// 释放空间
void free_all(struct Teacher ***p, int len) {
	struct Teacher **arr = *p;
	if (arr == NULL || len <= 0) {
		perror("error");
		return;
	}
	for (int i=0;i<len;i++) {
		// 1. 先释放二级指针成员指向的字符串指针
		for (int j=0;j<3;j++) {
			if ((arr[i]->students)[j] != NULL) {
				free((arr[i]->students)[j]);
				(arr[i]->students)[j] = NULL;
			}
		}
		// 2. 释放二级指针成员和指针成员
		if (arr[i]->students != NULL) {
			free(arr[i]->students);
			arr[i]->students = NULL;
		}
		if (arr[i]->name != NULL) {
			free(arr[i]->name);
			arr[i]->name = NULL;
		}
		// 3. 释放结构体指针
		if (arr[i] != NULL) {
			free(arr[i]);
			arr[i] = NULL;
		}
	}
	// 4. 释放结构体数组指针
	free(arr);
	arr = NULL;
	*p = arr;
}


int main(int argc, char *argv[]) {
	int len = 3;
	struct Teacher **arr = NULL;
	arr = alloc_space(len);
	print_arr(arr, len);
	free_all(&arr, len);
	printf("%d", arr);
	return 0;
}