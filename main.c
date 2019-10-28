//
#include <stdio.h>

int main(void) {
    int grade[5][3];
    int v[3] = {0};
    int sum = 0;
    for (int j = 0; j < 3 ; j++) {
        for (int i = 0; i < 5 ; i++) {
            scanf("%d", &grade[i][j]);
            sum += grade[i][j];
        }
        v[j] = sum / 5;
        sum = 0;
    }
    for (int k = 0; k < 3; k++) {
        printf("%d\n", v[k]);
    }
    return 0;
}