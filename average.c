// 求平均数和大于平均数的值

#include <stdio.h>

int main(void) {
    int num, sum, count;

    sum = 0;
    count = 0;
    int a[100];

    scanf("%d", &num);
    while (num != -1) {
        a[count] = num;
        sum += num;
//        printf("%d\n", sum);
        count++;
        scanf("%d", &num);
    }
    printf("%f\n", 1.0*sum/count);

    for (int i = 0; i < count ; i++) {
        if (a[i] > 1.0*sum/count) {
            printf("%d\n", a[i]);
        }
    }
    printf("end");

    return 0;
}