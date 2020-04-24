#include <stdio.h>

int main(int argc, char *argv[]) {
	int arr[5] = {10, 20, 30, 40, 50};
	printf("%lu\n", sizeof(arr));  // 20 数组名是指针常量(int * const p)
	
	int *p = arr;  // 将数组名指针常量赋给一个指针变量
	printf("%lu\n", sizeof(p));  // 8
	
	return 0;
}