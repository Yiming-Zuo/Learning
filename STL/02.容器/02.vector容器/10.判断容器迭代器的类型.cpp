#include <iostream>
#include <vector>
#include <list>
using namespace std;

void test() {
	// 随机访问迭代器
	vector<int>v;
	vector<int>::iterator p_v = v.begin();
	p_v++;
	p_v--;
	p_v+=5;
	
	// 双向迭代器
	list<int>l;
	list<int>::iterator p_l = l.begin();
	p_l++;
	p_l--;
//	p_l+=5;  // error
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}