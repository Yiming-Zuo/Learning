#include "lstack.h"

struct Student {
	struct LinkNode Node;
	char name[64];
	int age;
};

int main(int argc, char *argv[]) {
	Linkstack mystack = init_lstack();
	struct Student class[5] = {
		{ NULL, "关羽", 18 },
		{ NULL, "赵云", 19 },
		{ NULL, "孙悟空", 1000 },
		{ NULL, "廉颇", 88 },
		{ NULL, "张飞", 13 }
	};
	push_lstack(mystack, &class[0]);
	push_lstack(mystack, &class[1]);
	push_lstack(mystack, &class[2]);
	push_lstack(mystack, &class[3]);
	push_lstack(mystack, &class[4]);
	
	printf("栈当前大小：%d\n", sizeof_lstack(mystack));
	while(!isEmpety(mystack)) {
		void *data = top_lstack(mystack);
		struct Student *p_student = data;  // 将结点结构体转换为用户书记结构体
		printf("姓名：%s 年龄：%d\n", p_student->name, p_student->age);
		pop_lstack(mystack);
	}
	printf("栈当前大小：%d\n", sizeof_lstack(mystack));
	destory_lstack(mystack);
	
	return 0;
}