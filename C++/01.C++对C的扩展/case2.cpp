// 案例二：设计一个学生类，属性：姓名，学号
#include <iostream>
using namespace std;

class Student {
public:
	string name;
	int id;
	void setInfo(string m_name, int m_id) {
		name = m_name;
		id = m_id;
	}
	void showInfo() {
		cout << "姓名：" << name << " " << "学号：" << id << endl;
	}
};


int main(int argc, char *argv[]) {
	Student tom;
	tom.setInfo("Tom", 18);
	tom.showInfo();
	return 0;
}