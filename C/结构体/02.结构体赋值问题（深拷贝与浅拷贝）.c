#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PEOPLE1 {
	char name[32];
	int age;
};
// 栈区（浅拷贝）
void func01(void) {
	struct PEOPLE1 Tom = {"Tom", 15};
	struct PEOPLE1 Jerry = {"Jerry", 16};
	Tom = Jerry;  // 浅拷贝（逐字节拷贝）
	
	printf("%s %d\n", Tom.name, Tom.age);
}


struct PEOPLE2 {
	char *name;
	int age;
};
// 栈区（深拷贝）
void func02(void) {
	struct PEOPLE2 Tom;
	Tom.name = (char *)malloc(sizeof(sizeof(char)*32));
	strcpy(Tom.name, "Tom");
	Tom.age = 17;
	
	struct PEOPLE2 Jerry;
	Jerry.name = (char *)malloc(sizeof(sizeof(char)*32));
	strcpy(Jerry.name, "Jerry");
	Jerry.age = 18;
	
	// 浅拷贝
//	Tom = Jerry;
	
	// 深拷贝
	// 1. 释放原有堆区空间
	if (Tom.name != NULL) {
		free(Tom.name);
		Tom.name = NULL;
	}
	// 2. 重新申请堆区空间
	Tom.name = (char *)malloc(strlen(Jerry.name)+1);
	// 3. 拷贝数据
	strcpy(Tom.name, Jerry.name);
	Tom.age = Jerry.age;
	printf("%s %d\n", Tom.name, Tom.age);
	
	if (Tom.name != NULL) {
		free(Tom.name);
		Tom.name = NULL;
	}
	/* 由于浅拷贝 Tom.name == Jerry.name
	 * 造成：
	 * 	1. 堆区重复释放
	 * 	2. 内存泄漏  */
	if (Jerry.name != NULL) {
		free(Jerry.name);
		Jerry.name = NULL;
	}
}



int main(int argc, char *argv[]) {
//	func01();
	func02();
	return 0;
}