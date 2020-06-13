#include <iostream>
#include <vector>
using namespace std;

void print_vector(int val, int num) {
	cout << val+num << " ";
}

void test() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(print_vector), 30));  // 回调函数指针适配成函数对象
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}