// try {} catch () {}
// 栈解旋，try代码块中在栈上构造的所以对象在代码块结束后会自动析构，顺序与构造相反
#include <iostream>
using namespace std;

// 自定义异常类
class myException {
 public:
	void printError() {
		cout << "异常哦\n"; 
	}
};

class Test {
 public:
	Test() {
		cout << "构造对象" << endl;
	}
	~Test() {
		cout << "析构对象" << endl;
	}
};

double my_disivion(int num1, int num2) {
	if (num2 == 0) {
//		throw string("hello");  // 匿名对象，有参构造
		throw myException();
//		throw 1;
	}
	return num1/static_cast<double>(num2);
}

double my_add(int num1, int num2) {
	return my_disivion(num1, num2) + 100;
}

void test(void) {
	int ret = 0;
		// 异常被抛出后，从进入try块起，到异常被抛掷前，这期间在栈上构造的所有对象，都会被自动析构。析构的顺序与构造的顺序相反，这一过程称为栈的解旋
		try {
			int num =10000;
			Test test1;
			Test test2;
			ret = my_add(8, 0);
		} catch (string e) {
			cout << e << endl;
		} 
		// 没有捕获自定义类型的catch继续晚上抛
	//	cout << num << endl;  // error:被释放
		cout << ret << endl;
}



int main(void) {
	try {
		test();
	} catch (myException e) {
		e.printError();
	} catch(...) {  // 捕获其余类型异常
		cout << "其余异常\n";
	}
	// 如果异常没有任何的处理，程序会自动调用terminate函数，使程序中断掉
	return 0;
}