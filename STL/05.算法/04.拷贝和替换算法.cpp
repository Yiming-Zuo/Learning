#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// 1 copy算法 将容器内指定范围的元素拷贝到另一容器中
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++) {
		v.push_back(i);
	}

	vector<int>v2;
	v2.resize(v.size());
	copy(v.begin(), v.end(), v2.begin());

	//for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });
	//cout << endl;

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));  // 利用流输出迭代器遍历容器中的元素
	cout << endl;
}


// 2 replace算法 将容器内指定范围的旧元素修改为新元素
// replace_if算法 将容器内指定范围满足条件的元素替换为新元素
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	//将容器中的3  替换为 3000
	replace(v.begin(), v.end(), 3, 3000);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//将所有大于3的值 替换为30000
	replace_if(v.begin(), v.end(), bind2nd(greater<int>(), 3), 30000);
	// // 0 1 2 30000  30000 ....
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

// 3 swap算法 互换两个容器的元素
void test03() {
	vector<int>v1;
	vector<int>v2;
	for (int i = 0; i < 10;i++) {
		v1.push_back(i);
		v2.push_back(i+10);
	}

	cout << "交换前的结果为：" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	swap(v1, v2);
	
	cout << "交换后的结果为：" << endl;
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}


int main() {
//	test01();
//	test02();
	test03();
	return 0;
}