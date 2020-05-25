#include "myString.h"

ostream &operator<<(ostream &cout, const MyString &str) {
	cout << str.pString;
	return cout;
}

istream &operator>>(istream &cin, MyString &str) {
	// 1.先释放原来的堆区字符数组
	if (str.pString != NULL) {
		delete []str.pString;
		str.pString = NULL;
	}
	// 2.创建临时数组存储输入的字符串
	char temp[128] = "";
	cin >> temp;
	// 3.利用临时数组创建新的堆区空间
	str.pString = new char[strlen(temp)+1];
	strcpy(str.pString, temp);
	str.m_size = strlen(temp);
	
	return cin;
}


MyString::MyString() {
	pString = NULL;
	m_size = 0;
}

MyString::MyString(const char *str) {
	this->pString = new char[strlen(str)+1];
	strcpy(this->pString, str);
	this->m_size=strlen(str);
}

MyString::MyString(const MyString &str) {
	this->pString = new char[str.m_size+1];
	strcpy(this->pString, str.pString);
	this->m_size=str.m_size;
}

MyString::~MyString() {
	if (pString != NULL) {
		delete []pString;
		pString = NULL;
	}
};
	
MyString &MyString::operator=(const char *str) {
	if (this->pString != NULL) {
		delete []pString;
		pString = NULL;
	}
	pString = new char[strlen(str)+1];
	strcpy(pString, str);
	m_size = strlen(str);
	return *this;
}

MyString &MyString::operator=(const MyString &str) {
	if (this->pString != NULL) {
		delete []pString;
		pString = NULL;
	}
	pString = new char[str.m_size+1];
	strcpy(pString, str.pString);
	m_size = str.m_size;
	return *this;
}

// 对象自身不发生变化，返回一个新的对象
MyString MyString::operator+(const char *str) {
	// 1.根据两个字符串拼接好的长度在堆区创建一个临时字符数组并清空
	int new_size = m_size + strlen(str) + 1;
	char *temp = new char[new_size];
	memset(temp, 0, new_size);
	// 2.依次将两个字符串拼接进临时字符串
	strcat(temp, pString);
	strcat(temp, str);
	MyString newString = temp;  // 3.利用拼接好的字符串创建新的对象返回
	delete []temp;  // 4.释放堆区的临时字符串
	return newString;	
}

MyString MyString::operator+(const MyString &str) {
	int new_size = m_size + str.m_size + 1;
	char *temp = new char[new_size];
	memset(temp, 0, new_size);
	strcat(temp, pString);
	strcat(temp, str.pString);
	MyString newString = temp;  // 3.利用拼接好的字符串创建新的对象返回
	delete []temp;  // 4.释放堆区的临时字符串
	return newString;
}

char &MyString::operator[](int pos) {
	return pString[pos];
}

bool MyString::operator==(const char *str) {
	return !strcmp(pString, str);
}

bool MyString::operator==(const MyString &str) {
	return strcmp(pString, str.pString)==0;
}