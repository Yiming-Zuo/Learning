// C++类对象中变量和函数是分开存储的
// 每一个非内联成员函数只会诞生一份函数实例，多个同类型的对象共用一块代码
#include <iostream>
using namespace std;

class Myclass01 {
public:
	int m_num;
};

class Myclass02 {
public:
	int m_num;
	static int num;
};

class Myclass03 {
public:
	int m_num;
	static int num;
	void func() {
		this->m_num = 10;  // 哪个对象调用成员函数，this指针就指向谁
	}
};

class Myclass04 {
public:
	int m_num;
	static int num;
	void func() {
		int f_num = 10;
		cout << f_num << endl;
	}
	static void show_num() {
		cout << num << endl;
	}
};

class Myclass05 {
	
};

int main(int argc, char *argv[]) {
	Myclass01 mclass1;
	Myclass02 mclass2;
	Myclass03 mclass3;
	Myclass04 mclass4;
	Myclass05 mclass5;
	
	cout << sizeof(mclass1) << endl;  // 非静态数据成员保存在类对象中
	cout << sizeof(mclass2) << endl;  // 静态数据成员不保存在类对象中
	cout << sizeof(mclass3) << endl;  // 非静态成员函数不保存在类对象中 
	cout << sizeof(mclass4) << endl;  // 静态成员函数不保存在类对象中
	cout << sizeof(mclass5) << endl;  // 空类实例化占一字节，让每个实例在内存中都有独一无二的地址
	return 0;
}