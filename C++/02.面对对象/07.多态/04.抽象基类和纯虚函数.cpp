// 抽象基类：仅仅是派生类的一个接口，而不是希望用户创建一个基类的对象，在抽象基类中有纯虚函数为指定函数保留一个位置，而不需要具体实现。
// 子类必须实现抽象基类所有的虚函数，否则子类也是抽象基类
// virtual void fun()=0; 功能声明，告诉编译器在虚函数表中为该函数保留一个位置，但是在这个指定位置中不放函数的地址
#include <iostream>
using namespace std;

class AbstractDrinking {
 public:
	void makeDrink() {
		boil();
		brew();
		pourInCup();
		putSomething();
	}
 private:
	virtual void boil() = 0;  // 烧水
	virtual void brew() = 0;  // 冲泡
	virtual void pourInCup() = 0;  // 倒入杯中
	virtual void putSomething() = 0;  // 加入辅料
};

class Tea : public AbstractDrinking {
	void boil() {
		cout << "煮80摄氏度的山泉水\n";
	}
	void brew() {
		cout << "加入极品大红袍\n";
	}
	void pourInCup() {
		cout << "将冲好的茶叶倒入品茗杯中\n";
	}
	void putSomething() {
		cout << "啥都不加\n";
	}
};

void doWork(AbstractDrinking &drink) {
	drink.makeDrink();
}

int main(int argc, char *argv[]) {
	Tea tea;
	doWork(tea);
	return 0;
}