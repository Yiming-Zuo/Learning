// throw(SonException())  --> catch(BaseException &e)
// 父类引用接子类对象
#include <iostream>
using namespace std;

//异常的基类
class BaseException
{
public:
	virtual void printError() = 0;
};

//空指针异常
class NULLPointerException:public BaseException
{
public:
	virtual void printError()
	{
		cout << "空指针异常" << endl;
	}
};

//越界异常
class OutOfRangeException :public BaseException
{
public:
	virtual void printError()
	{
		cout << "越界异常" << endl;
	}
};


void doWork()
{
	//throw NULLPointerException();
	throw OutOfRangeException();  // 父类引用接子类对象
}

void test01()
{
	try
	{
		doWork();
	}
	catch (BaseException &e)
	{
		e.printError();
	}

}


int main(int argc, char *argv[]) {
	test01();
	return 0;
}