// 求平均数

#include <stdio.h>

int main(void) {
    int num, sum, count;

    sum = 0;
    count = 0;

    scanf("%d", &num);
    while (num != -1) {
        sum += num;
        printf("%d\n", sum);
        count += 1;
        scanf("%d", &num);
    }
    printf("%f\n", 1.0*sum/count);
    printf("end");

    return 0;
}