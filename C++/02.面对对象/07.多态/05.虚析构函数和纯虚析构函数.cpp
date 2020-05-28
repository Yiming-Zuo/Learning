// 虚析构函数：
// 解决多态不调用子类析构函数的问题
// 纯虚析构函数(类内声明，类外定义)：
// 有纯虚析构函数的类是抽象类，不能创建对象
#include <iostream>
using namespace std;

class Animal {
 public:
	Animal() {
		cout << "animal的构造函数调用\n";
	}
	// 如果不是虚析构函数，无法调用子类的析构函数
//	virtual ~Animal() {
//		cout << "animal的析构函数调用\n";
//	}
	virtual ~Animal() = 0;  // 纯虚析构函数
	virtual void speak() = 0;
	char *name;
};
// 纯虚析构函数的类外定义
Animal::~Animal() {
	cout << "animal的析构函数调用\n";
}

class Dog : public Animal {
 public:
	Dog(char *str) {
		cout << "dog的构造函数调用\n";
		this->name = new char[strlen(str)+1];
		strcpy(this->name, str);
	}
	~Dog() {
		cout << "dog的析构函数调用\n";
		if (NULL != this->name) {
			delete []name;
			name = NULL;
		}
	}
	void speak() {
		cout << name << "狗在叫\n";
	}
};

void test(void) {
	Animal *dog = new Dog("tom");
	dog->speak();
	delete dog;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}