#pragma once
#include <iostream>
using namespace std;

template <class ElementName>
class Array {
 public:
	Array() {
		m_capacity = 100;
		p_address = new ElementName[m_capacity];
		m_size = 0;
	}
	Array(int num) {
		m_capacity = num;
		p_address = new ElementName[m_capacity];
		m_size = 0;
	}
	Array(const Array &arr) {
		m_capacity = arr.m_capacity;
		p_address = new ElementName[m_capacity];
		memcpy(p_address, arr.p_address, sizeof(arr));
		m_size = arr.m_size;
	}
	~Array() {
		if (p_address != NULL) {
			delete []p_address;
			p_address = NULL;
		}
	}
	Array &operator=(const Array &arr) {
		if (p_address != NULL) {
			delete []p_address;
			p_address = NULL;
		}
		m_capacity = arr.m_capacity;
		p_address = new ElementName[m_capacity];
		memcpy(p_address, arr.p_address, sizeof(arr));
		m_size = arr.m_size;
		return *this;
	}
	ElementName &operator[](int pos) {
		return p_address[pos];
	}
	void push_back(ElementName data) {
		if (m_capacity == m_size) {
			return;
		}
		p_address[m_size] = data;
		m_size++;
	}
	int get_size() {
		return m_size;
	}
	int get_capacity() {
		return m_capacity;
	}
 public:
	ElementName *p_address;
	int m_capacity;
	int m_size;
};
