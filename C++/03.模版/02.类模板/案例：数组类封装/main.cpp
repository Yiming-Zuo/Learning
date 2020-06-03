#include <iostream>
#include "Array.hpp"
using namespace std;

void test() {
	Array<int> arr1(10);
	arr1.push_back(10);
	arr1.push_back(20);
	Array<int> arr2(arr1);
	arr2 = arr1 = arr2;
	cout << arr2[1] << endl;
}

class Person {
 public:
	string name;
	int age;
};

void printPersonArr(Array<Person> &arr) {
	for (int i=0; i<arr.get_size(); i++) {
		cout << "name:" << arr[i].name << endl;
		cout << "age:" << arr[i].age << endl;
	}
}

void test02() {
	Array<Person> arr1(10);
	arr1.push_back(Person());
	arr1[0].name="tom";
	arr1[0].age=10;
	printPersonArr(arr1);
}

int main(int argc, char *argv[]) {
//	test();
	test02();
	return 0;
}