#include <iostream>
using namespace std;

class Student {
	string m_name;
	int m_age;
public:
	Student() {
		cout << "默认构造函数调用" << endl;
	}
	Student(string name, int age) {
		m_name = name;
		m_age = age;
		cout << "有参构造函数调用" << endl;
	}
	Student(const Student &student) {
		m_name = student.m_name;
		m_age = student.m_age;
		cout << "拷贝构造函数调用" << endl;
	}
};
// 1.用已经创建好的对象初始化新的对象
void func01(void) {
	Student tom("tom", 100);
	Student tom2(tom);
	Student tom3 = Student(tom);
	Student tom4 = tom;
}
// 2.值传递的方式给函数传参
void doWork(Student student) {
	
}
void func02(void) {
	Student tom("tom", 100);
	doWork(tom);  // 相当于Student student = tom;
}
// 3.以值的方式返回函数中局部对象
Student doWork2(void) {
	Student tom("tom", 100);
	return tom;  // 编译器通过调用拷贝构造函数生成一个临时Student对象返回，然后调用tom的析构函数。
}
void func03(void) {
	Student tom = doWork2();
}
/*
// release版本中优化的代码：将返回对象作为引用参数传到函数中
Student tom;
void doWork(Student &tom) {
	
}
*/

int main(int argc, char *argv[]) {
//	func01();
//	func02();
	func03();
	return 0;
}