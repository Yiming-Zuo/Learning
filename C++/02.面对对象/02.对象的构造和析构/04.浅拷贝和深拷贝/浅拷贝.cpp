// 浅拷贝，编译器提供的默认拷贝构造函数是浅拷贝，只拷贝值，逐字节拷贝，造成内存泄漏和堆区重复释放
#include <iostream>
using namespace std;

class Student {
	char *m_name;
	int m_age;
public:
	Student(const char *name, int age) {
		m_age = age;
		m_name = (char *)malloc(strlen(name)+1);
		strcpy(m_name, name);
	}
	~Student() {
		if (m_name != NULL) {
			free(m_name);
			m_name = NULL;
		}
		cout << "析构函数调用" << endl;
	}
};

int main(int argc, char *argv[]) {
	Student tom("tom", 18);
	Student tom2(tom);  // 堆区重复释放
	return 0;
}