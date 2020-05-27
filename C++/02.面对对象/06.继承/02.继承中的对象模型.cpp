// 派生类继承了基类的所有成员变量，只是不同的继承方式导致成员变量的访问权限不同，
// 派生类也继承到了基类的私有变量，只是编译器做了保护，因此访问不到
// sizeof(子类) = 父类中的非静态成员属性大小 + 子类中的非静态成员属性大小
#include <iostream>
using namespace std;

class BaseClass {
 public:
	static void func() {
		cout << "hello\n";
	}
	static int num;
	int num1;
 protected:
	int num2;
 private:
	int num3;
};

class SonClass1 : public BaseClass {
public:
	int num4;
	static int num5;
};

class SonClass2 : protected BaseClass {};
class SonClass3 : private BaseClass {};

int main(int argc, char *argv[]) {
	cout << sizeof(BaseClass) << endl;  // 12
	cout << sizeof(SonClass1) << endl;  // 16
	cout << sizeof(SonClass2) << endl;  // 12
	cout << sizeof(SonClass3) << endl;  // 12
	return 0;
}