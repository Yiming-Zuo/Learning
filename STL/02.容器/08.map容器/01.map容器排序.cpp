#include <iostream>
#include <map>
#include <string>
using namespace std;


void print_map(map<string, int, greater<string> >my_map) {
	for (map< string, int, greater<string> >::iterator p=my_map.begin();p!=my_map.end();p++) {
		cout << (*p).first << ":" << (*p).second << endl;
	}
}

void test() {
	map<string, int, greater<string> >stu_map;
	stu_map.insert(pair<string, int>("tom", 18));
	stu_map.insert(make_pair("jerry", 19));
	stu_map.insert(map<string, int, greater<string> >::value_type("jack", 20));
	stu_map["mary"] = 21;
	print_map(stu_map);
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}