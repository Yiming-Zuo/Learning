#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PERSON{ 
	char name[32];
	int age;
};

struct {
	char name[32];
	int age;
} PRESON;  // 1. 匿名结构体变量

void input_struct(struct PERSON *p, int len) {
	for (int i = 0;i < len; i++) {
		sprintf(p[i].name, "xiao_%d", i+1);  // 3. sprintf赋值结构体字符串成员
		p[i].age = i+18;
	}
}

void print_struct(struct PERSON *p, int len) {
	for (int i=0;i<len;i++) {
		printf("%s %d\n", p[i].name, p[i].age);
	}
}
// 2. 堆区存放结构体数组
int main(int argc, char *argv[]) {
//	struct PERSON xiaoming;
//	xiaohong = {"xiaohong", 14};  // error
//	strcpy(xiaoming.name, "xioaming");
//	printf("%s", xiaoming.name);
	
	struct PERSON *p = (struct PERSON *)malloc(sizeof(struct PERSON)*4);
//	*p = {"xiaoong", 18};  // error
	int len = 4;
	input_struct(p, len);
	print_struct(p, len);
	if (p != NULL) {
		free(p);
		p = NULL;
	}
	
	return 0;
}