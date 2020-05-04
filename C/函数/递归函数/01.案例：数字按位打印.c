#include <stdio.h>

void print_num(int num) {
	if (num < 10) {
		printf("%d\n", num);
		return;
	}
	print_num(num/10);  // 当num/10<10时，开始return
	printf("%d\n", num % 10);
}

int main(int argc, char *argv[]) {
	int num = 8793;
	print_num(num);
}