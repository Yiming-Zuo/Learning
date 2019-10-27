#include <stdio.h>

int main(void) {
    int i, b;
    scanf("%d", &i);

    while(i > 0) {
        b = i % 10;
        printf("%d", b);
        if (i >= 10) {
            printf(" ");
        }
        i /= 10;
    }

    return 0;
}