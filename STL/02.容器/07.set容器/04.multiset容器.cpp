#include <iostream>
#include <set>
using namespace std;

void print_multiset(multiset<int>&myset) {
	for (multiset<int>::iterator p=myset.begin(); p!=myset.end(); p++) {
		cout << *p <<endl;
	}
}

void test() {
	multiset<int>my_set;
	my_set.insert(10);  // 只返回迭代器
	my_set.insert(10);
	my_set.insert(10);
	my_set.insert(10);
	my_set.insert(10);
	
	print_multiset(my_set);
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}