#include <stdio.h>

// 1. 先定义数组类型，再创建数组指针变量
void func01(void) {	
	typedef int(ARRAY)[5];
	int arr[5] = {10, 20, 30, 40, 50};
	ARRAY *p =  &arr;
	printf("%d", (*p)[0]);
}
// 2. 先定义数组指针类型，再创建数组指针变量
void func02(void) {
	typedef int(*P_ARRAY)[5];
	int arr[5] = {10, 20, 30, 40, 50};
	P_ARRAY p =  &arr;
	printf("%d", (*p)[1]);
}
// 3. 直接创建数组类型变量
void func03(void) {
	int arr[5] = {10, 20, 30, 40, 50};
	int (*p)[5] = &arr;
	printf("%d", (*p)[2]);
}


int main(int argc, char *argv[]) {
//	func01();
//	func02();
//	func03();
	
	return 0;
}