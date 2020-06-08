
#include <iostream>
#include <vector>
using namespace std;

// 1.构造函数
void test01() {
	string str2;  // string()
	string str1 = str2;  // string(const string &str)
	string str3 = "hello";  // string(const char *s)
	string str4(5, 'x');  // string(int n, char c)
	cout << str4 << endl;
}

// 2.基本赋值操作
void test02() {
	// 1.=
	string str1, str2;
	str1 = "hello";  // string &operator=(const char *s)
	str2 = str1;  // string &operator=(const string &str)
	str1 = 'a';  // string &operator=(const char *c);
	
	// 2. string.assign()
	string str3;
	str3.assign("hello");  // string& assign(const char *s);//把字符串s赋给当前的字符串
	cout << str3 << endl;
	str3.assign("hello", 3);  // string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
	cout << str3 << endl;
	str3.assign(str2);  // string& assign(const string &s);//把字符串s赋给当前字符串
	cout << str3 << endl;
	str3.assign(5, 'x');  // string& assign(int n, char c);//用n个字符c赋给当前字符串
	cout << str3 << endl;
	str3.assign(str2, 2, 3);  // string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
	cout << str3 << endl;
}

// 3.存取操作
void test03() {
	// []和at区别，[]访问越界 直接挂掉，at访问越界，抛出异常 out_of_range
	string str = "hello";
	cout << str[3] << endl;  // char& operator[](int n);//通过[]方式取字符
	str[3] = 'x';
	cout << str.at(3) << endl;  // char& at(int n);//通过at方法获取字符
}

// 4.拼接操作
void test04() {
	// 1.+=
	string str = "hello";
	str += str;  // string& operator+=(const string& str);//重载+=操作符
	cout << str << endl;
	str += "hello";  // string& operator+=(const char* str);//重载+=操作符
	cout << str << endl;
	str += 'x';  // string& operator+=(const char c);//重载+=操作符
	cout << str << endl;
	
	// 2. string.append()
	str = "hello";
	str.append(" world!");  // string& append(const char *s);//把字符串s连接到当前字符串结尾
	cout << str << endl;
	str.append(" byebye", 4);  //string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
	cout << str << endl;
	str.append(str);  //string& append(const string &s);//同operator+=()
	cout << str << endl;
	str.append(str, 5, 7);  // string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
	cout << str << endl;
	str.append(5, 'x');  // string& append(int n, char c);//在当前字符串结尾添加n个字符c
	cout << str << endl;
}

// 5.查找和替换操作
void test05() {
	// 1.查找 string.find() string.rfind()
	// find从左往后查 rfind 从右往左查
	// -1:未找到
	string str = "hello world!";
	cout << str.find(str) << endl;  //int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
	cout << str.find("world!") << endl;  // int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
	cout << str.find("worldxxxx", 0, 5) << endl;  // int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
	cout << str.find('d') << endl;  // int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
	cout << str.find(str) << endl;  // int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
	
	cout << str.rfind("wo") << endl; // int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
	cout << str.find(str) << endl;
	// int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
	cout << str.find('d') << endl;  // int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
	
	// 2.替换 str.replace()
	string str2 = "haha";
	cout << str.replace(1, 5, str2) << endl;  // string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
	cout << str.replace(1, 3, "xixi") << endl;  // string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
}

// 6.比较操作 str.compare()
void test06() {
	// >返回1，<返回-1，==返回0
	string str1 = "tom";
	string str2 = "jerry";
	cout << str1.compare(str2) << endl;  // int compare(const string &s) const;//与字符串s比较
	cout << str1.compare("tom") << endl;  // int compare(const char *s) const;//与字符串s比较
}

// 7.字串 str.substr()
void test07() {
//	string str = "hahaxixilala";
//	cout << str.substr(3, 5);  // string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串

#if 0	
	string email = "zhangtao@sina.com";
	int pos = email.find("@"); // pos = 8
	string usrName = email.substr(0, pos); // 8
	cout << "name = " << usrName << endl;
#endif

	string website = "www.blog.xmingo.com";
	vector<string>v;
	
	int start = 0;
	int pos = -1;
	while (true) {
		pos = website.find('.', start);
		if (pos == -1) {
			string sub_str = website.substr(start, website.size() - start);
			v.push_back(sub_str);
			break;
		}
		string sub_str = website.substr(start, pos - start);
		v.push_back(sub_str);
		start = pos + 1;
	}
	for (vector<string>::iterator p = v.begin(); p!=v.end(); p++) {
		cout << *p << endl;
	}
}

// 8.插入和删除操作
void test08() {
	// 1.插入 str.insert()
	string str = "hello";
	cout << str.insert(0, " world!") << endl;  // string& insert(int pos, const char* s); //插入字符串
	cout << str.insert(1, str) << endl;  // string& insert(int pos, const string& str); //插入字符串
	cout << str.insert(2, 5, 'x') << endl;  // string& insert(int pos, int n, char c);//在指定位置插入n个字符c
	
	// 2.删除 str.erese()
	cout << str.erase(0, 3) << endl;// string& erase(int pos, int n = npos);//删除从Pos开始的n个字符 
	cout << string::npos << endl;  // 不存在的位置
}

// 9.string 与 const char * 互转
void test09() {
	// 1 const char * --> string
	string str = "hello";  // 隐式类型转换
	// 2 string --> const char *
	const char *str2 = str.c_str();
	cout << str2 << endl;
}

// 10 为了修改string字符串的内容，下标操作符[]和at都会返回字符的引用。但当字符串的内存被重新分配之后，可能发生错误.
void test10() {
	string str = "abcdefg";
	char &c = str[2];
	char &d = str[3];
	c = '1';
	d = '2';
	cout << str << endl;
	cout << (int *)str.c_str() << endl;
	
	str = "helloaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";  // 重新分配内存
	//a和b不可以再使用了
//	a = '1';
//	b = '2';
	cout << str << endl;
	cout << (int *)str.c_str() << endl;
}

// 11 string大小写转换
string &convert_string(string &str) {
	for (int i=0; i<str.size(); i++) {
//		if (str[i] >= 97 & str[i] <= 122) {
//			str[i] -= 32;
//		}
		str[i] = toupper(str[i]);
//		str[i] = tolower(str[i]);
	}
	return str;
}

void test() {
	string str = "Hello World!";
	cout << convert_string(str) << endl;
}


int main(int argc, char *argv[]) {
//	test01();
//	test02();
//	test03();
//	test04();
//	test05();
//	test06();
	test07();
//	test08();
//	test09();
//	test10();
//	test();
	return 0;
}