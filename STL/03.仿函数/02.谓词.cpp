#include <iostream>
#include <vector>
using namespace std;

// 一元谓词
class GreaterThanFive {
public:
	bool operator()(int num) {
		return num > 5;
	}
};

void test01() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThanFive());  // 一元谓词改变算法策略
	if (pos == v.end()) {
		cout << "没有找到" << endl;
	} else {
		cout << "找到了:" << *pos << endl;
	}
}

// 2 二元谓词
class MyGreater {
public:
	bool operator()(int val1, int val2) {
		return val1>val2;
	}
};

void test02() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	sort(v.begin(), v.end(), MyGreater());  // 二元谓词改变算法策略
	for (vector<int>::iterator p=v.begin(); p!=v.end(); p++) {
		cout << *p << endl;
	}
}


int main(int argc, char *argv[]) {
	test01();
	test02();
	return 0;
}