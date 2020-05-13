#include <iostream>

#include "game1.h"
#include "game2.h"
using namespace std;

// 1 :: 作用域运算符
int a = 10;
void func01(void) {
	int a = 20;
	cout << "a:" << a <<endl;  // std::cout std作用域
	// 访问被局部变量屏蔽的全局变量
	cout << "a:" << ::a << endl;  // ::前为空代表全局作用域
}
// 2 名字控制
// 2.1 命名空间
// 1.命名空间：控制标识符的作用域，避免命名冲突
void func02() {
	kingGlory::goAtk();
	LOL::goAtk();
}
// 2.命名空间中可以存放变量、结构体、函数、类...
namespace Test {
	int a = 2000;
	void func();
	struct Person {};
	class A {};
	// 3.命名空间嵌套命名空间
	namespace Test2 {
		int a;
	}
}
// 4.命名空间是开放的，可以随时添加新成员
namespace Test {
	int b = 100;
}
// 5.声明和实现可分离
void Test::func() {
	cout << "test func" << endl;
}

// 6.匿名命名空间内的标志符只能在本文件内访问
namespace {
	int m_a = 10000;
}
// 7.命名空间起别名
void func03() {
	namespace T = Test;  // namespace shortName = longName
	cout << T::a << endl;
}

// 2.3 using声明
void func04() {
	using Test::a;
	// int a = 1;  // 二义性，相当于两个局部变量
	cout << a << endl;  // 可直接使用
}

// 2.4 using编译指令
void func05() {
	int a = 1;  // 就近原则
	using namespace Test;
//	int a = 1;  // 就近原则
	// 相当于全局变量和局部变量
	cout << a << endl;  // 可直接使用
}

// 3 全局变量检测增强
int b;
//int b = 10;  // c可以，c++不行

// 4 函数检测增强
// 5 严格的类型转换

// 6 struct类型增强
struct Student {
	string name;
	int age;
	// 6.1 可以放函数
	void setAge(int num) {
		age = num;
	}
	void func(void) {
		age++;
	}
	void showStudent(void) {
		cout << name << " " << age << endl;
	}
};
void func06(void) {
	// 6.2 创建变量时不需要struct关键字
	Student Tom = { "Tom", 18 };
	Tom.showStudent();
	Tom.setAge(16);
	Tom.func();
	Tom.showStudent();
}

// 7 新增bool类型
void func07(void) {
	bool flag = 100;
	cout << flag << endl;  // 1
}

// 8 三目运算符功能增强
void func08(void) {
	int a = 100;
	int b = 200;
	// 运算符优先级
//	int ret = a > b ? a : b = 3;  // b=3 ret=b
	int ret = (a > b ? a : b) = 3;  // ret = b =3
	cout << ret << endl;  // ret = b =3
//	// c中的实现
//	*(a>b?&a:&b) = 3
}

// 9 const增强
void func09(void) {
	const Student P = {"person", 10};
//	P.name = "person";
//	P.age = 10;
}

// 10 引用:给变量起别名
void func10(void) {
	int a = 10;
	int &b = a;  // 引用必须初始化
	b = 100;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	int c = 20;
//	&b = c;  // 引用一旦初始化，就不可以引向别处
}
// 对数组的引用
void func11(void) {
	int arr[5] = { 1, 2, 3, 4, 5 };
	// 1.直接定义引用
	int (&arr1)[5] = arr;
	// 2.先定义数据类型，在定义引用
	typedef int(ARRAY_TYPE)[5];  // 数组数据类型
	ARRAY_TYPE &arr2 = arr;
	// 3.先定义数据引用类型，再定义引用
	typedef int(&ARRAY_REF_TYPE)[5];  // 数组引用数据类型
	ARRAY_REF_TYPE arr3 =arr;
	
	for (int i=0; i<5; i++) {
		cout << arr3[i] << endl;
	}
}
// 函数参数传递的三种方式
// 1.值传递
void valuePass(int a, int b) {
	int tmp = a;
	a = b;
	b = a;
}
// 2.地址传递
void addressPass(int *p_a, int *p_b) {
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
}
// 3.引用传递
void referencePass(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void func12(void) {
	int a = 10;
	int b = 20;
//	valuePass(a, b);
//	addressPass(&a, &b);
	referencePass(a, b);
	cout << "a:" << a << endl << "b:" << b <<endl;
}
// 4.引用的注意事项
// 4.1 引用必须引用合法的内存空间
// 4.2 不要返回局部变量的引用
// 4.3 返回变量引用时，函数可以做赋值表达式的左值
int &passFunc(void) {
	static int a = 0;  // 静态局部变量
	return a;
}
void func13() {
	int &a = passFunc();  // int &a 返回的是引用类型
	cout << "a:" << a << endl;
	passFunc() = 1999;
	cout << "a:" << a << endl;
}
// 5.引用的本质：指针常量
void func14(void) {
	int a = 10;
	int &b = a;  // int * const b = a;
	b = 100;  // *b = 100;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
}
// 6.指针的引用
void allocateSpace(Student *&p) {
	p = (Student *)malloc(sizeof(struct Student));
	p->age = 18;
}
void func15(void) {
	Student *p = NULL;
	allocateSpace(p);
	cout << p->age << endl;
}
// 7.常量的引用
void func16(void) {
	const int &a = 100;  // int tmp = 100; const int &a = tmp;
	// 间接修改
	int *p = (int *)&a;
	*p = 1000;
	cout << a << endl;
}
// 应用：const修饰形参，防止误修改数据
void showValue(const int &a) {
//	a = 1;
	cout << a << endl;
}
void func17(void) {
	int a = 10000;
	showValue(a);
}






int main(int argc, char *argv[]) {
//	func01();
//	func02();
//	Test::func();
//	func03();
//	func04();
//	func05();
//	func06();
//	func07();
//	func08();
//	func09();
//	func10();
//	func11();
//	func12();
//	func13();
//	func15();
//	func16();
	func17();
	return 0;
}