// 凑硬币(凑齐一个就种植)

#include <stdio.h>

int main(void) {
    int one, two, five;
    int x=2;
//    int exit = 0;  // 接力break值

    for (one=0; one<=x*10; one++) {
        for(two=0; two<=x*10/2; two++) {
            for (five=0; five<=x*10/5; five++) {
                if (one + two * 2 + five * 5 == x * 10) {
                    printf("%d %d %d %d\n", one, two, five ,x);
                    goto out;
//                    exit = 1;
//                    break;
                }
            }
//            if (exit == 1) {
//                break;
//            }
        }
//        if (exit == 1) {
//            break;
//        }
    }
    out:
    return 0;
}