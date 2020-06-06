---
title: cpp_09.模板
date: 2020-06-02
categories: Cpp
---

> 模板：泛型编程，将形参数据类型参数化，表现为参数的多态，成为类属。
> 模板用于表达逻辑结构相同，但具体数据元素类型不同的数据对象的通用行为。

# 1 函数模板
## 1.1 语法
 * `template <typename T>` 定义通用类型
 * `void func(T &a, T &b){}` 函数模板
 * `template <> 返回类型 func(特殊类型列表)`  利用具体化实现，解决特殊数据类型的问题

```cpp
template <class T>
bool myCompare(T &a, T &b) {
	return a == b;
}
// 具体化实现解决特殊类型的问题
template <> bool myCompare(Person &a, Person &b) {
	return a.m_num == b.m_num && a.m_name == b.m_name;
}
```
	 
## 1.2 使用
 * `func(a, b);` 自动类型推导
 * `func<int>(a, b);` 显示指定类型 
 
## 1.3 函数模板和普通函数的区别
* 普通函数可以发生隐式类型转换

    ```cpp
    void my_print(int num) {
        cout << num << endl;
    }
    
    void test() {
        char ch = 'a';
        my_print(ch);  // 隐式类型转换
    }
    ```

* 函数模版的自动类型推导不可以发生隐式类型转换，指定类型可以

    ```cpp
    template<class TypeName>
    void my_print(TypeName num) {
            cout << num << endl;
        }
        
    void test() {
        char ch = 'a';
        //my_print(ch);  // 自动类型推导 'a'
        //my_print<int>(ch);  // 指定类型 65
    }
    ```
 
## 1.4 注意事项
* 必须推导出一致的T类型，才可以使用模版
* 模版必须要确定出T的类型才可以使用

    ```cpp
    template<class TypeName>
    void func() {
        cout << "hello\n";
    }
    
    void test() {
        //func();  // error
        func<int>();  // 必须先确定参数的类型
    }
    ```

* 函数模板也可以发生函数重载，为特殊类型提供具体化的模板 
`template <> 返回类型 func(特殊类型列表)`
* 如果想强调使用了模版函数，加空模板参数列表

    ```cpp
    // 普通函数
    void func(int num) {}
    
    // 函数模板
    template<class TypeName>
    void func(TypeName num) {}
    
    void test() {
        int num = 10;
        func(num);  // 普通函数调用
        func<>(num);  // 模版函数调用
    }
    ```

## 1.5 模版实现机制：两次编译
* 函数模版通过不用的数据类型产生不同的模版函数
* 两次编译：
    1. 在声明的地方对函数模板代码本身进行编译
    2. 在调用的地方对参数替换生成后的模版函数代码进行第二次编译。

# 2 类模板
> 类模板：成员函数类型参数化
> 几个类的功能是类似的，仅仅是成员变量的数据类型不同
## 2.1 基本语法
* 类模板不能进行类型自动推导

```cpp
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
	Person<int, string> tom(10, "tom");  // 需要指定类型
	tom.show_person();
}
```

## 2.2 类模板做函数参数

```cpp
// 1 指定传入类型
void func(Person<int, string> &person) {
	person.m_age += 1;
	person.m_name += "hello";
}
// 2 将参数模块化
template<class T1, class T2>
void func02(Person<T1, T2> &person) {
	cout << "T1:" << typeid(T1).name() << endl;
	cout << "T2:" << typeid(T2).name() << endl;
	person.show_person();
}
// 3 将类模块化
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
```

## 2.3 类模板派生普通类
* 父类需要具体化

```cpp
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
```

## 2.4 类模板派生类模板

```cpp
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
```

## 2.5 类模板的类外实现

```cpp
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
```

## 2.6 类模板的分文件编写
* .hpp : 类模板的声明和实现放在一个文件里，因为：
    * 1.类模板需要二次编译，在出现模板的地方编译一次，在调用模板的时候再次编译
    * 2.C++编译规则为独立编译

```cpp
// Student.hpp
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
```

```cpp
// main.cpp
#include <iostream>
#include "Student.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	Student<int, string> tom(1, "tom");
	tom.show_student();
}
```

## 2.7 类模板中的友元函数

* 友元函数类内实现
* 友元函数类外实现
    1. 类声明
    2. 函数模版声明
    3. 类内声明声明友元函数

```cpp
#include <iostream>
using namespace std;
// 2.1 让编译器看到类声明
template<class NameType, class AgeType> class Student;  // 类模板的声明
// 2.2 让编译器看到函数模板声明
template <class NameType, class AgeType> void print_student02(Student<NameType, AgeType> &student);

template<class NameType, class AgeType>
class Student {
	friend void print_student02<>(Student<NameType, AgeType> &student);  // 2.3 func<>() 模版函数  func() 普通函数
	// 1.友元函数类内实现
	friend void print_student01(Student<NameType, AgeType> &student) {
		cout << "name:" << student.name << endl;
		cout << "age:" << student.age << endl;
	}
 public:
	Student(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}
 private:
	NameType name;
	AgeType age;		
};

// 2.友元函数类外实现
template <class NameType, class AgeType>
void print_student02(Student<NameType, AgeType> &student) {
	cout << "name:" << student.name << endl;
	cout << "age:" << student.age << endl;
}

void test() {
	Student<string, int> tom("tom", 18);
//	print_student01(tom);
	print_student02(tom);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}
```