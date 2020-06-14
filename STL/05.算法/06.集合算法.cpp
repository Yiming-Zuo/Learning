#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

// 1. set_intersection算法 求两个set集合的交集
// 注意:两个集合必须是有序序列
void test01() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;
	vTarget.resize(min(v1.size(), v2.size()));
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());  // 返回目标容器的最后一个元素的迭代器地址

	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
	cout << endl;
}



// 2. set_union算法 求两个set集合的并集
// 注意:两个集合必须是有序序列
void test02() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;
	vTarget.resize( v1.size() + v2.size() );
	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
	cout << endl;
}

// 3 set_difference算法 求两个set集合的差集
// 注意:两个集合必须是有序序列
void test03() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int>vTarget;
	vTarget.resize( max(v1.size(),v2.size()) );
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
	cout << endl;


	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());
	copy(vTarget.begin(), itEnd, ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main(){
//	test01();
//	test02();
	test03();
	return 0;
}