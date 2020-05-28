// 动态绑定：如果类中有虚函数，编译器会创建一张虚函数表，存放虚函数的入口地址，并且在类中增加一个指针，指向虚函数表，在多态调用时根据指针找到虚函数表实现动态绑定
// 编译阶段，vptr指针没有初始化指向虚函数表
// 对象构建时，默认构造函数调用，初始化vptr指针指向本对象的虚函数表
// 子类继承了基类的vptr指针，指针是指向基类虚函数表，当子类调用构造函数，指针指向子类的虚函数表
#include <iostream>
using namespace std;

class Animal {
 public:
	virtual void speak() {
		cout << "动物叫\n";
	}	
};

class Dog : public Animal {
 public:
	void speak() {
		cout << "狗叫\n";
	}	
};

void DoSpeak(Animal &animal) {
	animal.speak();
}

int main(int argc, char *argv[]) {
	Dog dog;
	DoSpeak(dog);  // 回去dog指向的空间寻找vptr指针，通过指针找到子类重写的speak函数
	return 0;
}