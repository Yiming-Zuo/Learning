#include <stdio.h>

// sprintf()
void file_write(void) {
	FILE *fp = fopen("./04.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}
	fprintf(fp, "hello world %d", 1111111);  // sprintf()
	fclose(fp);
}

// sscanf()
void file_read(void) {
	FILE *fp = fopen("./04.txt", "r");
	if (!fp) {
		perror("fopen");
		return;
	}
	char buf[32] = "";
	while (!feof(fp)) {
		fscanf(fp, "%s", buf);  // %s以空格为分割单位
		printf("%s\n", buf);
	}
	fclose(fp);
}

int main(int argc, char *argv[]) {
	file_write();
	file_read();
}