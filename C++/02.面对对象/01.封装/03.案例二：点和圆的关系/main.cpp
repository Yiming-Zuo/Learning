#include <iostream>
#include "class.h"
using namespace std;




int main(int argc, char *argv[]) {
	Circle c1;
	Point p1;
	c1.set_circle(20, 20, 5);
	p1.set_point(25, 20);
	p1.isPointInCircle(c1);
	return 0;
}