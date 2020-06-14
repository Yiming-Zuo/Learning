#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

class Student {
 public:
	Student(string name, int age) {
		this->name = name;
		this->age = age;
	}
	bool operator==(const Student &sd) {  // 重载==运算符
		return (sd.name==name && sd.age==age);
	}
	string name;
	int age;
};

class GreaterStudent : public binary_function<Student, Student, bool>{
 public:
	bool operator()(Student s1, Student s2) const {
		return s1.age>s2.age;
	}
};

// 1.普通查找和条件查找
void test01() {
	vector<Student>v;
	v.push_back(Student("tom", 18));
	v.push_back(Student("jerry", 19));
	v.push_back(Student("jack", 20));
	v.push_back(Student("mary", 21));
	v.push_back(Student("tony", 22));
	
	// 1 find()
	vector<Student>::iterator pos1 = find(v.begin(), v.end(), Student("tom", 18));
	if (pos1 == v.end()) {
		cout << "未找到" << endl;
	} else {
		cout << "找到了元素:" << pos1->name << endl;
	}
	
	// 2 find_if()
	Student jack("jack", 20);
	vector<Student>::iterator pos2 = find_if(v.begin(), v.end(), bind2nd(GreaterStudent(), jack));
	if (pos2 == v.end()) {
		cout << "未找到" << endl;
	} else {
		cout << "找到了元素:" << pos2->name << endl;
	}
}

// 2 adjacent_find() 查找相邻重复元素
void test02() {
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());  // 返回相邻元素的第一个位置的迭代器
	if (pos == v.end()) {
		cout << "未找到" << endl;
	} else {
		cout << "找到了重复元素:" << *pos << endl;
	}
}

// 3 binary_search() 二分查找
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//v.push_back(3); 容器必须是有序序列！！
	bool ret = binary_search(v.begin(), v.end(), 9);
	if (ret) {
		cout << "找到了9" << endl;
	}
	else {
		cout << "未找到9" << endl;
	}
}

// count() 统计元素出现次数
void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	v.push_back(5);
	
	int num1 = count(v.begin(), v.end(), 5);
	cout << "元素5的个数为:" << num1 << endl;
	
	int num2 = count_if(v.begin(), v.end(), bind2nd(greater<int>(), 3));  // count_if()
	cout << "大于3的元素个数为:" << num2 << endl;
}

int main(int argc, char *argv[]) {
//	test01();
//	test02();
//	test03();
	test04();
	return 0;
}