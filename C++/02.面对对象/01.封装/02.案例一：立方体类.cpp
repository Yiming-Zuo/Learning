#include <iostream>
using namespace std;

class Cube {
	int m_length;
	int m_width;
	int m_height;
public:
	void set_cube(int length, int width, int height) {
		m_length = length;
		m_width = width;
		m_height = height;
	}
	int get_legth() {
		return m_length;
	}
	int get_width() {
		return m_width;
	}
	int get_height() {
		return m_height;
	}
	int caculate_area() {
		return (m_length*m_width + m_length*m_height +m_width*m_height) * 2;
	}
	int caculate_volume() {
		return m_length*m_width*m_height;
	}
	void get_cube() {
		cout << "长：" << m_length << endl;
		cout << "宽：" << m_width << endl;
		cout << "高：" << m_height << endl;
		cout << "面积：" << caculate_area() << endl;
		cout << "体积：" << caculate_volume() << endl;
	}
	bool compare_cube(Cube &c) {
		return c.get_legth() == m_length & c.get_width() == m_width & c.get_height() == m_height;
	}
};

int main(int argc, char *argv[]) {
	Cube c1, c2;
	c1.set_cube(3, 4, 5);
	c2.set_cube(3, 4, 5);
	c1.get_cube();
	if (c1.compare_cube(c2)) {
		cout << "c1和c2相等" << endl;
	} else {
		cout << "c1和c2不相等" << endl;
	}
	return 0;
}