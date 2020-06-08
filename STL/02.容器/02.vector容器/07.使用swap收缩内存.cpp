#include <iostream>
#include <vector>
#include "func.hpp"
using namespace std;

void test() {
	vector<int>v1;
	for (int i=0;i<100000;i++) {
		v1.push_back(i);
	}
	cout << "size:" << v1.size() << endl;
	cout << "capacity:" << v1.capacity() << endl;
	
	v1.resize(3);
	cout << "resize size:" << v1.size() << endl;
	cout << "resize capacity:" << v1.capacity() << endl;  // 容量没变
	print_vector(v1);
	
	// 巧用swap收缩内存
	vector<int>(v1).swap(v1);  // 匿名对象拷贝构造按照v.size()大小构造后与v交换，随后大容量匿名对象被自动释放
	cout << "resize size:" << v1.size() << endl;
	cout << "resize capacity:" << v1.capacity() << endl;
	
}



int main(int argc, char *argv[]) {
	test();
	return 0;
}