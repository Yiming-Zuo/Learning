//
// Created by 左一鸣 on 2020/4/17.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>


typedef struct PEOPLE{
    char name[16];
    int age;
    char grade;
} PEOPLE;

// fwrite()
void func01(void) {
    PEOPLE class1[5] = { {"小红", 12, 'A'},  // 结构体数组
                         {"小白", 13, 'B'},
                         {"小黑", 14, 'C'},
                         {"小蓝", 15, 'D'},
                         {"小黄", 16, 'E'} };
    FILE *fp = fopen("class.txt", "w");
    if (!fp) {
        perror("fopen");
        return;
    }
    fwrite(class1, sizeof(PEOPLE), 5, fp);  // 结构体指针，块大小，块数，文件指针
    fclose(fp);
}

// fread()
void func02(void) {
    FILE *fp = fopen("class.txt", "r");
    if (!fp) {
        perror("fopen");
        return;
    }
    PEOPLE class1[16];
    memset(class1, 0, sizeof(class1));

    int n = 0;
    n = fread(class1, sizeof(PEOPLE), 16, fp);  // 读到文件结尾结束，返回成功读读取到内存的块数

    for (int i = 0; i < n; i++) {
        printf("%d:%s %d %c\n", i+1, class1[i].name, class1[i].age, class1[i].grade);
    }

    fclose(fp);
}

// fscanf() fprintf()
void func03(void) {
    FILE *fp = fopen("format.txt", "r");
    if (!fp) {
        perror("fopen");
        return;
    }

    char name[16] = "";
    int age = 0;
    char grade = 0;
    fprintf(fp, "%s %d %c\n", "小红", 16, 'A');  // 写文件 fprintf到文件中
    fscanf(fp, "%s %d %c\n", name, &age, &grade);  // 读文件 从文件中fscanf
    printf("%s %d %c\n", name, age, grade);

    fclose(fp);

}

// 案例：读取文件对其中数值排序保存到新文件中
// 生成文件
void func04(int n) {
    srand(time(NULL));
    FILE *fp = fopen("number.txt", "w");
    if (!fp) {
        perror("fopen");
        return;
    }

    int num = 0;
    for (int i = 0; i < n; i++) {
        num = rand() % 1000 + 1;
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
}
void mySort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}
// 排序
void func05() {
    FILE *fp_p = fopen("number.txt", "r");
    FILE *fp_a = fopen("answer_num.txt", "w");
    if (!fp_p || !fp_a) {
        perror("fopen");
        return;
    }

    int arr[100] = {0};
    for (int i = 0; i < 100; i++) {
        fscanf(fp_p, "%d\n", arr + i);
    }

    mySort(arr, 100);
    for (int j = 0; j < 100; j++) {
        fprintf(fp_a, "%d\n", arr[j]);
    }

    fclose(fp_p);
    fclose(fp_a);
}

// rewind() fseek() ftell()
void func06(void) {
    FILE *fp = fopen("random.txt", "w+");
    if (!fp) {
        perror("fopen");
        return;
    }

    fputs("hello world!", fp);
    long loc = 0;
    loc = ftell(fp);  // 获取文件流指针位置（距首部字节数）：尾
    printf("%ld\n", loc);
//    rewind(fp);  // 文件流指针复位
    fseek(fp, -2, SEEK_CUR);  // 设置文件流指针位置
    loc = ftell(fp);
    printf("%ld\n", loc);
    char buf[32] = "";
    fgets(buf, sizeof(buf), fp);
    printf("%s\n", buf);

    fclose(fp);
}

// 案例：测量文件的长度，将文件内容保存在堆区中读取
void func07(void) {
    FILE *fp = fopen("format.txt", "r");
    if (!fp) {
        perror("fopen");
        return;
    }
    // 获取文件流指针偏移量
    fseek(fp, 0, SEEK_END);
    int len = (int)ftell(fp);
    // 从堆区申请len+1个字节
    char *p = (char *)malloc(len+1);  // `\0`不算
    memset(p, 0, len+1);
    // 复位文件流指针
    rewind(fp);
    // 将数据fread入堆区
    fread(p, len, 1, fp);
    // 从堆区中printf数据
    printf("%s", p);
    // 释放堆区空间
    if (p != NULL) {
        free(p);
        p = NULL;
    }
}

// 满刷新
// 缓存区满之后刷新到屏幕
void func08(void) {
    for (int i = 0; i < 100000; i++) {
        printf("hello world!");
        usleep(1000 * 10);
    }
}

// 关闭刷新
void func09(void) {
    printf("hello world!");
//    while (1);  // 死循环，无法关闭刷新
    return;
}

// 行刷新
void func10(void) {
    printf("hello world!\n");  // 行刷新
    while (1);  // 死循环，无法关闭刷新
    return;
}

// 强制刷新
void func11(void) {
    printf("hello world!");
    fflush(stdout);  // 标准输出(屏幕)文件指针
    while (1);  // 死循环，无法关闭刷新
    return;
}

int main(int argc, char *argv[]) {
    // stat()
//    if (argc == 2) {
//        struct stat stat_cur = {0};
//        stat(argv[1], &stat_cur);
//        printf("%d\n", stat_cur.st_mode);
//    }
    func08();
    return 0;
}
