#include <iostream>
#include <vector>
using namespace std;

class PrintAdd : public binary_function<int, int, void> {
public:
	void operator()(int val, int num) const {
		cout << "val:" << val << " num:" << num << " val+nu= " << val+num << endl;
	}
};

void test() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(PrintAdd(), 10));  // 10->num  将参数绑定为函数对象的第二个参数
	for_each(v.begin(), v.end(), bind1st(PrintAdd(), 10));  // 10->val  绑定第一个参数
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}