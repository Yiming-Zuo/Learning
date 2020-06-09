---
title: stl_02.迭代器
date: 2020-06-07T17:43:23+08:00
categories: Cpp
---
> `iterator` 普通迭代器
> `reverse_iterator` 反转迭代器
> `const_iterator` 只读迭代器

## 1 利用迭代器遍历容器中的元素
* 普通类型

```cpp
void test01() {
	vector<int>v;  // 单端数组
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	
	// 遍历容器1
	vector<int>::iterator pStart = v.begin();  // 起始迭代器，指向容器中中第一个元素的地址
	vector<int>::iterator pEnd = v.end();  // 结束迭代器，指向容器中最后一个元素的下一个位置的数组
	while (pStart != pEnd) {
		cout << *pStart << endl;
		pStart++;
	}
	
	// 遍历容器2
	for (vector<int>::iterator p=v.begin(); p!=v.end(); p++) {
		cout << *p << endl;
	}
	
	// 遍历容器3
	for_each(v.begin(), v.end(), myPrint);
}
```

* 自定义数据类型

```cpp
class Person {
 public:
	Person(string name, int age) : m_name(name), m_age(age) {}
	void print_person() {
		cout << "name:" << m_name << " age:" << m_age << endl;
	}
 private:
	string m_name;
	int m_age;
};

void my_print_person1(Person &person) {
	person.print_person();
}

void test02() {
	vector<Person>v;
	v.push_back(Person("tom", 18));
	v.push_back(Person("jerry", 19));
	v.push_back(Person("jack", 20));
	v.push_back(Person("marry", 21));
	
	for_each(v.begin(), v.end(), my_print_person1);
}
```

* 自定义数据类型指针

```cpp
void my_print_person2(Person *person) {
	person->print_person();
}

void test03() {
	vector<Person*>v;
	Person p1("tom", 18);
	Person p2("jerry", 19);
	Person p3("jack", 20);
	Person p4("marry", 21);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	
	for_each(v.begin(), v.end(), my_print_person2);
}
```

* 容器嵌套容器

> `vector< vector<int> >v;`

```cpp
void my_print_vector(vector<int> v) {
	for_each(v.begin(), v.end(), myPrint);
}

// 容器嵌套容器
void test04() {
	vector< vector<int> >v;
	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	for (int i=0; i<5; i++) {
		v1.push_back(i);
		v2.push_back(i+10);
		v3.push_back(i+10);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	
//	for_each(v.begin(), v.end(), my_print_vector);
	for (vector< vector<int> >::iterator p = v.begin(); p != v.end(); p++) {
		for (vector<int>::iterator p_int = (*p).begin(); p_int != (*p).end(); p_int++) {
			cout << *p_int << endl;
		}
	}
}

```

## 2 利用反转迭代器逆序遍历容器中的元素

```cpp
void test() {
	vector<int>v;
	for (int i=0;i<100000;i++) {
		v.push_back(i);
	}
	for (vector<int>::reverse_iterator p=v.rbegin(); p!=v.rend(); p++) {  // 反转迭代器
		cout << *p << endl;
	}
}
```

## 3 判断容器迭代器的类型

```cpp
void test() {
	// 随机访问迭代器
	vector<int>v;
	vector<int>::iterator p_v = v.begin();
	p_v++;
	p_v--;
	p_v+=5;
	
	// 双向迭代器
	list<int>l;
	list<int>::iterator p_l = l.begin();
	p_l++;
	p_l--;
//	p_l+=5;  // error
}
```