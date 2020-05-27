// 非静态成员
//  1.访问父类中同名的成员：加作用域
//  2.父类中同名函数的重载函数也需要加作用域
// 静态成员
//  1.通过类名访问：加作用域
//  2.通过对象名访问：加作用域
#include <iostream>
using namespace std;

class BaseClass {
 public:
	BaseClass() {
		num = 10;
	}
	void func() {
		cout << "baseclass的func调用\n";
	}
	void func(int n) {
		cout << n << endl;
	}
	static void show() {
		cout << "baseclass的show调用\n";
	}
 public:
	int num;
	static int id;
};
int BaseClass::id = 1000;  // 类内声明，类外定义

class Son : public BaseClass {
 public:
	Son() {
		num = 100;
	}
	void func() {
		cout << "son的func调用\n";
	}
	static void show(int num) {
		cout << num << endl;
	}
 public:
	int num;
	static int id;
};
int Son::id = 20;

int main(int argc, char *argv[]) {
	Son son;
	cout << son.num << endl;
	son.func();
	// 1.访问父类中同名的成员：加作用域
	cout << son.BaseClass::num << endl;
	son.BaseClass::func();
	// 2.父类中同名函数的重载函数也需要加作用域
//	son.func(10);
	son.BaseClass::func(1000);
	// 1.通过对象访问同名静态成员
	son.show(30);
	cout << son.id << endl;
	
	son.BaseClass::show();
	cout << son.BaseClass::id << endl;
	// 2.通过类名访问同名静态成员
	Son::show(40);
	cout << Son::id << endl;
	
	Son::BaseClass::show();
	cout << Son::BaseClass::id << endl;
	return 0;
}