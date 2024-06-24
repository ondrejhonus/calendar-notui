#include <stdio.h>
#include <time.h>
#include <string.h>

#define SIZE 100

static const int month_len[] = {31,28,31,30,31,30,31,31,30,31,30,31};

void get_month_name(int month_num, char month[20]){
    switch(month_num){
        case 1:
            strcpy(month, "January");
            break;
        case 2:
            strcpy(month, "February");
            break;
        case 3:
            strcpy(month, "May");
            break;
        case 4:
            strcpy(month, "March");
            break;
        case 5:
            strcpy(month, "April");
            break;
        case 6:
            strcpy(month, "June");
            break;
        case 7:
            strcpy(month, "July");
            break;
        case 8:
            strcpy(month, "August");
            break;
        case 9:
            strcpy(month, "September");
            break;
        case 10:
            strcpy(month, "October");
            break;
        case 11:
            strcpy(month, "November");
            break;
        case 12:
            strcpy(month, "December");
    }
}

static int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

static int get_first_day(struct tm tm) {
    int year = tm.tm_year + 1900;
    int mon = tm.tm_mon;
    int dow = 3;  // 1800-01-01 is a Wednesday.
    while (year-- > 1800) {
        int leap_days = is_leap_year(year);
        dow += 365 + leap_days;
    }
    while (mon--)
        dow += month_len[mon];
    dow += 1;
    return dow % 7;
}

void display_calendar(struct tm tm){
    int fday = get_first_day(tm);
    int col_num = 0;
    printf("  Mon Tue Wed Thu Fri Sat Sun\n");
    for (int i = 0; i < fday - 1; ++i) {
        printf("    ");
        col_num++;
    }
    for (int i = 0; i < month_len[tm.tm_mon]; ++i) {
        if(col_num < 6){
            printf("%4d", i + 1);
            col_num++;
        }
        else{
            printf("%4d\n", i + 1);
            col_num = 0;
        }

    }
}

int main(void) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char month[20];
    get_month_name(tm.tm_mon + 1, month);
    printf("%02d. %s %d %02d:%02d:%02d\n\n", tm.tm_mday, month, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
    display_calendar(tm);
    return 0;
}
