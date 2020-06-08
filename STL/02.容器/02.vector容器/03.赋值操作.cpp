#include <iostream>
#include <vector>
#include "func.hpp"
using namespace std;
/*
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
*/
void test() {
	int arr[] = {1,2,3,4,5};
	vector<int>v(arr, arr+sizeof(arr)/sizeof(arr[0]));
	
	vector<int>v1;
	v1.assign(arr, arr+sizeof(arr)/sizeof(arr[0]));
	print_vector(v1);
	
	v1.assign(5, 6);
	print_vector(v1);
	
	v1 = v;
	print_vector(v1);
	
	v1.assign(5, 6);
	v1.swap(v);
	print_vector(v1);
	print_vector(v);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}