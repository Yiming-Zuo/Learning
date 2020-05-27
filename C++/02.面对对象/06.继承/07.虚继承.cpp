// 虚继承的类中内存中增加了一个vbptr(virtual base pointer)，vbptr指向了一张表vbtable，表中保存了当前的虚指针对于虚基类的首地址偏移量，使他们共享一份数据
// 虚继承只能解决具备公共祖先的多继承所带来的二义性问题，不能解决没有公共祖先的多继承的.
#include <iostream>
using namespace std;

class Animal {
 public:
	void func() {
		cout << "动物类\n";
	}
	int age;
};

class Sheep : virtual public Animal {};
class Tuo : virtual public Animal {};
class SheepTuo : public Sheep, public Tuo {};  // 继承了两份vbptr指针

int main(int argc, char *argv[]) {
	SheepTuo st;
//	st.func();  // 二义性
	st.Sheep::func();
	// 重复继承
	cout << sizeof(Animal) << endl;  // 4
	cout << sizeof(Sheep) << endl;  // 4+8(指针)+4(表)
	cout << sizeof(Tuo) << endl;
	cout << sizeof(SheepTuo) << endl;  // 4+4+4+8+4(覆盖表)
	return 0;
}