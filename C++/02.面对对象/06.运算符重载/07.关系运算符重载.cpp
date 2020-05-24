#include <iostream>
using namespace std;

class Person {
public:
	Person(string name, int age):m_name(name), m_age(age){}
	bool operator==(Person &p) {
		return m_name==p.m_name&&m_age==p.m_age;
	}
	bool operator!=(Person &p) {
		return m_name!=p.m_name||m_age!=p.m_age;
	}
private:
	string m_name;
	int m_age;
};

int main(int argc, char *argv[]) {
	Person tom("tom", 18);
	Person jerry("jerry", 20);
	cout << (tom==jerry) << endl;
	return 0;
}