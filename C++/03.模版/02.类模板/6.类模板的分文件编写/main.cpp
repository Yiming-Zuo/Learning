#include <iostream>
#include "Student.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	Student<int, string> tom(1, "tom");
	tom.show_student();
}