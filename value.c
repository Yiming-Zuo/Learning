// 数字特征值：根据编码算法得出表示输入非负整数奇偶性的二进制数字，输出它对应的十进制数字

#include <stdio.h>

int main(void) {
    int num, a, count, sum, c, b;

    scanf("%d", &num);
    sum = 0;
    count = 0;
    b = 1;
    while ( num > 0) {
        a = num % 10;
        num = num / 10;
        count++;
//        printf("%d %d ", a, count);
        if ( (a % 2 == 0 && count % 2 == 0) || (a % 2 != 0 && count % 2 != 0)) {
            c = 1;
        } else {
            c = 0;
        }
//        printf("%d\n", c);
        sum = sum + c * b;
        b*=2;
    }

    printf("%d", sum);

    return 0;
}
