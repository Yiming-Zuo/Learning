#include <iostream>
#include <string>
using namespace std;

void test(void) {
	pair<string, int>tom("tom", 15);
	cout << tom.first << endl << tom.second << endl;
	
	pair<string, int>jerry = make_pair("jerry", 18);
	cout << jerry.first << endl << jerry.second << endl;
}

int main(void) {
	test();
	return 0;
}