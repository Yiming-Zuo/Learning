#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// 2.1 fopen()
void func01(void) {
    FILE *f = NULL;  // 定义文件指针(FILE结构体指针)
    f = fopen("./a.txt", "r");  // 返回文件信息(结构体)首元素地址
    if (f == NULL) {  // 必须判断文件是否成功打开
        perror("fopen");  // 字符串写函数名称判断哪个函数出错
        return;
    }

    char buf[] = "hello world!";

    for (int i = 0; buf[i] != 0; i++) {
        fputc(buf[i], f);
    }

    while (!feof(f)) {
        char ch = 0;
        ch = fgetc(f);
//        if (ch == EOF) {  // #define EOF -1(文本文件0～255)
//            break;
//        }

//        if (feof(f)) {  // 到文件末尾返回非零值
//            break;
//        }
        printf("%c", ch);
    }

    fclose(f);  // 保存文件信息(内存缓冲区的数据写入文件中)，释放空间(指针和缓存区)
}

//案例
void func02(char *filename) {
    FILE *fp = NULL;
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    while(1) {
        char buf[128] = "";
        fgets(buf, sizeof(buf), stdin);
        if (!strncmp(buf, ":quit", sizeof(":quit")-1)) {
            break;
        }
        for (int i = 0; buf[i] != 0; i++) {
            fputc(buf[i], fp);

        }
    }

    fclose(fp);
}

// fgets fputs
void func03(void) {
    char *buf[] = {"shabi\n", "xixi\n", "jinglei"};  // 字符串指针数组
    FILE *p = NULL;
    p = fopen("c.txt", "r");
    if (p == NULL) {
        perror("fopen");
        return;
    }

    for (int i = 0; i < sizeof(buf)/ sizeof(buf[0]); i++) {
        fputs(buf[i], p);
    }

    char str[128] = "";
    while (fgets(str, sizeof(str), p)) {  // 读到文件尾或出错返回NULL
                                          // 读到换行符，文件尾或者已经读了n-1个字符后，加上'\0'保存到str
        printf("%s", str);
    }

    fclose(p);
}

// 案例：四则运算之出题存储到文件
void func04(void) {
    srand(time(NULL));
    int num1 = 0, num2 = 0;
    char arr[] = "+-*/";
    char cmd = 0;

    FILE *fp = NULL;
    fp = fopen("test.txt", "w");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    int n = 50;
    for (int i = 0; i < n; i++) {
        num1 = rand() % 100 + 1;  // 0~100
        num2 = rand() % 100 + 1;  // 0~100
        cmd = arr[rand() % 4];  // 0~3

        char msg[128] = "";
        sprintf(msg, "%d%c%d=\n", num1, cmd, num2);
        fputs(msg, fp);
    }

    fclose(fp);
}

// 案例：四则运算之解题存储到文件
void func05(void) {
    FILE *fp1 = fopen("test.txt", "r");
    FILE *fp2 = fopen("answer.txt", "w");
    if (!fp1 || !fp2) {
        perror("fopen");
    }

    char str[128] = "";
    while (fgets(str, sizeof(str), fp1)) {  // 读到文件尾或出错返回NULL
        int num1 = 0, num2 = 0;
        char cmd = 0;
        sscanf(str,"%d%c%d=", &num1, &cmd, &num2);
        int result = 0;
        switch (cmd) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                result = num1 / num2;
                break;
            default:
                break;
        }

        char answer[128] = "";
        sprintf(answer, "%d%c%d=%d\n", num1, cmd, num2, result);
        fputs(answer, fp2);
    }

    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[]) {
    func05();
    return 0;
}

