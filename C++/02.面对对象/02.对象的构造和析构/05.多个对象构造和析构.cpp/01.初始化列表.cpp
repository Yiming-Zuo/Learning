// 构造函数(形参列表):属性(值), 属性(值)...{}
#include <iostream>
using namespace std;

class Person {
	string m_name;
	int m_age;
public:
	Person(string name, int age):m_name(name), m_age(age) {
		
	}
	void get_info() {
		cout << "name:" << m_name << endl;
		cout << "age" << m_age << endl;
	}
};

int main(int argc, char *argv[]) {
	Person tom("tom", 19);
	tom.get_info();
	return 0;
}