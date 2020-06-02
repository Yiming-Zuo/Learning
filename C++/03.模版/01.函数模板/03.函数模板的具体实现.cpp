// 1.3
#include <iostream>
using namespace std;

class Person {
public:
	Person(int num, string name) {
		m_num = num;
		m_name = name;
	}
	int m_num;
	string m_name;	
};

template <class T>
bool myCompare(T &a, T &b) {
	return a == b;
}

template <> bool myCompare(Person &a, Person &b) {  // 1.3
	return a.m_num == b.m_num && a.m_name == b.m_name;
}

void test01(void) {
	int a = 10;
	int b = 10;
	cout << myCompare(a, b) << endl;
}

void test02(void) {
	Person tom(1, "tom");
	Person jerry(1, "tom");
	cout << myCompare(tom, jerry) << endl;
}


int main(int argc, char *argv[]) {
	test01();
	test02();
	string str1 = "hello";
	string str2 = "hello";
	cout << (str1 == str2) << endl;
	return 0;
}