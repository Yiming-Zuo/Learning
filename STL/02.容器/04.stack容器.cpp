#include <iostream>
#include <stack>
using namespace std;

void test() {
	stack<int>stk;
	cout << "stk是否为空:" << stk.empty() << endl;
	cout << "stk当前容量:" << stk.size() << endl;
	for (int i=0; i<10; i++) {
		stk.push(i);
	}
	cout << "stk是否为空:" << stk.empty() << endl;
	cout << "stk当前容量:" << stk.size() << endl;
	stk.pop();
	cout << "栈顶元素:" << stk.top() << endl;
}



int main(int argc, char *argv[]) {
	test();
	return 0;
}