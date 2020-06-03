// dynamic_cast<type> (expression)
// 具有检查功能，不允许向下类型的转换，不安全
#include <iostream>
using namespace std;

class Base {};
class Son : public Base {};

void test() {
//	// error：向下类型转换，不安全
//	Base *p_base_1 = NULL;
//	Son *p_son_1 = dynamic_cast<Son *> (p_base_1);
	// 向上类型转换，安全
	Son *p_son_2 = NULL;
	Base *p_base_2 = dynamic_cast<Base *> (p_son_2);
//	// 多态下的类型转换总是安全的，父类指针指向子类对象
//	Base *p = new Son;
//	Son *pSon = dynamic_cast<Son *> (p);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}