---
title: cpp_06.运算符重载
date: 2020-05-21
categories: Cpp
---

> 运算符重载：`operator@` 对已有的运算符重新定义，赋予其另一种功能，以适应不同的数据类型，本质时另外一种形式的函数调用

# 1 加号运算符重载

```cpp
class Num {
public:
	Num(){}
	Num(int a, int b):num_a(a), num_b(b) {}
	// 成员函数实现
	Num operator+(Num &n) {
		Num temp;
		temp.num_a = this->num_a + n.num_a;
		temp.num_b = this->num_b + n.num_b;
		return temp;  // 调用拷贝构造函数创建一个新对象返回
	}
	int num_a;
	int num_b;	
};
// 全局函数实现
Num operator+(Num &n1, int num) {
	Num temp;
	temp.num_a = n1.num_a + num;
	temp.num_b = n1.num_b + num;
	return temp;  // 调用拷贝构造函数创建一个新对象返回
}

int main(int argc, char *argv[]) {
	Num n1(10, 20);
	Num n2(20, 10);
//	Num n3 = n1.operator+(n2);  // 本质调用
	Num n3 = n1 + n2;
	cout << n3.num_a << " " << n3.num_b << endl;
	Num n4 = n1 + 100;  // 运算符重载可以发生函数重载
	cout << n4.num_a << " " << n4.num_b << endl;
	return 0;
}
```

# 2 左移运算符重载
* 全局函数实现配合友元函数
* 实现链式编程：返回自身引用

```cpp
class Num {
friend ostream &operator<<(ostream &cout, Num n);  // 配合友元函数
public:
	Num(){}
	Num(int a, int b):num_a(a), num_b(b) {}
private:
	int num_a;
	int num_b;	
};
// 全局函数实现
ostream &operator<<(ostream &cout, Num n) {
	cout << "num_a:" << n.num_a << " " << "num_b:" << n.num_b;
	return cout;
}

int main(int argc, char *argv[]) {
	Num n1(10, 20);
	cout << n1 << endl;  // 实现链式编程：返回cout本身
	return 0;
}
```

# 3 递增运算符重载
* 前置运算符重载：返回自身引用
* 后置运算符重载(int占位符)：返回实现记录好的对象(值传递)
* 形参是值，实参可以是引用
* 形参是引用，实参不可以是值

```cpp
class Num {
	friend ostream &operator<<(ostream &cout, Num num);
public:
	Num(){}
	Num(int num):m_num(num) {}
	// 前置递增运算符重载
	Num &operator++() {  // 单目运算符
		m_num++;
		return *this;  // 返回自身引用
	}
	// 后置递增运算符重载
	Num operator++(int) {  // int占位符：后置
		Num temp = *this;  // 先记录当前对象
		m_num++;  // 当前对象值改变
		return temp;  // 返回之前对象（栈上返回值）调用拷贝构造函数创建新的对象（返回引用不调用拷贝构造函数，栈上被释放）
	}
private:
	int m_num;
};

ostream &operator<<(ostream &cout, Num num) {  // Num不是传入引用，是传入值，如果参数是引用，++i重载时传入值时报错
	cout << num.m_num;
	return cout;
}

void func01(void) {
	Num num(10);
	cout << ++(++num) << endl;
//	num++;  // 返回的是之前的对象的记录，但是当前对象已经发生了变化
	cout << num++ << endl;
	cout << num << endl;
}

int main(int argc, char *argv[]) {
	func01();
	return 0;
}
```

# 4 指针运算符重载
* 智能指针，可以托管new出来的对象，不用手动delete
* 堆区空间只有delete时才会调用析构函数

```cpp
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
```

# 5 指针运算符重载
* 编译器为类提供默认的operator=(值传递)函数
* 当类中有成员指针变量时，要定义深拷贝构造函数和进行赋值运算符重载

```cpp
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
```

# 6 中括号运算符重载

```cpp
// 数组类封装
// 链式编程：返回自身引用
int &MyArray::operator[](int pos) {
	return p_address[pos];
}
```

# 7 关系运算符重载

```cpp
class Person {
public:
	Person(string name, int age):m_name(name), m_age(age){}
	bool operator==(Person &p) {
		return m_name==p.m_name&&m_age==p.m_age;
	}
	bool operator!=(Person &p) {
		return m_name!=p.m_name||m_age!=p.m_age;
	}
private:
	string m_name;
	int m_age;
};

int main(int argc, char *argv[]) {
	Person tom("tom", 18);
	Person jerry("jerry", 20);
	cout << (tom==jerry) << endl;
	return 0;
}
```

# 8 函数调用运算符重载
* 仿函数：本质是函数对象

```cpp
class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1+num2;
	}
};

int myadd(int num1, int num2) {
	return num1+num2;
}

int main(int argc, char *argv[]) {
	MyAdd add;
	cout << myadd(10, 29) << endl;  // 普通函数
	cout << add(10, 29) << endl;  // 仿函数，本质是函数对象
	cout << MyAdd()(10, 29) << endl;  // 常用：匿名函数对象MyAdd()执行完自动销毁
	return 0;
}
```

# 9 运算符重载总结
* 不能重载&&和||：无法实现短路规则      
因为操作符重载其实是另外一种形式的函数调用，而函数调用总是在函数执行之前对所有参数求值，因此无法实现内置版本的&&和||首先计算左边表达式，如果能决定结果就无需计算右边表达式的特性
* << 和 >> 只能通过全局函数配合友元函数进行重载
* 其余的运算符(一元)大多可以通过成员函数重载
* 二元运算符建议使用全局函数配合友元函数进行重载

# 10 案例：字符串类封装