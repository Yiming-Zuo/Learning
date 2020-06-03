---
title: cpp_04.类型转换
date: 2020-06-03
categories: Cpp
---

# 1 静态类型转换
`static_cast<type> (expression)`
* 基本类型转换

    ```cpp
    void test01() {
    	char ch = 'a';
    	cout << static_cast<double>(ch) << endl;
    }
    ```

* 父类子类之间转换

    ```cpp
    class Base {};
    class Son : public Base {};
    
    void test02() {
    	// 向下类型转换，不安全
    	Base *p_base_1 = NULL;
    	Son *p_son_1 = static_cast<Son *> (p_base_1);
    	// 向上类型转换，安全
    	Son *p_son_2 = NULL;
    	Base *p_base_2 = static_cast<Base *> (p_son_2);
    }
    ```

# 2 动态类型转换
`dynamic_cast<type> (expression)`
* 具有检查功能，不允许向下类型转换，因为不安全

```cpp
class Base {};
class Son : public Base {};

void test() {
//	// error：向下类型转换，不安全
//	Base *p_base_1 = NULL;
//	Son *p_son_1 = dynamic_cast<Son *> (p_base_1);
	// 向上类型转换，安全
	Son *p_son_2 = NULL;
	Base *p_base_2 = dynamic_cast<Base *> (p_son_2);
//	// 多态下的类型转换总是安全的，父类指针指向子类对象
//	Base *p = new Son;
//	Son *pSon = dynamic_cast<Son *> (p);
}
```

# 3 常量转换
`const_cast<type> (expression)`
* 常量指针和普通指针之间的转换

    ```cpp
    void test01() {
    	int num = 10;
    	const int *p_num = &num;
    //	*p_num = 100;  // error:const
    	int *p_num2 = const_cast<int *> (p_num);  // 去除const
    	*p_num2 = 100;
    	const int *p_num3 = const_cast<const int *> (p_num2);  // 转换为const
    	cout << num << endl;
    }
    ```

* 常量引用会让普通引用之间的转换

    ```cpp
    void test02() {
    	int num = 10;
    	const int &num_ref = num;
    //	num_ref = 100;  // error:const
    	int &num_ref2 = const_cast<int &> (num_ref);  // 去除const
    	num_ref2 = 100;
    //	const int &num_ref3 = const_cast<const int &> (num_ref2);  // 转换为const
    	cout << num << endl;
    }
    ```

* 不能对非指针或非引用的变量使用以去除它的const

# 4 重新解释类型转换
`reinterpret_cast<type> (expression)`
* 将一种数据类型转换为另一种数据类型，不安全

```cpp
void test() {
	int num = 100;
	char *p = reinterpret_cast<char *> (num);
	cout << p << endl;
}
```