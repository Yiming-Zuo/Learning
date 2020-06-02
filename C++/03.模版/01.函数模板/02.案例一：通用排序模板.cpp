#include <iostream>
using namespace std;

template <class T>
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
void mySort(T arr[], int len) {
	for (int i=0; i<len; i++) {
		int max = i;
		for (int j=i+1; j<len; j++) {
			if (arr[max] < arr[j]) {
				max = j;
			}
		}
		if (i != max) {
			mySwap(arr[i], arr[max]);
		}
	}
}

template <class T>
void myPrint(T arr[], int len) {
	for (int i=0; i<len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01(void) {
	int arr[] = {4, 3, 4, 1, 7, 9, 2};
	mySort(arr, sizeof(arr)/sizeof(arr[0]));
	myPrint(arr, sizeof(arr)/sizeof(arr[0]));
}

void test02(void) {
	char arr[] = {'d', 'a', 'b', 'c', 'e', 'f', 'g'};
	mySort(arr, sizeof(arr)/sizeof(arr[0]));
	myPrint(arr, sizeof(arr)/sizeof(arr[0]));
}


int main(int argc, char *argv[]) {
	test01();
	test02();
	return 0;
}