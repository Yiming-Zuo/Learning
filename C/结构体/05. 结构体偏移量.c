#include <stdio.h>
#include <stddef.h>

struct Teacher {
	char buf;
	int age;
};

// 结构体偏移量
void func01(void) {
	struct Teacher tom;
	struct Teacher *p = &tom;
	printf("%ld\n", (char *)&(p->age) - (char *)p);  // 将指针转换为char *
	printf("%lu\n", offsetof(struct Teacher, age));  // 成员age相对于结构体Teacher的偏移量
}
// 通过偏移量获取数据
void func02(void) {
	struct Teacher jerry = {'b', 13};
	struct Teacher *p = &jerry;
	printf("%d\n", *(int *)((char *)p+offsetof(struct Teacher, age)));
	printf("%d\n", *(int *)((int *)p + 1));
}

struct Teachers {
	char buf;
	int age;
	struct Teacher s;
};
// 嵌套结构体偏移量
void func03(void) {
	struct Teachers wang = {'a', 23, 'b', 13};
	struct Teachers *p = &wang;
	int offset1 = offsetof(struct Teachers, s);
	int offser2 = offsetof(struct Teacher, age);
	printf("%d\n", *(int *)((char *)p + offset1 +offser2));
	printf("%d\n", ((struct Teacher *)((char *)p + offset1))->age);
}

int main(int argc, char *argv[]) {
//	func01();
	func02();
	func03();
}