#include <iostream>
using namespace std;

class Student {
	string m_name;
	int m_age;
public:
	// 无参（默认）构造函数
	Student() {
		cout << "构造函数调用" << endl;
		m_name = "tom";
		m_age = 18;
	}
	// 有参构造函数
	Student(string name, int age) {
		m_name = name;
		m_age = age;
	}
	// 拷贝构造函数：使用另外一个对象初始化本对象
	// 参数不加引用：值传递的本质就是调用拷贝构造函数、递归调用
	Student(const Student &student) {
		m_name = student.m_name;
		m_age = student.m_age;
	}
	~Student() {
		cout << "析构函数调用" << endl;
	}
	void get_info() {
		cout << "name:" << m_name << endl;
		cout << "age:" << m_age << endl;
	}
};
int main(int argc, char *argv[]) {
// 1.括号法调用
#if 0
//	Student tom;  // 默认构造函数调用，不加括号，加括号就是一个函数的声明
	Student tom("tomma", 20);  // 有参构造函数调用
	tom.get_info();
	Student tom2(tom);  // 拷贝构造函数调用
	tom2.get_info();
#endif
// 2.显示法调用
// 匿名对象：没有名字的对象，当本行执行完毕立即释放
#if 0
	Student("tom", 20);  // 当本行执行完毕立即释放
	cout << "-----------" << endl;
	Student tom = Student("tom", 20);  // 有参构造函数调用，相当于给匿名对象
//	Student(tom);  // 不能使用拷贝构造函数初始化匿名对象：重定义，相当于Student tom; , 可以当右值
	Student tom2 = Student(tom);  // 拷贝构造函数调用
	tom.get_info();
	tom2.get_info();
#endif
// 3.隐式转换法调用
#if 1
	Student tom = 100;  // 编译器隐式将代码转换为Student tom = Student(100);
	Student tom2 = tom;  // 编译器隐式将代码转换为Student tom2 = Student(tom);
#endif
	return 0;
}