// 1.重复继承，数据有两份
// 2.对重复继承的成员产生二义性
#include <iostream>
using namespace std;

class Animal {
 public:
	void func() {
		cout << "动物类\n";
	}
	int age;
};

class Sheep : public Animal {};
class Tuo : public Animal {};
class SheepTuo : public Sheep, public Tuo {};

int main(int argc, char *argv[]) {
	SheepTuo st;
//	st.func();  // 二义性
	st.Sheep::func();
	// 重复继承
	cout << sizeof(Animal) << endl;
	cout << sizeof(Sheep) << endl;
	cout << sizeof(Tuo) << endl;
	cout << sizeof(SheepTuo) << endl;
	return 0;
}