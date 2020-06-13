#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
 public:
	Student(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void get_info() {
		cout << "name:" << name << " age:" << age << endl;
	}
 private:
	string name;
	int age;
};

void test() {
	vector<Student>v;
	v.push_back(Student("tom", 18));
	v.push_back(Student("jerry", 19));
	v.push_back(Student("jeck", 20));
	for_each(v.begin(), v.end(), mem_fun_ref(&Student::get_info));  // 成员函数适配成函数对象
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}