#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

// 1 fill算法: 向容器中添加元素
void test01() {
	vector<int>v;
	v.resize(10);
	fill(v.begin(), v.end(), 1000);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

// 2 accumulate算法 计算容器元素累计总和
void test02() {
	vector<int>v;
	for (int i=1;i<10;i++) {
		v.push_back(i);
	}
	int num = accumulate(v.begin(), v.end(), 0);  // 累加起始值
	cout << num << endl;
}

int main(int argc, char *argv[]) {
//	test01();
	test02();
	return 0;
}