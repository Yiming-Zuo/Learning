#include <stdio.h>

#pragma pack (show)  // 查看对齐模数的值：8，以warning message的形式显示
//#pragma pack (1)  // 设置对齐模数为1

struct TYPE {
	char a;  // 0~3  // 0
	int b;  // 4~7  // 1～4
	char c;  // 8~11  // 5
	int d;  // 12~15  // 6～9
	double e;  // 16~23  // 10~17
};  // 24  // 18
// 结构体嵌套结构体
struct TYPE2 {
	char a;  // 1~7
	struct TYPE b;  // 8~31
	int c;  // 32~35
};  // 36+8=40


int main(int argc, char *argv[]) {
	printf("%lu\n", sizeof(struct TYPE2));  // %lu:32位无符号整数
}