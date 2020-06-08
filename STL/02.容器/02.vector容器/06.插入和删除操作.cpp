#include <iostream>
#include <vector>
#include "func.hpp"
using namespace std;
/*
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素
*/
void test() {
	int arr[] = {1,2,3,4,5,6};
	vector<int>v(arr, arr+sizeof(arr)/sizeof(arr[0]));
	
	v.insert(v.begin(), 2, 100);
	print_vector(v);
	
	v.pop_back();
	v.push_back(7);
	v.erase(v.begin(), v.begin()+2);
	print_vector(v);
	
	v.erase(v.end()-1);
	print_vector(v);
	
	v.clear();
	cout << v.size() << endl;
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}