#include <iostream>
#include <fstream>
using namespace std;

void test()
{
	ifstream ifs;
	ifs.open("./test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}

	//第一种方式
	char buf[1024] = {0};

	while (ifs >> buf)
	{
		cout << buf << endl;
	}

	//第二种方式
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf,sizeof(buf)))
	//{
	//	cout << buf << endl;
	//}


	//第三种方式
	//string buf;
	//while (getline(ifs,buf))
	//{
	//	cout << buf << endl;
	//}

	//第四种方式  不推荐
//	char c;
//	while ( (c = ifs.get() ) != EOF)
//	{
//		cout << c;
//	}
//
//	ifs.close();
}

int main(int argc, char *argv[]) {
	test();
	return 0;
}