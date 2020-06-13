#include <iostream>
using namespace std;

// 1 仿函数可以保存函数的调用状态
template<class T>
class MyPrint {
public:
	MyPrint() {m_count = 0;}
	void operator()(T num) {
		cout << num << endl;
		m_count++;  // 调用次数
	}
	int get_count() {
		return m_count;
	}
private:
	int m_count;
};

void test01() {
	MyPrint<int> my_print;
	my_print(10);  // 是一个对象不是函数
	my_print(10);
	my_print(10);
	my_print(10);
	my_print(10);
	cout << "已打印次数:" << my_print.get_count() << endl;
}

// 2 仿函数可以做普通函数的参数
void doSomething(MyPrint<int> my_print, int num) {
	my_print(num);
}

void test02() {
	doSomething(MyPrint<int>(), 100);  // 匿名对象
}

int main(void) {
//	test01();
	test02();
	return 0;
}