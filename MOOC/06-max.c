#include <stdio.h>

int main(void) {
    int a, b, min, i;

    scanf("%d %d", &a, &b);

    if (a > b) {
        min = b;
    } else {
        min = a;
    }

    for (i=min; i>=1; i--) {
        if (a%i==0 && b%i==0) {
            printf("%d", i);
            break;
        }
    }

    return 0;
}