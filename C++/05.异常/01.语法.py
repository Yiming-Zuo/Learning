#include <iostream>
using namespace std;
r
double my_disivion(int num1, int num2) {
	if (num2 == 0) {
		throw 0;
	}
	return num1/static_cast<double>(num2);
}

int main(void) {
	cout << my_disivion(8, 0) << endl;
	return 0;
}