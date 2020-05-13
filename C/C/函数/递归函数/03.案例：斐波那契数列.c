// 递归函数案例三：斐波那契数列
//  给定结束条件，从结束条件慢慢回传。
#include <stdio.h>

int fibonacci(int pos) {
	if (pos == 1 || pos == 2) {
		return 1;
	}
	return fibonacci(pos-1)+fibonacci(pos-2);
}

int main(int argc, char *argv[]) {
	int num = fibonacci(3);
	printf("%d\n", num);
	return 0;
}