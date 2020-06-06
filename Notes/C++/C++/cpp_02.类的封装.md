---
title: cpp_02.类的封装
date: 2020-05-16
categories: Cpp
---

* 封装：
    1. 将事物的属性和行为作为一个整体，封装在一个类中
    2. 可以对变量和函数进行访问控制
* c中实现访问控制：`typedef void * NAME`
* 访问权限：
    1. 类内没有访问权限之分
    2. 类外：   
        * public: 公共权限
        * protected: 保护权限，不可访问，子类可以访问父类保护权限的内容
        * private: 私有权限，不可访问，子类不可以访问父类保护权限的内容
    3. struct中默认权限是public，class中默认权限是private
* 将成员属性设为私有，实现不可访问、只读访问、只写访问和读写访问

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person {
	string m_name = "tom";  // 只读
	int m_age;  // 可读可写
	string m_lover;  // 只写
public:
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
```
