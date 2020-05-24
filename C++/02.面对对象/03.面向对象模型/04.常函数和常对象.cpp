// this指针：指针常量 Person *const this
#include <iostream>
using namespace std;

class Person {
public:
	void test01() {
//		this = NULl;  // 指针常量的指向不可以修改
		this->age = 10;  // 指针常量指向的值可以修改
	}
	// 常函数：this指针指向的值也不可以修改
	void test02() const {  // 修饰this指针:const Person *const this
//		this->age = 10;  
	}
public:
	int age;
	mutable int num;  // 在常函数中也可以修改该成员变量
};

int main(int argc, char *argv[]) {
	// 常对象
	const Person person();
	person.age = 20;  // 常对象不可以直接修改成员变量
	person.num = 20;  // mutable修饰的成员变量可以修改
	person.test01();  // 常函数不可以调用普通成员函数，因为普通成员函数可能会修改成员变量
	person.test02();  // 常函数可以调用常函数，因为常函数也不会修改成员变量
}