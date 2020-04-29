#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 加密
int codeFile(char *sourceFilePath, char *destFilePath) {
	srand(time(NULL));
	FILE *fp_read = fopen(sourceFilePath, "rb");
	FILE *fp_write = fopen(destFilePath, "wb");
	if (fp_read == NULL) {
		perror("fp_read_open");
		return -1;
	}
	if (fp_write == NULL) {
		perror("fp_write_open");
		return -1;
	}
	char word;
	while ((word=getc(fp_read)) != EOF) {
		short tmp = (short)word;
		printf("%#o\n", tmp);
		// 加密过程
		tmp = tmp << 4;
		printf("%#o\n", tmp);
//		tmp |= 0x8000;
//		tmp += random()%16;
		fprintf(fp_write, "%hd", tmp);  // 以char形式写入文件中
	}
	
	
	fclose(fp_read);
	fclose(fp_write);
	return 0;
}
// 解密
int decodeFile(char *sourceFilePath, char *destFilePath) {
	FILE *fp_read = fopen(sourceFilePath, "rb");
	FILE *fp_write = fopen(destFilePath, "wb");
	if (fp_read == NULL) {
		perror("fp_read_open");
		return -1;
	}
	if (fp_write == NULL) {
		perror("fp_write_open");
		return -1;
	}
	short tmp;
	printf("\n-------------\n");
	while (!feof(fp_read)) {
		fscanf(fp_read, "%hd", &tmp);  // 从文件中格式化出short
		// char word = (char)tmp;  // !!!!!!!!!!!!!!!!!!!!
		// 解密过程
		tmp = tmp >> 4;
		char word = (char)tmp;
		printf("%c", tmp);
		fputc(tmp, fp_write);  // 格式化写入char
	}
	
	fclose(fp_read);
	fclose(fp_write);
	return 0;
}
int main(int argc, char *argv[]) {
	codeFile("06.txt", "code.txt");
	decodeFile("code.txt", "decode.txt");
}