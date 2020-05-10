#include <stdio.h>
#include <string.h>
#include "sstack.h"

int isleft(char ch) {
	return '('==ch;
}
int isright(char ch) {
	return ')'==ch;
}
// 打印错误信息
void print_err(char *str, const char *msg, char* pos) {
	printf("%s\n", msg);
	printf("%s\n", str);
	int num = pos - str;  // 相差的字符数
	for (int i=0; i<num; i++) {
		printf(" ");
	}
	printf("A\n");
}

int isyes(char *str) {
	sstack *mystack = init_sstack();
	int len = strlen(str);
#if 1
	char *p = str;
	while (*p != '\0') {
		if (isleft(*p)) {
			push_sstack(mystack, p);
		}
		if (isright(*p)) {
			if (isEmpety(mystack)) {
				print_err(str, "错误信息：缺少对应的'('", p);
				break;  // 一旦出错，立即退出
			}
			pop_sstack(mystack);
		}
		p++;
	}
#endif
#if 0
	for (int i=0;i<len;i++) {
		if (isleft(str[i])) {
			push_sstack(mystack, &str[i]);
		}
		if (isright(str[i])){
			if (isEmpety(mystack)) {
				return -1;  // )
			}
			pop_sstack(mystack);
		} 
	}
#endif
	if (!isEmpety(mystack)) {
		while (!isEmpety(mystack)) {
			print_err(str, "错误信息：缺少')'", top_sstack(mystack));  // 多余的(在栈顶
			pop_sstack(mystack);
		}
	}
		destory_sstack(mystack);
	return 0;
}

int main(int argc, char *argv[]) {
	char *str = "h)ello,w)or(ld)!";
	isyes(str);
	return 0;
}