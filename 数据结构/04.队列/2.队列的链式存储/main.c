#include "LQueue.h"

struct Person {
	void *p;  // 4个字节
	char name[64];
	int age;
};

int main(int argc, char *argv[]) {
	struct Person class[5] = {
				{ NULL, "关羽", 18 },
				{ NULL, "张飞", 17 },
				{ NULL, "刘备", 20 },
				{ NULL, "孙尚香", 14 },
				{ NULL, "孙权", 21 }
			};
	LinkQueue myqueue = init_queue();
	push_queue(myqueue, &class[0]);
	push_queue(myqueue, &class[1]);
	push_queue(myqueue, &class[2]);
	push_queue(myqueue, &class[3]);
	push_queue(myqueue, &class[4]);
	while (!isEmpety_queue(myqueue)) {
		struct Person *p = front_queue(myqueue);
		printf("%s %d\n", p->name, p->age);
		pop_queue(myqueue);
	}
	destory_queue(myqueue);
	return 0;
}