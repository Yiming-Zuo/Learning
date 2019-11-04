// 线性搜索：遍历数组找到某一个数值的位置

#include <stdio.h>

int search(int key, int a[], int len) {
    int ret = -1;
    for (int i = 0; i < len; i++) {
        if (a[i] == key) {
            ret = i;
            break;
        }
    }
    return ret;
}

int main(void) {
    int a[] = {2,6,3,8,234,23,64};
    int r;
    r = search(23, a, sizeof(a)/ sizeof(a[0]));
    printf("%d", r);

    return 0;
}