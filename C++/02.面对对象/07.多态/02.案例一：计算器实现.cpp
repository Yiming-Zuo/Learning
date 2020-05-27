// 抽象类
// 纯虚函数
#include <iostream>
using namespace std;

#if 0
class Caculator {
 public:
	int getResult(int num1, int num2, char oper) {
		if (oper == '+') {
			return num1+num2;
		} else if (oper == '-') {
			return num1-num2;
		} else if (oper == '*') {
			return num1*num2;
		} else if (oper == '/') {
			if (num2 == 0) {
				cout << "爬！\n";
			}
			return num1/num2;
		} else {
			return -1;
		}
	}
 private:
	int num1;
	int num2;
	char oper;
};

void test(void) {
	Caculator cal;
	cout << cal.getResult(16, 4, '/') << endl;
}
#endif
// 如果要扩展新功能或者修改功能，只能修改源码
// 面向对象的程序设计的原则：开闭原则，对扩展开放，对修改关闭

// 抽象类：有纯虚函数就是抽象类，抽象类无法实例化对象
// 子类继承抽象父类时，必须重写父类中的纯虚函数(子类必须有重写操作)，否则子类也是抽象类
class AbstractCaculator {
 public:
	virtual ~AbstractCaculator() {}  // 有纯虚函数，就要有虚析构函数
	virtual int getResult() = 0;  // 纯虚函数
	int num1;
	int num2;
};

class AddCaculator : public AbstractCaculator {
	virtual int getResult() {
		return num1+num2;
	}
};

class SubCaculator : public AbstractCaculator {
	virtual int getResult() {
		return num1/num2;
	}
};

class MulCaculator : public AbstractCaculator {
	int getResult() {
		return num1*num2;
	}
};

void test() {
	AbstractCaculator *cal = new MulCaculator;  // 父类指针指向子类对象
	cal->num1 = 10;
	cal->num2 = 30;
	cout << cal->getResult() << endl;
	delete cal;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}