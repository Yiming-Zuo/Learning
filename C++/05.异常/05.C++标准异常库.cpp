#include <iostream>
#include <stdexcept>  //标准异常头文件
using namespace std;


class Person
{
public:
	Person(int age)
	{
		if (age < 0 || age > 150)
		{
			throw out_of_range("年龄越界，必须在0~150之间");  // 有参构造，异常信息的描述

			//throw length_error("长度出错！");
		}
		this->m_Age = age;
	}

	int m_Age;
};


void test01()
{
	try
	{
		Person p1(1000);
	}
	catch (exception & e)  // 父类引用
	{
		cout << e.what() << endl;  // what()方法描述异常信息
	}

}


int main(int argc, char *argv[]) {
	test01();
}