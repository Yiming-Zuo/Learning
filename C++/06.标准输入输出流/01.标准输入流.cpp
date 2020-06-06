#include <iostream>
using namespace std;
/*
cin.get() //一次只能读取一个字符
cin.get(一个参数) //读一个字符
cin.get(两个参数) //可以读字符串
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
*/
// cin.get()
void test01() {
	// as ，第一次获取a  ，第二次获取s，第三次获取换行，第四次等待输入
	char ch = cin.get();
	cout << "ch = " << ch << endl;
	ch = cin.get();
	// cin.get(ch)
	cout << "ch = " << ch << endl;
	ch = cin.get();
	cout << "ch = " << ch << endl;
	ch = cin.get();
	cout << "ch = " << ch << endl;
}
// cin.get()重载 获取字符串
void test02()
{
	char buf[1024] = "";
	cin.get(buf, sizeof(buf));//换行符遗留在缓冲区中
	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "换行符遗留在缓冲区中" << endl;
	}
	else
	{
		cout << "换行符未遗留在缓冲区中" << endl;
	}
	cout << "buf = " << buf << endl;
}

// cin.getline()获取字符串
void test03()
{
	char buf[1024] = "";
	//换行符不会遗留在缓冲区中，并且从缓冲区中扔掉
	cin.getline(buf, sizeof(buf));  // 最大字节数
	char ch = cin.get();
	if (ch == '\n')
	{
		cout << "换行符遗留在缓冲区中" << endl;
	}
	else
	{
		cout << "换行符未遗留在缓冲区中" << endl;
	}
	cout << "buf = " << buf << endl;
}

// cin.ignore()忽略
void test04()
{
	cin.ignore(3); //默认忽略1个缓冲区中的字符（包括换行符），可以填写忽略个数
	char ch = cin.get();
	cout << "ch = " << ch << endl;
}

// cin.peek() 偷窥
void test05()
{
	//查看缓冲区中第一个字符，并不取走
	char ch = cin.peek();
	cout << "ch = " << ch << endl;
	ch = cin.get();
	cout << "ch = " << ch << endl;
	ch = cin.get();
	cout << "ch = " << ch << endl;
}

// cin.putback() 放回
void test06()
{
	char ch = cin.get();
	cin.putback(ch); //将ch放回到缓冲区中,并且放回原位
	char buf[1024] = { 0 };
	cin.getline(buf, sizeof(buf));
	cout << "buf = " << buf << endl;
}

// 案例一：判断用户输入的是字符串还是数字
void test07() {
	cout << "请输入字符串或者数字:\n";
	char ch = cin.peek();
	if (ch > '0' & ch < '9') {
		int num;
		cin >> num;
		cout << "您输入的是数字:" << num << endl;
	} else {
		char buf[1024] = "";
		cin.getline(buf, sizeof(buf));
		cout << "您输入的是字符串:" << buf << endl;
	}
}

// 案例二：让用户输入1～10之间的数字，若输入有误重新输入
void test08() {
	while (true) {
		cout << "请输入1～10之间的数字\n";
		int num;
		cin >> num;
		if (num >= 1 & num <=10 ) {
			cout << "您输入的数字是:" << num << endl;;
			cout << cin.fail() << endl;  // 判断流操作是否失败
			break;
		}
		cin.clear();  // 清除错误状态
		cin.sync();  // 清空缓存区,如果用户输入的是字符，那么这个字符会一直待在缓冲区中造成无限循环
		cout << cin.fail() << endl;
		cout << "请重新输入";
	}
}

int main(int argc, char *argv[]) {
//	test01();
//	test02();
//	test03();
//	test04();
//	test05();
//	test06();
//	test07();
	test08();
	return 0;
}