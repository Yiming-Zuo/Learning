#pragma once
#include <iostream>
using namespace std;

class MyArray {
public:
	MyArray();
	explicit MyArray(int capacity);
	MyArray(MyArray &arr);
	~MyArray();
	// 用户操作接口
	void set_data(int pos, int val);
	void push_back(int val);
	int get_data(int pos);  // 返回值
	int &operator[](int pos);  // 返回自身引用，操作符重载
	int get_len();
private:
	int m_capacity;
	int m_size;
	int *p_address;
};