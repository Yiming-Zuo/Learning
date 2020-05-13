#include <stdio.h>

// fputs()
void func01(void) {
	FILE *fp = fopen("./02.txt", "w");
	if (fp == NULL) {
		perror("fopen");
		return;
	}
	char *arr[] = {
		"窗前明月光\n",
		"疑是地上霜\n",
		"举头望明月\n",
		"低头思故乡\n"
	};
//	printf("%lu\n", sizeof(arr)/sizeof(arr[0]));
	for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++) {
		fputs(arr[i], fp);
	}
	fclose(fp);
}
// fgets()
void func02(void) {
	FILE *fp = fopen("./02.txt", "r");
	if (fp == NULL) {
		perror("fopen");
		return;
	}
	char buf[32] = "";
	
#if 0
	while (!feof(fp)) {
		fgets(buf, sizeof(buf), fp);
		if (feof(fp)) {
			break;
		}
		printf("%s", buf);
	}
#endif

	while (fgets(buf, sizeof(buf), fp)) {  // 读到文件尾或出错返回NULL
											// 读到换行符，文件尾或者已经读了n-1个字符后，加上'\0'保存到str
		printf("%s", buf);
	}
	fclose(fp);
}
int main(int argc, char *argv[]) {
	func01();
	func02();
}