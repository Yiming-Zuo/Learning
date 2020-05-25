#include "MyArray.h"

MyArray::MyArray() {
	this->m_capacity = 100;
	this->m_size = 0;
	this->p_address = new int[this->m_capacity];
}

MyArray::MyArray(int capacity) {
	this->m_capacity = capacity;
	this->m_size = 0;
	this->p_address = new int[this->m_capacity];
}

MyArray::MyArray(MyArray &arr) {
	this->m_capacity = arr.m_capacity;
	this->m_size = arr.m_size;
	this->p_address = new int[arr.m_capacity];
	memcpy(this->p_address, arr.p_address, sizeof(int)*this->m_capacity);
}

MyArray::~MyArray() {
	if (this->p_address != NULL) {
		delete []this->p_address;
		this->p_address = NULL;
	}
}

void MyArray::set_data(int pos, int val) {
	if (pos >= m_capacity) {
		return;
	}
	if (pos < 0 || pos > m_size) {
		pos = m_size;
	}
	p_address[pos] = val;
}

void MyArray::push_back(int val) {
	p_address[m_size] = val;
	m_size++;
}

int MyArray::get_data(int pos) {
	return p_address[pos];
}

int &MyArray::operator[](int pos) {
	return p_address[pos];
}


int MyArray::get_len() {
	return m_size;
}
