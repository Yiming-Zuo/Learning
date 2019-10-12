#include <stdio.h>

int main(void)
{
    int H;
    scanf("%d", &H);
    double W = (H - 100) * 0.9 * 2;
    printf("%.2f", W);

    return 0;
}