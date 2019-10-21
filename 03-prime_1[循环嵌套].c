// 列出前50个素数

#include <stdio.h>

int main(void)
{
    int n, i, cnt;
    cnt = 0; // 初始化素数个数是0
    n = 2;

//    for (n=2; cnt<50 ; n++)  // 1. for循环
    while (cnt < 50) {  // 2. while循环
        int isPrime = 1; // 初始化n是素数
        for (i = 2; i < n; i++) {
            if (n % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime == 1) {
            printf("%d ", n);
            cnt++;
        }

        n++;
    }
    printf("\n");

    return 0;
}
