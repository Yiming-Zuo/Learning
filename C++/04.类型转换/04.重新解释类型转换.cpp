// reinterpret_cast<type> (expression)
// 将一种数据类型转换为另一种数据类型，不安全
#include <iostream>
using namespace std;

void test() {
	int num = 100;
	char *p = reinterpret_cast<char *> (num);
	cout << p << endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}