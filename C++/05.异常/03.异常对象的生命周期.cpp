// 推荐用法: throw myException()  -->  catch(myException &e)
#include <iostream>
using namespace std;

class myException {
 public:
	myException() {
		cout << "普通构造\n";
	}
	myException(const myException &e) {
		cout << "拷贝构造\n";
	}
	~myException() {
		cout << "析构\n";
	}
};

void func() {
	throw myException();  // 匿名函数，没人用自己释放
}


int main(int argc, char *argv[]) {
	try {
		func();
	} catch (myException &e) {  // 使用引用
		cout << "捕获到异常\n";
	}
	return 0;
}