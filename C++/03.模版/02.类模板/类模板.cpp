
#include <iostream>
using namespace std;

// 类模板：成员函数类型参数化
// 几个类的功能是类似的，仅仅是成员变量的数据类型不同
template <class AgeType, class NameType = string>  // 模板中可以使用默认参数
class Person {
public:
	Person() {}
	Person(AgeType age, NameType name) {
		m_age = age;
		m_name = name;
	}
	void show_person() {
		cout << "name:" << m_name << endl;
		cout << "age:" << m_age << endl;
	}
public:
	AgeType m_age;
	NameType m_name;	
};

void test01(void) {
//	Person tom(10, "tom");  // 类模板不能进行类型自动推导
	Person<int, string> tom(10, "tom");
	tom.show_person();
}

// 2 类模板做函数参数
// 2.1 指定传入类型
void func(Person<int, string> &person) {
	person.m_age += 1;
	person.m_name += "hello";
}
// 2.2 将参数模块化
template<class T1, class T2>
void func02(Person<T1, T2> &person) {
	cout << "T1:" << typeid(T1).name() << endl;
	cout << "T2:" << typeid(T2).name() << endl;
	person.show_person();
}
// 2.3 将类模块化
template<class T>
void func03(T &person) {
	cout << "T:" << typeid (T).name() << endl;
	person.show_person();
}

void test02() {
	Person<int, string> tom(10, "tom");
//	func(tom);
//	tom.show_person();
//	func02(tom);
	func03(tom);
}

// 3 类模板派生普通类
class Son : public Person<int, string> {  // 需要具体化的父类
 public:
	Son(int age, string name) : Person<int, string> (20, "jerry") {  // 先调用父类构造函数
		m_age = age;
		m_name = name;
	}
};

void test03(void) {
	Son tom(10, "tom");
	tom.show_person();
}

// 4 类模板派生类模板
template <class GradeName, class T1, class T2>
class Son2 : public Person<T1, T2> {
public:
	GradeName m_grade;
};

void test04(void) {
	Son2<int, string, int> tom;
	tom.m_grade = 100;
	cout << tom.m_grade << endl;
}

// 5 类模板的类外实现
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

void test05() {
	Student<int, string> tom(1, "tom");
	tom.show_student();
}


int main(int argc, char *argv[]) {
//	test01();
//	test02();
//	test03();
	test04();
//	test05();
	return 0;
}