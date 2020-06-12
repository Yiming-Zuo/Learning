#include <iostream>
#include <set>
using namespace std;

// set.insert() 返回pair< set<T>::iterator, bool >
void test() {
	set<int>my_set;
	pair< set<int>::iterator, bool > ret = my_set.insert(10);
	if (ret.second) {
		cout << "第一次插入成功" << endl;
	} else {
		cout << "第一次插入失败" << endl;
	}
	
	ret = my_set.insert(10);
	if (ret.second) {
			cout << "第二次插入成功" << endl;
		} else {
			cout << "第二次插入失败" << endl;
		}
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}