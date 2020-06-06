---
title: cpp_05.友元
date: 2020-05-18
categories: Cpp
---

* 可以访问到类对象的私有成员
    * 类做友元
    * 全局函数做友元
    * 类的成员函数做友元

```cpp
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
	
	Building *room;  // 对象指针
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
```
