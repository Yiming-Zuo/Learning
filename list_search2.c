// 二分搜索:有序数组

#include <stdio.h>

int max(int a[], int len) {
    int maxid = 0;
    for (int i=0; i<len; i++) {
        if (a[i] > a[maxid]) {
            maxid = i;
        }
    }
    return maxid;
}

// 选择排序


int search(int key, int a[], int len) {
    int ret = -1;
    int left = 0, right = len - 1;
    while (right >= left) {
        int mid = (left + right)/2;
        if (a[mid] == key) {
            ret = mid;
            break;
        } else if (a[mid] > key) {
            right = mid - 1;
        } else {
            left = mid +1;
        }
    }
    return ret;
}

int main(void) {
    int a[] = {1,3,10,4,5,9,2,11,2,18,2};
    int len = sizeof(a)/ sizeof(a[0]);
    int b[len];
    for (int i = 0; i < len; i++) {
        b[i] = a[i];
    }
    for (int i = len; i > 0; i--) {
        int maxid = max(b, i);
        int t = b[maxid];
        b[maxid] = b[i-1];
        b[i-1] = t;
    }
//    for (int j = 0; j < len; j++) {
//        printf("%d ", a[j]);
//    }

//    for (int j = 0; j < len; j++) {
//        printf("%d ", b[j]);
//    }

    int r = search(5, b, len);
//    printf("%d", r);

    for (int i = 0; i < len; i++) {
        if (a[i] == b[r]) {
            printf("%d", i);
        }
    }


    return 0;
}