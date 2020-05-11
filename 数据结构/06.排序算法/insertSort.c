#include <stdio.h>

void insertSort(int *arr, int len) {
	for (int i=1;i<len;i++) {
		if(arr[i]<arr[i-1]) {
			int tmp = arr[i];
			int j = i-1;
			for (;j>=0&&arr[j]>tmp;j--) {
				arr[j+1] = arr[j];
			}
			arr[j+1] = tmp;
		}
	}
}

void insertSort_re(int *arr, int len) {
	for (int i=1;i<len;i++) {
		if(arr[i]>arr[i-1]) {
			int tmp = arr[i];
			int j = i-1;
			for (;j>=0&&arr[j]<tmp;j--) {
				arr[j+1] = arr[j];
			}
			arr[j+1] = tmp;
		}
	}
}

int main(int argc, char *argv[]) {
	int arr[] = {4, 2, 8, 0, 5, 7, 1, 3, 9};
	int len = sizeof(arr) / sizeof(arr[0]);
	insertSort(arr, len);
	insertSort_re(arr, len);
	for (int i=0;i<len;i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}