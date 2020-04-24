#include <stdio.h>

// 选择排序
void my_sort(char *p[], int len) {
	for (int i = 0; i < len; i++) {
		int min = i;
		for (int j = i+1;j < len; j++) {
			if (*p[min] <  *p[j]) {
				min = j;
			}
		}
		if (min != i) {
			char *tmp = p[i];
			p[i] = p[min];
			p[min] = tmp;
		}
	}
}

void print_arr(char *p[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%s ", p[i]);
	}
}

int main(int argc, char *argv[]) {
	char *pArr[] = { "aaa", "bbb", "ccc", "ddd", "fff", "eee"};
	int len = sizeof(pArr) / sizeof(pArr[0]);
	my_sort(pArr, len);
	print_arr(pArr, len);
	
	return 0;
}