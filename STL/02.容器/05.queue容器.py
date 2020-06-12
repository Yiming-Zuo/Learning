
#include <iostream>
#include <queue>
using namespace std;

void test() {
	queue<int>q;
	for (int i=0;i<10;i++) {
		q.push(i);
	}
	cout << q.size() << endl;
	cout << q.back() << endl;
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();  // 出队
	}
}

int main(void) {
	test();
	return 0;
}