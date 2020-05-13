#include <stdio.h>

int add(int x, int y) {
	return x+y;
}

int main(int argc, char *argv[]) {
	printf("add(10, 20)=%d\n", add(10, 20));
	// 1 先定义函数类型，根据类型定义函数指针变量
	typedef int(FUNC)(int, int);  // 未函数类型重命名
	FUNC *p1 = add;
	printf("p1(10, 20)=%d\n", p1(10, 20));
	// 2 先定义函数指针类型，根据类型定义函数指针变量
	typedef int(*P_FUNC)(int, int);  // 未函数类型重命名
	P_FUNC p2 = add;
	printf("p2(10, 20)=%d\n", p1(10, 20));
	// 3 直接定义函数指针变量
//	int *p3 = add;  // 看警告
	int(*p3)(int, int) = add;
	printf("p3(10, 20)=%d\n", p3(10, 20));
	
	return 0;
}