// this指针是隐含在每个类的非静态成员函数中的一种指针(形参、指针常量Person *const this)，成员函数通过this指针知道自己操作的是哪个对象的数据，this指针永远指向当前对象
// 静态成员函数内没有this指针，不能操作非静态成员变量
#include <iostream>
using namespace std;

class Person {
public:
	Person(string name, int age) {
		this->name = name;  // 1.解决命名冲突
		this->age = age;
	}
	// 返回值->调用拷贝构造函数
	Person addAge0(Person &person) {
		this->age += person.age;
		return *this;  // *this:person本身
	}
	// 2.返回对象本身的引用
	Person &addAge(Person &person) {
		this->age += person.age;
		return *this;  // *this:person本身
	}
public:
	string name;
	int age;
};

int main(int argc, char *argv[]) {
	Person p("tom", 13);
	// 链式编程思想
	p.addAge0(p).addAge0(p);  // 返回值，返回的是拷贝构造函数拷贝的新对象p',p'再进行操作
//	p.addAge(p).addAge(p);  // 返回引用是返回对象本身
	cout << p.age << endl; 
	return 0;
}