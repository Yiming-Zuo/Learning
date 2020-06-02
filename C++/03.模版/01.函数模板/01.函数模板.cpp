// 泛型编程
// 函数模板：将类型参数化
// 1.语法
//	 1.1 template <typename T> 定义通用类型
//	 1.2 void func(T &a, T &b){}
//	 1.3 template <> 返回类型 函数名(特殊类型列表)  利用具体化实现，解决特殊数据类型的问题
// 2.使用
//	 2.1 func(a, b); 自动类型推导
//	 2.2 func<int>(a, b); 显示指定类型 
// 3 注意事项
// 3.1 必须推导出一致的T类型，才可以使用模版
// 3.2 模版必须要确定出T的类型才可以使用
// 3.3 函数模板也可以发生函数重载
// 3.4 如果想强调使用了模版函数，加空模板参数列表
// 4 函数模板和普通函数的区别
// 4.1 普通函数可以发生隐式类型转换
// 4.2 自动类型推导不可以发生隐式类型转换，指定类型可以
// 5 两次编译：
// 5.1 对函数模板进行编译
// 5.2 对替换T之后生成的模板函数进行第二次编译

#include <iostream>
using namespace std;

class Person {
public:
	Person(int id, const char *name) {
		this->id = id;
		this->name = name;
	}
	int id;
	string name;
};

template <typename T>  // 1.1 通用类型T
void mySwap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
void func(void) {
	cout << "hello" << endl;
}

void test(void) {
	int a = 10;
	int b = 20;
	mySwap<int>(a, b);  // 2.2
	cout << a << endl << b << endl;
	
	float num1 = 111.11;  // 4.1
	float num2 = 222.22;
	mySwap<>(num1, num2);  // 3.4
	cout << num1 << endl << num2 << endl;
}


int main(int argc, char *argv[]) {
	test();
	func<int>();  // 3.2
	test02();
	return 0;
}