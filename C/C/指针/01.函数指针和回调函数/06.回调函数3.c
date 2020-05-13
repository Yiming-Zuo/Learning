// 案例：自定函数，查找结构体数组中成员，存在返回1，不存在返回0。
#include <stdio.h>
#include <string.h>

struct Person {
	char name[64];
	int age;
};

int compare_all(void *p_data, void *p_src) {
	struct Person *p1 = p_data;
	struct Person *p2 = p_src;
	if (strcmp(p1->name, p2->name)==0 && p1->age==p2->age) {
		return 1;
	} else {
		return 0;
	}
}

int compare_name(void *p_data, void *p_src) {
	struct Person *p1 = p_data;
	char *p2 = p_src;
	if (strcmp(p1->name, p2)==0) {
		return 1;
	} else {
		return 0;
	}
}

int find_arr(void *p_struct, int len, int size, void *p_src, int(*p_func)(void *, void *)) {
	for (int i=0; i<len; i++) {
		void *p = p_struct + i*size;
		if (p_func(p, p_src)) {
			return 1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	struct Person class[5] = {
		{ "tom", 16 },
		{ "jerry", 17 },
		{ "jack", 18 },
		{ "tony", 19 },
		{ "pony", 20 }
	};
	struct Person person = { "tony", 19 };
//	int ret = find_arr(class, 5, sizeof(struct Person), &person, compare_all);  // 查找成员
	int ret = find_arr(class, 5, sizeof(struct Person), "jack", compare_name);  // 查找成员姓名
	if (ret) {
		printf("存在\n");
	} else {
		printf("不存在\n");
	}
	return 0;
}