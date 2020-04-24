// 构建n以内（不含）的素数表

#include <stdio.h>

int main(void) {
    // 初始化n
    const int n = 100;
    const int number = 1000;
    // 创建prime列表
    int prime[number];
    int count;
    count = 0;

    // 初试化prime[n]的所有值为1，prime[n]=1表示n为素数。
    for (int i = 0; i < number; i++) {
        prime[i] = 1;
    }

    // n=2开始，去除n的倍数，n++
    for (int i = 2; i < number; i++) {
        if (prime[i]) {
            for (int j = 2; j*i < number; j++) {
                prime[j*i] = 0;
            }
        }
    }

    // 输出prime[n]=1的n值（素数）
    for (int i = 1; i < number; i++) {
        if (prime[i]) {
           printf("%d ", i);
           count++;
           if (count == n) {
               break;
           }
        }
    }

    return 0;
}