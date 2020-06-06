// void func() throw() {}  不能抛出任何异常
#include <iostream>
using namespace std;

void func(void) throw(int, double) {  // 只能抛出int,double异常
	throw 1;
}

int main(int argc, char *argv[]) {
	try {
		func();
	} catch (int) {
		cout << "int异常\n";
	}
}