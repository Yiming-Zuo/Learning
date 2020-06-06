// 必须重写虚析构函数和what()函数
// const char * 可以隐式转换为string，反之不行
// string转换为 const char * : 调用string类的c_str()方法
#include <iostream>
using namespace std;

class myException : public exception {
 public:
	// 提供string和 const char * 两种类型的有参构造
	myException(const char *str) : m_error(str) {}
	myException(string str) : m_error(str) {}
	virtual ~myException() _NOEXCEPT {};
	virtual const char *what() const _NOEXCEPT {  // 常函数，无法修改成员变量
		return m_error.c_str();
	}
 private:
	string m_error;
};

void func() {
	throw myException("爬");
}


int main(int argc, char *argv[]) {
	try {
		func();
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	return 0;
}