// .hpp : 类模板的声明和实现放在一个文件里，因为：
//  1.类模板需要二次编译，在出现模板的地方编译一次，在调用模板的时候再次编译
//  2.C++编译规则为独立编译
#pragma once
#include <iostream>
using namespace std;

template <class IdType, class NameType>
class Student {
 public:
	Student(IdType id, NameType name);
	void show_student();
 private:
	IdType id;
	NameType name;	
};

template<class IdType, class NameType>
Student<IdType, NameType>::Student(IdType id, NameType name) {
	this->id = id;
	this->name = name;
}

template<class IdType, class NameType>
void Student<IdType, NameType>::show_student() {
	cout << "id:" << id << endl;
	cout << "name:" << name << endl;
}