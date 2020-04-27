#include <stdio.h>
#include <string.h>

// fputc()
void func01() {
	FILE *fp = fopen("./01.txt", "w");
	if (fp == NULL) {
		perror("fopen");  // errno宏:错误代码，每个错误代码对应相应的错误
		return;
	}
	char buf[] = "hello world\n";
//	printf("%lu\n", strlen(buf));
	for (int i=0;i<strlen(buf);i++) {  // buf[i] != 0
		fputc(buf[i], fp);
	}
	fclose(fp);
}
// fgetc()
void func02() {
	FILE *fp = fopen("./01.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}
	char word = 0;
	while ((word=fgetc(fp)) != EOF) {
		printf("%c", word);
	}
	fclose(fp);
}


int main(int argc, char *argv[]) {
	func01();
	func02();
}