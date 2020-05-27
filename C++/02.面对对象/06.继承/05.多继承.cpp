// 多继承：作用域区分同名成员
#include <iostream>
using namespace std;

class BaseClass1 {
 public:
	BaseClass1() {
		num = 10;
	}
	int num;
};

class BaseClass2 {
 public:
	BaseClass2() {
		num = 20;
	}
	int num;
};

// 多继承
class Son : public BaseClass1, public BaseClass2 {
 public:
	Son() {
		num = 30;
	}
	int num;
};

int main(int argc, char *argv[]) {
	cout << sizeof(BaseClass1) << endl;
	cout << sizeof(BaseClass2) << endl;
	cout << sizeof(Son) << endl;
	cout << endl;
	Son s;
	cout << s.num << endl;
	cout << s.BaseClass1::num << endl;
	cout << s.BaseClass2::num << endl;
	return 0;
}