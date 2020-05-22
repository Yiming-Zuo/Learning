// 只有一个对象，共享这个对象：静态成员指针变量
#include <iostream>
using namespace std;

class ChairMan {
// 私有化构造函数:防止创建多个对象
private:
	ChairMan() {}
	ChairMan(const ChairMan &) {}
public:
	// 获取单例指针的接口:可以通过类型访问
	static ChairMan *getInstance() {
		return pChairMan;
	}
private:
	// 对象指针私有化
	static ChairMan *pChairMan;  // 单例
};
// 类外初始化
ChairMan *ChairMan::pChairMan = new ChairMan;

int main(int argc, char *argv[]) {
	ChairMan *p = ChairMan::getInstance();  // 访问单例对象
	return 0;
}