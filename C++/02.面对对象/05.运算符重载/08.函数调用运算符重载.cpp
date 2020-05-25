#include <iostream>
using namespace std;

class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1+num2;
	}
};

int myadd(int num1, int num2) {
	return num1+num2;
}

int main(int argc, char *argv[]) {
	MyAdd add;
	cout << myadd(10, 29) << endl;  // 普通函数
	cout << add(10, 29) << endl;  // 仿函数，本质是函数对象
	cout << MyAdd()(10, 29) << endl;  // 常用：匿名函数对象MyAdd()执行完自动销毁
	return 0;
}