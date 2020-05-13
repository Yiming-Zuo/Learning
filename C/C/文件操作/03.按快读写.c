#include <stdio.h>

struct HERO {
	char *name;
	int age;
};

// fwrite()
void func01(void) {
	struct HERO arr[] = {
		{"亚瑟", 18},
		{"妲己", 20},
		{"兰陵王", 13},
		{"武则天", 68},
		{"孙悟空", 1778}
	};
	int n = sizeof(arr)/sizeof(arr[0]);
//	printf("%d", n);
	
	FILE *fp = fopen("./03.txt", "wb");
	if (fp == NULL) {
		perror("fopen");
		return;
	}
	fwrite(arr, sizeof(struct HERO), n, fp);
	fclose(fp);
}
// fread()
void func02(void) {
	struct HERO hero;
	FILE *fp = fopen("./03.txt", "rb");
	if (fp == NULL) {
		perror("fopen");
		return;
	}
	fread(&hero, sizeof(struct HERO), 1, fp);
	printf("%s %d", hero.name, hero.age);
	fclose(fp);
}


int main(int argc, char *argv[]) {
	func01();
	func02();
}