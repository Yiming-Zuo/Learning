// 案例2：自定函数，打印任意类型的数组
#include <stdio.h>

struct Person {
	char name[64];
	int age;
};
// 回调函数
void print_int(void *p_data) {
	int *p = p_data;
	printf("%d ", *p);
}

void print_float(void *p_data) {
	float *p = p_data;
	printf("%.2f ", *p);
}

void print_Person(void *p_data) {
	struct Person *p = p_data;
	printf("name:%s age:%d\n", p->name, p->age);
}

void print_arr(void *p_arr, int len, int size, void(*p_func)(void *p_data)) {
	for (int i=0; i<len; i++) {
		void *p = p_arr + i * size;  // 每一个数组元素的首地址
		p_func(p);  // 调用函数指针打印不同类型的变量
	}
	printf("\n");
	
}

int main(int argc, char *argv[]) {
	int arr_int[5] = {10, 20, 30, 40, 50};
	print_arr(arr_int, 5, sizeof(int), print_int);
	
	float arr_float[5] = {11.11, 22.22, 33.33, 44.44, 55.55};
	print_arr(arr_float, 5, sizeof(float), print_float);
	
	struct Person class[5] = {
		{ "tom", 16 },
		{ "jerry", 17 },
		{ "jack", 18 },
		{ "tony", 19 },
		{ "pony", 20 }
	};
	print_arr(class, 5, sizeof(struct Person), print_Person);
}