// 运算符重载：operator@ 对已有的运算符重新定义，赋予其另一种功能，以适应不同的数据类型
#include <iostream>
using namespace std;

class Num {
public:
	Num(){}
	Num(int a, int b):num_a(a), num_b(b) {}
	// 成员函数实现
	Num operator+(Num &n) {
		Num temp;
		temp.num_a = this->num_a + n.num_a;
		temp.num_b = this->num_b + n.num_b;
		return temp;  // 调用拷贝构造函数创建一个新对象返回
	}
	int num_a;
	int num_b;	
};
// 全局函数实现
Num operator+(Num &n1, int num) {
	Num temp;
	temp.num_a = n1.num_a + num;
	temp.num_b = n1.num_b + num;
	return temp;  // 调用拷贝构造函数创建一个新对象返回
}

int main(int argc, char *argv[]) {
	Num n1(10, 20);
	Num n2(20, 10);
//	Num n3 = n1.operator+(n2);  // 本质调用
	Num n3 = n1 + n2;
	cout << n3.num_a << " " << n3.num_b << endl;
	Num n4 = n1 + 100;  // 运算符重载可以发生函数重载
	cout << n4.num_a << " " << n4.num_b << endl;
	return 0;
}