#include <stdio.h>

void my_sort(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		int min = i;
		for (int j = i+1; j < len; j++) {
			if (arr[min] > arr[j]) {  // 更新min
				min = j;
			}
		}
		if (min != i) {
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}

void print_arr(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
}


int main(int argc, char *argv[]) {
	int arr[] = {5, 3, 6, 1, 8, 2, 9, 4};
	int len = sizeof(arr) / sizeof(arr[0]);
	my_sort(arr, len);
	print_arr(arr, len);
	
	return 0;
}