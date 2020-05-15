// 内联函数：不会出现宏函数的缺陷，也有宏函数的优点，以空间换时间
#include <iostream>
using namespace std;
// 声明和定义要同时加inline
inline int func(int x, int y);
inline int func(int x, int y) {
	return x+y;
}

int main(int argc, char *argv[]) {
	int num1 = 100;
	int num2 = 200;
	cout << func(num1, num2) << endl;
	return 0;
} 