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

## 2.4 构造函数的调用规则
* 默认情况下，编译器至少为我们的类增加4个函数：
    * 默认构造函数（无参，空函数体）
    * 默认析构函数（无参，空函数体）
    * 默认拷贝构造函数：对类中非静态成员属性简单值拷贝
    * operator=（值拷贝）
* 如果用户自定义了有参构造函数，编译器不再提供无参默认构造函数
* 如果用户自定义了拷贝构造函数，编译器不再提供任何默认构造函数

## 2.5 深拷贝与浅拷贝（自定义拷贝构造函数）
* 浅拷贝：默认拷贝函数：逐字节拷贝，只拷贝值，容易造成内存泄漏和堆区空间重复释放
* 深拷贝：自行给指针动态分配空间

```cpp
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
```

```cpp
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
```

## 2.6 多个对象构造和析构
### 2.6.1 初始化列表
`构造函数(形参列表):属性(值), 属性(值)...{}`

```cpp
// 构造函数(形参列表):属性(值), 属性(值)...{}
#include <iostream>
using namespace std;

class Person {
	string m_name;
	int m_age;
public:
	Person(string name, int age):m_name(name), m_age(age) {
		
	}
	void get_info() {
		cout << "name:" << m_name << endl;
		cout << "age" << m_age << endl;
	}
};

int main(int argc, char *argv[]) {
	Person tom("tom", 19);
	tom.get_info();
	return 0;
}
```

### 2.6.2 类对象作为成员
类对象作为成员时，先调用对象成员的构造函数，再调用类本身的构造函数，析构函数调用顺序相反。

```cpp
// 先调用对象成员的构造函数，在调用自身的构造函数，析构函数与构造相反
#include <iostream>
using namespace std;

class Game {
	string game_name;
public:
	Game() {
		cout << "game的普通构造函数调用" << endl;
	}
	Game(string name) {
		game_name = name;
		cout << "game的有参构造函数调用" << endl;
	}
	string get_name() {
		return game_name;
	}
	~Game() {
		cout << "game有析构函数调用" << endl;
	}
};

class Phone {
	string phone_name;
public:
	Phone() {
		cout << "phone的普通构造函数调用" << endl;
	}
	Phone(string name) {
		phone_name = name;
		cout << "phone的有参构造函数调用" << endl;
	}
	string get_name() {
		return phone_name;
	}
	~Phone() {
		cout << "phone有析构函数调用" << endl;
	}
};

class Person {
	string m_name;
	Phone m_phone;
	Game m_game;
public:
	Person() {
		cout << "person的普通构造函数调用" << endl;
	}
	Person(string name, string phone_name, string game_name):m_name(name), m_phone(phone_name), m_game(game_name) {
		cout << "person的有参构造函数调用" << endl;
	}
	void playGame() {
		cout << m_name << "拿着" << m_phone.get_name() << "玩着" << m_game.get_name() << endl;
	}
	~Person() {
		cout << "person的析构函数调用" << endl;
	}
};

int main(int argc, char *argv[]) {
	Person tom("tom", "苹果", "吃鸡");
	tom.playGame();
	return 0;
}
```

## 2.7 explicit关键字
使用explicit关键字修饰的构造函数不能使用隐式转换，防止产生歧义

```cpp
// 使用explicit关键字修饰的构造函数防止隐式转换
#include <iostream>
using namespace std;

class Mystress {
public:
	explicit Mystress(int len) {
		cout << "构造函数(int)调用" << endl;
	}
	Mystress(const char *str) {
		cout << "构造函数(char *)调用" << endl;
	}
};

int main(int argc, char *argv[]) {
	Mystress str1 = "hello";
	Mystress str2 = Mystress("hello");
	Mystress str3("hello");
	
//	Mystress str4 = 10;  // 防止有歧义，使用explicit关键字
	Mystress str5 = Mystress(10);
	Mystress str6(10);
	return 0;
}
```

## 2.8 动态对象创建

* 运算符`new`：动态内存分配，在堆区为对象开辟空间并调用构造函数完成初始化
* 运算符`delete`：先调用析构函数，再释放内存
* 在堆区开辟数组(必须有默认构造函数)
    * `int *p = new int[10]`
    * `delete []p`

