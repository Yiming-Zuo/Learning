#include <iostream>
using namespace std;

class Printer {
private:
	Printer() {
		m_time = 0;
	}
	Printer(const Printer &) {}
public:
	static Printer *getInstance() {
		return printer;
	}
	void printText(string text) {
		cout << text << endl;
		cout << "打印次数:" << ++m_time << endl;
	}
private:
	static Printer *printer;
	int m_time;
};
Printer *Printer::printer = new Printer;  // 静态函数初始化可以访问到私有构造函数

int main(int argc, char *argv[]) {
	Printer* printer = Printer::getInstance();
	printer->printText("离职报告!");
	printer->printText("入职合同!");
	printer->printText("提交代码!");
	return 0;
}