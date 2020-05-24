// ++i效率高，i++会调用拷贝构造函数创建临时对象
#include <iostream>
using namespace std;

class Num {
	friend ostream &operator<<(ostream &cout, Num num);
public:
	Num(){}
	Num(int num):m_num(num) {}
	// 前置递增运算符重载
	Num &operator++() {  // 单目运算符
		m_num++;
		return *this;  // 返回自身引用
	}
	// 后置递增运算符重载
	Num operator++(int) {  // int占位符：后置
		Num temp = *this;  // 先记录当前对象
		m_num++;  // 当前对象值改变
		return temp;  // 返回之前对象（栈上返回值）调用拷贝构造函数创建新的对象（返回引用不调用拷贝构造函数，栈上被释放）
	}
private:
	int m_num;
};

ostream &operator<<(ostream &cout, Num num) {  // Num不是传入引用，是传入值，如果参数是引用，++i重载时传入值时报错
	cout << num.m_num;
	return cout;
}


void func01(void) {
	Num num(10);
	cout << ++(++num) << endl;
//	num++;  // 返回的是之前的对象的记录，但是当前对象已经发生了变化
	cout << num++ << endl;
	cout << num << endl;
}

int main(int argc, char *argv[]) {
	func01();
	return 0;
}