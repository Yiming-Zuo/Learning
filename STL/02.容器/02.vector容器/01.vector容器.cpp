// vector是动态空间，随着元素的加入，它的内部机制会自动扩充以容纳新空间
// vector迭代器：普通指针。
// vector<int>::iterator p; p的类型其实就是int *

// vector.capacity()  查看容器容量

// 一旦vector的动态空间重新配置，指向原vector的所有迭代器都会失效

#include <iostream>
#include <vector>
#include "func.hpp"
using namespace std;

void test() {
	vector<int>v;
	vector<int>::iterator p = v.begin();
	for (int i=0; i<10; i++) {
		v.push_back(i);	
		cout << "当前容量:" << v.capacity() << endl; 
		cout << "当前地址:" << &v[0] << endl;  // todo
	}
//	print_vector<int>(v);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}