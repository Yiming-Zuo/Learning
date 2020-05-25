// 编译器为类提供默认的operator=(值传递)函数
// 当类中有成员指针变量时，要定义深拷贝构造函数和进行赋值运算符重载
#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	Person() {
		p_name = NULL;
	}
	Person(const char *name) {
		this->p_name = new char[strlen(name)+1];
		strcpy(this->p_name, name);
	}
	~Person() {
		if (this->p_name != NULL) {
			delete p_name;
			p_name = NULL;
		}
		cout << "空间释放" << endl;
	}
	Person &operator=(const Person &person) {
		// 先释放自身开辟的空间
		if (this->p_name != NULL) {
			delete []this->p_name;  // []
			this->p_name = NULL;
		}
		this->p_name = new char[strlen(person.p_name)+1];  // 需要重新开辟空间，空间大小可能不一样
		strcpy(this->p_name, person.p_name);
		return *this;  // 返回对象本身
	}
	void show_name() {
		cout << p_name << endl;
	}
private:
	char *p_name;
};

int main(int argc, char *argv[]) {
	Person tom("tom");
	Person tom2("jerry");
	Person tom3;
	// tom3 = tom2  // 默认的值拷贝
	tom3 = tom2 = tom;  // 深拷贝 链式编程
	tom2.show_name();
	tom3.show_name();
	return 0;
}