#include <iostream>
using namespace std;

class Num {
friend ostream &operator<<(ostream &cout, Num n);  // 配合友元函数
public:
	Num(){}
	Num(int a, int b):num_a(a), num_b(b) {}
private:
	int num_a;
	int num_b;	
};
// 全局函数实现
ostream &operator<<(ostream &cout, Num n) {
	cout << "num_a:" << n.num_a << " " << "num_b:" << n.num_b;
	return cout;
}

int main(int argc, char *argv[]) {
	Num n1(10, 20);
	cout << n1 << endl;  // 实现链式编程：返回cout本身
	return 0;
}