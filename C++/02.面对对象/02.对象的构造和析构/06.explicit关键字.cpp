// 使用explicit关键字修饰的构造函数防止隐式转换
#include <iostream>
using namespace std;

class Mystress {
public:
	explicit Mystress(int len) {
		cout << "构造函数(int)调用" << endl;
	}
	Mystress(const char *str) {
		cout << "构造函数(char *)调用" << endl;
	}
};

int main(int argc, char *argv[]) {
	Mystress str1 = "hello";
	Mystress str2 = Mystress("hello");
	Mystress str3("hello");
	
//	Mystress str4 = 10;  // 防止有歧义，使用explicit关键字
	Mystress str5 = Mystress(10);
	Mystress str6(10);
	return 0;
}