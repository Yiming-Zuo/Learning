#include <iostream>
#include <vector>
#include "func.hpp"
using namespace std;

void test() {
	vector<int>v;  // 事先预留好空间，不需要多次开辟浪费时间
	v.reserve(100000);
	int num = 0;
	int *p = NULL;
	for (int i=0;i<100000;i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	// 添加100000次数据，重新开辟空间的次数
	cout << num << endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}