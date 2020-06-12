#include <iostream>
#include <set>
using namespace std;

void print_set(set<int>my_set) {
	for (set<int>::iterator p=my_set.begin();p!=my_set.end();p++) {
		cout << *p << endl;
	}
}

void test() {
	set<int>my_set;
	my_set.insert(20);
	my_set.insert(50);
	my_set.insert(40);
	my_set.insert(10);
	my_set.insert(30);
	// 1.查找 set.find()
	set<int>::iterator pos = my_set.find(30);
	if (pos != my_set.end()) {
		cout << "找到了元素：" << *pos << endl;
	} else {
		cout << "未找到" << endl;
	}
	// 2.计数 set.count()
	// set而言，结果无法要么是0，要么是1
	my_set.insert(40);
	int num = my_set.count(40);
	cout << "40的个数为:" << num << endl;
	// 3.set.lower_bound()  >=
	set<int>::iterator pos_lower = my_set.lower_bound(30);
	if (pos_lower != my_set.end()) {
			cout << "找到了lower_bound：" << *pos_lower << endl;
	} else {
			cout << "未找到" << endl;
	}
	// 4.set.upper_bound() >
	set<int>::iterator pos_upper = my_set.upper_bound(30);
	if (pos_upper != my_set.end()) {
			cout << "upper_bound：" << *pos_upper << endl;
	} else {
			cout << "未找到" << endl;
	}
	// 5.set.equal_range() 返回容器中key与keyElem相等的上下限的两个迭代器
	pair< set<int>::iterator, set<int>::iterator > pos_equal = my_set.equal_range(30);
	if (pos_equal.first != my_set.end()) {
		cout << "equal_range中的lower_bound的值为:" << *(pos_equal.first) << endl;
	} else {
		cout << "未找到" << endl;
	}
	if (pos_equal.second != my_set.end()) {
		cout << "equal_range中的upper_bound的值为:" << *(pos_equal.second) << endl;
	} else {
		cout << "未找到" << endl;
	}
}

int main(int argc, char *argv[]) {
	test();
}