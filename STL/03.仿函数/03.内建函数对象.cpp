#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// 1 算数类函数对象
void test01() {
	plus<int> my_plus;  // 加法
	cout << my_plus(20, 10) << endl;
	
	modulus<int> my_mod;
	cout << my_mod(-5, -3) << endl;  // 取模运算 %
	
	negate<int> neg;
	cout << neg(20) << endl;  // 取反
}

// 2 关系运算类函数对象
void test02() {
	less_equal<int> less_e;
	cout << less_e(20,21) << endl;
}

// 3 逻辑运算类函数对象
void print_v(vector<bool> &v) {
	for (vector<bool>::iterator p=v.begin();p!=v.end();p++) {
		cout << *p << endl;
	}
}

void test03() {
//	logical_and<bool> my_and;
//	cout << my_and(5>3, 5>8) << endl;
	
	vector<bool>v;
	v.push_back(false);
	v.push_back(true);
	v.push_back(true);
	v.push_back(false);
	print_v(v);
	cout << "----------" << endl;
	vector<bool>v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());  // 匿名对象改变算法策略
	print_v(v2);
}

int main(int argc, char *argv[]) {
	test01();
//	test02();
//	test03();
	return 0;
}