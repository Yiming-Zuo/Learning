#include "MyArray.h"

int main(int argc, char *argv[]) {
	MyArray myarr;
	myarr.push_back(0);
	myarr.push_back(1);
	myarr.push_back(2);
	myarr.push_back(3);
	myarr.push_back(4);
	myarr.push_back(5);
	myarr.push_back(6);
	myarr.set_data(3, 100);
	for (int i=0;i<myarr.get_len();i++) {
		cout << i << ":" << myarr.get_data(i) << endl;
	}
	cout << "len=" << myarr.get_len() << endl;
	
	MyArray myarr2(myarr);
	for (int i=0;i<myarr2.get_len();i++) {
		cout << i << ":" << myarr2.get_data(i) << endl;
	}
	// 操作符重载
	cout << myarr[2] << endl;
	myarr[2] = 200;
	cout << myarr[2] << endl;
	
	return 0;
}