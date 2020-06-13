---
title: stl_13.适配器
date: 2020-06-13T23:30:06+08:00
categories: STL
---
> 适配器:修饰容器、仿函数、和迭代器接口，给函数对象绑定额外参数，或将普通函数、成员函数适配成函数对象

## 1 函数对象适配器
> 将二元函数对象适配成一元函数对象，给函数对象绑定额外的参数

1. 继承(自己写函数对象)
    * `binary_function<参数类型, 参数类型, 返回值类型>  // 二元函数对象`
    * `unary_function<参数类型, 返回值类型>  // 一元函数对象`
2. 重写`operator()() const{}`(自己写函数对象)
3. 绑定
    * `bind1st(class(), x)  // 将参数x绑定为函数对象的第一个参数`
    * `bind2nd(class(), x)  // 将参数x绑定为函数对象的第二个参数`

```cpp
class PrintAdd : public binary_function<int, int, void> {
public:
	void operator()(int val, int num) const {
		cout << "val:" << val << " num:" << num << " val+nu= " << val+num << endl;
	}
};

void test() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(PrintAdd(), 10));  // 10->num  将参数绑定为函数对象的第二个参数
	for_each(v.begin(), v.end(), bind1st(PrintAdd(), 10));  // 10->val  绑定第一个参数
}
```

## 2 取反适配器
> 将函数对象适配成相反的策略

* 一元函数对象 `not1(class())`

```cpp
// 一元取反适配器
void test01() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 5)));  // 函数对象适配器+取反适配器
	cout << *it << endl;
}
```

* 二元函数对象 `not2(class())`

```cpp
// 二元取反适配器
void test02() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	sort(v.begin(), v.end(), not2(less<int>()));
	for (vector<int>::iterator it=v.begin(); it!=v.end(); it++) {
		cout << *it << endl;
	}
}
```

## 3 函数指针适配器
> 将普通函数指针适配成函数对象
> `ptr_fun(func)`

```cpp
void print_vector(int val, int num) {
	cout << val+num << " ";
}

void test() {
	vector<int>v;
	for (int i=0;i<10;i++) {
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(print_vector), 30));  // 回调函数指针适配成函数对象
}
```

## 4 成员函数适配器
> 将类的成员函数适配成函数对象

* `mem_fun_ref(&class::func)  // 容器中存放的是对象`
* `mem_fun(&class::func)  // 容器中存放的是对象指针`

```cpp
class Student {
 public:
	Student(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void get_info() {
		cout << "name:" << name << " age:" << age << endl;
	}
 private:
	string name;
	int age;
};

void test() {
	vector<Student>v;
	v.push_back(Student("tom", 18));
	v.push_back(Student("jerry", 19));
	v.push_back(Student("jeck", 20));
	for_each(v.begin(), v.end(), mem_fun_ref(&Student::get_info));  // 成员函数适配成函数对象
}
```
