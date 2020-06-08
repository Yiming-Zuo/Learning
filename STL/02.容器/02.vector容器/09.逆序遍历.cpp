#include <iostream>
#include <vector>
#include "func.hpp"
using namespace std;

void test() {
	vector<int>v;
	for (int i=0;i<100000;i++) {
		v.push_back(i);
	}
	for (vector<int>::reverse_iterator p=v.rbegin(); p!=v.rend(); p++) {  // 反转迭代器
		cout << *p << endl;
	}
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}