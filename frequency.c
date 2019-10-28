// 经典数组
// 输入数量不确定的[0,9]范围内的整数，统计每一种数字出现的次数，输入-1结束

#include <stdio.h>

int main(void) {
    // 定义数组大小
    const int number = 10;
    int num;
    // 定义数组
    int count[number];
    // 初始化数组
    for (int i = 0; i < number; i++) {
        count[i] = 0;
    }

    scanf("%d", &num);
    while ( num != -1 ) {
        if (num >= 0 && num <= 9) {
            // 数组参与运算
            count[num]++;
        }
        scanf("%d", &num);
    }
    // 遍历数组输出
    for (int i = 0; i < number; i++) {
        printf("%d:%d\n", i, count[i]);
    }


    return 0;
}