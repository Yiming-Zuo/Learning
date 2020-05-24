#include <iostream>
using namespace std;
class GoodGay;  // 类声明
class Building {
	friend void visit_bedroom(Building &build);  // 全局函数做友元
	friend class GoodGay;  // 类做友元
	friend void GoodGay::visit();  // 类的成员函数做友元
public:
	Building() {
		bedroom = "bedroom";
		sittingroom = "sittingroom";
	}
	string sittingroom;
private:
	string bedroom;
};

class GoodGay {
public:
	GoodGay() {
		room = new Building();
	}
	void visit() {
		cout << room->bedroom << endl;
	}
	
	Building *room;	
};




void visit_bedroom(Building &build) {
	cout << build.bedroom << endl;
}

int main(int argc, char *argv[]) {
	Building build;
	visit_bedroom(build);
	
	GoodGay gg;
	gg.visit();
	return 0;
}