#include <iostream>
#include <vector>
#include "func.hpp"
using namespace std;
/*
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素
*/
void test() {
	int arr[] = {1,2,3,4,5,6};
	vector<int>v(arr, arr+sizeof(arr)/sizeof(arr[0]));
	
	cout << "v[0]=" << v.front() << endl;
	cout << "v[0]=" << v.at(0) << endl;
	cout << "v[0]=" << v[0] << endl;
	cout << "v[-1]=" << v.back() << endl;
	cout << "v[-1]=" << v.at(v.size()-1) << endl;
	cout << "v[-1]=" << v[v.size()-1] << endl;
}


int main(int argc, char *argv[]) {
	test();
	return 0;
}