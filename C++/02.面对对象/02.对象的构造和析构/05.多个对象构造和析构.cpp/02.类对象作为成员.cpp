// 先调用对象成员的构造函数，在调用自身的构造函数，析构函数与构造相反
#include <iostream>
using namespace std;

class Game {
	string game_name;
public:
	Game() {
		cout << "game的普通构造函数调用" << endl;
	}
	Game(string name) {
		game_name = name;
		cout << "game的有参构造函数调用" << endl;
	}
	string get_name() {
		return game_name;
	}
	~Game() {
		cout << "game有析构函数调用" << endl;
	}
};

class Phone {
	string phone_name;
public:
	Phone() {
		cout << "phone的普通构造函数调用" << endl;
	}
	Phone(string name) {
		phone_name = name;
		cout << "phone的有参构造函数调用" << endl;
	}
	string get_name() {
		return phone_name;
	}
	~Phone() {
		cout << "phone有析构函数调用" << endl;
	}
};

class Person {
	string m_name;
	Phone m_phone;
	Game m_game;
public:
	Person() {
		cout << "person的普通构造函数调用" << endl;
	}
	Person(string name, string phone_name, string game_name):m_name(name), m_phone(phone_name), m_game(game_name) {
		cout << "person的有参构造函数调用" << endl;
	}
	void playGame() {
		cout << m_name << "拿着" << m_phone.get_name() << "玩着" << m_game.get_name() << endl;
	}
	~Person() {
		cout << "person的析构函数调用" << endl;
	}
};

int main(int argc, char *argv[]) {
	Person tom("tom", "苹果", "吃鸡");
	tom.playGame();
	return 0;
}