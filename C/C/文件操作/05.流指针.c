#include <stdio.h>

struct Hero {
	char *name;
	int age;
};

void file_write(void) {
	FILE *fp = fopen("./05.txt", "wb");
	if (fp == NULL) {
			perror("fopen");
			return;
		}
	struct Hero heros[4] = {
		{ "1", 19 },
		{ "2", 20 },
		{ "3", 23 },
		{ "4", 1000 },
	};
	fwrite(&heros, sizeof(struct Hero), 4, fp);
	fclose(fp);
}

void file_read(void) {
	FILE *fp = fopen("./05.txt", "rb");
	if (!fp) {
		perror("fopen");
		return;
	}
	struct Hero hero;
//	fseek(fp, sizeof(struct Hero)*2, SEEK_SET);
	fseek(fp, -(long)(sizeof(struct Hero)*2), SEEK_END);  // sizeof()返回的是无符号整型
	fread(&hero, sizeof(struct Hero), 1, fp);
	printf("%s %d", hero.name, hero.age);
	fclose(fp);
}

int main(int argc, char *argv[]) {
	file_write();
	file_read();
	return 0;
}