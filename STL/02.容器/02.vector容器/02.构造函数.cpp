#include <iostream>
#include <vector>
#include "func.hpp"
using namespace std;
/*
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数
*/
void test() {
	vector<int>v;
	
	vector<int>v2(5, 6);
	print_vector(v2);
	
	vector<int>v3(v2.begin(), v2.end());
	print_vector(v3);
	
	char arr[] = {3, 4, 5, 6, 7};
	vector<int>v4(arr, arr+3);  // 指针
	print_vector(v4);
	
	vector<int>v5(v4);
	print_vector(v5);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}