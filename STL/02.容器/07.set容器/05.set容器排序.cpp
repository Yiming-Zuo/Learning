#include <iostream>
#include <set>
using namespace std;

class MyCompare {
public:
	bool operator()(int v1, int v2) {
		return v1>v2;
	}
};

void print_set(set<int, MyCompare>&my_set) {
	for (set<int, MyCompare>::iterator p=my_set.begin();p!=my_set.end();p++) {
		cout << *p << endl;
	}
}

void test() {
	// 仿函数而不是回调函数，因为模版参数需要传入一个类型，仿函数本质就是一个类
	set<int, MyCompare>my_set;
	my_set.insert(10);
	my_set.insert(20);
	my_set.insert(30);
	my_set.insert(40);
	my_set.insert(50);
	print_set(my_set);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}