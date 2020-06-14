#include<iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 1 merge() 两个容器元素合并，并存储到另一容器中
// 两个容器必须是有序的,而且必须同序
void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10;i++) {
		v1.push_back(i);
		v2.push_back(i+1);
	}

	vector<int>vTarget; //目标容器
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	// [](){} 匿名函数  lambda表达式
	for_each(vTarget.begin(), vTarget.end(), [](int val){cout << val << " ";});
	cout << endl;
}

// 2 sort() 排序算法
void test02()
{
	vector<int>v1;
	
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	//利用sort降序
	sort(v1.begin(), v1.end(), greater<int>());

	for_each(v1.begin(), v1.end(), [](int val){ cout << val << " "; });
	cout << endl;
}

// 3 random_shuffle算法 对指定范围内的元素随机调整次序
void test03()
{
	vector<int>v1;

	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	
	random_shuffle(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val){ cout << val << " "; });
	cout << endl;
}


// 4 reverse算法 反转指定范围的元素
void test04()
{
	vector<int>v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	cout << "反转前遍历结果： " << endl;
	for_each(v1.begin(), v1.end(), [](int val){ cout << val << " "; });
	cout << endl;

	reverse(v1.begin(), v1.end());  // 反转
	
	cout << "反转后遍历结果： " << endl;
	for_each(v1.begin(), v1.end(), [](int val){ cout << val << " "; });
	cout << endl;

}

int main(int argc, char *argv[]) {
//	test01();
//	test02();
//	test03();
	test04();
	return 0;
}