// const_cast<type> (expression)
// 1.常量指针与普通指针之间的转换
// 2.常量引用与普通引用之间的转换
// 3.不能对非指针或非引用的变量使用以去除它的const
#include <iostream>
using namespace std;

// 1
void test01() {
	int num = 10;
	const int *p_num = &num;
//	*p_num = 100;  // error:const
	int *p_num2 = const_cast<int *> (p_num);  // 去除const
	*p_num2 = 100;
	const int *p_num3 = const_cast<const int *> (p_num2);  // 转换为const
	cout << num << endl;
}

// 2
void test02() {
	int num = 10;
	const int &num_ref = num;
//	num_ref = 100;  // error:const
	int &num_ref2 = const_cast<int &> (num_ref);  // 去除const
	num_ref2 = 100;
//	const int &num_ref3 = const_cast<const int &> (num_ref2);  // 转换为const
	cout << num << endl;
}

int main(int argc, char *argv[]) {
//	test01();
	test02();
	return 0;
}