// 案例一：设计一个圆的类，求其周长
#include <iostream>
using namespace std;

const double PI = 3.14;

class Circle {
public:
	int m_R;
	void setR(int r) {
		m_R = r;
	}
	int getR() {
		return m_R;
	}
	double calPerimeter() {
		return 2 * PI * m_R;
	}
	void showCircle() {
		cout << "半径：" << getR() << endl;
		cout << "周长：" << calPerimeter() << endl;
	}
};

int main(int argc, char *argv[]) {
	Circle c1;
	c1.setR(10);
	c1.showCircle();
	return 0;
}