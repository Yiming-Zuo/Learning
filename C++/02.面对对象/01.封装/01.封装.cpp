#include <iostream>
#include <string>
using namespace std;

class Person {
	string m_name;  // 只读
	int m_age;  // 可读可写
	string m_lover;  // 只写
public:
	Person() {
		m_name = "tom";
	}
	void get_name() {
		cout << "name:" << m_name << endl;
	}
	
	void set_age(int age) {
		if (age < 0 || age > 100) {
			cout << "爬！" << endl;
			return;
		}
		m_age = age;
	}
	void get_age() {
		cout << "age:" << m_age << endl;
	}
	
	void set_lover(string lover) {
		m_lover = lover;
	}
};

int main(int argc, char *argv[]) {
	Person tom;
	tom.set_age(18);
	tom.set_lover("貂蝉");
	
	tom.get_name();
	tom.get_age();
	return 0;
}