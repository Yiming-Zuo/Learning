#pragma once
#include <iostream>
using namespace std;
class MyString;

ostream &operator<<(ostream &cout, const MyString &str);
istream &operator>>(istream &cin, MyString &str);

class MyString {
	friend ostream &operator<<(ostream &cout, const MyString &str);
	friend istream &operator>>(istream &cin, MyString &str);
public:
	MyString();
	MyString(const char *str);  // Mystring str = "abc"
	MyString(const MyString &str);  // Mystring str2 = str
	~MyString();
	
	MyString &operator=(const char *str);  // str = "bcd"
	MyString &operator=(const MyString &str);  // str2 = str
	
	MyString operator+(const char *str);
	MyString operator+(const MyString &str);
	
	char &operator[](int pos);
	
	bool operator==(const char *str);
	bool operator==(const MyString &str);

private:
	char *pString;
	int m_size; 	
};