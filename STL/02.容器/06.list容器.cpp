#include <iostream>
#include <list>
using namespace std;

// 排序
// 标准算法适用于 只支持随机访问迭代器的容器
// 不支持随机访问迭代器的容器，内部会对应提供一些算法

void print_list(list<int> &mylist) {
	for (list<int>::iterator p_list = mylist.begin();p_list!=mylist.end();p_list++) {
		cout << *p_list << endl;
	}
}

int my_compare(int v1, int v2) {
	return v1>v2;
}

void test() {
	list<int> myList;
	for (int i = 0; i < 10; i++){
		myList.push_back(i);
	}
	myList.sort(my_compare);
	print_list(myList);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}