#include <iostream>
using namespace std;
// 基类
class BasePage {
 public:
	void header() {
		cout << "首页、公开课、登陆、注册..." << endl;
	}
	void leftList() {
		cout << "Java、Python、C++..." << endl;
	}
	void footer() {
		cout << "帮助中心、友情链接、站内地图、注册..." << endl;
	}
};
// 派生类
class Java : public BasePage {
 public:
	void content() {
		cout << "Java资料内容" << endl;
	}
};

class Cpp : public BasePage {
 public:
	void content() {
		cout << "C++资料内容" << endl;
	}
};

class Python : public BasePage {
 public:
	void content() {
		cout << "Python资料内容" << endl;
	}
};


int main(int argc, char *argv[]) {
	cout << "Java页面:" << endl;
	Java java;
	java.header();
	java.leftList();
	java.content();
	java.footer();
	cout << endl;
	cout << "Python页面:" << endl;
	Python python;
	python.header();
	python.leftList();
	python.content();
	python.footer();
	cout << endl;
	cout << "C++页面:" << endl;
	Cpp cpp;
	cpp.header();
	cpp.leftList();
	cpp.content();
	cpp.footer();
	return 0;
}