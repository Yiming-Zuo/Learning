// 猜数字

#include <stdio.h>
// standard library标准库函数头文件
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n, a, count;
    // 根据当前时间设置种子[https://m.php.cn/csharp-article-421884.html]
    srand(time(0));
    n = rand()%100+1;
    count = 0;

    do {
        scanf("%d", &a);
        count += 1;
        if (a > n) {
            printf("大了\n");
        // 可以不包括全部情况
        } else if (a < n) {
            printf("小了\n");
        }
    } while (a != n);

    printf("你猜了%d次\n", count);

    return 0;
}