#include <stdio.h>
#include <string.h>

// 打印
int reverse1(char *str) {
	if (str == NULL) {
		return -1;
	}
	if (*str == 0) {
		return 0;
	}
	// printf("%c", *str);  // 正序
	reverse1(str+1);
	printf("%c", *str);
	return 0;
}
// 保存
int reverse2(char *str, char *dst) {
	if (str == NULL || dst == NULL) {
		return -1;
	}
	if (*str == 0) {
		return 0;
	}
	reverse2(str+1, dst);
//	printf("%c\n", *str);
	strncat(dst, str, 1);  // 不断dst里拼接
	return 0;
}

int main(int argc, char *argv[]) {
	char str[64] = "hello";
	
//	reverse1(str)
	
	char dst[64] = "";
	reverse2(str, dst);
	printf("%s\n", dst);
	
	return 0;
}