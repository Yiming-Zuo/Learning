// 运算符new:动态内存分配，在堆区为对象开辟空间并调用构造函数完成初始化
// 运算符delete:先调用析构函数，再释放内存
#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "普通构造函数调用" << endl;
	}
	Person(int a) {
		cout << "有参构造函数调用" << endl;
	}
	Person(const Person &person) {
		cout << "拷贝构造函数调用" <<endl;
	}
	~Person() {
		cout << "析构函数调用" << endl;
	}
};

void func01(void) {
	Person *p1 = new Person;
	Person *p2 = new Person(10);
	Person *p3 = new Person(*p1);
	
	delete p1;
	delete p2;
	delete p3;
}
// 在堆区开辟数组(必须有默认构造函数)
void func02() {
	Person *p = new Person[10];
	int *p_int = new int[10];  // 堆区开辟int数组
	delete []p;
}
int main(int argc, char *argv[]) {
//	func01();
	func02();
	return 0;
}