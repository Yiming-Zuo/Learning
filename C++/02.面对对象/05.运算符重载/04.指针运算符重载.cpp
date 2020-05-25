// 智能指针：可以托管new出来的对象，不用手动delete
#include <iostream>
using namespace std;

class Person {
public:
	Person(int age):m_age(age){
		cout << "Person的构造函数调用" << endl;
	}
	~Person() {
		cout << "Person的析构函数调用" << endl;
	}
	void show_age() {
		cout << this->m_age << endl;
	}
private:
	int m_age;  // 维护的指针
};

class SmartPointer {
public:
	SmartPointer(Person *p):m_p(p) {
		cout << "SM的构造函数调用" << endl;
	}
	~SmartPointer() {
		cout << "SM的析构函数调用" << endl;
		if (m_p != NULL) {
			delete m_p;
			m_p = NULL;
		}	
	}
	Person *operator->() {
		return this->m_p;
	}
	Person &operator*() {  // 返回对象本身
		return *this->m_p;
	}
private:
	Person *m_p;	
};


int main(int argc, char *argv[]) {
#if 0
	// 普通指针
	Person *p1 = new Person(10);
	p1->show_age();
	(*p1).show_age();
	// 堆区空间只有delete时才调用析构函数
	delete p1;  // 调用析构函数，释放堆区空间
#endif
	// 智能指针
	SmartPointer p2(new Person(100));
	p2->show_age();  // p2->->show_age()的优化
	(*p2).show_age();
	// 智能指针对象开辟在栈区，释放时自身析构函数调用释放堆区数据，维护指针的析构函数随之调用
	
	return 0;
}