#include <stdio.h>

int main(void) {
    const int num=100;
    int a_list[num];
    int b_list[num];
    int a, b,c,d, count, count_1;

    count = 0;
    count_1 = 0;
    do {scanf("%d %d", &a, &b);
        if (a==0) {
            count_1++;
        }
        a_list[count] = a;
        b_list[count] = b;
        count++;
    } while (count_1!=2);

//    for (int i = 0; i < 10; i++) {
//        printf("%d ", b_list[i]);
//    }
//    printf("\n");

    for (int k = num-1; k >= 0 ; k--) {
        if (a_list[k]&&b_list[k]){
            c = b_list[k];
            for (int i = k-1; i >=0 ; i--) {
                if (a_list[k]==a_list[i]){
                    c = b_list[k]+b_list[i];
                    printf("%d, %d", a_list[k], c);
                    break;
                }
            }
            printf("%d, %d", a_list[k], c);
        }
    }
//    for (int i = 0; i < num; i++) {
//        for (int j = i+1; j < num; j++) {
//            if (a_list[i] == a_list[j]) {
//                d = a_list[i];
//                c = b_list[i] + b_list[j];
////                printf("%d %d %d ", i, j, c);
//            } else {
//                c = b_list[i];
//                d = a_list[i];
//            }
//
//
//        }
//        printf("%dx%d\n", c,d);
//    }

    
    return 0;
}