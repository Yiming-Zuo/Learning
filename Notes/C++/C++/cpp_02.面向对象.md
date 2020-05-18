---
title: cpp_02.面向对象
date: 2020-05-16
categories: Cpp
---

# 1 类的封装
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

# 2 对象的构造和析构
## 2.1 构造函数和析构函数
* 构造函数：创建对象时为对象的成员属性赋值
* 析构函数：对象销毁前执行清理工作

> 1.要写到公共权限下
> 2.不需要返回值
> 3.构造函数可以有参数，可以发生函数重载，析构函数不可以
> 4.自动调用

```cpp
class Student {
	string m_name;
	int age;
public:
	Student() {
		cout << "构造函数调用" << endl;
	}
	~Student() {
		cout << "析构函数调用" << endl;
	}
};

int main(int argc, char *argv[]) {
	// 对象销毁：进程结束，或者在栈上时作用域结束
	Student tom;
	cout << "进程结束" << endl;
	return 0;
}
```

## 2.2 构造函数的分类和调用
* 按参数分：
    * 无参构造函数
    * 有参构造函数
* 按类型分：
    * 普通构造函数
    * 拷贝构造函数 `Student(const Student &student)`
* 调用方式：
    1. 括号法 `Student tom2(tom);`
    2. 显示法 `Student tom2 = Student(tom);`    
    3. 隐式转换法 `Student tome = tom;`
* 注意事项
    1. 匿名函数：没有名字的对象，本行执行完立即析构
        * 不能用拷贝构造函数初始化匿名对象：重定义 `Student(tom);` == `Student tom;`
        * 但是可以当右值 `Student tom2 = Student(tom);`
    2. 默认构造函数括号法调用不加括号，加了就是一个函数的声明 `Student tom();`
 
 ```cpp
class Student {
	   string m_name;
	   int m_age;
public:
	// 无参（默认）构造函数
	Student() {
		cout << "构造函数调用" << endl;
		m_name = "tom";
		m_age = 18;
	}
	// 有参构造函数
	Student(string name, int age) {
		m_name = name;
		m_age = age;
	}
	// 拷贝构造函数：使用另外一个对象初始化本对象
	// 参数不加引用：值传递的本质就是调用拷贝构造函数、递归调用
	Student(const Student &student) {
		m_name = student.m_name;
		m_age = student.m_age;
	}
	~Student() {
		cout << "析构函数调用" << endl;
	}
	void get_info() {
		cout << "name:" << m_name << endl;
		cout << "age:" << m_age << endl;
	}
};
int main(int argc, char *argv[]) {
// 1.括号法调用
#if 0
//	Student tom;  // 默认构造函数调用，不加括号，加括号就是一个函数的声明
	Student tom("tomma", 20);  // 有参构造函数调用
	tom.get_info();
	Student tom2(tom);  // 拷贝构造函数调用
	tom2.get_info();
#endif
// 2.显示法调用
// 匿名对象：没有名字的对象，当本行执行完毕立即释放
#if 0
	Student("tom", 20);  // 当本行执行完毕立即释放
	cout << "-----------" << endl;
	Student tom = Student("tom", 20);  // 有参构造函数调用，相当于给匿名对象
//	Student(tom);  // 不能使用拷贝构造函数初始化匿名对象：重定义，相当于Student tom; , 可以当右值
	Student tom2 = Student(tom);  // 拷贝构造函数调用
	tom.get_info();
	tom2.get_info();
#endif
// 3.隐式转换法调用
#if 1
	Student tom = 100;  // 编译器隐式将代码转换为Student tom = Student(100);
	Student tom2 = tom;  // 编译器隐式将代码转换为Student tom2 = Student(tom);
#endif
	return 0;
}
```

## 2.3 拷贝构造函数的调用时机
1. 用已经创建好的对象初始化新的对象
2. 值传递的方式给函数传参
3. 以值的方式返回函数中的局部对象

```cpp
class Student {
	string m_name;
	int m_age;
public:
	Student() {
		cout << "默认构造函数调用" << endl;
	}
	Student(string name, int age) {
		m_name = name;
		m_age = age;
		cout << "有参构造函数调用" << endl;
	}
	Student(const Student &student) {
		m_name = student.m_name;
		m_age = student.m_age;
		cout << "拷贝构造函数调用" << endl;
	}
};
// 1.用已经创建好的对象初始化新的对象
void func01(void) {
	Student tom("tom", 100);
	Student tom2(tom);
	Student tom3 = Student(tom);
	Student tom4 = tom;
}
// 2.值传递的方式给函数传参
void doWork(Student student) {
	
}
void func02(void) {
	Student tom("tom", 100);
	doWork(tom);  // 相当于Student student = tom;
}
// 3.以值的方式返回函数中局部对象
Student doWork2(void) {
	Student tom("tom", 100);
	return tom;  // 编译器通过调用拷贝构造函数生成一个临时Student对象返回，然后调用tom的析构函数。
}
void func03(void) {
	Student tom = doWork2();
}
/*
// release版本中优化的代码：将返回对象作为引用参数传到函数中
Student tom;
void doWork(Student &tom) {
	
}
*/

int main(int argc, char *argv[]) {
//	func01();
//	func02();
	func03();
	return 0;
}
```

# 2.4 构造函数的调用规则
* 默认情况下，编译器至少为我们的类增加3个函数：
    * 默认构造函数（无参，空函数体）
    * 默认析构函数（无参，空函数体）
    * 默认拷贝构造函数：对类中非静态成员属性简单值拷贝
* 如果用户自定义了有参构造函数，编译器不再提供无参默认构造函数
* 如果用户自定义了拷贝构造函数，编译器不再提供任何默认构造函数