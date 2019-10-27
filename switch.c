// 根据成绩给出等级

#include <stdio.h>

int main(void) {
    int grade;
    scanf("%d", &grade);
    grade /= 10;

    switch(grade) {
        case 10:
        case 9:printf("A");
            break;
        case 8:printf("B");
            break;
        case 7:printf("C");
            break;
        case 6:printf("D");
            break;
        default:printf("F");
    }

    return 0;
}