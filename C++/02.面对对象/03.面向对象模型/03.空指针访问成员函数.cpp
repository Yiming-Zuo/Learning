#include <iostream>
using namespace std;

class Person {
	int age;
public:
	Person(int age) {
		this->age = age;
	}
	void showPerson() {
		cout << "showPerson" << endl;
	}
	void showAge() {
		// 判断是否为空指针
		if (this == NULL) {
			return;
		}
		cout << this->age << endl;
	}
};
int main(int argc, char *argv[]) {
	Person *p = NULL;  // this=NULL
	p->showPerson();
	p->showAge();
	return 0;
}