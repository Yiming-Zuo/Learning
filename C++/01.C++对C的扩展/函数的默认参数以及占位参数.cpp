#include <iostream>
using namespace std;

// 1 默认参数
// 函数的声明和定义只能有一个有默认参数
int func01(int x, int y);
int func01(int x, int y=20) {
	return x+y;
}
// 2 占位参数
// 只声明形参类型，不声明形参变量名，调用函数时必须传入数值
// 占位参数也可以设置默认值
// int func02(int x, int y, int = 10);
int func02(int x, int y, int) {
	return x+y;
}

int main(int argc, char *argv[]) {
	int x = 1;
	cout << func01(x) << endl;
	
	cout << func02(x, 10, 1) << endl;
	return 0;
}