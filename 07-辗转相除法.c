//求最大公约数：
//如果b等于零，计算结束，a就是最大公约数
//否则，计算a除以b的余数，让a等于b，而b等于那个余数
//回到第一步

#include <stdio.h>

int main(void) {
    int a, b, t, gcd;
    scanf("%d %d", &a, &b);

    while (b != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    gcd = a;
    printf("%d", gcd);

    return 0;
}
