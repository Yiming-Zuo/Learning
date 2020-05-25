#include <iostream>
#include "myString.h"
using namespace std;

int main(int argc, char *argv[]) {
	// <<
	MyString str = "abc";
	cout << str << endl;
	// >>
	cin >> str;
	cout << str << endl;
	// =
	MyString str2 = str;
	cout << str2 << endl;
	str = "hello";
	cout << str << endl;
	// ==
	MyString str3;
	str3 = str = str2;
	cout << str3 << endl;
	// +
	str = "hello";
	MyString str4;
//	str4 = str + " world" + " xixi";
	str4 = str + " world" + str;
	cout << str4 << endl;
	// []
	cout << str4[2] << endl;
	str4[2] = '8';
	cout << str4 << endl;
	// ==
	cout << (str=="hello") << endl;
	cout << (str==str4) << endl;
	return 0;
}
