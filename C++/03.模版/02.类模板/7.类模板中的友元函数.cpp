#include <iostream>
using namespace std;
// 2.1 让编译器看到类声明
template<class NameType, class AgeType> class Student;  // 类模板的声明
// 2.2 让编译器看到函数模板声明
template <class NameType, class AgeType> void print_student02(Student<NameType, AgeType> &student);

template<class NameType, class AgeType>
class Student {
	friend void print_student02<>(Student<NameType, AgeType> &student);  // 2.3 func<>() 模版函数  func() 普通函数
	// 1.友元函数类内实现
	friend void print_student01(Student<NameType, AgeType> &student) {
		cout << "name:" << student.name << endl;
		cout << "age:" << student.age << endl;
	}
 public:
	Student(NameType name, AgeType age) {
		this->name = name;
		this->age = age;
	}
 private:
	NameType name;
	AgeType age;		
};

// 2.友元函数类外实现
template <class NameType, class AgeType>
void print_student02(Student<NameType, AgeType> &student) {
	cout << "name:" << student.name << endl;
	cout << "age:" << student.age << endl;
}

void test() {
	Student<string, int> tom("tom", 18);
//	print_student01(tom);
	print_student02(tom);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}