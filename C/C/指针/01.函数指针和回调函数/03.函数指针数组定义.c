#include <stdio.h>

void func01() {
	printf("这里是func01。\n");
}

void func02() {
	printf("这里是func02。\n");
}
void func03() {
	printf("这里是func03。\n");
}

int main(int argc, char *argv[]) {
	void(*p_func[3])() = {func01, func02, func03};  // 函数指针数组定义
#if 0
	void(*p_func[3])();
	p_func[0] = func01;
	p_func[1] = func02;
	p_func[2] = func03;
#endif
	int len = sizeof(p_func)/sizeof(p_func[0]);
	for(int i=0; i<len; i++) {
		p_func[i]();
	}
	return 0;
}
