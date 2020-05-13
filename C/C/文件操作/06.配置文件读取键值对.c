#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ConfigInfo {
	char key[64];
	char value[64];
};

// 1. 获取文件有效行数
int get_lines(const char *filepath) {
	FILE *fp = fopen(filepath, "r");
	if (fp == NULL) {
		perror("fopen");
		return -1;
	}
	char buf[128] = "";
	int num = 0;
	while (!feof(fp)) {
		fgets(buf, sizeof(buf), fp);
//		printf("%s", buf);
		if (strchr(buf, ':')) {
//			printf("%s", buf);
			num++;
		}
	}
	fclose(fp);
//	printf("%d", num);
	return num;
}
// 2. 解析文件,放入数组中
struct ConfigInfo *parseFile(const char *filepath, int lines) {
	FILE *fp = fopen(filepath, "r");
	if (fp == NULL) {
		perror("fopen");
		return NULL;
	}
	struct ConfigInfo *p = malloc(sizeof(struct ConfigInfo)*lines);
	char buf[128] = "";
	int i = 0;
	while (!feof(fp)) {
		fgets(buf, sizeof(buf), fp);
		if (strchr(buf, ':')) {
			memset(p[i].key, 0, sizeof(p[i].key));
			memset(p[i].value, 0, sizeof(p[i].value));
			
			strcpy(p[i].key, strtok(buf, ":"));
			strcpy(p[i].value, strtok(NULL, ":"));	
			p[i].value[strlen(p[i].value)-1] = 0;  // 去除回车
			i++;
		}
		memset(buf, 0, sizeof(buf));
	}
	fclose(fp);
	
	return p;
}
// 3. 根据key访问相应的value
void get_value(const char *key, struct ConfigInfo *p, int lines) {
	for (int i=0;i<lines;i++) {
		if (strcmp(key, p[i].key) == 0) {
			printf("%s\n", p[i].value);
		}
	}
}

void free_all(struct ConfigInfo *p) {
	if (p != NULL) {
		free(p);
		p = NULL;
	}
}


int main(int argc, char *argv[]) {
	const char *filepath = "./06.txt";
	int lines = get_lines(filepath);
//	printf("%d\n", lines);
	struct ConfigInfo *p = parseFile(filepath, lines);
	get_value("heroAtk", p, lines);
	get_value("heroInfo", p, lines);
	free_all(p);
	p = NULL;
	
	return 0;
}