// 静态多态（地址早绑定，静态联编，编译时多态）：编译时可以确定函数的代码
//  1.运算符重载
//  2.函数重载
// 动态多态（地址晚绑定，动态联编，运行时多态）：运行时才能确定函数的代码
//  1.虚函数
//  c++中父类的指针或者引用可以指向子类的对象
//  2.派生类
#include <iostream>
using namespace std;

class Animal {
 public:
	// 虚函数
	virtual void speak() {
		cout << "动物说话\n";
	}	
};

class Cat : public Animal {
 public:
	virtual void speak() {
		cout << "猫说话\n";
	}	
};

class Dog : public Animal {
 public:
	virtual void speak() {
		cout << "狗说话\n";
	}	
};

void doSpeak(Animal &animal) {  // 父类的引用可以指向子类对象
	animal.speak();  // 如果传入参数是父类，地址早绑定，speak的函数地址已经确定
	// 如果传入参数是子类，地址晚绑定
}


int main(int argc, char *argv[]) {
	Cat cat;
	Dog dog;
	doSpeak(cat);
	doSpeak(dog);
	return 0;
}