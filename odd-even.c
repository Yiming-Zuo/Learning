// 奇偶个数：你的程序要读入一系列正整数数据，输入-1表示输入结束，-1本身不是输入的数据。程序输出读到的数据中的奇数和偶数的个数。

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