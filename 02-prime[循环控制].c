// 判断一个数是否是素数（大于1且只有1和自身两个因数的自然数）

#include <stdio.h>

int main(void)
{
    int n, i;

    scanf("%d", &n);

//    int isPrime = 1; // 初始化n是素数
    for (i=2;i<n;i++) {
        if (n % i == 0){
//            isPrime = 0;
            break;
        }
    }

//    if (isPrime == 1) {
//        printf("Y");
//    } else {
//        printf("N");
//    }

    if (i == n) {
        printf("Y"); // 如果循环没有被break判断n是质数
    } else {
        printf("N");
    }

    return 0;
}