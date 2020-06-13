#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// 一元取反适配器
void test01() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));  // 函数对象适配器+取反适配器
	cout << *it << endl;
}


// 二元取反适配器
void test02() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	sort(v.begin(), v.end(), not2(less<int>()));
	for (vector<int>::iterator it=v.begin(); it!=v.end(); it++) {
		cout << *it << endl;
	}
}

int main(int argc, char *argv[]) {
	test01();
//	test02();
	return 0;
}