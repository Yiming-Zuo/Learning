#include <iostream>
#include <stack>
using namespace std;

void test() {
	stack<int>stk;
	for (int i=0; i<10; i++) {
		stk.push(i);
	}
	cout << "stk当前容量:" << stk.size() << endl;
	while (!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}