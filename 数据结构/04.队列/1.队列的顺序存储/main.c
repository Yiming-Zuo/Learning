#include "SeqQueue.h"

struct Person {
	char name[64];
	int age;
};

int main(int argc, char *argv[]) {
	struct Person class[5] = {
				{ "关羽", 18 },
				{ "张飞", 17 },
				{ "刘备", 20 },
				{ "孙尚香", 14 },
				{ "孙权", 21 }
			};
	SeqQueue myqueue = init_queue();
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