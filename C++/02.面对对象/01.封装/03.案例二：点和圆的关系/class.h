#pragma once
#include <iostream>
using namespace std;
// 类的声明
class Point;
class Circle;

class Point {
	int m_x;
	int m_y;
public:
	void set_point(int x, int y);
	int get_x();
	int get_y();
	void isPointInCircle(Circle &circle);
};

class Circle {
	Point center;
	int m_r;
public:
	void set_circle(int x, int y, int r);
	int get_x();
	int get_y();
	int get_r();
};

