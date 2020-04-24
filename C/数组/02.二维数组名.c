#include <stdio.h>

// 1. 二维数组名
void func01(void){
	int arr[3][4] = {
		{1, 2, 3, 0}, 
		{4, 5, 6, 0}, 
		{7, 8, 9, 0} };
	int (*p)[4] = arr;  // 一般情况下，二维数组名指向第一行数组指针，p是指向第一个行数组的数组指针(arr)
//	int (*p) = &arr // 一位数组，p是指向数组的指针
	
	printf("%d\n", *(*p+6));  // p是一个数组指针，*p是一个数组
	printf("%d\n", *(*(p+1)+2));  // p+1 指向第二个行数组的数组指针，*(p+1)第二个行数组首元素
	printf("%d\n", p[1][2]); // p == arr
}
// 2. 二维数组名难过作为函数的参数
//void printf_arr2(int (*p)[4], int row, int col) {
void printf_arr2(int p[3][4], int row, int col) {
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int arr[3][4] = {
		{1, 2, 3, 0}, 
		{4, 5, 6, 0}, 
		{7, 8, 9, 0} };	
	printf_arr2(arr, 3, 4);
}