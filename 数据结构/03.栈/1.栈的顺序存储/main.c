#include "sstack.h"

struct Student {
	char name[64];
	int age;
};

void print_struct(void *data) {
	if (NULL == data) {
		return;
	}
	struct Student *p = data;
	printf("姓名：%s 年龄：%d\n", p->name, p->age);
}

int main(int argc, char *argv[]) {
	sstack mystack = init_sstack();
	struct Student class[5] = {
		{ "关羽", 18 },
		{ "赵云", 19 },
		{ "孙悟空", 1000 },
		{ "廉颇", 88 },
		{ "张飞", 13 }
	};
	push_sstack(mystack, &class[0]);
	push_sstack(mystack, &class[1]);
	push_sstack(mystack, &class[2]);
	push_sstack(mystack, &class[3]);
	push_sstack(mystack, &class[4]);
	
	printf("大小：%d\n", sizeof_sstack(mystack));
	while (!isEmpety(mystack)) {
		top_sstack(mystack, print_struct);
		pop_sstack(mystack);
	}
	printf("大小：%d\n", sizeof_sstack(mystack));
	destory_sstack(mystack);

	return 0;
}