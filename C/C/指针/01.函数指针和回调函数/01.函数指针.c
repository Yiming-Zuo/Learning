#include <stdio.h>

int func(int a, int b) {
	printf("%d\n", a+b);
	return 0;
}

int main(int argc, char *argv[]) {
	func(10, 20);
	printf("%p\n", func);  // 函数名：函数入口的地址
//	int (*p)(int, int) = (int (*)(int, int))0x10e1c2ef0;  // 函数指针：指向函数入口地址的指针
	int (*p)(int, int) = func;
	p(10, 20);
	
	return 0;
}