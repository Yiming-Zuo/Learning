#include <iostream>
using namespace std;
// 构造函数：创建对象时为对象的成员属性赋值
// 析构函数：对象销毁前执行清理工作
// 1.要写到公共权限下
// 2.不需要返回值
// 3.构造函数可以有参数，可以发生函数重载，析构函数不可以
// 4.自动调用

class Student {
	string m_name;
	int age;
public:
	Student() {
		cout << "构造函数调用" << endl;
	}
	~Student() {
		cout << "析构函数调用" << endl;
	}
};

int main(int argc, char *argv[]) {
	// 对象销毁：进程结束，或者在栈上时作用域结束
	Student tom;
	cout << "进程结束" << endl;
	return 0;
}