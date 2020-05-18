#include "class.h"

void Circle::set_circle(int x, int y, int r) {
	center.set_point(x, y);
	m_r = r;
}
int Circle::get_x() {
	return center.get_x();
}
int Circle::get_y() {
	return center.get_y();
}
int Circle::get_r() {
	return m_r;
}

void Point::set_point(int x, int y) {
	m_x = x;
	m_y = y;
}
int Point::get_x() {
	return m_x;
}
int Point::get_y() {
	return m_y;
}
void Point::isPointInCircle(Circle &circle) {
	int distance = (m_x-circle.get_x()) * (m_x-circle.get_x()) + (m_y-circle.get_y())*(m_y-circle.get_y());
	int radius = circle.get_r() * circle.get_r();
	if ( distance == radius ) {
		cout << "点在圆上" << endl;
	} else if ( distance < radius ) {
		cout << "点在圆内" << endl;
	} else {
		cout << "点在圆外" << endl;
	}
}
