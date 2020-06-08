#include <iostream>
#include <vector>
#include "func.hpp"
using namespace std;
/*
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/
void test() {
	int arr[] = {1,2,3,4,5,6};
	vector<int>v(arr, arr+sizeof(arr)/sizeof(arr[0]));
	
	cout << "capacity:" << v.capacity() << endl;
	
	cout << "size:" << v.size() << endl;
	
	cout << "empty:" << v.empty() << endl;
	
	v.resize(10, 0); // 12
	cout << "resize capacity:" << v.capacity() << endl;
	
	v.reserve(2);
	cout << "reserve capacity:" << v.capacity() << endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}