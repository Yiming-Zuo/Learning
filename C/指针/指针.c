//
// Created by 左一鸣 on 2020/4/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 1 案例：从字符串中取出myname
void func01(void) {
    char buf[] = "123abcd$myname@000qwe";
    char buf1[32] = "";
    sscanf(buf, "%*[^$]$%[^@]", buf1);
    printf("%s\n", buf1);
}

// 2 二级指针做函数参数的输入特性
void print_pp(int **p, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d\n", *p[i]);
    }
}

// 在栈上开辟空间存放二级指针，指向堆区
int main01(void) {
    int *p[5] = {NULL};  // int *p[]: int **p

    for (int i = 0; i < 5; i++) {
        p[i] = (int *)malloc(sizeof(int *));
        *p[i] = i + 10;
    }
    // p[]定义可以， **定义不可以
    int len = sizeof(p) / sizeof(p[0]);  // 5
//    printf("%d\n", len);
    print_pp(p, len);

    for (int i = 0; i < len; i++) {
        if (p[i] != NULL) {
            free(p[i]);
            p[i] = NULL;
        }
    }
    return 0;
}

// 在堆区开辟空间存放二级指针，指向栈区
int main02(void) {
    int **p = (int **)malloc(sizeof(int *) * 5);  // p指向的是int *， 本身是int **
    int num[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        p[i] = num+i;  // *p+i = num+i
    }

//    int len = sizeof(p) / sizeof(p[0]);  // 1 == sizeof(p) == sizeof(p[0])
//    printf("%d\n", len);
    print_pp(p, 5);

    if (p != NULL) {
        free(p);
        p = NULL;
    }

    return 0;
}

// 3 二级指针做函数参数的输出特性
void my_allocate(int **p, int n){
    *p = (int *)malloc(sizeof(int) * n);
}

void func02(void) {
    int *p = NULL;
    my_allocate(&p, 1);
    *p = 100;
    printf("%d\n", *p);
    if (p != NULL) {
        free(p);
        p = NULL;
    }
}

// 案例：
// 获取文件行数
int get_lines(FILE *fp) {
    if (fp == NULL) {
        return -1;
    }
    int lines = 0;
    char buf[32] = "";
//    printf("%s", fgets(buf, sizeof(buf), fp));
//    fflush(stdout);
    while (fgets(buf, sizeof(buf), fp)) {
//        printf("%s", buf);
        lines += 1;
//        memset(buf, 0, sizeof(buf));  // 清空字符串
    }
    printf("[1]获取到文件共%d行数据\n", lines);
    // 文件流指针复位
    fseek(fp, 0, SEEK_SET);
    return lines;
}
// 在堆区为获取到的每一行字符串分配空间
int allocate_lines(char **p, FILE *fp, int lines) {
    if ( p == NULL || fp == NULL || lines <= 0) {
        return -1;
    }
    char buf[32] = "";
    int i = 0;
    while (fgets(buf, sizeof(buf), fp)) {
        int len = strlen(buf) + 1;  // 获取的字符串应该分配的字节数
        buf[strlen(buf)-1] = '\0';  // 去除回车
        char *p_line = (char *)malloc(sizeof(char) * len);  // 申请空间
        strcpy(p_line, buf);   // 将字符串拷贝到新空间
        p[i++] = p_line;
        memset(buf, 0, sizeof(buf));  // 清空字符串
    }
    printf("[2]数据读取到堆区成功\n");
    // 文件流指针复位
    fseek(fp, 0, SEEK_SET);
    return 0;
}
// 打印堆区数据
int show_lines(char **p, int lines) {
    if ( p == NULL || lines <= 0) {
        return -1;
    }
    printf("[3]开始打印数据\n");
    for (int i = 0; i < lines; i++) {
        printf("%d:%s\n", i+1, p[i]);
    }
    return 0;
}
// 释放堆区数据
int free_all(char **p, int lines) {
    if ( p == NULL || lines <= 0) {
        return -1;
    }
    printf("[4]开始释放堆区空间\n");
    for (int i = 0; i < lines; i++) {
        printf("%d:%p空间释放\n", i+1, p[i]);
        free(p[i]);
        p[i] = NULL;
    }
    printf("p:%p空间释放\n", p);
    free(p);
    p = NULL;
    return 0;
}

void func03(void) {
    // 打开文件
    FILE *fp = NULL;
    fp = fopen("./answer.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        return;
    }
    // 获取文件行数
    int lines = get_lines(fp);
//    printf("%d\n", lines);
    // 在堆区申请一个二级指针存放一级指针数组
    char **p = (char **)malloc(sizeof(int *) * lines);
    // 在堆区为获取到的每一行字符串分配空间
    allocate_lines(p,fp, lines);
    // 打印堆区数据
    show_lines(p,lines);
    // 释放堆区数据
    free_all(p, lines);
    // 关闭文件
    fclose(fp);
}

int main(int argc, char *argv[]) {
    int a = 10;
    return 0;
}