```cpp
// 运算符new:动态内存分配，在堆区为对象开辟空间并调用构造函数完成初始化
// 运算符delete:先调用析构函数，再释放内存
#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		cout << "普通构造函数调用" << endl;
	}
	Person(int a) {
		cout << "有参构造函数调用" << endl;
	}
	Person(const Person &person) {
		cout << "拷贝构造函数调用" <<endl;
	}
	~Person() {
		cout << "析构函数调用" << endl;
	}
};

void func01(void) {
	Person *p1 = new Person;
	Person *p2 = new Person(10);
	Person *p3 = new Person(*p1);
	
	delete p1;
	delete p2;
	delete p3;
}
// 在堆区开辟数组(必须有默认构造函数)
void func02() {
	Person *p = new Person[10];
	int *p_int = new int[10];  // 堆区开辟int数组
	delete []p;
}
int main(int argc, char *argv[]) {
//	func01();
	func02();
	return 0;
}
``` 

## 2.9 静态成员
* 静态成员变量
    * 静态成员变量属于一个类，被所有对象共享
    * 静态成员变量在编译阶段分配空间，不属于某一个对象，不占对象的空间
    * 静态成员变量必须在类内声明，类外定义。定义时可以访问类内私有数据
        * 类内声明：`static Person *p`;
        * 类外定义：`Person *Person::p = new Person;
        * 静态成员变量可以通过类名或者对象名来进行访问
    * const静态成员：既共享，又不可改变，最好在类内初始化
* 静态成员函数
    * 静态成员函数主要用来管理静态数据成员，完成对静态数据成员的封装，不能访问普通成员变量（无法确定访问哪个对象的变量）
    * 普通成员函数可以访问静态成员变量

```cpp
#include <iostream>
using namespace std;

class Person {
	static int m_id;
public:
	static int m_age;
		static const int m_share = 100;  // const静态成员，既共享，又不可改变，最好在类内初始化
	static void func(int num) {
		m_age = num;
	}
};
// 类外初始化
int Person::m_id = 1;
int Person::m_age = 19;

int main(int argc, char *argv[]) {
	// 访问静态变量(类名)
//	cout << Person::m_id << endl;
	cout << Person::m_age << endl;
	// 通过对象访问变量
	Person tom;
	cout << tom.m_age << endl;
	tom.m_age = 20;
	cout << Person::m_age << endl;
	// 访问静态成员函数
//	tom.func(100);
	Person::func(102);
	cout << Person::m_age << endl;
	
	return 0;
}
```

## 2.10 静态成员实现单例模式

> 单例模式保证系统中一个类只有一个实例而且该实例易于外界访问，从而方便对实例个数的控制并节省系统资源
> Singleton Pattern
> getInstance()方法：让客户可以访问到它的唯一实例

1. 将默认构造函数和拷贝构造函数设为私有
2. 在类内定义一个Singleton类型的静态对象，作为外部共享的唯一实例

```cpp
// 单例模式-主席类
// 只有一个对象，共享这个对象：静态成员指针变量
#include <iostream>
using namespace std;

class ChairMan {
// 私有化构造函数:防止创建多个对象
private:
	ChairMan() {}
	ChairMan(const ChairMan &) {}
public:
	// 获取单例指针的接口:可以通过类型访问
	static ChairMan *getInstance() {
		return pChairMan;
	}
private:
	// 对象指针私有化
	static ChairMan *pChairMan;  // 单例
};
// 类外初始化
ChairMan *ChairMan::pChairMan = new ChairMan;

int main(int argc, char *argv[]) {
	ChairMan *p = ChairMan::getInstance();  // 访问单例对象
	return 0;
}
```

```cpp
// 单例模式-打印机类
#include <iostream>
using namespace std;

class Printer {
private:
	Printer() {
		m_time = 0;
	}
	Printer(const Printer &) {}
public:
	static Printer *getInstance() {
		return printer;
	}
	void printText(string text) {
		cout << text << endl;
		cout << "打印次数:" << ++m_time << endl;
	}
private:
	static Printer *printer;
	int m_time;
};
Printer *Printer::printer = new Printer;  // 静态函数初始化可以访问到私有构造函数

int main(int argc, char *argv[]) {
	Printer* printer = Printer::getInstance();
	printer->printText("离职报告!");
	printer->printText("入职合同!");
	printer->printText("提交代码!");
	return 0;
}
```

## 运算符重载总结
* 不能重载&&和||：无法实现短路规则      
因为操作符重载其实是另外一种形式的函数调用，而函数调用总是在函数执行之前对所有参数求值，因此无法实现内置版本的&&和||首先计算左边表达式，如果能决定结果就无需计算右边表达式的特性
* << 和 >> 只能通过全局函数配合友元函数进行重载
* 其余的运算符(一元)大多可以通过成员函数重载
* 二元运算符建议使用全局函数配合友元函数进行重载