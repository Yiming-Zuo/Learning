#include <stdio.h>

int main(void) {
    int num, odd, even;
    odd = 0, even = 0;

    do {
        scanf("%d", &num);
        if ( num == -1 )
        {
            break;
        }
        else if ( num % 2 == 0 )
        {
            even++;
        } else
        {
            odd++;
        }

    } while ( num != -1 );

    printf("%d %d", odd, even);
    return 0;
}