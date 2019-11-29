#include <stdio.h>
#include <string.h>

int main(void){
    int a = 100;
    char str[] = "www.baidu.com";

    printf("%p %p\n", &a, str);


    return 0;
}