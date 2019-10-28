#include <stdio.h>

int main(void) {
    int num, a, count, sum, zero, c;

    scanf("%d", &num);
    sum = 0;
    count = 0;
    while ( num > 0) {
        a = num % 10;
        count++;
//        printf("%d %d ", a, count);
        if ( (a % 2 == 0 && count % 2 == 0) || (a % 2 != 0 && count % 2 != 0)) {
            c = 1;
        } else {
            c = 0;
        }

        sum = sum + c * 10 * (count - 1 );
        num /= 10;
    }

    printf("%d", sum);
    return 0;
}
