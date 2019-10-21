// f(n)=1-1/2+1/3-1/4+...+1/n

#include <stdio.h>

int main(void) {
    int n;
    double sum = 0.0;
    double sign = 1.0;  // 正负号且浮点

    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        sum += sign * 1 / i;
        sign = -sign;
    }
    printf("f(%d)=%f", n, sum);

    return 0;
}