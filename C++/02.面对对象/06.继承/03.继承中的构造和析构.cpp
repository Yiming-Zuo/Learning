// 当创建一个子类对象时，先调用父类构造函数，再调用类成员的构造函数，最后调用子类的构造函数，析构的顺序与构造相反
// 当父类中有有参构造函数时，创建子类对象时需要使用初始化列表方法调用父类的有参构造函数
#include <iostream>
using namespace std;

class Info {
 public:
	Info() {
		cout << "Info的普通构造函数调用" << endl;
	}
	~Info() {
		cout << "Info的析构函数调用" << endl;
	}
 public:
	int id;
};

class BaseClass {
 public:
	BaseClass() {
		cout << "BaseClass的普通构造函数调用" << endl;
	}
	BaseClass(int n) : num(n) {
		cout << "BaseClass的有参构造函数调用" << endl;
	}
	~BaseClass() {
		cout << "BaseClass的析构函数调用" << endl;
	}
 private:
	int num;	
};

class SonClass : public BaseClass {
 public:
	SonClass() : BaseClass(100) {
		cout << "SonClass的普通构造函数调用" << endl;
	}
	SonClass(int num) : BaseClass(num) {
		cout << "SonClass的普通构造函数调用" << endl;
	}
	~SonClass() {
		cout << "SonClass的析构函数调用" << endl;
	}
 public:
	Info info;
};

int main(int argc, char *argv[]) {
	SonClass son;
//	SonClass son(100);
	return 0;
}