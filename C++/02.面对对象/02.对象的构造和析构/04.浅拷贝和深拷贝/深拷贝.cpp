// 自己提供拷贝构造函数，实现深拷贝：自行给指针动态分配空间
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
	Student(const Student &student) {
		m_name = (char *)malloc(sizeof(student.m_name));  // 给指针成员动态分配空间
		strcpy(m_name, student.m_name);
		m_age = student.m_age;
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
	Student tom2(tom);
	return 0;
}