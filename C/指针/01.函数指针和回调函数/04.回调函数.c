// 案例：自定函数：打印任意类型的变量
#include <stdio.h>

struct Person {
	char name[64];
	int age;
};

void print_int(void *p_data) {
	printf("%d\n", *(int *)p_data);
}

void print_float(void *p_data) {
	printf("%.2f\n", *(float *)p_data);
}

void print_Person(void *p_data) {
	struct Person *p = (struct Person *)p_data;
	printf("name:%s age:%d\n", p->name, p->age);
}
// 回调函数
void print(void *p_data, void(*p_func)(void *p_data)) {  // 函数指针做函数参数
	p_func(p_data);
}

int main(int argc, char *argv[]) {
	int data01 = 10;
	print(&data01, print_int);  // print_int(&data)
	
	float data02 = 2.22;
	print(&data02, print_float);  // print_float(&data)
	
	struct Person jerry = { "jerry", 18	};
	print(&jerry, print_Person);  // print_Person(&jerry)
	
	return 0;
}