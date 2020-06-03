// static_cast<type> (expression)
// 1.基本数据类型转换
// 2.父类子类之间转换
#include <iostream>
using namespace std;

// 1
void test01() {
	char ch = 'a';
	cout << static_cast<double>(ch) << endl;
}

//2
class Base {};
class Son : public Base {};

void test02() {
	// 向下类型转换，不安全
	Base *p_base_1 = NULL;
	Son *p_son_1 = static_cast<Son *> (p_base_1);
	// 向上类型转换，安全
	Son *p_son_2 = NULL;
	Base *p_base_2 = static_cast<Base *> (p_son_2);
}

int main(int argc, char *argv[]) {
//	test01();
	test02();
	return 0;
}