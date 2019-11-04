#include <stdio.h>
int count(int year, int month, int day);

int main(void) {
    int year, month, day;
    scanf("%d/%d/%d", &year, &month, &day);

    printf("%d", count(year, month, day));
}


int count(int year, int month, int day) {
    int n=0;

    switch (month) {
        case 1:n = day;
            break;
        case 2:n = day + 31;
            break;
        case 3:n = day + 59;
            break;
        case 4:n = day + 90;
            break;
        case 5:n = day + 120;
            break;
        case 6:n= day + 151;
            break;
        case 7:n = day + 181;
            break;
        case 8:n = day + 212;
            break;
        case 9:n = day + 243;
            break;
        case 10:n = day + 273;
            break;
        case 11:n = day + 304;
            break;
        case 12:n = day + 334;
            break;
    }
    if( ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0 ) {
        if ( month > 2 ) {
            n++;
        }
    }

    return n;
}