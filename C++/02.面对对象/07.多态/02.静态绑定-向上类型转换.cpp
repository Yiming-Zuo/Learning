// 父类引用或指针指向子类对象，通过父类指针或引用来操作子类对象
#include <iostream>
using namespace std;

class Animal {
 public:
	void speak() {
		cout << "动物叫\n";
	}	
};

class Dog : public Animal {
 public:
	void speak() {
		cout << "狗叫\n";
	}	
};

// 绑定：把函数体和函数调用相联系
// 地址早绑定：绑定的的是Animal::speak(),而不是传入对象的speak()
void DoSpeak(Animal &animal) {
	animal.speak();
}

int main(int argc, char *argv[]) {
	Dog dog;
	DoSpeak(dog);
	return 0;
}