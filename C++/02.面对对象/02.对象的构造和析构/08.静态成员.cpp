// 静态成员变量
// 静态成员变量属于一个类，被所有对象共享
// 静态变量在编译阶段分配空间，不属于某个对象，为对象分配空间时不占空间
// 静态成员变量必须在类中声明，类外定义
// 静态成员变量可以通过类名或者对象名来进行访问
//
// 静态成员函数
// 静态成员函数主要用于管理静态数据成员，完成对静态数据成员的封装，不能访问普通成员变量(无法区分是哪个对象的普通成员变量)
// 普通成员函数可以访问静态成员变量
#include <iostream>
using namespace std;

class Person {
	static int m_id;
public:
	static int m_age;
	static const int m_share = 100;  // const静态成员，既共享，又不可改变，最好在类内初始化
	static void func(int num) {
		m_age = num;
	}
};
// 类外初始化
int Person::m_id = 1;
int Person::m_age = 19;

int main(int argc, char *argv[]) {
	// 访问静态变量(类名)
//	cout << Person::m_id << endl;
	cout << Person::m_age << endl;
	// 通过对象访问变量
	Person tom;
	cout << tom.m_age << endl;
	tom.m_age = 20;
	cout << Person::m_age << endl;
	// 访问静态成员函数
//	tom.func(100);
	Person::func(102);
	cout << Person::m_age << endl;
	
	return 0;
}