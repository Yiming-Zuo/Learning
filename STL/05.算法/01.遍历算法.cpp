#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1 for_each()
class PrintVector {
 public:
	PrintVector() {count = 0;}
	void operator()(int val) {
		cout << val << endl;
		count++;
	}
	int count;	
};

void test01() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	PrintVector pv = for_each(v.begin(), v.end(), PrintVector());  // 返回函数对象
	cout << "迭代次数:" << pv.count << endl;
}

// 2 transform()
class PlusVector {
 public:
	int operator()(int val1, int val2) {
		return val1+val2;
	}
};

void test02() {
	vector<int>v1;
	for (int i=0;i<10;i++) {
		v1.push_back(i);
	}
	vector<int>v2 = v1;
	vector<int>v3;
	v3.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), PlusVector());  // 返回目标容器迭代器
	for_each(v3.begin(), v3.end(), PrintVector());
}


int main(int argc, char *argv[]) {
//	test01();
	test02();
	return 0;
}