#include <iostream>
using namespace std;

template <class T>
void print_vector(vector<T>&v) {
	for (vector<int>::iterator p=v.begin(); p!=v.end(); p++) {
		cout << *p << ' ';
	}
	cout << endl;
}